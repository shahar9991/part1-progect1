// BloomFilter.cpp
#include "BloomFilter.h"

BloomFilter::BloomFilter(size_t size, std::function<size_t(const std::string&)> hash1, std::function<size_t(const std::string&)> hash2)
    : bitArray(size, false), hashFunction1(hash1), hashFunction2(hash2) {}

void BloomFilter::addURL(const std::string& url) {
    size_t index1 = hashFunction1(url) % bitArray.size();
    size_t index2 = hashFunction2(url) % bitArray.size();
    bitArray[index1] = true;
    bitArray[index2] = true;
}

bool BloomFilter::isBlacklisted(const std::string& url) const {
    size_t index1 = hashFunction1(url) % bitArray.size();
    size_t index2 = hashFunction2(url) % bitArray.size();
    return bitArray[index1] && bitArray[index2];
}

