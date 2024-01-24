//
// Created by user on 24/01/2024.
//
#include <gtest/gtest.h>
#include "../src/version2/ArgsHandler1.cpp"


TEST(CalcTests, PrintRealArgs_Duplicate) {

ArgsHandler argsHandler;

// Test with duplicate values
std::vector<int> input = {1, 2, 1, 1, 2, 2, 2};
std::vector<int> expected = {1, 2};

EXPECT_EQ(argsHandler.PrintRealArgs(8, input), expected);
}
TEST(CalcTests,  PrintRealArgs_NoDuplicate) {

ArgsHandler argsHandler;
// Test with no duplicate values
std::vector<int> input = {1,2};
std::vector<int> expected = {1, 2};

EXPECT_EQ(argsHandler.PrintRealArgs(8, input), expected);

}
TEST(CalcTests,  PrintRealArgs_None) {

ArgsHandler argsHandler;

// Test with an empty vector
std::vector<int> input;
std::vector<int> expected;

EXPECT_EQ(argsHandler.PrintRealArgs(8, input), expected);


}