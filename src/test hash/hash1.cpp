#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <functional>

class HashGenerator {
public:
    using HashFunction = std::function<size_t(const std::string&)>;

private:
    std::unordered_map<int, HashFunction> hashFunctionMap;  // Map to store hash functions
    std::unordered_set<size_t> trueKeysSet;  // Set to store true keys

public:
    HashGenerator() {
        // Initialize hash functions and store them in the map
        hashFunctionMap[1] = [](const std::string& s) { return std::hash<std::string>()(s); };
        hashFunctionMap[2] = [](const std::string& s) {
            size_t hashValue1 = std::hash<std::string>()(s);
            size_t hashValue2 = std::hash<std::string>()(std::to_string(hashValue1));
            return hashValue2 + hashValue2; // Return twice the result
        };
    }

    // Function to add true keys to the set based on hash function keys
    void addTrueKeysToSet(const std::vector<int>& hashFunctionKeys) {
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
    const std::unordered_map<int, HashFunction>& getHashFunctionMap() const {
        return hashFunctionMap;
    }

    // Function to iterate over true hash functions and print information
    void iterateOverTrueHashFunctions() const {
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
    const std::unordered_set<size_t>& getTrueKeysSet() const {
        return trueKeysSet;
    }
};


class BloomFilter {
public:
    BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions)
        : bitArray(size, false), hashFunctions(hashFunctions) {}

    void addTrueKeys(const std::unordered_set<size_t>& trueKeysSet) {
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

    bool isBlacklisted(const std::string& url) const {
        for (const auto& hashFunction : hashFunctions) {
            size_t index = hashFunction(url) % bitArray.size();
            std::cout << "Checking URL: " << url << " at index " << index << std::endl;

            if (!bitArray[index]) {
                return false; // If any bit is false, the URL is not blacklisted
            }
        }

        return true; // All bits were true, URL is potentially blacklisted
    }

    // Add URL to BloomFilter
    void addURL(const std::string& url) {
        for (const auto& hashFunction : hashFunctions) {
            size_t index = hashFunction(url) % bitArray.size();
            std::cout << "Adding URL: " << url << " at index " << index << std::endl;

            // Only set the bit to true if it is not already true
            if (!bitArray[index]) {
                bitArray[index] = true;
            }
        }
    }

private:
    std::vector<bool> bitArray;
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;
};

int main() {
    HashGenerator hashGenerator;

    // Simulate user input: 1, 2
    re

    // Get the set of true keys from HashGenerator
    hashGenerator.addTrueKeysToSet(userInput);
    const std::unordered_set<size_t>& trueKeysSet = hashGenerator.getTrueKeysSet();

    // Extract hash functions corresponding to true keys
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;
    for (int key : userInput) {
        auto it = hashGenerator.getHashFunctionMap().find(key);
        if (it != hashGenerator.getHashFunctionMap().end()) {
            hashFunctions.push_back(it->second);
        }
    }                   

    // Create a BloomFilter instance with hash functions
    BloomFilter bloomFilter(8, hashFunctions);

    // Simulate adding URLs to the BloomFilter
    std::cout << "Adding URLs to BloomFilter:\n";
    bloomFilter.addURL("www.example.com0");
    bloomFilter.addURL("www.example.com2");

    // Simulate checking if URLs are blacklisted
    std::cout << "\nChecking if URLs are blacklisted:\n";
    std::cout << "Is 'example_url_1' blacklisted? " << (bloomFilter.isBlacklisted("www.example.com0") ? "Yes" : "No") << "\n";
    std::cout << "Is 'example_url_3' blacklisted? " << (bloomFilter.isBlacklisted("www.example.com1") ? "Yes" : "No") << "\n";

    return 0;
}

