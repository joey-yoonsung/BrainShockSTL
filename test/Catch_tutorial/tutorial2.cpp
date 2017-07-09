//
// Created by yoonsung-mac on 08/07/2017.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch.hpp>
using namespace std;
TEST_CASE("TEMP_01", "[vector]"){
    REQUIRE(1==2);
}
TEST_CASE("TEMP_02", "[resize]"){
    REQUIRE(1==1);
}
TEST_CASE("TEMP_03", "[nothing]"){
    REQUIRE(1==1);
}

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
        WHEN( "more capacity is reserved" ) {
            v.reserve( 10 );

            THEN( "the capacity changes but not the size" ) {
                REQUIRE( v.size() == 5 );
                REQUIRE( v.capacity() >= 10 );
            }
        }
        WHEN( "less capacity is reserved" ) {
            v.reserve( 0 );

            THEN( "neither size nor capacity are changed" ) {
                REQUIRE( v.size() == 5 );
                REQUIRE( v.capacity() >= 5 );
            }
        }
    }
}