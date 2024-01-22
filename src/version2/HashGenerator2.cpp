#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <functional>
#include "HashGenerator2.h"

HashGenerator2::HashGenerator2() {
    // Initialize hash functions and store them in the map
    hashFunctionMap[1] = [](const std::string& s) { return std::hash<std::string>()(s); };
    hashFunctionMap[2] = [](const std::string& s) {
        size_t hashValue1 = std::hash<std::string>()(s);
        size_t hashValue2 = std::hash<std::string>()(std::to_string(hashValue1));
        return hashValue2 + hashValue2; // Return twice the result
    };
}

// Function to add true keys to the set based on hash function keys
void HashGenerator2::addTrueKeysToSet(const std::vector<int>& hashFunctionKeys) {
    for (int hashFunctionKey : hashFunctionKeys) {
        auto it = hashFunctionMap.find(hashFunctionKey);
        if (it != hashFunctionMap.end()) {
            HashFunction hashFunction = it->second;
            size_t key = hashFunction("example_string");  // Replace "example_string" with your actual input
            trueKeysSet.insert(key);
        }
    }
}

// Getter function for hashFunctionMap
const std::unordered_map<int, HashGenerator2::HashFunction>& HashGenerator2::getHashFunctionMap() const {
    return hashFunctionMap;
}

// Function to iterate over true hash functions and print information
void HashGenerator2::iterateOverTrueHashFunctions() const {
    std::cout << "True Hash Functions:\n";
    for (const auto& entry : hashFunctionMap) {
        int hashFunctionKey = entry.first;
        HashFunction hashFunction = entry.second;

        // Use hashFunction as needed (for example, call it with an input)
        size_t result = hashFunction("example_input");

        // Print information about the true hash function
        std::cout << "Hash Function " << hashFunctionKey << ": Result=" << result << "\n";
    }
}

// Function to get the true keys set
const std::unordered_set<size_t>& HashGenerator2::getTrueKeysSet() const {
    return trueKeysSet;
}
