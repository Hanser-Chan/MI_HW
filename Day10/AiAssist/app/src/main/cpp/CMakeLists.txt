#说明 android cmake生成的target需要主动链接两个库： android和log，
#其中android库用来调用相关android的功能，log用来打印日志
#例子：target_link_libraries(aiassist
#        android
#        log

#请补全以下cmakelists.txt的内容
#作业要求：
#1. 要求可以生成动态库，库的名字叫做aiassist。
#2. 工程具有子工程cJSON，生成库叫cjson。
#3. aiassist库需要依赖cjson。
#说明：
#cJSON里面的cmake是编写好的不用做修改，只需要不全以下cmakelists.txt文件即可。


cmake_minimum_required(VERSION 3.20)

project("assist")

set(INCLUDE_DIR cJSON)

include_directories(${INCLUDE_DIR})

add_subdirectory(cJSON)

add_library(${CMAKE_PROJECT_NAME} SHARED assist.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}
    cjson
    android
    log)