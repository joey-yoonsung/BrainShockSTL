//
// Created by yoonsung-mac on 10/07/2017.
//
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

TEST_CASE("CHAPTER6", "[stl][sequence][container][vector]") {

    vector<int> v;
    for (int i = 0; i < 5; i++) {
        v.push_back(10 * (i + 1));
    }
    // 이부분이 각 section 들어가기전에 항상 실행되고 들어감

    SECTION("EX_6-1") {

        for (int i = 0; i < v.size(); i++) {
            REQUIRE(v[i] == (10 * (i + 1)));
        }
    }

    SECTION("EX_6-2") {
        for (vector<int>::size_type i = 0; i < v.size(); ++i) {
            REQUIRE(v[i] == (10 * (i + 1)));
        }
        REQUIRE(strcmp(typeid(vector<int>::size_type).name(), "unsinged_int"));
    }

    SECTION("EX_6-3") {
        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 6);
        REQUIRE(v.max_size() >= INT_MAX);
    }

    SECTION("EX_6-5") {
        v.clear();
        v.reserve(8);

        for (int i = 0; i < 8; i++) {
            v.push_back(10 * (i + 1));
            REQUIRE(v.size() == (i + 1));
            REQUIRE(v.capacity() == 8);
        }

        v.push_back(90);
        REQUIRE(v.size() == 9);
        REQUIRE(v.capacity() >= 9);
    }

    SECTION("EX_6-6") {
        vector<int> v1(5);

        for (int i = 0; i < 5; i++) {
            v1.push_back(10 * (i + 1));
        }
        for (int i = 0; i < 5; i++) {
            REQUIRE(v1[i] == 0);
        }
        for (int i = 5; i < 10; i++) {
            REQUIRE(v1[i] == (10 * (i - 4)));
        }

        vector<int> v2(5);

        for (int i = 0; i < 5; i++) {
            v2[i] = (10 * (i + 1));
        }
        for (int i = 0; i < v2.size(); i++) {
            REQUIRE(v2[i] == (10 * (i + 1)));
        }
    }

    SECTION("EX_6-7") {
        vector<int> v1(5);

        for (int i = 0; i < 5; i++) {
            v1.push_back(10 * (i + 1));
        }
        for (int i = 0; i < 5; i++) {
            REQUIRE(v1[i] == 0);
        }
        for (int i = 5; i < 10; i++) {
            REQUIRE(v1[i] == (10 * (i - 4)));
        }

        vector<int> v2(5, 10);

        for (int i = 0; i < v2.size(); i++) {
            REQUIRE(v2[i] == 10);
        }
        for (int i = 0; i < 5; i++) {
            v2[i] = (10 * (i + 1));
        }
        for (int i = 0; i < v2.size(); i++) {
            REQUIRE(v2[i] == (10 * (i + 1)));
        }
    }

    SECTION("EX_6-8") {

        REQUIRE(v.size() == 5);
        REQUIRE((v.capacity() >= 5 && v.capacity() <10));

        v.resize(10);
        for(int i=5; i<10 ;i++){
            REQUIRE(v[i] == 0);
        }
        REQUIRE(v.size() == 10);
        REQUIRE(v.capacity() >= 10 );
        int tempCapacity=v.capacity();

        v.resize(5);
        for(int i=0; i<v.size() ;i++){
            REQUIRE(v[i] == (10*(i+1)));
        }
        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() == tempCapacity );

        //현재 capacity 16인데 그 이하로 resize 해도 capacity 변하지 않음
        v.resize(16, 100);
        for(int i=5; i<16 ;i++){
            REQUIRE(v[i] == 100);
        }
        REQUIRE(v.size() == 16);
        REQUIRE(v.capacity() == tempCapacity );
    }

    SECTION("EX_6-9"){
        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 5 );
        int tempCapacity = v.capacity();

        v.clear();
        REQUIRE(v.size() == 0 );
        REQUIRE(v.capacity() == tempCapacity );
        REQUIRE(v.empty());
    }

    SECTION("EX_6-10"){
        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 5 );
        int tempCapacity = v.capacity();

        vector<int>().swap(v);

        REQUIRE(v.size() == 0 );
        REQUIRE(v.capacity() == 0 );
        REQUIRE(v.empty());
    }

    SECTION("EX_6-11"){
        for (int i = 0; i < v.size(); i++) {
            REQUIRE(v[i] == (10 * (i + 1)));
        }

        REQUIRE(v.size() == 5);
        REQUIRE(v.capacity() >= 5 );
        int tempCapacity = v.capacity();

        vector<int> v2;
        for( int i=0;i< 10; ++i){
            v2.push_back(100*(i+1));
        }
        int tempCapacity2=v2.capacity();

        v2.swap(v);

        for(int i=0 ; i<10 ; ++i){
            REQUIRE(v[i] == (100*(i+1)));
        }
        REQUIRE(v.capacity() == tempCapacity2);
        REQUIRE(v2.capacity() == tempCapacity);

        REQUIRE(v.size() == 10);
        REQUIRE(v2.size() == 5);
    }

}
