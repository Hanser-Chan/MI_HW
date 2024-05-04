# 实现内容

1. **JNI 入口函数**：`Java_com_example_androidplayer_Player_nativePlay` 是 JNI 入口函数，由 Java 调用。它接受一个文件路径和一个 Surface 对象作为参数，然后开始视频播放流程。
2. **FFmpeg 初始化**：`initializeFFmpeg` 函数用于初始化 FFmpeg 库，注册所有组件，确保后续的解码和播放操作可以正常进行。
3. **打开视频文件**：`openVideoFile` 函数用于打开指定的视频文件，返回一个 `AVFormatContext` 结构体，该结构体包含了视频文件的格式信息。
4. **获取流信息**：`getStreamInfo` 函数用于获取视频流的信息，如分辨率、码率等。
5. **查找视频流索引**：`findVideoStreamIndex` 函数用于在视频文件的流中查找视频流的索引。
6. **获取解码器上下文**：`getCodecContext` 函数用于获取视频解码器的上下文，它包含了解码器的相关参数和状态信息。
7. **渲染视频**：`renderVideo` 函数负责将解码后的视频帧渲染到指定的 Surface 上，实现视频的实时播放。它使用了 FFmpeg 的解码器解码视频帧，并将其转换为 RGBA 格式，然后通过 Android 的 Native Window API 将视频帧渲染到 Surface 上。
8. **暂停视频**：改善`renderVideo`函数，加入互斥锁，并且在主函数中使用线程管理渲染视频的功能。



## 暂未实现

1. 线程实现
2. 播放音频