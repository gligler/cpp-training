#include <gtest/gtest.h>

#include "hello.h"

TEST(hello, test_case1)
{
    EXPECT_EQ(666, test());
}

TEST(hello,test_case2)
{
    EXPECT_EQ(77, add(7,70));
}