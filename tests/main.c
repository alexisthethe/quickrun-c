#include <gtest/gtest.h>

#include "simple.h"

TEST(SimpleAddTest, Simple)
{
    EXPECT_EQ(simple_add(1, 2), 3);
    EXPECT_EQ(simple_add(4, 0), 4);
    EXPECT_EQ(simple_add(3, -6), -3);
}

TEST(VerySimpleTest, VerySimple)
{
    EXPECT_EQ(1, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}