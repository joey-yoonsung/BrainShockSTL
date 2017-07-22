//
// Created by yoonsung-mac on 22/07/2017.
//

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int StartGoogleTest(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

int main(int argc, char** argv){
    StartGoogleTest(argc, argv);
}

TEST(ex_8_76, accumulate){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    EXPECT_EQ(150, accumulate(v.begin(), v.end(), 0));
    EXPECT_EQ(250, accumulate(v.begin(), v.end(), 100));
}

TEST(ex_8_77, func_accumulate){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    EXPECT_EQ(15, accumulate(v.begin(), v.end(), 0, plus<int>()));
    EXPECT_EQ(120, accumulate(v.begin(), v.end(), 1, multiplies<int>()));
    EXPECT_EQ(0, accumulate(v.begin(), v.end(), 0, multiplies<int>()));
}

TEST(ex_8_78, inner_product){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    // TODO : 왜안대지
//    EXPECT_EQ(30, inner_product(v.begin(), v.end(), v2.begin(), v2.end()));
}
int Plus(int left, int right){
    return left+right;
}
int Minus(int left, int right){
    return left-right;
}
TEST(ex_8_79, func_inner_product){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);
    v2.push_back(2);

    // TODO : 왜 안되지 ? type 이 안맞데
//    cout << inner_product(v.begin(), v.end(), v2.begin(), 0, Plus, Minus) << endl;
//    EXPECT_EQ(140, inner_product(v.begin(), v.end(), v2.begin(), 0, plus<int>(), minus<int>()));
}

TEST(ex_8_80,  adjacent_difference){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2(5);
    vector<int>::iterator iter_end;
    iter_end = adjacent_difference(v.begin(), v.end(), v2.begin());
    for(vector<int>::iterator iter = v2.begin() ; iter != iter_end; ++iter) {
        EXPECT_EQ(10, *iter);
    }
}

TEST(ex_8_81,  func_adjacent_difference){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2(5);
    vector<int>::iterator iter_end;
    iter_end = adjacent_difference(v.begin(), v.end(), v2.begin(), plus<int>());
    for(vector<int>::iterator iter = v2.begin()+1 ; iter != iter_end; ++iter) {
        EXPECT_EQ(*(iter-1)+20, *iter);
    }
}

TEST(ex_8_82, partial_sum){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2(5);
    vector<int>::iterator iter_end;
    iter_end = partial_sum(v.begin(), v.end(), v2.begin());
    vector<int>::iterator origin_iter = v.begin()+1;
    for(vector<int>::iterator iter = v2.begin()+1 ; iter != iter_end; ++iter) {
        EXPECT_EQ(*(iter-1) + *origin_iter++, *iter);
    }
}

TEST(ex_8_83, func_partial_sum){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2(5);
    vector<int>::iterator iter_end;
    iter_end = partial_sum(v.begin(), v.end(), v2.begin(), multiplies<int>());
    vector<int>::iterator origin_iter = v.begin()+1;
    for(vector<int>::iterator iter = v2.begin()+1 ; iter != iter_end; ++iter) {
        EXPECT_EQ(*(iter-1) * *origin_iter++, *iter);
    }
}
