
// BloomFilter.h
#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>

class FalsePositiveDictionary;  // Forward declaration

class BloomFilter {
public:
    BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions);

    void addURL(const std::string& url);

    std::string isBlacklisted(const std::string& url) const;

    ~BloomFilter();  // Declare the destructor

private:
    std::vector<bool> bitArray;
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;
    FalsePositiveDictionary* falsePositiveDict;  // Pointer to FalsePositiveDictionary
};

#endif // BLOOM_FILTER_H
