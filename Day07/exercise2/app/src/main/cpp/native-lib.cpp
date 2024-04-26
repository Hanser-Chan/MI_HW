#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_cjj_hellocpp_JNITest_stringFromJNI(
        JNIEnv* env,
        jclass clazz) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C" JNIEXPORT jint JNICALL
Java_com_cjj_hellocpp_JNITest_add(JNIEnv *env, jclass clazz, jint num1, jint num2)
{
    return num1+num2;
}