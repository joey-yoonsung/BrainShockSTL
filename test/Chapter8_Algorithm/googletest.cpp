//
// Created by yoonsung-mac on 15/07/2017.
//

#include <gtest/gtest.h>

// TODO : Compile 속도는 google 이 확 느껴지게 빠름 (library linking 이어서 그런가?)
int StartGoogleTest(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

int main(int argc, char** argv){
    StartGoogleTest(argc, argv);
}

TEST(sam__Test, sam__Test_sam_Test){
    EXPECT_EQ(1, 0);
    EXPECT_TRUE(1 ==2);

}

TEST(hi__Test, hi__Test_testName_Test){ //naming에 제한이 있네!


}
