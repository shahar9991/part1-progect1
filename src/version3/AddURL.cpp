#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>

void AddURL::execute(const std::string& url) {
    bloomFilter.falsePositiveDict->AddUrlToDict(url);
    bloomFilter.falsePositiveDict->DisplayAllUrls();
    for (const auto& hashFunction : hashFunctions) {
        size_t index = hashFunction(url) % bloomFilter.bitArray.size();
        std::cout << "Adding URL: " << url << " at index " << index << std::endl;

        // Only set the bit to true if it is not already true
        if (!bloomFilter.bitArray[index]) {
            bloomFilter.bitArray[index] = true;
        }
    }
}