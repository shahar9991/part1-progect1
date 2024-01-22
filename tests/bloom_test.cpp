// test_BloomFilter.cpp
#include "../src/BloomFilter.h"
#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"
TEST(BloomFilterTest, BasicFunctionality) {
// Define two simple hash functions
auto hashFunction1 = [](const std::string& str) -> size_t {
    return std::hash<std::string>{}(str);
};

auto hashFunction2 = [](const std::string& str) -> size_t {
    // A simple custom hash function
    size_t hash = 0;
    for (char ch : str) {
        hash = hash * 31 + static_cast<size_t>(ch);
    }
    return hash;
};

// Create a BloomFilter with a size of 1000 bits and the two hash functions
BloomFilter bloomFilter(1000, hashFunction1, hashFunction2);

// Add a URL to the filter
bloomFilter.addURL("example.com");

// Check if the URL is blacklisted (it should be)
EXPECT_TRUE(bloomFilter.isBlacklisted("example.com"));

// Check a URL that hasn't been added (it might give a false positive)
EXPECT_FALSE(bloomFilter.isBlacklisted("notblacklisted.com"));
}

