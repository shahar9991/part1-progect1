#include "BloomFilter.h"
#include "FalsePositive.h"  // Include the FalsePositive header file

BloomFilter::BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions)
    : bitArray(size, false), hashFunctions(hashFunctions) {
    falsePositiveDict = new FalsePositiveDictionary();  // Initialize the FalsePositiveDictionary
}

BloomFilter::~BloomFilter() {
    delete falsePositiveDict;
}
// Definition of BloomFilter functions
void BloomFilter::isBlacklisted(const std::string& url) const {
    bool foundInDict = false;

    // Check if the URL is present in the FalsePositiveDictionary
    foundInDict = falsePositiveDict->SearchUrlInDict(url);

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
    std::cout << (anyBitFalse ? "false " : "true ") << (foundInDict ? "true" : "false") << std::endl;
}



void BloomFilter::addURL(const std::string& url) {
    falsePositiveDict->AddUrlToDict(url);
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bitArray.size();
        // Only set the bit to true if it is not already true
        if (!bitArray[index]) {
            bitArray[index] = true;
        }
    }
}
