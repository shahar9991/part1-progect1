#include "IsBlackListed.h"
#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>

IsBlackListed::execute(const std::string& url){
    bool foundInDict = false;
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bloomFilter.bitArray.size();
        std::cout << "Checking URL: " << url << " at index " << index << std::endl;

        if (!bloomFilter.bitArray[index]) {
            return false; // If any bit is false, the URL is not blacklisted
        }

        if (bloomFilter.falsePositiveDict->SearchUrlInDict(url)) {
            foundInDict = true;
        }
    }
    return foundInDict; // Return whether the URL was found in the FalsePositiveDictionary
}