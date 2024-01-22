// BloomFilter2.cpp
#include "BloomFilter2.h"

BloomFilter::BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions)
    : bitArray(size, false), hashFunctions(hashFunctions) {
    // Implementation of the constructor goes here
}

void BloomFilter::addTrueKeys(const std::unordered_set<size_t>& trueKeysSet) {
    for (size_t key : trueKeysSet) {
        for (const auto& hashFunction : hashFunctions) {
            size_t index = hashFunction(std::to_string(key)) % bitArray.size();
            std::cout << "Adding Key: " << key << " at index " << index << std::endl;

            // Only set the bit to true if it is not already true
            if (!bitArray[index]) {
                bitArray[index] = true;
            }
        }
    }
}

bool BloomFilter::isBlacklisted(const std::string& url) const {
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bitArray.size();
        std::cout << "Checking URL: " << url << " at index " << index << std::endl;

        if (!bitArray[index]) {
            return false; // If any bit is false, the URL is not blacklisted
        }
    }

    return true; // All bits were true, URL is potentially blacklisted
}

void BloomFilter::addURL(const std::string& url) {
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bitArray.size();
        std::cout << "Adding URL: " << url << " at index " << index << std::endl;

        // Only set the bit to true if it is not already true
        if (!bitArray[index]) {
            bitArray[index] = true;
        }
    }
}
