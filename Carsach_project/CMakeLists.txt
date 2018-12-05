cmake_minimum_required(VERSION 3.3)
project(untitled3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lcurl")

set(SOURCE_FILES main.cpp)
add_executable(example ${SOURCE_FILES})
target_link_libraries(untitled3 curl)