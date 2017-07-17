//
// Created by yoonsung-mac on 17/07/2017.
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

TEST(ex_8_25, copy){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2(5);

    vector<int>::iterator iter = copy(v1.begin(), v1.end(), v2.begin());
    EXPECT_TRUE(iter == v2.end());
    EXPECT_EQ(*(iter-1), 50);

    EXPECT_TRUE(equal(v1.begin(), v1.end(), v2.begin()));


    vector<int> v3(3);
//    iter = copy(v1.begin(), v1.end(), v3.begin()); // 이때 iter에 뭐가들어갈지는 알 수 없다
//    for(;iter != v3.end(); ++iter){
//        cout<< *iter << endl;
//    } // TODO : 무한히 돈다
//    cout<< *(iter-1)<< endl; //50
//    cout <<*iter  << endl;    //20, 20, 1
//    cout<< *(iter+1)<< endl; //0
//    cout<< *iter << endl;
//    EXPECT_TRUE(iter == v3.end());
//    EXPECT_EQ(*(iter-1), 30);
}

TEST(ex_8_26, copy_backward){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    vector<int> v2(10);

    vector<int>::iterator iter = copy_backward(v1.begin(), v1.end(), v2.end());
    EXPECT_TRUE(iter != v2.begin());
    EXPECT_EQ(*(iter), 10);
    EXPECT_TRUE((iter+5) == v2.end());
    EXPECT_EQ(*v2.begin(), 0);
}

TEST(ex_8_27, fill) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    fill(v1.begin(), v1.end(), 0);
    EXPECT_EQ(*v1.begin(), 0);
    EXPECT_EQ(*(v1.end() - 1), 0);

    fill_n(v1.begin(), 3, 55);
    EXPECT_EQ(*v1.begin(), 55);
    EXPECT_EQ(*(v1.begin() + 3), 0);
}
void Func(int& r){
    r+=5;
}
TEST(ex_8_28, for_each_modify){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    for_each(v1.begin(), v1.end(), Func);
    int i=1;
    for(vector<int>::iterator iter = v1.begin(); iter!=v1.end() ;++iter, ++i){
        EXPECT_EQ(*iter, 10*i + 5);
    }
}
class Accumulation{
    int total;
public:
    explicit Accumulation(int init=0):total(init){}
    void operator()(int& r){
        total += r;
        r = total;
    }
};

TEST(ex_8_29, for_each_modify) {
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    for_each(v1.begin(), v1.end(), Accumulation(0));

    EXPECT_EQ(*v1.begin(), 1);
    EXPECT_EQ(*(v1.begin()+1), 3);
    EXPECT_EQ(*(v1.begin()+2), 6);
    EXPECT_EQ(*(v1.begin()+3), 10);
    EXPECT_EQ(*(v1.begin()+4), 15);
}

class Integer{
    int data;
public:
    explicit Integer(int d=0):data(d){}
    int operator()(){
        return data++;
    }
};
TEST(ex_8_30, generate) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);

    generate(v1.begin(), v1.end(), Integer(1));
    int i=1;
    for(vector<int>::iterator iter = v1.begin(); iter != v1.end(); ++iter, ++i){
        EXPECT_EQ(*iter, i);
    }

    generate_n(v1.begin(), 3, Integer(100));
    EXPECT_EQ(*v1.begin(), 100);
    EXPECT_EQ(*(v1.begin()+1), 101);
    EXPECT_EQ(*(v1.begin()+2), 102);
    EXPECT_EQ(*(v1.begin()+3), 4);
    EXPECT_EQ(*(v1.begin()+4), 5);
}

TEST(ex_8_31, swap_iter_swap){
    int a=10, b=20;
    vector<int> v;
    v.push_back(10);
    v.push_back(30);
    v.push_back(20);
    swap(a, b);
    EXPECT_EQ(a, 20);
    EXPECT_EQ(b, 10);

    vector<int>::iterator p = v.begin();
    vector<int>::iterator q = v.begin()+2;
    iter_swap(p, q);
    EXPECT_EQ(*p, 20);
    EXPECT_EQ(*q, 10);
}

TEST(ex_8_32, merge){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(30);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(80);

    vector<int> v2;
    v2.push_back(20);
    v2.push_back(40);
    v2.push_back(70);
    v2.push_back(90);
    v2.push_back(100);

    vector<int> v3(10);
    vector<int>::iterator iter_end;
    iter_end = merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    EXPECT_TRUE(iter_end==v3.end());
    int i=1;
    for(vector<int>::iterator iter = v3.begin(); iter!=v3.end(); ++iter, ++i) {
        EXPECT_EQ(*iter, 10 * i);
    }
}

TEST(ex_8_34, replace){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(30);
    v1.push_back(50);

    replace(v1.begin(), v1.end(), 30, 0);
    EXPECT_EQ(*(v1.begin()+2), 0);
    EXPECT_EQ(*(v1.begin()+4), 0);
    EXPECT_EQ(*(v1.begin()+5), 0);
}

bool Pred_UpperEqual30AndLessEqual50(int n){
    return 30<= n && n <= 50;
}


TEST(ex_8_35, replace_if) {
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    v1.push_back(60);
    v1.push_back(70);
    v1.push_back(80);

    replace_if(v1.begin(), v1.end(), Pred_UpperEqual30AndLessEqual50, 0);
    EXPECT_EQ(*(v1.begin()+2), 0);
    EXPECT_EQ(*(v1.begin()+3), 0);
    EXPECT_EQ(*(v1.begin()+4), 0);
}

TEST(ex_8_36, replace_copy_if){

    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(30);
    v1.push_back(50);

    vector<int> v2(6);
    vector<int> v3(6);

    vector<int>::iterator iter_end;
    iter_end = replace_copy(v1.begin(), v1.end(), v2.begin(), 30, 0);
    iter_end = replace_copy_if(v1.begin(), v1.end(), v3.begin(), Pred_UpperEqual30AndLessEqual50, 0);
    EXPECT_EQ(*(v2.begin()+2), 0);
    EXPECT_EQ(*(v2.begin()+4), 0);
    for(vector<int>::iterator iter = v3.begin()+2; iter !=v3.end() ; ++iter){
        EXPECT_EQ(*iter, 0);
    }
}

TEST(ex_8_37, swap_ranges){
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    vector<int> v2;
    v2.push_back(11);
    v2.push_back(22);
    v2.push_back(33);
    v2.push_back(44);
    v2.push_back(55);

    swap_ranges(v1.begin(), v1.end(), v2.begin());

    int i=1;
    for(vector<int>::iterator iter = v2.begin() ; iter !=v2.end(); ++iter, ++i){
        EXPECT_EQ(*iter, 10*i);
    }
}