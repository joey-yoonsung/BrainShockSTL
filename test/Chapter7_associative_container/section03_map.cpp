//
// Created by yoonsung-mac on 10/07/2017.
//
#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include <map>
using namespace std;

TEST_CASE("CHAPTER7", "[stl][associative][container][set]") {

    map<int, int> m;

    m.insert(pair<int, int>(5, 50));
    m.insert(pair<int, int>(3, 30));
    m.insert(pair<int, int>(1, 10));
    m.insert(pair<int, int>(2, 20));
    m.insert(pair<int, int>(8, 80));
    m.insert(pair<int, int>(6, 60));
    m.insert(pair<int, int>(4, 40));
    m.insert(pair<int, int>(7, 70));

    pair<int , int> pr(9, 90);
    m.insert(pr);

    SECTION("EX_7-14") {
        int i=1;
        for(map<int, int>::iterator iter = m.begin(); iter !=m.end() ; ++iter, ++i){
            REQUIRE(iter->first == i);
            REQUIRE(iter->second== 10*i);
        }
    }

    SECTION("EX_7-15"){
        pair<map<int, int>::iterator, bool> pr;

        pr = m.insert(pair<int, int>(10, 100));
        REQUIRE(pr.second);
        REQUIRE(pr.first->first == 10);
        REQUIRE(pr.first->second == 100);

        pr.first--;
        REQUIRE(pr.first->first == 9 );
        REQUIRE(pr.first->second == 90 );


        //실패
        pr = m.insert(pair<int, int>(9, 95));
        REQUIRE_FALSE(pr.second);
        REQUIRE(pr.first->first  == 9);
        REQUIRE(pr.first->second == 90);
        //이미 위치한 element pair 를 받음
    }

    SECTION("EX_7-16"){
        map<int, int> ma;

        ma[1]=10;
        ma[5]=50;
        ma[7]=70;

        REQUIRE(ma[1]==10);
        REQUIRE(ma[5]==50);
        REQUIRE(ma[7]==70);

        ma[1]=100;
        REQUIRE(ma[1] == 100);

    }

    SECTION("EX_7-17"){
        map<int, string, greater<int>> m;

        m[5]="five";
        m[1]="one";
        m[3]="three";
        m[2]="two";
        m[4]="four";
        int i=5;
        for(map<int, string>::iterator iter = m.begin() ;iter !=m.end(); ++iter, --i){
            REQUIRE(iter->first == i);
            cout << iter->second << endl;
        }
    }

    SECTION("EX_7-18", "[find]"){
        map<int, int>::iterator iter;
        iter = m.find(5);
        REQUIRE(iter != m.end());
        REQUIRE(iter->first == 5);
        REQUIRE(iter->second == 50);

        map<int,int>::iterator lower_iter=m.lower_bound(5);
        map<int,int>::iterator upper_iter=m.upper_bound(5);
        REQUIRE(lower_iter->second == 50);
        REQUIRE(upper_iter->second == 60);

        pair<map<int, int>::iterator ,map<int, int>::iterator> iter_pair;
        iter_pair=m.equal_range(5);
        for(iter = iter_pair.first; iter != iter_pair.second ;++iter){
            REQUIRE(iter->first == 5);
            REQUIRE(iter->second == 50);
        }

        iter_pair = m.equal_range(100);
        REQUIRE(iter_pair.first == iter_pair.second);
        REQUIRE(iter_pair.first == m.end());
        cout<< iter_pair.first->first << " : " << iter_pair.first->second << endl; //쓰레기값


    }

}