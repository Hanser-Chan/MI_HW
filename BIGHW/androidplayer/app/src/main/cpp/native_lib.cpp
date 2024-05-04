#include <jni.h>
#include <string>
#include <android/native_window_jni.h>
#include <thread>
#include "log.h"

#include "Player.h"
extern "C"{
#include "libavformat/avformat.h"
#include "libavcodec/avcodec.h"
}


std::thread thDemux;

std::thread thVideoRender;


extern "C"
JNIEXPORT jint JNICALL
Java_com_example_androidplayer_Player_nativePlay(JNIEnv *env, jobject /* this */, jstring file,
                                                 jobject surface) {


    const char *fileStr = env->GetStringUTFChars(file, nullptr);
    ANativeWindow *window = ANativeWindow_fromSurface(env, surface);
    initializeFFmpeg();
    AVFormatContext *formatContext = openVideoFile(fileStr);
    if (!formatContext) {
        env->ReleaseStringUTFChars(file, fileStr);
        ANativeWindow_release(window);
        return -1;
    }
    if (getStreamInfo(formatContext) < 0) {
        avformat_close_input(&formatContext);
        env->ReleaseStringUTFChars(file, fileStr);
        ANativeWindow_release(window);
        return -1;
    }
    int videoStreamIndex = findVideoStreamIndex(formatContext);
    if (videoStreamIndex == -1) {
        avformat_close_input(&formatContext);
        env->ReleaseStringUTFChars(file, fileStr);
        ANativeWindow_release(window);
        return -1;
    }
    AVCodecContext *codecContext = getCodecContext(formatContext->streams[videoStreamIndex]->codecpar);
    if (!codecContext) {
        avformat_close_input(&formatContext);
        env->ReleaseStringUTFChars(file, fileStr);
        ANativeWindow_release(window);
        return -1;
    }

    //thVideoRender = std::thread(renderVideo2,window, codecContext, formatContext, videoStreamIndex);

    // 确保没有其他视频播放线程正在运行
    if (thVideoRender.joinable()) {
        thVideoRender.join(); // 等待之前的线程结束
    }

    // 重置暂停状态并启动新的播放线程
    {//加大括号限制作用域
        std::lock_guard<std::mutex> lock(playMutex);
        isPaused = false;
    }
    thVideoRender = std::thread(renderVideo2, window, codecContext, formatContext, videoStreamIndex);
    thVideoRender.detach(); // 如果不需要同步线程结束，可以选择分离线程

    env->ReleaseStringUTFChars(file, fileStr);
    // 注意：不要在这里释放 codecContext 和 formatContext，这些资源应该在 renderVideo2 中或线程结束时释放

    return 0; // 返回成功

// 音频
//    const char *nativeFilePath = env->GetStringUTFChars(file, 0);
//
//    // 初始化格式上下文
//    AVFormatContext *formatContext = avformat_alloc_context();
//    if (avformat_open_input(&formatContext, nativeFilePath, nullptr, nullptr) != 0) {
//        LOGE("JNI", "无法打开文件");
//        return -1;
//    }
//
//    // 获取流信息
//    if (getStreamInfo(formatContext) != 0) {
//        LOGE("JNI", "无法获取流信息");
//        return -1;
//    }
//
//    // 查找音频流索引
//    int audioStreamIndex = findAudioStreamIndex(formatContext);
//    if (audioStreamIndex == -1) {
//        LOGE("JNI", "找不到音频流");
//        return -1;
//    }
//
//    // 获取解码器上下文
//    AVCodecContext *codecContext = getCodecContext(formatContext->streams[audioStreamIndex]->codecpar);
//    if (codecContext == nullptr) {
//        LOGE("JNI", "无法获取解码器上下文");
//        return -1;
//    }
//
//    // 初始化音频渲染器
//    AAudioRender audioRenderer;
//    audioRenderer.configure(44100, 2, AAUDIO_FORMAT_PCM_I16);
//
//    // 解码并播放音频
//    if (decodeAndPlayAudio(codecContext, formatContext, audioStreamIndex, audioRenderer) != 0) {
//        LOGE("JNI", "解码或播放失败");
//    }
//
//    // 释放资源
//    avcodec_free_context(&codecContext);
//    avformat_close_input(&formatContext);
//    env->ReleaseStringUTFChars(file, nativeFilePath);
//    return 0;

}


extern "C"
JNIEXPORT void JNICALL
Java_com_example_androidplayer_Player_nativePause(JNIEnv *env, jobject thiz, jboolean p){
    std::lock_guard<std::mutex> lock(playMutex);
    isPaused = p;
    playCondition.notify_all(); // 通知所有等待的线程检查暂停状态
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_androidplayer_Player_nativeSeek(JNIEnv *env, jobject thiz, jdouble position){
    return 0;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_androidplayer_Player_nativeStop(JNIEnv *env, jobject thiz){
    return 0;
}

extern "C"
JNIEXPORT jint JNICALL
Java_com_example_androidplayer_Player_nativeSetSpeed(JNIEnv *env, jobject thiz, jfloat speed){
    std::lock_guard<std::mutex> lock(playMutex);
    // 假设有一个全局变量来存储播放速度
    currentSpeed = speed;
    // 通知播放线程速度已改变
    playCondition.notify_all();
    return 0;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_example_androidplayer_Player_nativeGetPosition(JNIEnv *env, jobject thiz){
    return 0;
}

extern "C"
JNIEXPORT jdouble JNICALL
Java_com_example_androidplayer_Player_nativeGetDuration(JNIEnv *env, jobject thiz){
    return 0;
}