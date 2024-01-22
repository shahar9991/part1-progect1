// BloomFilter2.h
#ifndef BLOOM_FILTER2_H
#define BLOOM_FILTER2_H

#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>

class BloomFilter {
public:
    BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions);

    void addTrueKeys(const std::unordered_set<size_t>& trueKeysSet);

    void addURL(const std::string& url);

    bool isBlacklisted(const std::string& url) const;

private:
    std::vector<bool> bitArray;
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;
};

#endif // BLOOM_FILTER2_H
