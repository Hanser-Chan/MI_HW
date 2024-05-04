//
// Created by 85262 on 2024/5/2.
//

#ifndef ANDROIDPLAYER_PLAYER_H
#define ANDROIDPLAYER_PLAYER_H
#include <queue>
#include <android/native_window.h>
#include <mutex>
#include <condition_variable>
extern "C"{
#include "libavcodec/packet.h"
#include "libavutil/frame.h"
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
};

#include "AAudioRender.h"

extern std::mutex playMutex;
extern std::condition_variable playCondition;
extern bool isPaused;
extern float currentSpeed;

void initializeFFmpeg();

AVFormatContext* openVideoFile(const char* fileStr);

int getStreamInfo(AVFormatContext* formatContext);

int findVideoStreamIndex(AVFormatContext* formatContext);

AVCodecContext* getCodecContext(AVCodecParameters* codecParameters);


int renderVideo2(ANativeWindow *window, AVCodecContext *codecContext, AVFormatContext *formatContext,
                int videoStreamIndex);


int findAudioStreamIndex(AVFormatContext *formatContext);

int decodeAndPlayAudio(AVCodecContext *codecContext, AVFormatContext *formatContext, int audioStreamIndex, AAudioRender &audioRenderer);

void convertFloatToInt16(float* in, int16_t* out, int numSamples);

////音视频解码
////void decodeVideoPackets1(std::queue<AVPacket *> &VideoPacketQueue, ANativeWindow *window);
////void decodeVideoPackets2(std::queue<AVFrame *> &decodedFrameQueue,std::queue<AVPacket *> &VideoPacketQueue, ANativeWindow *window);
//void decodeVideoPackets5(std::queue<AVFrame *> &decodedFrameQueue,
//                         std::queue<AVPacket *> &VideoPacketQueue,
//                         ANativeWindow *window);
//void renderDecodedFrames(std::queue<AVFrame*> &decodedFrameQueue, ANativeWindow *window);
//
//
//void decodeAndRenderAudioPackets(std::queue<AVPacket*> AudioPacketQueue, AAudioRender& audioRender);

#endif //ANDROIDPLAYER_PLAYER_H
