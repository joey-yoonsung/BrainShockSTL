//
// Created by yoonsung-mac on 22/07/2017.
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

TEST(ex_8_66, binary_search){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    EXPECT_TRUE(binary_search(v.begin(), v.end(), 20));
    EXPECT_FALSE(binary_search(v.begin(), v.end(), 60));
}

bool Pred_SubGreaterThan3(int left, int right){
    return 3< right-left;
}
TEST(ex_8_67, binary_search_if){
    /* TODO : Binary Search 를 이렇게 쓸 일이 있나..? 이렇게 차가 3이하인 예보다는 객체로 객체의 멤버가지고 비교할때 쓸것 같은데
    */
    vector<int> v;
    v.push_back(40);
    v.push_back(46);
    v.push_back(12);
    v.push_back(80);
    v.push_back(10);
    v.push_back(47);
    v.push_back(30);
    v.push_back(55);
    v.push_back(90);
    v.push_back(53);

    
    sort(v.begin(), v.end(), Pred_SubGreaterThan3);
    EXPECT_TRUE(binary_search(v.begin(), v.end(), 32, Pred_SubGreaterThan3)); // 찾는 조건이 (!Pred(left, right)&& !Pred(right, left)) 
    EXPECT_FALSE(binary_search(v.begin(), v.end(), 35, Pred_SubGreaterThan3));
}

TEST(ex_8_69, include){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2;
    v2.push_back(10);
    v2.push_back(20);
    v2.push_back(40);
    vector<int> v3;
    v3.push_back(10);
    v3.push_back(20);
    v3.push_back(60);

    EXPECT_TRUE(includes(v.begin(), v.end(), v2.begin(), v2.end()));
    EXPECT_FALSE(includes(v.begin(), v.end(), v3.begin(), v3.end()));
    EXPECT_TRUE(includes(v.begin(), v.end(), v3.begin(), v3.end()-1));

}
// TODO : 70~72 는 앞서 동일한 내용을 해서 생략

TEST(ex_8_73, inplace_merge){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    v.push_back(20);
    v.push_back(30);
    v.push_back(60);

    inplace_merge(v.begin(), v.begin()+5, v.end());
    for(vector<int>::iterator iter = v.begin()+1; iter != v.end();++iter){
        EXPECT_LE(*(iter-1), *iter);
    }

}

TEST(ex_8_74, set_union) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2;
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(60);
    vector<int> v3(10);
    vector<int>::iterator iter_end;

    iter_end = set_union(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
    int i=1;
    for(vector<int>::iterator iter = v3.begin(); iter != iter_end ; ++iter, ++i){
        EXPECT_EQ(*iter , i*10);
    }
}

TEST(ex_8_75, set_intersection) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2;
    v2.push_back(20);
    v2.push_back(30);
    v2.push_back(60);
    vector<int> v3(10);
    vector<int>::iterator iter_end;

    iter_end = set_intersection(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin());
    int i=2;
    for(vector<int>::iterator iter = v3.begin(); iter != iter_end ; ++iter, ++i){
        EXPECT_EQ(*iter , i*10);
    }
    iter_end = set_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin()); //v1-v2 된 차집합
    EXPECT_EQ(*(iter_end-1), 50);
    EXPECT_EQ(*(iter_end-2), 40);
    EXPECT_EQ(*(iter_end-3), 10);

    iter_end = set_symmetric_difference(v.begin(), v.end(), v2.begin(), v2.end(), v3.begin()); //(v1 U v2) - (v1 n V2) 된 차집합
    EXPECT_EQ(*(iter_end-1), 60);
    EXPECT_EQ(*(iter_end-2), 50);
    EXPECT_EQ(*(iter_end-3), 40);
    EXPECT_EQ(*(iter_end-4), 10);

}

