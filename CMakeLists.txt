cmake_minimum_required(VERSION 3.0)
project(BrainShockSTL)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

#set(SOURCE_FILES test/Chapter1_operator_overloading/section1-5.cpp)
#set(SOURCE_FILES test/Chapter1_operator_overloading/section6.cpp)
set(SOURCE_FILES test/Chapter1_operator_overloading/section7.cpp.cpp)
add_executable(BrainShockSTL ${SOURCE_FILES})