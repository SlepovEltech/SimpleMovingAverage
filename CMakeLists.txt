cmake_minimum_required(VERSION 3.26)
project(SMA)

set(CMAKE_CXX_STANDARD 17)

add_executable(SMA main.cpp
        SimpleMovingAverage.cpp
        SimpleMovingAverage.h)
