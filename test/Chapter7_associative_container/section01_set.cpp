//
// Created by yoonsung-mac on 10/07/2017.
//
#define CATCH_CONFIG_MAIN
#include <catch.hpp>

#include <iostream>
using namespace std;

class temp{
    int val;
public:
    temp(int a){
        val=a;
    }
    int getVal(){return val;}

};

temp& OPER(temp& arg_l, temp& arg_r){
    return arg_l.getVal() < arg_r.getVal() ? arg_l : arg_r;
}

TEST_CASE("CHAPTER7", "[stl][associative][container][set]") {

    set<int> s;

    s.insert(50);
    s.insert(30);
    s.insert(80);
    s.insert(40);
    s.insert(10);
    s.insert(70);
    s.insert(90);
    s.insert(20);
    s.insert(60);

    SECTION("EX_7-1"){
        set<int>::iterator iter;
        int i=0;
        for(iter=s.begin(); iter!=s.end() ; ++iter, ++i){
            REQUIRE(*iter == 10*(i+1));
        }
    }

    SECTION("EX_7-2"){

        pair<set<int>::iterator, bool> pr;

        pr = s.insert(100); //삽입한 위치의 노드 포인터
        REQUIRE(*pr.first == 100);
        REQUIRE(pr.second );

        set<int>::iterator iter = pr.first;
        REQUIRE(++iter == s.end());

        pr = s.insert(10); //삽입 실패한 위치의 노드 포인터
        REQUIRE(*pr.first == 10);
        REQUIRE(!pr.second);

        int i=0;
        for(set<int>::iterator iter = pr.first; iter!=s.end() ; ++iter, ++i){
            REQUIRE(*iter == 10*(i+1));
        }

    }

    SECTION("EX_7-3"){
        pair<set<int>::iterator, bool> pr;

        pr = s.insert(100);

        set<int>::iterator iter;
        int i=0;
        for(set<int>::iterator iter = s.begin() ; iter!=s.end() ; ++iter, ++i){
            REQUIRE(*iter == 10*(i+1));
        }

        s.insert(pr.first, 85); // 100노드부터 검색 시작 후 삽입
        iter = pr.first;
        --iter;--iter;
        REQUIRE(*iter == 85);

    }

    SECTION("EX_7-4"){
        set<int, std::greater<int> > st;

        st.insert(50);
        st.insert(30);
        st.insert(80);
        st.insert(40);
        st.insert(10);
        st.insert(70);
        st.insert(90);
        st.insert(20);
        st.insert(60);


        set<int>::iterator iter;
        int i=0;
        for(set<int>::iterator iter = st.begin() ; iter!=st.end() ; ++iter, ++i){
            REQUIRE(*iter == 10*(10-(i+1)));
        }
    }

    SECTION("EX_7-5"){
        set<int, std::less<int> > s_less;
        set<int, std::greater<int> > s_greater;

        s_less.insert(50);
        s_less.insert(80);
        s_less.insert(40);

        s_greater.insert(50);
        s_greater.insert(80);
        s_greater.insert(40);

        set<int, less<int>>::key_compare l_cmp = s_less.key_comp();
        REQUIRE( l_cmp(10, 20) ); //10<20

        set<int, greater<int>>::key_compare g_cmp = s_greater.key_comp();
        REQUIRE( !g_cmp(10, 20) ); //10>20

        REQUIRE( strcmp(typeid(s_less.key_comp()).name(), "struct std::less<int>"));
        REQUIRE( strcmp(typeid(s_greater.key_comp()).name(), "struct std::greater<int>"));
        REQUIRE( strcmp(typeid(s_less.value_comp()).name(), "struct std::less<int>"));
        REQUIRE( strcmp(typeid(s_greater.value_comp()).name(), "struct std::greater<int>"));

    }

    SECTION("EX_7-6"){
        REQUIRE( s.count(50) == 1 );
        REQUIRE( s.count(100) == 0);
    }

    SECTION("EX_7-7"){
        set<int>::iterator iter;
        iter = s.find(30);

        REQUIRE(*iter == 30);

        iter = s.find(100);

        REQUIRE(iter == s.end());
    }

    SECTION("EX_7-8"){
        set<int, less<int>> s_less;
        REQUIRE_FALSE((!s_less.key_comp()(30, 50)&&!s_less.key_comp()(50, 30)));
        REQUIRE((!s_less.key_comp()(30, 30)&&!s_less.key_comp()(30, 30)));
    }
    SECTION("EX_7-9"){

        set<int>::iterator iter;
        set<int>::iterator iter_lower;
        set<int>::iterator iter_upper;

        iter_lower = s.lower_bound(30);
        iter_upper = s.upper_bound(30);
        REQUIRE(*iter_lower == 30);
        REQUIRE(*iter_upper == 40);

        iter_lower = s.lower_bound(55);
        iter_upper = s.upper_bound(55);
        REQUIRE(iter_lower == iter_upper);
        REQUIRE(*iter_lower == 60);
        REQUIRE(*iter_upper == 60);

        iter_lower = s.lower_bound(95);
        iter_upper = s.upper_bound(95);
        REQUIRE(iter_lower == iter_upper);
        REQUIRE(iter_lower == s.end());
        REQUIRE(*iter_upper == 0 );

//        SECTION("IF Class is Class"){
//            set<temp, OPER> st;
//            temp* tm=new temp(1);
//            st.insert(tm);
//            st.insert(new temp(2));
//            st.insert(new temp(5));
//            st.insert(new temp(7));
//
//
//
//        }
    }

    SECTION("EX_7-10"){
        pair<set<int>::iterator, set<int>::iterator> iter_pair;

        iter_pair = s.equal_range(30);
        REQUIRE(*iter_pair.first == 30);
        REQUIRE(*iter_pair.second == 40);

        iter_pair = s.equal_range(55);
        REQUIRE(iter_pair.first == iter_pair.second);
        REQUIRE(*iter_pair.first == 60 );
        REQUIRE(*iter_pair.second == 60 );
        REQUIRE_FALSE(iter_pair.first == s.end());
        // TODO : 왜 iter_pair 는 다음을 가리키지? lower,upper bound 랑 find 는 end iterator 를 받았는데.


    }

}
