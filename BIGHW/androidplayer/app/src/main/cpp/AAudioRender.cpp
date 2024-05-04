#include "AAudioRender.h"
#include "log.h"

#define LOG_TAG "AAudioRender"

AAudioRender::AAudioRender() {
    this->paused = false;
    this->sample_rate = 44100;
    this->channel_count = 2;
    this->format = AAUDIO_FORMAT_PCM_I16;
    this->callback = nullptr;
}

AAudioRender::~AAudioRender() {
    AAudioStream_close(stream);
}

int AAudioRender::start() {
    AAudioStreamBuilder *builder;
    aaudio_result_t result = AAudio_createStreamBuilder(&builder);
    if (result != AAUDIO_OK) {
        LOGE(LOG_TAG, "createStreamBuilder failed: %s", AAudio_convertResultToText(result));
        return -1;
    }
    AAudioStreamBuilder_setSampleRate(builder, this->sample_rate);
    AAudioStreamBuilder_setChannelCount(builder, this->channel_count);
    AAudioStreamBuilder_setFormat(builder, this->format);
    AAudioStreamBuilder_setPerformanceMode(builder, AAUDIO_PERFORMANCE_MODE_LOW_LATENCY);
    AAudioStreamBuilder_setSharingMode(builder, AAUDIO_SHARING_MODE_SHARED);
    if (!this->callback) {
        LOGE(LOG_TAG, "callback is nullptr");
        return -1;
    }
    AAudioStreamBuilder_setDataCallback(builder, callback, user_data);
    result = AAudioStreamBuilder_openStream(builder, &stream);
    if (result != AAUDIO_OK) {
        LOGE(LOG_TAG, "openStream failed: %s", AAudio_convertResultToText(result));
        return -1;
    }
    this->format = AAudioStream_getFormat(stream);
    this->channel_count = AAudioStream_getChannelCount(stream);
    this->sample_rate = AAudioStream_getSampleRate(stream);
    result = AAudioStream_requestStart(stream);
    if (result != AAUDIO_OK) {
        LOGE(LOG_TAG, "requestStart failed: %s", AAudio_convertResultToText(result));
        return -1;
    }
    AAudioStreamBuilder_delete(builder);
    return 0;
}

int AAudioRender::flush() {
    const int64_t timeout = 100000000; //100ms
    AAudioStream_requestPause(stream);
    aaudio_result_t result = AAUDIO_OK;
    aaudio_stream_state_t currentState = AAudioStream_getState(stream);
    aaudio_stream_state_t inputState = currentState;
    while (result == AAUDIO_OK && currentState != AAUDIO_STREAM_STATE_PAUSED) {
        result = AAudioStream_waitForStateChange(
                stream, inputState, &currentState, timeout);
        inputState = currentState;
    }
    AAudioStream_requestFlush(stream);
    AAudioStream_requestStart(stream);
    result = AAUDIO_OK;
    currentState = AAudioStream_getState(stream);
    inputState = currentState;
    while (result == AAUDIO_OK && currentState != AAUDIO_STREAM_STATE_STARTED) {
        result = AAudioStream_waitForStateChange(
                stream, inputState, &currentState, timeout);
        inputState = currentState;
    }
    return result;

}

int AAudioRender::pause(bool p) {
    if (p == paused) {
        return 0;
    }
    if (p) {
        const int64_t timeout = 100000000; //100ms
        AAudioStream_requestPause(stream);
        aaudio_result_t result = AAUDIO_OK;
        aaudio_stream_state_t currentState = AAudioStream_getState(stream);
        aaudio_stream_state_t inputState = currentState;
        while (result == AAUDIO_OK && currentState != AAUDIO_STREAM_STATE_PAUSED) {
            result = AAudioStream_waitForStateChange(
                    stream, inputState, &currentState, timeout);
            inputState = currentState;
        }
        paused = true;
        return result;
    } else {
        const int64_t timeout = 100000000; //100ms
        AAudioStream_requestStart(stream);
        aaudio_result_t result = AAUDIO_OK;
        aaudio_stream_state_t currentState = AAudioStream_getState(stream);
        aaudio_stream_state_t inputState = currentState;
        while (result == AAUDIO_OK && currentState != AAUDIO_STREAM_STATE_STARTED) {
            result = AAudioStream_waitForStateChange(
                    stream, inputState, &currentState, timeout);
            inputState = currentState;
        }
        paused = false;
        return result;
    }
}

void AAudioRender::setCallback(AAudioCallback cb, void* data) {
    this->callback = cb;
    this->user_data = data;
}

void AAudioRender::configure(int32_t sampleRate, int32_t channelCnt, aaudio_format_t fmt) {
    this->sample_rate = sampleRate;
    this->channel_count = channelCnt;
    this->format = fmt;
}

void AAudioRender::onAudioDataReceived(void* data, int32_t numSamples) {
    // 确保AAudio流已经开启并准备好写入数据
    if (stream == nullptr) {
        LOGE("OADR", "AAudio stream is not initialized.");
        return;
    }

    // 转换数据类型
    int16_t* audioData = static_cast<int16_t*>(data);

    // 计算实际的写入字节数
    int32_t numBytes = numSamples * sizeof(int16_t) * channel_count;

    // 将解码的PCM数据写入AAudio流
    aaudio_result_t result = AAudioStream_write(stream, audioData, numSamples, 10);
    if (result != AAUDIO_OK) {
        LOGE("OADR", "Failed to write audio data to AAudio stream: %s", AAudio_convertResultToText(result));
    }
}
