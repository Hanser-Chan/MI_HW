/*************************************************************************
	> File Name: ANWDisplay.h
	> Author: wuhao
	> Mail: 
	> Created Time: 2022年11月24日 星期四 19时46分10秒
 ************************************************************************/

#ifndef ANWDISPLAY_H_
#define ANWDISPLAY_H_

#include <stdint.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>

class ANWRender{
public:
    ANWRender(ANativeWindow *window);
    int init(int videoWidth, int videoHeight);
    int render(uint8_t* rgba);

private:
    ANativeWindow *native_window;
    int width;
    int height;
};
#endif
