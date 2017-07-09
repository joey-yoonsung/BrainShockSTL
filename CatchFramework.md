# Catch Framework Basic Tutorial

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

## Keyword

#### Test Case & Section
```cpp
TEST_CASE("TEST CASE NAME" , "[TAG1][TAG2]..."){
    //code
    SECTION("SECTION NAME"){
        //code
    }
}
```

#### BDD Style - _SCENARIO, GIVEN, WHEN, THEN_
TEST_CASE : _SCENARIO_

SECTION : _GIVEN, WHEN, THEN_
```cpp
//SCENARIO == TEST_CASE
SCENARIO( "vectors can be sized and resized", "[vector][resize]" ) {

    //GIVEN == SECTION
    GIVEN( "A vector with some items" ) {
        std::vector<int> v( 5 );

        REQUIRE( v.size() == 5 );
        REQUIRE( v.capacity() >= 5 );

        //WHEN == SECTION
        WHEN( "the size is increased" ) {
            v.resize( 10 );

            //THEN == SECTION
            THEN( "the size and capacity change" ) {
                REQUIRE( v.size() == 10 );
                REQUIRE( v.capacity() >= 10 );
            }
        }
        WHEN( "the size is reduced" ) {
            v.resize( 0 );

            THEN( "the size changes but not capacity" ) {
                REQUIRE( v.size() == 0 );
                REQUIRE( v.capacity() >= 5 );
            }
        }
    }
}
```
