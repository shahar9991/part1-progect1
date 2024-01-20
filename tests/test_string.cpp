
#include <gtest/gtest.h>
#include "../src/string.cpp" // Include the code to be tested

// Test case 1: Valid input with both hash functions
TEST(CalcTests, isValidInputFormat_ValidInput) {
    ASSERT_TRUE(isValidInputFormat(8, {1, 2}));
}

// Valid input with only hash function 1
TEST(CalcTests, isValidInputFormat_ValidInput_HashFunction1) {
    ASSERT_TRUE(isValidInputFormat(8, {1}));
}

// Valid input with only hash function 2
TEST(CalcTests, isValidInputFormat_ValidInput_HashFunction2) {
    ASSERT_TRUE(isValidInputFormat(8, {2}));
}

// Valid input with hash functions 1 and 2
TEST(CalcTests, isValidInputFormat_ValidInput_HashFunctions1And2) {
    ASSERT_TRUE(isValidInputFormat(8, {2, 1}));
}

// Valid input with hash functions 2 and 1
TEST(CalcTests, isValidInputFormat_ValidInput_HashFunctions2And1) {
    ASSERT_TRUE(isValidInputFormat(8, {2, 2,2,2,2,2,2}));
}

// Invalid input with hash function 1 and 5 doesn't exist
TEST(CalcTests, isValidInputFormat_InvalidInput_HashFunction1) {
    ASSERT_FALSE(isValidInputFormat(8, {1, 5}));
}

// Invalid input with hash functions does not exist.
TEST(CalcTests, isValidInputFormat_InvalidInput_HashFunction11) {
    ASSERT_FALSE(isValidInputFormat(8, {5, 5}));
}
