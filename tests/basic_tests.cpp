#include <gtest/gtest.h>
#include "../src/edit_string.cpp" // here we include the code to be tested
TEST(bloom_filter, basic_test) {
EXPECT_GT(edit_string("8 1 2"),1);
}
