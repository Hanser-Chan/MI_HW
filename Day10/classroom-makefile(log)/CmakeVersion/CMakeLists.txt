cmake_minimum_required(VERSION 3.10)  # 设置CMake最低版本要求

project(Logging)  # 定义项目名称

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含当前项目的 src 目录
include_directories(${PROJECT_SOURCE_DIR}/src)

# 添加可执行文件
add_executable(LogExe main.cpp src/easylogging++.cc)


