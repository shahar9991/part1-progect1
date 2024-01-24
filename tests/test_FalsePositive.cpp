// false_positive_test.cpp
#include <gtest/gtest.h>
#include "../src/version2/FalsePositive.cpp"

TEST(FalsePositiveDictionaryTest, AddSingleUrl) {
    FalsePositiveDictionary dictionary;

    // Test adding a single URL to the set
    dictionary.AddUrlToDict("http://example.com");
    EXPECT_TRUE(dictionary.SearchUrlInDict("http://example.com"));
}

TEST(FalsePositiveDictionaryTest, SearchNonexistentUrl) {
    FalsePositiveDictionary dictionary;

    // Test searching for a non-existing URL
    EXPECT_FALSE(dictionary.SearchUrlInDict("http://nonexistent.com"));
}

TEST(FalsePositiveDictionaryTest, AddAndSearchMultipleUrls) {
    FalsePositiveDictionary dictionary;

    // Test adding multiple URLs and searching for them
    dictionary.AddUrlToDict("http://site1.com");
    dictionary.AddUrlToDict("http://site2.com");
    dictionary.AddUrlToDict("http://site3.com");

    EXPECT_TRUE(dictionary.SearchUrlInDict("http://site1.com"));
    EXPECT_TRUE(dictionary.SearchUrlInDict("http://site2.com"));
    EXPECT_TRUE(dictionary.SearchUrlInDict("http://site3.com"));
}

TEST(FalsePositiveDictionaryTest, SearchNonexistentUrlAfterUpdate) {
    FalsePositiveDictionary dictionary;

    // Test searching for a non-existing URL in the updated set
    dictionary.AddUrlToDict("http://site1.com");
    dictionary.AddUrlToDict("http://site2.com");

    EXPECT_FALSE(dictionary.SearchUrlInDict("http://newsite.com"));
}

TEST(FalsePositiveDictionaryTest, AddEmptyUrl) {
    FalsePositiveDictionary dictionary;

    // Test adding an empty URL
    dictionary.AddUrlToDict("");
    EXPECT_TRUE(dictionary.SearchUrlInDict(""));
}

TEST(FalsePositiveDictionaryTest, AddUrlsWithSpecialCharacters) {
    FalsePositiveDictionary dictionary;

    // Test adding URLs with special characters
    dictionary.AddUrlToDict("http://site-with-special-chars.com/?query=value");
    dictionary.AddUrlToDict("ftp://ftp-site.com");
    dictionary.AddUrlToDict("file:///local/file.txt");

    EXPECT_TRUE(dictionary.SearchUrlInDict("http://site-with-special-chars.com/?query=value"));
    EXPECT_TRUE(dictionary.SearchUrlInDict("ftp://ftp-site.com"));
    EXPECT_TRUE(dictionary.SearchUrlInDict("file:///local/file.txt"));
}

TEST(FalsePositiveDictionaryTest, AddUrlsWithTrailingSpaces) {
    FalsePositiveDictionary dictionary;

    // Test adding URLs with trailing spaces
    dictionary.AddUrlToDict("http://url-with-space.com ");
    dictionary.AddUrlToDict("http://url-with-space.com\t");

    EXPECT_TRUE(dictionary.SearchUrlInDict("http://url-with-space.com "));
    EXPECT_TRUE(dictionary.SearchUrlInDict("http://url-with-space.com\t"));
}
