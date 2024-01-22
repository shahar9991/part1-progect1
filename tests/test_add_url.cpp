#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp" // Include the code to be tested

// Test case 1: Valid input with both hash functions
TEST(CalcTests, isValidInputFormat_ValidInput) {
    ASSERT_TRUE(isValidInputFormat(8, {1, 2}));
}