//
// Created by user on 24/01/2024.
//
//
// Created by user on 24/01/2024.
//
#include <gtest/gtest.h>
#include "../src/version2/ArgsHandler1.cpp"
// test_ReadSizeAndArgs.cpp

TEST(ArgsHandlerTest, ReadSizeAndArgs) {
ArgsHandler argsHandler;

// Simulate user input using a stringstream
std::istringstream input("3 1 2");

int size;
std::vector<int> args;

argsHandler.readSizeAndArgs(size, args, input);

// Check if the function correctly reads size and arguments
EXPECT_EQ(size, 3);
EXPECT_EQ(args.size(), 2);
EXPECT_EQ(args[0], 1);
EXPECT_EQ(args[1], 2);
}
TEST(ArgsHandlerTest, ReadSizeAndArgs_OneNumber) {
ArgsHandler argsHandler;

// Simulate user input with only one number using a stringstream
std::istringstream input("4");

int size;
std::vector<int> args;

argsHandler.readSizeAndArgs(size, args, input);

// Check if the function correctly reads size and arguments
// In this case, the size should be 4, and args should be empty
EXPECT_EQ(size, 4);
EXPECT_TRUE(args.empty());
}

TEST(ArgsHandlerTest, ReadSizeAndArgs_OneNumber) {
ArgsHandler argsHandler;

// Simulate user input with only one number using a stringstream
std::istringstream input("4 3 3");

int size;
std::vector<int> args;

argsHandler.readSizeAndArgs(size, args, input);

// Check if the function correctly reads size and arguments
// In this case, the size should be 4, and args should be empty
EXPECT_EQ(size, 4);
EXPECT_TRUE(args.empty());
}
TEST(ArgsHandlerTest, ReadSizeAndArgs_NoInput) {
ArgsHandler argsHandler;

// Simulate user entering nothing using an empty stringstream
std::istringstream input("");

int size;
std::vector<int> args;

argsHandler.readSizeAndArgs(size, args, input);

// Check if the function handles no input gracefully
// In this case, both size and args should be unchanged
EXPECT_EQ(size, 0);
EXPECT_TRUE(args.empty());
}
// Add more test cases as needed

//
//TEST(CalcTests, ReadSize_WrongSize) {
//
//ArgsHandler argsHandler;
//
//// Test with duplicate values
//std::vector<int> input = {1, 2, 1, 1, 2, 2, 2};
//std::vector<int> expected = {1, 2};
//
//EXPECT_EQ(argsHandler.PrintRealArgs(8, input), expected);
//}
//TEST(CalcTests,  ReadSize_RightSize) {
//
//ArgsHandler argsHandler;
//// Test with no duplicate values
//std::vector<int> input = {1,2};
//std::vector<int> expected = {1, 2};
//
//EXPECT_EQ(argsHandler.PrintRealArgs(8, input), expected);
//
//}
//TEST(CalcTests,  ReadArgs_RightArgs) {
//
//ArgsHandler argsHandler;
//// Test with no duplicate values
//std::vector<int> input = {1,2};
//std::vector<int> expected = {1, 2};
//
//EXPECT_EQ(argsHandler.PrintRealArgs(8, input), expected);
//
//}
//TEST(CalcTests,  ReadArgs_WrongArgs) {
//
//ArgsHandler argsHandler;
//// Test with no duplicate values
//std::vector<int> input = {1,2};
//std::vector<int> expected = {1, 2};
//
//EXPECT_EQ(argsHandler.PrintRealArgs(8, input), expected);
//
//}