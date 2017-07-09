//
// Created by yoonsung-mac on 05/07/2017.
//

#define CATCH_CONFIG_MAIN
#include <iostream>
#include <catch.hpp>
using namespace std;

unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE("Factorials", "[factorial]"){

//    CHECK( Factorial(0) == 1);
    REQUIRE( Factorial(1) == 1);
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
    cout << "merong" << endl;
}
