cmake_minimum_required(VERSION 3.10)
project(HTTPProject)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(learn-http/include)

# 添加子目录，这将执行子目录中的CMakeLists.txt
add_subdirectory(libghttp)


add_executable(HTTPexe main.cpp src/download.cpp src/get.cpp)

# 链接动态库libghttp

target_link_libraries(HTTPexe libghttp)



