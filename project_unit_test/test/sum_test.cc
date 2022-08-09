#include "gtest/gtest.h"
#include "sum.h"

TEST(sum_worker_init_false__Test, sum_worker_test)
{
    sum_worker sum_worker_tester;
    
    EXPECT_FALSE(sum_worker_tester.run());
    EXPECT_EQ(0, sum_worker_tester.getValue());
}

TEST(sum_worker_sum_test, sum_worker_test)
{
    sum_worker sum_worker_tester;
    
    sum_worker_tester.setLeft(5);
    sum_worker_tester.setRight(3);
    EXPECT_TRUE(sum_worker_tester.run());
    EXPECT_EQ(8, sum_worker_tester.getValue());
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}