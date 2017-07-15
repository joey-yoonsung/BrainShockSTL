# How to use Catch Framework on CMake Project.
This tutorial will be helpful who do not experienced with CMake yet and try to adjust unit testing using Catch framework on CMake.

If you don't have any experience unit testing tool in c++ world, I can suggest the Catch framework as the easiest tool for beginner. These guy will be easy to adjust unit testing as following this tutorial.


## Basic Source Prerequisite on Catch framework
  * No "Main" Function

    Thinks like auto main function generation.
    ```cpp
    #define CATCH_CONFIG_MAIN
    #include "catch.hpp"
    ```
    **#define must be located previous than #include**
  * There is "Main" function
    ```cpp
    #define CATCH_CONFIG_RUNNER
    #include "catch.hpp"
    int main( int argc, char* argv[] )
    {
      // global setup...

      int result = Catch::Session().run( argc, argv );

      // global clean-up...

      return ( result < 0xff ? result : 0xff );
    }
    ```

## CMake Usage
  The principle of CMake test (ctest) is simple.
  1. Make executable (command **add_executable**)
  2. Add this executable to test target (command **add_test**)

  In other word, ctest just triggers the executable file whether this executable has unit test or not.

  Then, we just make executable file including unit test sources and add it to test target.

  * Step

    1. Set include directory
        ```cmake
        set(CATCH "${YOUR_CATCH_ROOT_DIR}/include")
        include_directories(${CATCH})
        ```

    2. Set library
        ```cmake
        add_library(Catch INTERFACE)
        ```

    3. Set executable
        ```cmake
        add_executable(Test_CatchTutorial_01 tutorial.cpp)
        target_link_libraries(Test_CatchTutorial_01 Catch)

        add_executable(Test_CatchTutorial_02 tutorial2.cpp, tutorial3.cpp)
        target_link_libraries(Test_CatchTutorial_02 Catch)
        ```
        If proper executable file will be created, there is one 'main' function in executable.
        If you compose the executable with only Catch framework tests, you have to use '#define CATCH_CONFIG_MAIN' signature on only one cpp file.
        Then, test cases on other cpp files will run fine. In above case, '#define CATCH_CONFIG_MAIN' is defined on tutorial2.cpp file only.

    4. Set enable_testing
        ```cmake
        enable_testing()
        ```
        When you has subdirectory (use add_subdirectory), you must write enable_testing on higher(parent) project CMakeLists.txt if you want test operation.
        If you don't write it, cmake ignores subdirectory's add_test.

    5. Set add_test
        ```cmake
        add_test(CatchTutorial_01 Test_CatchTutorial_01)
        add_test(CatchTutorial_02 Test_CatchTutorial_02 -o "result2" -r "xml")
        ```

        This script is same with below.

        ```cmake
        add_test(NAME CatchTutorial_01 COMMAND Test_CatchTutorial_01)
        add_test(NAME CatchTutorial_02 COMMAND Test_CatchTutorial_02 -o "result2" -r "xml")
        ```

    6. Total
        ```cmake
        set(CATCH "${YOUR_CATCH_ROOT_DIR}/include")
        include_directories(${CATCH})

        add_library(Catch INTERFACE)
        target_link_libraries(Catch INTERFACE ${CATCH})


        add_executable(Test_CatchTutorial_01 tutorial.cpp)
        target_link_libraries(Test_CatchTutorial_01 Catch)

        add_executable(Test_CatchTutorial_02 tutorial2.cpp)
        target_link_libraries(Test_CatchTutorial_02 Catch)

        enable_testing()

        add_test(CatchTutorial_01 Test_CatchTutorial_01 -o "result1" -r "junit" )
        add_test(CatchTutorial_02 Test_CatchTutorial_02 -o "result2" -r "xml")
        ```
  * How to run unit test?

    1. make

    2. make test (or) ctest

  * Test Result

    We can't confirm the test result if use cmake test on console. So, we have to pick it out file.

    '-o' option for file output. '-r' option for output form.
    ```cmake
    add_test(CatchTutorial_02 Test_CatchTutorial_02 -o "result2" -r "xml")
    ```
    This means that output file name is 'result2' and output result form is 'xml'.

    '-r' option supply the way which is located in "${Catch_SOURCE_DIR}/include/reporters"

    Current List
    ```console
    catch_reporter_automake.hpp
    catch_reporter_compact.hpp
    catch_reporter_junit.hpp
    catch_reporter_tap.hpp
    catch_reporter_xml.hpp
    catch_reporter_bases.hpp
    catch_reporter_console.hpp
    catch_reporter_multi.hpp
    catch_reporter_teamcity.hp
    ```
      * **CAUTION :** Each add_test has unique output file name because there is no way to append output to origin file._

  * Tag

    If you run test with tag operation supplied by catch, following like below.
    ```cmake
    add_test(CatchTutorial_02 Test_CatchTutorial_02 -o "result2" -r "xml" "[tag1][tag2]") # tag1 and tag2
    ```
    If you use programmable way, you can run with tag dynamically.

## Auto Detect Catch Framework Unit Test
  [tutorial](https://github.com/philsquared/Catch/blob/master/contrib/ParseAndAddCatchTests.cmake)

