#include <gtest/gtest.h>
#include "../src/bloom_filter.cpp" // here we include the code to be tested
TEST(bloom_filter, basic_test) {
EXPECT_EQ(input("a"),false);
}
