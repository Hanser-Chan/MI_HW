#include <jni.h>
#include <string>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include "include/log.h"
#include "include/Player.h"
#include "ANWRender.h"
#include <mutex>

extern "C" {
#include "libavutil/imgutils.h"
#include "libswresample/swresample.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libavformat/avformat.h"
}

std::mutex playMutex;
std::condition_variable playCondition;
bool isPaused {false};

float currentSpeed{1.0f};


void initializeFFmpeg() {
    avformat_network_init();
    LOGI("INIFF", "已注册所有组件");
}

// 打开视频文件


AVFormatContext *openVideoFile(const char *fileStr) {
    AVFormatContext* formatContext = avformat_alloc_context();
    if (avformat_open_input(&formatContext, fileStr, nullptr, nullptr) != 0) {
        LOGE("OVF", "打开文件失败: %s", fileStr);
        return nullptr;
    }
    return formatContext;
}

// 获取视频流信息


int getStreamInfo(AVFormatContext *formatContext) {
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        LOGE("GSI", "无法获取流信息");
        return -1;
    }
    return 0;
}

// 查找视频流索引


int findVideoStreamIndex(AVFormatContext *formatContext) {
    for (int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            return i;
        }
    }
    return -1;
}


// 获取解码器


AVCodecContext *getCodecContext(AVCodecParameters *codecParameters) {
    AVCodec* codec = avcodec_find_decoder(codecParameters->codec_id);
    if (codec == nullptr) {
        LOGE("GCC", "找不到解码器");
        return nullptr;
    }

    AVCodecContext* codecContext = avcodec_alloc_context3(codec);
    if (avcodec_parameters_to_context(codecContext, codecParameters) != 0) {
        LOGE("GCC", "创建解码器上下文失败");
        avcodec_free_context(&codecContext);
        return nullptr;
    }

    if (avcodec_open2(codecContext, codec, nullptr) != 0) {
        LOGE("GCC", "打开解码器失败");
        avcodec_free_context(&codecContext);
        return nullptr;
    }

    return codecContext;
}


int renderVideo2(ANativeWindow* window, AVCodecContext* codecContext, AVFormatContext* formatContext, int videoStreamIndex) {
    ANWRender renderer(window);
    if (renderer.init(codecContext->width, codecContext->height) != 0) {
        return -1;
    }

    AVFrame* videoFrame = av_frame_alloc();
    AVFrame* rgbFrame = av_frame_alloc();
    uint8_t* buffer = (uint8_t*)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGBA, codecContext->width, codecContext->height, 1));
    av_image_fill_arrays(rgbFrame->data, rgbFrame->linesize, buffer, AV_PIX_FMT_RGBA, codecContext->width, codecContext->height, 1);
    SwsContext* swsContext = sws_getContext(codecContext->width, codecContext->height, codecContext->pix_fmt, codecContext->width, codecContext->height, AV_PIX_FMT_RGBA, SWS_BILINEAR, nullptr, nullptr, nullptr);

    bool isPlaying = true;
    double iteration = 0.0; // 使用浮点数来累积迭代次数
    while (isPlaying) {
        std::unique_lock<std::mutex> lock(playMutex);
        playCondition.wait(lock, [] { return !isPaused; });
        lock.unlock();

        while (iteration < currentSpeed) {
            AVPacket packet;
            if (av_read_frame(formatContext, &packet) >= 0) {
                if (packet.stream_index == videoStreamIndex) {
                    avcodec_send_packet(codecContext, &packet);
                    if (avcodec_receive_frame(codecContext, videoFrame) == 0) {
                        if (iteration == 0) {
                            // 如果是第一次迭代，进行渲染
                            sws_scale(swsContext, (const uint8_t* const*)videoFrame->data, videoFrame->linesize, 0, codecContext->height, rgbFrame->data, rgbFrame->linesize);
                            renderer.render(rgbFrame->data[0]);
                        }
                        iteration += 1.0; // 每次解码后增加1.0
                    }
                }
                av_packet_unref(&packet);
            } else {
                isPlaying = false;
            }
        }
        iteration -= currentSpeed; // 减去已经处理的倍速部分
    }

    av_free(buffer);
    av_frame_free(&videoFrame);
    av_frame_free(&rgbFrame);
    sws_freeContext(swsContext);
    return 0;
}
// 查找音频流索引


int findAudioStreamIndex(AVFormatContext *formatContext) {
    for (int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
            return i;
        }
    }
    return -1;
}

// 假设frame->data[0]包含浮点PCM数据


void convertFloatToInt16(float *in, int16_t *out, int numSamples) {
    for (int i = 0; i < numSamples; i++) {
        out[i] = static_cast<int16_t>(in[i] * 32768.0f);
    }
}


int decodeAndPlayAudio(AVCodecContext *codecContext, AVFormatContext *formatContext,
                       int audioStreamIndex, AAudioRender &audioRenderer) {
    AVPacket packet;
    AVFrame *frame = av_frame_alloc();
    if (!frame) {
        LOGE("DAPA", "无法分配音频帧");
        return -1;
    }

    // 启动音频渲染器
    if (audioRenderer.start() != 0) {
        LOGE("DAPA", "音频渲染器启动失败");
        av_frame_free(&frame);
        return -1;
    }

    int16_t* int16Buffer = nullptr;

    while (av_read_frame(formatContext, &packet) >= 0) {
        if (packet.stream_index == audioStreamIndex) {
            avcodec_send_packet(codecContext, &packet);
            while (avcodec_receive_frame(codecContext, frame) == 0) {
                // 确定样本数量
                int numSamples = frame->nb_samples * frame->channels;

                // 创建int16缓冲区
                if (!int16Buffer || numSamples > numSamples) {
                    delete[] int16Buffer;
                    int16Buffer = new int16_t[numSamples];
                }

                // 将浮点PCM数据转换为16位整数
                convertFloatToInt16((float*)frame->data[0], int16Buffer, numSamples);

                // 将16位整数PCM数据发送到音频渲染器
                audioRenderer.onAudioDataReceived(int16Buffer, numSamples);
            }
            av_packet_unref(&packet);
        }
    }

    delete[] int16Buffer;
    av_frame_free(&frame);
    return 0;
}




