// test_BloomFilter.cpp
#include <gtest/gtest.h>
#include "../src/version0/BloomFilter.h"

//add url, then check if blacklisted is indeed equal to add
//for function isBlacklisted:
//check 1&2
//check 1
//check2
//check false

// Test case 1: add url with both hash functions
TEST(CalcTests, Blacklist_HashFunctions1And2) {
    BloomFilter bloomFilter1(8, std::hash<std::string>(), std::hash<std::string>());
    ASSERT_FALSE(bloomFilter1.isBlacklisted("example.com"));
    ASSERT_TRUE(bloomFilter1.addURL("example.com"));
    ASSERT_TRUE(bloomFilter1.isBlacklisted("example.com"));
}

// add url with only hash function 1
TEST(CalcTests, Blacklist_HashFunction1) {
BloomFilter bloomFilter2(8, std::hash<std::string>(), nullptr);

ASSERT_FALSE(bloomFilter2.isBlacklisted("example.org"));
ASSERT_TRUE(bloomFilter2.addURL("example.org"));
ASSERT_TRUE(bloomFilter2.isBlacklisted("example.org"));
}

// add url with only hash function 2
TEST(CalcTests, Blacklist_HashFunction2) {
BloomFilter bloomFilter3(8, nullptr, std::hash<std::string>());

ASSERT_FALSE(bloomFilter3.isBlacklisted("example.net"));
ASSERT_TRUE(bloomFilter3.addURL("example.net"));
ASSERT_TRUE(bloomFilter3.isBlacklisted("example.net"));
}

// add url  without hash functions 1 and 2
TEST(CalcTests, Blacklist_None) {
BloomFilter bloomFilter3(8, nullptr, nullptr);
ASSERT_FALSE(bloomFilter3.addURL("example.net"));
ASSERT_FALSE(bloomFilter3.isBlacklisted("example.net"));
}




