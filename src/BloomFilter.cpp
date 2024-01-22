// BloomFilter.cpp
#include "BloomFilter.h"
#include <iostream>
#include <functional>
#include <string>

BloomFilter::BloomFilter(size_t size, std::function<size_t(const std::string&)> hash1, std::function<size_t(const std::string&)> hash2)
    : bitArray(size, false), hashFunction1(hash1), hashFunction2(hash2) {}

void BloomFilter::addURL(const std::string& url) {
    // Check if both hash functions are provided
    if (hashFunction1 && hashFunction2) {
        size_t index1 = hashFunction1(url) % bitArray.size();
        size_t index2 = hashFunction2(url) % bitArray.size();

        std::cout << "Adding URL: " << url << " at indices " << index1 << " and " << index2 << std::endl;

        // Only set the bits to true if they are not already true
        if (!bitArray[index1]) {
            bitArray[index1] = true;
        }

        if (!bitArray[index2]) {
            bitArray[index2] = true;
        }
    } else if (hashFunction1) { // Use only the first hash function
        size_t index1 = hashFunction1(url) % bitArray.size();

        std::cout << "Adding URL: " << url << " at index " << index1 << std::endl;

        // Only set the bit to true if it is not already true
        if (!bitArray[index1]) {
            bitArray[index1] = true;
        }
    } else if (hashFunction2) { // Use only the second hash function
        size_t index2 = hashFunction2(url) % bitArray.size();

        std::cout << "Adding URL: " << url << " at index " << index2 << std::endl;

        // Only set the bit to true if it is not already true
        if (!bitArray[index2]) {
            bitArray[index2] = true;
        }
    }
}

bool BloomFilter::isBlacklisted(const std::string& url) const {
    // Check if both hash functions are provided
    if (hashFunction1 && hashFunction2) {
        size_t index1 = hashFunction1(url) % bitArray.size();
        size_t index2 = hashFunction2(url) % bitArray.size();

        std::cout << "Checking URL: " << url << " at indices " << index1 << " and " << index2 << std::endl;

        return bitArray[index1] && bitArray[index2];
    } else if (hashFunction1) { // Use only the first hash function
        size_t index1 = hashFunction1(url) % bitArray.size();

        std::cout << "Checking URL: " << url << " at index " << index1 << std::endl;

        return bitArray[index1];
    } else if (hashFunction2) { // Use only the second hash function
        size_t index2 = hashFunction2(url) % bitArray.size();

        std::cout << "Checking URL: " << url << " at index " << index2 << std::endl;

        return bitArray[index2];
    }

    return false; // No hash functions provided
}
