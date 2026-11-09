cmake_minimum_required(VERSION 4.1)
project(swapandserve)

set(CMAKE_CXX_STANDARD 14)

add_executable(swapandserve
        ChainingHashMap.cpp
        ChainingHashMap.h)
