cmake_minimum_required(VERSION 3.0)
project(BrainShockSTL_TEST)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

set(CATCH "/Users/yoonsung-mac/OpenSources/Catch/include")
include_directories(${CATCH})

option(BUILD_TEST "Build the unit tests" ON)

add_subdirectory(Catch_tutorial)

enable_testing()