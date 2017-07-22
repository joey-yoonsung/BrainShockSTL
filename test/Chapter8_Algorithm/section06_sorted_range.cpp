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

