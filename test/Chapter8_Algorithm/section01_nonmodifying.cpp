//
// Created by yoonsung_mac on 15/07/2017.
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

TEST(ex_8_1_2, find){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    v.push_back(40);
    v.push_back(40);
    v.push_back(50);
    vector<int>::iterator iter = adjacent_find(v.begin(), v.end());
    EXPECT_TRUE(iter != v.end());
    EXPECT_EQ(*iter, 30);
    ++iter;
    EXPECT_EQ(*iter, 30);
    v.erase(iter);
    v.erase(++iter);
    iter = adjacent_find(v.begin(), v.end());
    EXPECT_TRUE(iter == v.end());

    iter = adjacent_find(v.begin(), ++v.begin());
    EXPECT_TRUE(iter != v.end());
    EXPECT_TRUE( iter == ++v.begin());
}
bool Pred_subTen(int a, int b){
    return abs(b-a) > 10; //인접 원소의 차의 절대값이 10보다 크면 인접하다 판단
}
TEST(EX_8_3, find_if){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(50);
    v.push_back(90);

    vector<int>::iterator iter = adjacent_find(v.begin(), v.end(), Pred_subTen);
    EXPECT_TRUE(*iter++ == 30);
    EXPECT_TRUE(*iter++ == 50);
    EXPECT_TRUE(*iter == 90);
}

TEST(EX_8_4, count){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(30);
    v.push_back(50);

    EXPECT_EQ(2, count(v.begin(), v.end(), 30));
}

bool Pred_GreaterThan25(int n){
    return 25 < n;
}
TEST(EX_8_5, count_if){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    EXPECT_EQ(3, count_if(v.begin(), v.end(), Pred_GreaterThan25));
}

TEST(EX_8_6, equal){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    EXPECT_TRUE(equal(v1.begin(), v1.end(), v2.begin()));
}

bool Pred_SubLess5(int left, int right){
    return abs(right-left) < 5;
}
TEST(EX_8_7, equal_if){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(21);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(34);

    EXPECT_TRUE(equal(v1.begin(), v1.end(), v2.begin(), Pred_SubLess5));
}

bool Pred_GreaterThan35(int n){
    return 35<n;
}
TEST(EX_8_8, find_and_find_if){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    vector<int>::iterator iter = find(v.begin(), v.end(), 20);
    EXPECT_EQ(20, *iter);
    iter = find_if(v.begin(), v.end(), Pred_GreaterThan35);
    EXPECT_EQ(40, *iter);

    iter = find(v.begin(), v.end(), 100);
    EXPECT_EQ(iter, v.end()); // TODO : 못찾으면 end
}

TEST(ex_8_9, find_end) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30); //pattern 1
    v1.push_back(40); //pattern 1
    v1.push_back(50); //pattern 1
    v1.push_back(60);
    v1.push_back(70);
    v1.push_back(30); //pattern 2
    v1.push_back(40); //pattern 2
    v1.push_back(50); //pattern 2


    vector<int> v2;
    v2.push_back(30);
    v2.push_back(40);
    v2.push_back(50);

    vector<int>::iterator iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
    EXPECT_TRUE(iter != v1.end());
    EXPECT_EQ(*iter, 30);
    EXPECT_EQ(*(iter - 1), 70);
    EXPECT_EQ(*(iter + 1), 40);
    EXPECT_EQ((iter + 3), v1.end());

    v2.clear();
    v2.push_back(10);
    v2.push_back(30);
    iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end());
    EXPECT_TRUE(iter == v1.end());
}

bool Pred_LeftLessEqualRight(int left, int right){
    return left <= right;
}
TEST(ex_8_10, find_end_if) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(15);
    v1.push_back(20);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(10);
    v1.push_back(11);
    v1.push_back(12);
    v1.push_back(80);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(15);
    v2.push_back(25);

    vector<int>::iterator iter = find_end(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred_LeftLessEqualRight);
    EXPECT_TRUE(iter !=  v1.end());
    EXPECT_EQ(*iter, 10);
    EXPECT_EQ(*(iter-1), 60);
    EXPECT_EQ(*(iter+1), 11);
}

TEST(ex_8_11, find_first_of) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    v2.push_back(40);
    v2.push_back(80);
    v2.push_back(20);
    //v2에 있는 것 중에 v1에 처음으로 발견 되는 위치 iterator
    vector<int>::iterator iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end());
    EXPECT_TRUE(iter != v1.end());
    EXPECT_EQ(*iter, 20);

}
bool Pred_LeftGreaterThanRight(int left, int right){
    return left>right;
}
TEST(ex_8_12, find_first_of_if) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2;
    v2.push_back(40);
    v2.push_back(80);
    v2.push_back(20);
    //v2에 있는 것 중에 v1에 처음으로 발견 되는 위치 iterator
    vector<int>::iterator iter = find_first_of(v1.begin(), v1.end(), v2.begin(), v2.end(), Pred_LeftGreaterThanRight);
    EXPECT_TRUE(iter != v1.end());
    EXPECT_EQ(*iter, 30);
}

void Print(int n){
    cout << n << " ";
}
TEST(ex_8_13, for_each) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for_each(v.begin(), v.begin()+2, Print);
    cout<< endl;
    for_each(v.begin(), v.begin()+4, Print);
    cout<< endl;
    for_each(v.begin(), v.end(), Print);
    cout<< endl;
}

class PrintFunctor{
    char fmt;
public:
    explicit PrintFunctor(char c= ' '):fmt(c){}
    void operator()(int n) const{
        cout << n << fmt;
    }
};

TEST(ex_8_14, for_each_Functor) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    for_each(v.begin(), v.begin()+2, PrintFunctor());
    cout<< endl;
    for_each(v.begin(), v.begin()+4, PrintFunctor(','));
    cout<< endl;
    for_each(v.begin(), v.end(), PrintFunctor('\n'));
    cout<< endl;
}


TEST(ex_8_15, lexicographical_compare) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(50);

    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(30);

    EXPECT_TRUE(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end()));
    EXPECT_TRUE(!lexicographical_compare(v1.begin(), v1.end(), v3.begin(), v3.end()));
}

template <typename T>
struct Equal{
    bool operator()(const T& left, const T& right)const{
        return left==right;
    }
};

TEST(ex_8_16, lexicographical_compare_if) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(25);
    v2.push_back(30);

    EXPECT_TRUE(lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), less<int>()));
    EXPECT_TRUE(!lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), greater<int>()));
    EXPECT_TRUE(!lexicographical_compare(v1.begin(), v1.end(), v2.begin(), v2.end(), Equal<int>()));
    // TODO : Equal 은 어떻게 되지? 사전편집순이 정확히 뭐야??
}

