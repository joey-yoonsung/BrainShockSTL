//
// Created by yoonsung-mac on 10/07/2017.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <set>
using namespace std;

TEST_CASE("CHAPTER7", "[stl][associative][container][set]") {

    multiset<int> ms;

    ms.insert(50);
    ms.insert(30);
    ms.insert(30); //duplicate
    ms.insert(80);
    ms.insert(80); //duplicate
    ms.insert(40);
    ms.insert(10);
    ms.insert(70);
    ms.insert(90);
    ms.insert(20);
    ms.insert(60);

    SECTION("EX_7-12") {

        multiset<int>::iterator iter = ms.find(30);
        REQUIRE(*iter == 30);
        ++iter;
        REQUIRE(*iter == 30);

        multiset<int>::iterator lower_iter;
        multiset<int>::iterator upper_iter;

        lower_iter = ms.lower_bound(30);
        upper_iter = ms.upper_bound(30);
        REQUIRE( *lower_iter ==30);
        REQUIRE( *upper_iter ==40);

        for(iter = lower_iter ; iter != upper_iter ; ++iter){ //발견되지 않았다면 lower==upper이니까 반복문 안돌고 끝나겠지
            REQUIRE(*iter == 30);
        }
    }

    SECTION("EX_7-13"){

        pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair;
        iter_pair = ms.equal_range(30);
        multiset<int>::iterator iter;
        for(iter = iter_pair.first ; iter!=iter_pair.second ; ++iter){
            REQUIRE(*iter ==30);
        }

        iter_pair = ms.equal_range(55);
        REQUIRE(iter_pair.first == iter_pair.second); //TODO : pair는 실패를 기본적으로 first==second  로 확인
        REQUIRE(*iter_pair.first == 60 );
        REQUIRE(*iter_pair.second == 60 );
        REQUIRE_FALSE(iter_pair.first == ms.end()); // TODO : 여긴 왜 또 end 가 아니지?
    }
}