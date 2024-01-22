#include <gtest/gtest.h>
#include "../src/FalsePositive.h" // here we include the code to be tested
#include "../src/false_positive.cpp"
// Test case 1: Valid input with both hash functions
// Test case for FalsePositiveDictionary



class FalsePositiveDictionaryTest : public ::testing::Test{
protected:
    // Declare an instance of FalsePositiveDictionary for testing
    FalsePositiveDictionary dictionary;
};


TEST(AddTest,TruePositive) {

// Test adding a new URL
EXPECT_EQ(dictionary.addURL("http://example.com", "Example Data"),"added");



// Test adding an existing URL
EXPECT_EQ(dictionary.addURL("http://example.com", "Example Data"),"exist");

};

TEST(SearchTest, TruePositive){
// Test searching for a non-existent URL
EXPECT_FALSE(dictionary.searchURL("http://nonexistent.com"));

// Test searching for an existing URL
dictionary.addURL("http://existing.com", "Existing Data");
EXPECT_TRUE(dictionary.searchURL("http://existing.com"));
};