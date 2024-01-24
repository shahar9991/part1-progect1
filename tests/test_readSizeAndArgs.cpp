
#include <gtest/gtest.h>
#include "ArgsHandler.cpp"


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
// Test case for valid input
TEST(test_ReadSizeAndArgs, ReadSizeAndArgs_ValidInput) {
    ArgsHandler argsHandler;
    int size;
    std::vector<int> args;

    // Set up input stream with valid input
    std::istringstream input("3 1 2");

    // Redirect cin to the input stream
    std::streambuf* originalCin = std::cin.rdbuf(input.rdbuf());

    argsHandler.readSizeAndArgs(size, args);

    // Restore cin
    std::cin.rdbuf(originalCin);

    // Verify that size and args are correctly set
    ASSERT_EQ(size, 3);
    ASSERT_EQ(args.size(), 2);
    ASSERT_EQ(args[0], 1);
    ASSERT_EQ(args[1], 2);

    // Verify that the condition "if args is not empty" is true
    ASSERT_TRUE(!args.empty());
}
