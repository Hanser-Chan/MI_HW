cmake_minimum_required(VERSION 3.20)
project(calc)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(calc
        add.cpp
        add.h
        division.cpp
        division.h
        main.cpp
        mutiple.cpp
        mutiple.h
        sub.cpp
        sub.h)
