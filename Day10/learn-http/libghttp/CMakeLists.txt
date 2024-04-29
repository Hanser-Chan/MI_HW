cmake_minimum_required(VERSION 3.10)
project(libghttp)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 将所有源文件编译成一个动态库
add_library(libghttp SHARED
    ghttp.c
    http_base64.c
    http_date.c
    http_hdrs.c
    http_req.c
    http_resp.c
    http_trans.c
    http_uri.c
)

# 确保库的头文件在其他地方也可以被包含进来
target_include_directories(libghttp PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

