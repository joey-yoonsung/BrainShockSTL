//
// Created by yoonsung-mac on 10/07/2017.
//

#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <map>

using namespace std;

TEST_CASE("CHAPTER7", "[stl][associative][container][set]") {

    multimap<int, int> mm;

    mm.insert(pair<int, int>(5, 50));
    mm.insert(pair<int, int>(3, 30));
    mm.insert(pair<int, int>(3, 35));
    mm.insert(pair<int, int>(1, 10));
    mm.insert(pair<int, int>(2, 20));
    mm.insert(pair<int, int>(8, 80));
    mm.insert(pair<int, int>(6, 60));
    mm.insert(pair<int, int>(4, 40));
    mm.insert(pair<int, int>(4, 45));
//    mm.insert(pair<int, int>(7, 70));

    pair<int, int> pr(9, 90);
    mm.insert(pr);

    SECTION("EX_7-21", "[find][count]") {
        REQUIRE(mm.count(2) == 1);
        REQUIRE(mm.count(3) == 2);
        REQUIRE(mm.count(4) == 2);

        multimap<int, int>::iterator iter = mm.find(3);
        REQUIRE(iter->first == 3);
        REQUIRE(iter->second == 30);
        ++iter;
        REQUIRE(iter->first == 3);
        REQUIRE(iter->second == 35);
    }

    SECTION("EX_7-22", "[lower_bound][upper_bound][equal_range]") {


        map<int, int>::iterator lower_iter = mm.lower_bound(3);
        map<int, int>::iterator upper_iter = mm.upper_bound(3);
        REQUIRE(lower_iter->second == 30);
        REQUIRE((++lower_iter)->second == 35);
        REQUIRE(upper_iter->second == 40);

        lower_iter = mm.lower_bound(10);
        upper_iter = mm.upper_bound(10);

        REQUIRE(lower_iter == upper_iter);
        REQUIRE(lower_iter == mm.end());
        cout << lower_iter->first << " : " << lower_iter->second << endl; //쓰레기값
        cout << upper_iter->first << " : " << upper_iter->second << endl; //쓰레기값
        //대신 값은 같음(주소가같으니까)
        // first값이 어떤때는 0 이고 어떤때는 1 이고 어떤떄는 124152343 이런값이고... 바뀐다

        pair<multimap<int, int>::iterator, multimap<int, int>::iterator> iter_pair;
        iter_pair = mm.equal_range(3);

        int count = 0;
        for (multimap<int, int>::iterator iter = iter_pair.first; iter != iter_pair.second; ++iter) {
            REQUIRE(iter->first == 3);
            if (!count) {
                REQUIRE(iter->second == 30);
                ++count;
            } else {
                REQUIRE(iter->second == 35);
            }
        }

        iter_pair = mm.equal_range(7);
        REQUIRE(iter_pair.first->first == 8); //TODO : 여기선 왜 end 를 받지
        REQUIRE(iter_pair.first == iter_pair.second);

    }
}