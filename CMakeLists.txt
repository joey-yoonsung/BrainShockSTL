cmake_minimum_required(VERSION 3.0)
project(BrainShockSTL)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(SOURCE_FILES test/Chapter1_operator_overloading/section1.cpp)
add_executable(BrainShockSTL ${SOURCE_FILES})