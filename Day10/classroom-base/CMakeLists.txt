cmake_minimum_required(VERSION 3.12)
project(bases_library)

set(CMAKE_CXX_STANDARD 11)

# 设置头文件目录
include_directories(include)

# 添加源文件
set(SOURCES
    src/Condition.cc
    src/CountDownLatch.cc
    src/CurrentThread.cc
    src/Date.cc
    src/Exception.cc
    src/FileUtil.cc
    src/LogFile.cc
    src/Logging.cc
    src/LogStream.cc
    src/ProcessInfo.cc
    src/Thread.cc
    src/ThreadPool.cc
    src/TimeZone.cc
)

# 生成静态库
add_library(base_static_library STATIC ${SOURCES})

# 生成动态库
add_library(base_shared_library SHARED ${SOURCES})

# 设置静态库和动态库的输出名称
set_target_properties(base_static_library PROPERTIES OUTPUT_NAME base_static_library)
set_target_properties(base_shared_library PROPERTIES OUTPUT_NAME base_shared_library)
