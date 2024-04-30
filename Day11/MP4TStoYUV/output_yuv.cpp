#include <iostream>
#include <string>

extern "C"
{
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
}

#define OUTPUT_YUV_FILE "output.yuv"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " input_file" << std::endl;
        return 1;
    }

    const char *input_filename = argv[1];
    AVFormatContext *format_ctx = nullptr;
    AVCodecContext *codec_ctx = nullptr;
    AVCodec *codec = nullptr;
    AVPacket packet;
    AVFrame *frame = nullptr;
    struct SwsContext *sws_ctx = nullptr;
    FILE *yuv_file = nullptr;

    avformat_network_init();

    //判断
    if (avformat_open_input(&format_ctx, input_filename, nullptr, nullptr) != 0)
    {
        std::cerr << "不能打开文件" << std::endl;
        return 1;
    }

    if (avformat_find_stream_info(format_ctx, nullptr) < 0)
    {
        std::cerr << "无法找到流信息" << std::endl;
        return 1;
    }

    av_dump_format(format_ctx, 0, input_filename, 0);

    int video_stream_index = -1;
    for (unsigned int i = 0; i < format_ctx->nb_streams; ++i)
    {
        if (format_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            video_stream_index = i;
            break;
        }
    }

    if (video_stream_index == -1)
    {
        std::cerr << "找不到视频流" << std::endl;
        return 1;
    }

    codec = avcodec_find_decoder(format_ctx->streams[video_stream_index]->codecpar->codec_id);
    if (!codec)
    {
        std::cerr << "不支持的编码方式" << std::endl;
        return 1;
    }

    codec_ctx = avcodec_alloc_context3(codec);
    if (!codec_ctx)
    {
        std::cerr << "不能分配编码上下文" << std::endl;
        return 1;
    }

    if (avcodec_parameters_to_context(codec_ctx, format_ctx->streams[video_stream_index]->codecpar) < 0)
    {
        std::cerr << "Failed to copy codec parameters to codec context" << std::endl;
        return 1;
    }

    if (avcodec_open2(codec_ctx, codec, nullptr) < 0)
    {
        std::cerr << "不能打开解码器" << std::endl;
        return 1;
    }

    frame = av_frame_alloc();
    if (!frame)
    {
        std::cerr << "不能分配帧" << std::endl;
        return 1;
    }

    yuv_file = fopen(OUTPUT_YUV_FILE, "wb");
    if (!yuv_file)
    {
        std::cerr << "不能打开输出的 YUV 文件" << std::endl;
        return 1;
    }

    // 转换
    sws_ctx = sws_getCachedContext(nullptr,
                                   codec_ctx->width,
                                   codec_ctx->height,
                                   codec_ctx->pix_fmt,
                                   codec_ctx->width,
                                   codec_ctx->height,
                                   AV_PIX_FMT_YUV420P,
                                   SWS_BICUBIC,
                                   nullptr, nullptr, nullptr);
    if (!sws_ctx)
    {
        std::cerr << "不能初始化" << std::endl;
        return 1;
    }

    int ret;
    while (av_read_frame(format_ctx, &packet) >= 0)
    {
        if (packet.stream_index == video_stream_index)
        {
            ret = avcodec_send_packet(codec_ctx, &packet);
            if (ret < 0)
            {
                std::cerr << "不能对发送的包解码" << std::endl;
                break;
            }
            while (ret >= 0)
            {
                ret = avcodec_receive_frame(codec_ctx, frame);
                if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF)
                    break;
                else if (ret < 0)
                {
                    std::cerr << "Error during decoding" << std::endl;
                    return 1;
                }

                // 进行图像转换
                sws_scale(sws_ctx, frame->data, frame->linesize, 0, frame->height, frame->data, frame->linesize);

                // 写入 YUV 数据
                fwrite(frame->data[0], 1, frame->width * frame->height, yuv_file);
                fwrite(frame->data[1], 1, frame->width * frame->height / 4, yuv_file);
                fwrite(frame->data[2], 1, frame->width * frame->height / 4, yuv_file);
            }
        }
        av_packet_unref(&packet);
    }

    av_frame_free(&frame);
    avcodec_close(codec_ctx);
    avcodec_free_context(&codec_ctx);
    avformat_close_input(&format_ctx);
    fclose(yuv_file);
    sws_freeContext(sws_ctx);

    return 0;
}
