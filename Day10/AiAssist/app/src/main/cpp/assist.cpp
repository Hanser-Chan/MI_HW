#include <jni.h>
#include "cJSON/cJSON.h"
#include <chrono>
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_com_mi_ai_assist_MainActivity_encodeObjToJsonStr(JNIEnv *env, jobject thiz, jobject data) {
    //TODO::请用cjson实现对象转成string的功能逻辑

//    cJSON *parseJSON = cJSON_Parse(reinterpret_cast<const char *>(data));
//
//    const char *answer = cJSON_GetObjectItem(parseJSON, "answer")->valuestring;
//
//    std::string str = answer;
//
//    cJSON_Delete(parseJSON);
//    delete[] answer;

//    return nullptr;
    //TODO::请把返回值做替换

    // 转换 JSONObject 到 char* 字符串
    const char *jsonString = env->GetStringUTFChars(static_cast<jstring>(data), 0);

    // 解析 JSON 字符串
    cJSON *json = cJSON_Parse(jsonString);

    // 创建 JSON 对象
    cJSON *jsonObj = cJSON_CreateObject();
    cJSON_AddItemToObject(jsonObj, "json", json);

    // 将 JSON 对象转换为字符串
    char *resultJsonString = cJSON_Print(jsonObj);

    // 释放资源
    cJSON_Delete(jsonObj);
    env->ReleaseStringUTFChars(static_cast<jstring>(data), jsonString);

    // 转换为 jstring 并返回
    jstring result = env->NewStringUTF(resultJsonString);
    free(resultJsonString);
    return result;

}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_mi_ai_assist_MainActivity_decodeJsonStrToObj(JNIEnv *env, jobject thiz, jstring json_str) {
    //TODO::请用string实现string转成对象的功能逻辑
//    auto now = std::chrono::system_clock::now();
//    float timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
//
//    cJSON *obj = cJSON_CreateObject();
//
//    cJSON_AddStringToObject(obj, "question", reinterpret_cast<const char *const>(json_str));
//    cJSON_AddNumberToObject(obj, "time", timestamp);
//
//    return reinterpret_cast<jobject>(std::move(obj));

    //TODO::请把返回值做替换

    const char *jnString = env->GetStringUTFChars(json_str, 0);
    auto now = std::chrono::system_clock::now();
    float timestamp = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();


    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json, "question", jnString);
    cJSON_AddNumberToObject(json, "timestamp", timestamp);

    // 将 JSON 对象转换为字符串
    char *jsonString = cJSON_Print(json);

    // 释放 JNI 字符串资源
    env->ReleaseStringUTFChars(json_str, jnString);
    cJSON_Delete(json);

    // 转换为 jstring 并返回
    jstring result = env->NewStringUTF(jsonString);
    free(jsonString);  // 释放 cJSON_Print 产生的字符串
    return result;

}