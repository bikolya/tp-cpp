cmake_minimum_required(VERSION 2.8.4)
project(tp_ccp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tp-cpp-1/main.cpp)
add_executable(tp_ccp ${SOURCE_FILES})