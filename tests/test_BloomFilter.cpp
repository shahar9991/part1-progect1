// test_BloomFilter.cpp
#include <gtest/gtest.h>
#include "../src/version2/BloomFilter2.cpp"

TEST(BloomFilterTest, AddAndCheckSingleURL) {
    // Create a BloomFilter instance with a single hash function
    std::function<size_t(const std::string&)> hashFunction = [](const std::string& s) {
        return std::hash<std::string>()(s);
    };
    BloomFilter bloomFilter(100, {hashFunction});

    // Add a URL and check if it is blacklisted
    bloomFilter.addURL("http://example.com");

    testing::internal::CaptureStdout();
    bloomFilter.isBlacklisted("http://example.com");
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "true true\n");
}

TEST(BloomFilterTest, AddAndCheckMultipleURLs) {
    // Create a BloomFilter instance with multiple hash functions
    std::function<size_t(const std::string&)> hashFunction1 = [](const std::string& s) {
        return std::hash<std::string>()(s);
    };
    std::function<size_t(const std::string&)> hashFunction2 = [](const std::string& s) {
        return std::hash<std::string>()(std::to_string(std::hash<std::string>()(s)));
    };
    BloomFilter bloomFilter(100, {hashFunction1, hashFunction2});

    // Add URLs and check if they are blacklisted
    bloomFilter.addURL("http://site1.com");
    bloomFilter.addURL("http://site2.com");

    testing::internal::CaptureStdout();
    bloomFilter.isBlacklisted("http://site1.com");
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "true true\n");

    testing::internal::CaptureStdout();
    bloomFilter.isBlacklisted("http://site2.com");
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "true true\n");

    testing::internal::CaptureStdout();
    bloomFilter.isBlacklisted("http://site3.com");
    std::string output3 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output3, "false false\n");
}
TEST(BloomFilterTest, AddAndCheckMultipleURLs1) {
    // Create a BloomFilter instance with multiple hash functions
    std::function<size_t(const std::string&)> hashFunction1 = [](const std::string& s) {
        return std::hash<std::string>()(s);
    };
    std::function<size_t(const std::string&)> hashFunction2 = [](const std::string& s) {
        return std::hash<std::string>()(std::to_string(std::hash<std::string>()(s)));
    };
    BloomFilter bloomFilter(1, {hashFunction1, hashFunction2});

    // Add URLs and check if they are blacklisted
    bloomFilter.addURL("http://site1.com");
    

    testing::internal::CaptureStdout();
    bloomFilter.isBlacklisted("http://site1.com");
    std::string output1 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output1, "true true\n");

    testing::internal::CaptureStdout();
    bloomFilter.isBlacklisted("http://site2.com");
    std::string output2 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output2, "true false\n");

    bloomFilter.addURL("http://site2.com");

    testing::internal::CaptureStdout();
    bloomFilter.isBlacklisted("http://site3.com");
    std::string output3 = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output3, "true false\n");
}