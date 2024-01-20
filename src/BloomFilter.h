// BloomFilter.h
#pragma once

#include <vector>
#include <functional>
#include <string>

class BloomFilter {
private:
    std::vector<bool> bitArray;
    std::function<size_t(const std::string&)> hashFunction1;
    std::function<size_t(const std::string&)> hashFunction2;

public:
    BloomFilter(size_t size, std::function<size_t(const std::string&)> hash1, std::function<size_t(const std::string&)> hash2);
    void addURL(const std::string& url);
    bool isBlacklisted(const std::string& url) const;
};