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

TEST(ex_8_47, next_permutation){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    int i=1;
    while(next_permutation(v.begin(), v.end())){ i++;}
    EXPECT_EQ(i, 6);
    EXPECT_EQ(v[0], 10);
    EXPECT_EQ(v[1], 20);
    EXPECT_EQ(v[2], 30);
}


class Point{
    int x,y;
public:
    explicit  Point(int _x=0, int _y=0):x(_x), y(_y){}
    int GetX() const {return x;}
    int GetY() const {return y;}
    void Print() const {cout << '('<< x<< ','<< y<< ')'<< endl;}
};
ostream& operator<<(ostream& out, const Point& arg){
    out << "(" << arg.GetX() << ", " << arg.GetY() <<")";
    return out;
}

bool Pred_leftYLessThanRight(const Point& left, const Point& right){
    return left.GetY() < right.GetY();
}
bool Pred_LessThan40(int n){
    return n< 40;
}
TEST(ex_8_49, partition){ //QuickSort 처럼
    vector<int> v;
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(60);

    vector<int>::iterator iter_sep;
    iter_sep = partition(v.begin(), v.end(), Pred_LessThan40);
    for(vector<int>::iterator iter = v.begin(); iter != iter_sep ; ++iter){
        EXPECT_LE(*iter, 40);
    }
    for(vector<int>::iterator iter = iter_sep; iter!=v.end(); ++iter){
        EXPECT_TRUE(*iter >= 40);
    }
}
TEST(ex_8_50, stable_partition){ // 상대적 순서 유지, 하지만 느림
    // TODO : 상대적 순서라는게 이해안됨
    vector<int> v;
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(60);

    vector<int>::iterator iter_sep;
    iter_sep = stable_partition(v.begin(), v.end(), Pred_LessThan40);

    for(vector<int>::iterator iter = v.begin(); iter != iter_sep ; ++iter){
        EXPECT_LE(*iter, 40);
    }
    for(vector<int>::iterator iter = iter_sep; iter!=v.end(); ++iter){
        EXPECT_TRUE(*iter >= 40);
    }
}

TEST(ex_8_51, random_shuffle){
    vector<int> v;
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(10);
    v.push_back(20);
    v.push_back(60);

    random_shuffle(v.begin(), v.end());
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter){
        cout<< *iter << "  " ;
    }
    cout <<endl;
}

TEST(ex_8_52, reverse){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    reverse(v.begin(), v.end());
    int i=5;
    for(vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter, --i){
        EXPECT_EQ(*iter, 10*i);
    }
}
TEST(ex_8_53, reverse_copy){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2(5);
    vector<int>::iterator iter_end = reverse_copy(v.begin(), v.end(), v2.begin());
    int i=5;
    for(vector<int>::iterator iter = v2.begin(); iter != iter_end; ++iter, --i){
        EXPECT_EQ(*iter, 10*i);
    }
}


TEST(ex_8_54, rotate) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int>::iterator middle = v.begin()+2;
    rotate(v.begin(), middle, v.end());

    EXPECT_EQ(*v.begin(), 30);
    EXPECT_EQ(*(v.end()-1), 20);
}
TEST(ex_8_55, rotate_copy) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    vector<int> v2(5);
    vector<int>::iterator middle = v.begin()+2;
    vector<int>::iterator iter_end = rotate_copy(v.begin(), middle, v.end(), v2.begin());


    EXPECT_EQ(*v.begin(), 10);
    EXPECT_EQ(*(v.end()-1), 50);
    EXPECT_EQ(*v2.begin(), 30);
    EXPECT_EQ(*(v2.end()-1), 20);
}