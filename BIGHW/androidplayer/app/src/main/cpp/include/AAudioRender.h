#include <aaudio/AAudio.h>

// AAudio使用的回调函数定义。第一个参数为当前的音频流，第二个参数是用户设置的数据指针，
// 第三个参数是AAudio提供的音频缓冲区，需要在回调中向该缓冲区写入pcm数据，需要写入的
// 采样数由第四个参数指定。在完成向音频缓冲区写入数据后，返回0表示让AAudio在下一次继续调用
// 这个回调，返回1表示希望AAudio停止调用回调。
using AAudioCallback = int(*)(AAudioStream*, void*, void*, int32_t);

class AAudioRender{
    AAudioStream* stream;
    int32_t channel_count;
    int32_t sample_rate;
    bool paused;
    AAudioCallback callback;
    void* user_data;
    aaudio_format_t format;

public:
    ~AAudioRender() ;

    AAudioRender();

    // 指定采样率，通道数和数据格式，否则使用默认
    void configure(int32_t sampleRate, int32_t channelCnt, aaudio_format_t fmt);

    // 设置AAudio的回调，指定user_data为你需要的数据指针，user_data会传递给callback的第二个参数
    void setCallback(AAudioCallback cb, void* data);

    // AAudioStream开始工作，成功返回0，失败返回<0
    int start();

    // 刷新AAudio的内部缓冲区
    int flush();

    // 参数p为true时表示暂停，为false时表示取消暂停
    int pause(bool p);


    //添加的数据接受函数
    void onAudioDataReceived(void *data, int32_t numSamples);
};