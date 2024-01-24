#include "BloomFilter2.h"
#include "FalsePositive.h"  // Include the FalsePositive header file

BloomFilter::BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions)
    : bitArray(size, false), hashFunctions(hashFunctions) {
    falsePositiveDict = new FalsePositiveDictionary();  // Initialize the FalsePositiveDictionary
}

BloomFilter::~BloomFilter() {
    delete falsePositiveDict;
}

// Definition of BloomFilter functions
// Definition of BloomFilter functions
bool BloomFilter::isBlacklisted(const std::string& url) const {
    bool foundInDict = false;
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bitArray.size();
        std::cout << "Checking URL: " << url << " at index " << index << std::endl;

        if (!bitArray[index]) {
            return false; // If any bit is false, the URL is not blacklisted
        }

        if (falsePositiveDict->SearchUrlInDict(url)) {
            foundInDict = true;
        }
    }
    return foundInDict; // Return whether the URL was found in the FalsePositiveDictionary
}

void BloomFilter::addURL(const std::string& url) {
    falsePositiveDict->AddUrlToDict(url);
    falsePositiveDict->DisplayAllUrls();
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bitArray.size();
        std::cout << "Adding URL: " << url << " at index " << index << std::endl;

        // Only set the bit to true if it is not already true
        if (!bitArray[index]) {
            bitArray[index] = true;
        }
    }
}
