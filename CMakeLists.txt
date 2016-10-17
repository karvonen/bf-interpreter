cmake_minimum_required(VERSION 3.6)
project(bf_interpreter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(bf_interpreter ${SOURCE_FILES})