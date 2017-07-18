//
// Created by yoonsung-mac on 18/07/2017.
//

#include <gtest/gtest.h>
#include <vector>
#include <algorithm>
using namespace std;

int StartGoogleTest(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

int main(int argc, char** argv){
    StartGoogleTest(argc, argv);
}

TEST(ex_8_41, remove){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int>::iterator iter_end;
    iter_end = remove(v1.begin(), v1.end(), 30);
    EXPECT_EQ(*iter_end, 50);
    vector<int>::iterator iter_find = find(v1.begin(), v1.end(), 30);
    EXPECT_TRUE(iter_find == v1.end());
    EXPECT_EQ(v1.size(), 5);
}

TEST(ex_8_42, erase){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    v1.erase(v1.begin(), v1.begin()+2); //[ , ) 조건
    EXPECT_EQ(v1.size(), 3);
    EXPECT_EQ(*v1.begin(), 30);
    EXPECT_EQ(*(v1.end()-1), 50);

}
bool Pred_GreaterEqual30AndLessEqual40(int n){
    return 30 <= n  && n <= 40;
}
TEST(ex_8_43, remove_if){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int>::iterator iter_end;
    iter_end= remove_if(v1.begin(), v1.end(), Pred_GreaterEqual30AndLessEqual40);
    EXPECT_EQ(*(iter_end-1), 50);
    EXPECT_EQ(v1.size(), 5);
}

TEST(ex_8_44, remove_copy){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    vector<int> v2(5);

    vector<int>::iterator iter_end;
    iter_end = remove_copy(v1.begin(), v1.end(), v2.begin(), 30); //end는 v2의 iter_end
    EXPECT_EQ(iter_end-v2.begin(), 4);
    EXPECT_EQ(*(v1.end()-1), 50);
    EXPECT_EQ(*(v2.end()-1), 0);
}

TEST(ex_8_45, unique){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(50);

    vector<int>::iterator iter_end;
    iter_end = unique(v1.begin(), v1.end());
    EXPECT_EQ(iter_end-v1.begin(), 6);

}
bool Pred_SubLess10(int left, int right){
    return abs(right-left) < 10;
}
TEST(ex_8_46, unique_if){
    vector<int> v;
    v.push_back(10);
    v.push_back(11);
    v.push_back(30);
    v.push_back(32);
    v.push_back(40);
    v.push_back(50);
    vector<int>::iterator iter_end;
    iter_end = unique(v.begin(), v.end(), Pred_SubLess10);
    EXPECT_EQ(*v.begin(), 10);
    EXPECT_EQ(*(v.begin()+1), 30);
    EXPECT_EQ(*(v.begin()+2), 40);
    EXPECT_EQ(iter_end-v.begin(), 4);
}

