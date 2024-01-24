#include "IsBlackListed.h"
#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>
// Definition of BloomFilter functions
void BloomFilter::isBlacklisted(const std::string& url) const {
    bool foundInDict = false;

    // Check if the URL is present in the FalsePositiveDictionary
    if (falsePositiveDict->SearchUrlInDict(url)) {
        foundInDict = true;
    }

    // Iterate over hash functions and check bitArray
    bool anyBitFalse = false;
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bitArray.size();
        if (!bitArray[index]) {
            anyBitFalse = true; // If any bit is false, set anyBitFalse to true
            break;  // Exit the loop if a false bit is found
        }
    }

    // Print the result
    std::cout  << (anyBitFalse ? "false " : "true ")<< (foundInDict ? "true " : "false") << std::endl;
}