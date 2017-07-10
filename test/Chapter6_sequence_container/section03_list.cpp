#define CATCH_CONFIG_MAIN

#include <catch.hpp>

#include <iostream>
#include <list>

using namespace std;

//
// Created by yoonsung-mac on 10/07/2017.
//
/**
 * list 는 vector 와 deque와는 다르게 배열기반이 아닌 노드기반 컨테이너이다 (double linked list)
 */

bool Predicate(int n){
    return 10 <= n && n<=30;
}

bool Predicate2(int first, int second){
    //앞의 원소가 뒤의 원소보다 같거나 크면 지우겠다
    return second-first <= 0;
}
int globalCount=0;
int localCount =0;
TEST_CASE("CHAPTER6", "[stl][sequence][container][list]") {
    list<int> lt;

    for (list<int>::size_type i = 0; i < 5; ++i) {
        lt.push_back(10 * (i + 1));
    }

    cout << "global count : "<< ++globalCount << endl;

    SECTION("EX_6-32") {
        list<int>::iterator iter;
        int i = 0;
        for (iter = lt.begin(); iter != lt.end(); ++iter, ++i) {
            REQUIRE(*iter == 10 * (i + 1));
        }

        lt.push_front(100);
        REQUIRE(*lt.begin() == 100);
    }

    SECTION("EX_6-33") {

        list<int>::iterator iter = lt.begin();
        list<int>::iterator iter2;
        ++iter;
        ++iter;

        iter2=lt.erase(iter); //30 을 지우고 그자리의 포인터를 넘긴다
        REQUIRE(*iter2 == 40);
        REQUIRE(lt.size() == 4);
        iter = iter2;
        iter2 = lt.insert(iter, 300); // 40이 있는 자리에 300 을 끼워넣는다
        REQUIRE(*iter2 == 300);
        REQUIRE(lt.size() == 5);
    }

    SECTION("EX_6-34"){
        /**
         * vector 와 list의 insert, erase 차이
         * vector는 capacity에 따라 메모리 재할당이 일어날 수 있음
         * list는 노드를 생성,삭제하고 포인터만 바꿔줌
         */
    }

    SECTION("EX_6-35"){
        list<int>::iterator iter = lt.begin();
        lt.insert(iter, 100);
        ++iter, ++iter;
        lt.insert(iter, 100);
        iter=lt.end();
        lt.insert(iter, 100);

        REQUIRE(lt.size() == 8);
        lt.remove(100);
        REQUIRE(lt.size() == 5);
    }

    SECTION("EX_6-36") {
        REQUIRE(lt.size() == 5);

        lt.remove_if(Predicate);
        REQUIRE(lt.size() == 2);
        list<int>::iterator iter;
        int i=0;
        for(iter = lt.begin(); iter != lt.end() ; ++iter, ++i){
            REQUIRE(*iter == (10*(i+4)));
        }
    }


    SECTION("EX_6-37") {
        cout << "local count : " << ++localCount << endl;
        list<int> lt2;
        for(int i=0; i<5 ;++i){
            lt2.push_back(100 * (i+1));
        }

        list<int>::iterator iter = lt.begin();
        ++iter;++iter;

        lt.splice(iter, lt2);

        REQUIRE(lt.size() == 10);
        REQUIRE(lt2.size() == 0);

        int sumTotal=0;
        int sumLt2 =0;

        list<int>::iterator iter2;
        for(iter2 = lt.begin(); iter2 !=lt.end() ; ++iter2){
            sumTotal+=*iter2;
            if(*iter2 >= 100){
                sumLt2+=*iter2;
            }
        }
        REQUIRE(sumTotal == 1650);
        REQUIRE(sumLt2 == 1500);

        cout<< "out section "<< endl;
        SECTION("in section1"){
            cout << "insection 1"<< endl;
        }

        SECTION("in section2"){
            cout << "insection 2"<< endl;
        }
    }

    SECTION("EX_6-38"){
        //splice(iter1, lt2, iter2); iter1의 위치에 lt의 iter2위치를 잘라붙임
        //splice(iter1, lt2, lt2.begin(), lt2.end() ); iter1의 위치에 lt2의 lt2.begin ~ lt2.end 범위를 잘라 붙임
    }
    SECTION("EX_6-39"){
        lt.reverse();
        list<int>::iterator iter= lt.end();
        int i=0;
        while(iter != lt.begin()){
            --iter; ++i;
            REQUIRE(*iter == 10*(i));
        }
    }
    SECTION("EX_6-40"){
        // list.unique() 는 인접한 중복 원소를 하나만 남김
    }

    SECTION("EX_6-41"){
        list<int> lt2;
        lt2.push_back(10);
        lt2.push_back(10);
        lt2.push_back(20);
        lt2.push_back(30);
        lt2.push_back(30);
        lt2.push_back(30);
        lt2.push_back(40);
        lt2.push_back(50);
        lt2.push_back(10);

        REQUIRE(lt2.size() == 9);

        lt2.unique(Predicate2);
        REQUIRE(lt2.size()==5);

        int sumLocal = 0;
        list<int>::iterator iter;
        for(iter=lt2.begin();iter!=lt2.end();++iter){
            sumLocal +=*iter;
        }
        REQUIRE(sumLocal==150);

    }

    SECTION("EX_6-43"){
        list<int>::iterator iter;
        int i=0;
        for(iter=lt.begin();iter!=lt.end();++iter){
            REQUIRE(*iter == 10*(++i) );
        }

        lt.sort(std::greater<int>());
        i=5;
        for(iter=lt.begin();iter!=lt.end();++iter){
            REQUIRE(*iter == 10*(i--) );
        }

        lt.sort(std::less<int>());
        i=0;
        for(iter=lt.begin();iter!=lt.end();++iter){
            REQUIRE(*iter == 10*(++i) );
        }

    }

    SECTION("EX_6-44") {
        list<int> lt2;
        lt2.push_back(25);
        lt2.push_back(35);
        lt2.push_back(60);

        lt.merge(lt2);

        list<int>::iterator iter=lt.begin();
        ++iter;++iter;
        REQUIRE(*iter == 25);
        ++iter;++iter;
        REQUIRE(*iter == 35);
        iter=lt.end();
        --iter;
        REQUIRE(*iter == 60);
    }

    SECTION("EX_6-45") {
        list<int> lt2;
        lt2.push_back(25);
        lt2.push_back(35);
        lt2.push_back(60);
        //merge 전에 정렬이 안되어있으면 merge 결과도 이상해져 (예측한대로X)
        lt.sort(std::greater<int>());
        lt2.sort(std::greater<int>());
        lt.merge(lt2, std::greater<int>());

        list<int>::iterator iter=lt.begin();
        cout<< *iter<< endl;
        REQUIRE(*iter == 60);
        ++iter;++iter;++iter;
        REQUIRE(*iter == 35);
        ++iter;++iter;
        REQUIRE(*iter == 25);
    }
}

