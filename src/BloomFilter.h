// BloomFilter.h
#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <string>
#include <vector>
#include <functional>

class BloomFilter {
public:
    BloomFilter(size_t size, std::function<size_t(const std::string&)> hash1, std::function<size_t(const std::string&)> hash2 = nullptr);
    
    void addURL(const std::string& url);
    bool isBlacklisted(const std::string& url) const;

private:
    std::vector<bool> bitArray;
    std::function<size_t(const std::string&)> hashFunction1;
    std::function<size_t(const std::string&)> hashFunction2;
};

#endif  // BLOOM_FILTER_H
