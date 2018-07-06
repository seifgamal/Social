cmake_minimum_required(VERSION 3.3)
project(Social)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

file(GLOB Omar "*.h" "*.cpp")
add_executable(Social ${Omar} Notifications.h)
