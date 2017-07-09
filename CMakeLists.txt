cmake_minimum_required(VERSION 3.0)
project(BrainShockSTL)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
#set(CATCH "/Users/yoonsung-mac/OpenSources/Catch/include")
#include_directories(${CATCH})
#message(${CATCH})

#set(SOURCE_FILES test/Chapter1_operator_overloading/section1-5.cpp)
#set(SOURCE_FILES test/Chapter1_operator_overloading/section6.cpp)
#set(SOURCE_FILES test/Chapter1_operator_overloading/section7.cpp.cpp)
#set(SOURCE_FILES test/Chapter2_function_pointer/section1-2.cpp )
#set(SOURCE_FILES test/Chapter2_function_pointer/section3.cpp)
#set(SOURCE_FILES test/Chapter3_functor/section1.cpp)
#set(SOURCE_FILES test/Chapter3_functor/section2.cpp)
set(SOURCE_FILES test/Chapter4_template/section1.cpp)

option(BUILD_TEST "Build the unit tests" ON)

### CATCH FRAMEWORK TUTORIAL ###
#add_library(Catch INTERFACE)
#target_link_libraries(Catch INTERFACE ${CATCH})
#add_executable(Test_BrainShockSTL ${TEST_FILES})
#target_link_libraries(Test_BrainShockSTL Catch)

#enable_testing()

#add_test(NAME ADDTest_BrainShockSTL COMMAND Test_BrainShockSTL arg1="-r junit")
#add_test(ADDTest_BrainShockSTL Test_BrainShockSTL -r junit)
add_subdirectory(test)
add_executable(BrainShockSTL ${SOURCE_FILES})

enable_testing()
