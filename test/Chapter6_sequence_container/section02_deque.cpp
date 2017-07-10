//
// Created by yoonsung-mac on 10/07/2017.
//

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <iostream>
#include <deque>

using namespace std;

TEST_CASE("CHAPTER6", "[stl][sequence][container][deque]") {

    deque<int> dq;

    for (deque<int>::size_type i = 0; i < 10; ++i) {
        dq.push_back(10 * (i + 1));
    }

    SECTION("EX_6-27"){
        for (deque<int>::size_type i = 0; i < dq.size(); ++i) {
            REQUIRE(dq[i] == 10 * (i + 1));
        }
    }

    SECTION("EX_6-29"){
        dq.push_front(100);
        REQUIRE(dq[0] == 100);
    }

    SECTION("EX_6-30"){
        deque<int>::iterator iter;
        int i=0;
        for(iter = dq.begin(); iter != dq.end() ; ++iter, ++i){
            REQUIRE( *iter == (10 * (i + 1)));
        }

        iter = dq.begin()+2;
        REQUIRE(*iter == 30 );
        iter +=2;
        REQUIRE(*iter == 50);
        iter -=3;
        REQUIRE(*iter == 20);
    }

    SECTION("EX_6-31") {
        deque<int>::iterator iter;
        deque<int>::iterator iter2;
        iter = dq.begin()+2;
        iter2= dq.insert(iter, 500);
        cout << *iter2 << endl;
        REQUIRE(*iter2 == 500);
        iter = dq.begin()+2;
        REQUIRE(*iter == 500);
    }


}