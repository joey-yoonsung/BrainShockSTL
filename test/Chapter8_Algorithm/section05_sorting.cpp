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

TEST(ex_8_56, make_heap) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    make_heap(v.begin(), v.end());
    for(vector<int>::iterator iter = v.begin()+1 ; iter!=v.end() ; ++iter){
        EXPECT_LE(*iter, *v.begin());
    }
}
TEST(ex_8_57, push_heap) {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    make_heap(v.begin(), v.end());
    for(vector<int>::iterator iter = v.begin()+1 ; iter!=v.end() ; ++iter){
        EXPECT_LE(*iter, *v.begin());
    }

    v.push_back(35);
    EXPECT_EQ(*(v.end()-1), 35);
    push_heap(v.begin(), v.end());
    EXPECT_EQ(*(v.end()-1),30);
    EXPECT_EQ(*(v.begin()+2), 35);
}

TEST(ex_8_58, pop_heap){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    make_heap(v.begin(), v.end());
    for(vector<int>::iterator iter = v.begin()+1 ; iter!=v.end() ; ++iter){
        EXPECT_LE(*iter, *v.begin());
    }

    pop_heap(v.begin(), v.end());
    EXPECT_EQ(*(v.end()-1), 60);
    EXPECT_EQ(*(v.begin()), 50);
}

TEST(ex_8_59, sort_heap){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    make_heap(v.begin(), v.end());
    for(vector<int>::iterator iter = v.begin()+1 ; iter!=v.end() ; ++iter){
        EXPECT_LE(*iter, *v.begin());
    }

    sort_heap(v.begin(), v.end());
    EXPECT_EQ(*(v.end()-1), 60);
    EXPECT_EQ(*(v.begin()), 10);
}

TEST(ex_8_60, heap_if){
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    make_heap(v.begin(), v.end(), greater<int>());
    for(vector<int>::iterator iter = v.begin() ; iter!=v.end() ; ++iter){
        EXPECT_GE(*iter, *v.begin());
    }

    v.push_back(35);
    push_heap(v.begin(), v.end(), greater<int>());
    for(vector<int>::iterator iter = v.begin() ;iter!=v.end() ;++iter){
        cout << *iter << "  ";
    }
    cout << endl;
    EXPECT_EQ(*(v.begin()+2), 35); //TODO : push_heap 이 적용이 안되는데?

    sort_heap(v.begin(), v.end(), greater<int>());
    EXPECT_EQ(*(v.end()-1), 10);
    EXPECT_EQ(*(v.begin()), 60);
    EXPECT_EQ(*(v.begin()+3), 35);
}


TEST(ex_8_61, nth_element) {
    vector<int> v;
    for(int i=0; i< 100; ++i)
        v.push_back(rand()%100);

    nth_element(v.begin(), v.begin()+20, v.end());
    for(vector<int>::iterator iter = v.begin(); iter != v.begin()+20; ++iter){
        for(vector<int>::iterator post_iter=v.begin()+20 ; post_iter != v.end() ; ++post_iter){
            EXPECT_LE(*iter, *post_iter);
        }
    }
}

TEST(ex_8_62, sort){
    vector<int> v;
    for(int i=0; i< 100; ++i)
        v.push_back(rand()%100);

    sort(v.begin(), v.end()); //less
    for(vector<int>::iterator iter = v.begin()+1; iter != v.end(); ++iter){
        EXPECT_LE(*(iter-1), *iter);
    }
    sort(v.begin(), v.end(), greater<int>()); //less
    for(vector<int>::iterator iter = v.begin()+1; iter != v.end(); ++iter){
        EXPECT_GE(*(iter-1), *iter);
    }
}

TEST(ex_8_64, sort){
    vector<int> v;
    for(int i=0; i< 100; ++i)
        v.push_back(rand()%100);

    partial_sort(v.begin(), v.begin()+20,  v.end()); //less
    for(vector<int>::iterator iter = v.begin()+1; iter != v.begin()+20; ++iter){
        EXPECT_LE(*(iter-1), *iter);
    }
    for(vector<int>::iterator iter = v.begin(); iter != v.begin()+20; ++iter){
        for(vector<int>::iterator post_iter=v.begin()+20 ; post_iter != v.end() ; ++post_iter){
            EXPECT_LE(*iter, *post_iter);
        }
    }
}

