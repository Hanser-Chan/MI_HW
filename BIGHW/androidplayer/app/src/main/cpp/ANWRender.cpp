#include "ANWRender.h"
#include <string.h>
#include "log.h"

#define LOG_TAG "ANWDisplay"

ANWRender::ANWRender(ANativeWindow* window) {
    native_window = window;
}

int ANWRender::init(int videoWidth, int videoHeight) {
    width = videoWidth;
    height = videoHeight;
    if (native_window == NULL)
        return -1;
    return ANativeWindow_setBuffersGeometry(native_window, videoWidth,
                                            videoHeight, WINDOW_FORMAT_RGBA_8888);
}

int ANWRender::render(uint8_t* rgba) {
    if (native_window == NULL || rgba == NULL)
        return -1;

    ANativeWindow_Buffer out_buffer;
    ANativeWindow_lock(native_window, &out_buffer, NULL);

    int srcLineSize = width * 4;
    int dstLineSize = out_buffer.stride * 4;
    uint8_t* dstBuffer = static_cast<uint8_t*>(out_buffer.bits);

    for (int i = 0; i < height; ++i) {
        memcpy(dstBuffer + i * dstLineSize, rgba + i * srcLineSize, srcLineSize);
    }

    ANativeWindow_unlockAndPost(native_window);
    return 0;

}
