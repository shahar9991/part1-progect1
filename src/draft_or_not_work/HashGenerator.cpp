#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

class HashGenerator {
public:
    using HashFunction = std::function<size_t(const std::string&)>;

private:
    std::unordered_map<int, std::function<HashFunction()>> hashFunctionGenerators;

public:
    HashGenerator() {
        // Register hash function generators
        hashFunctionGenerators[1] = []() { return std::hash<std::string>(); };
        hashFunctionGenerators[2] = []() {
            return []() {
                return [](const std::string& s) { return std::hash<std::string>()(s) * 2; };
            };
        };
    }

    std::vector<HashGenerator::HashFunction> getHashFunctions(const std::vector<int>& hashFunctionKeys) {
        std::vector<HashFunction> hashFunctions;
        for (int key : hashFunctionKeys) {
            auto generatorIt = hashFunctionGenerators.find(key);
            if (generatorIt != hashFunctionGenerators.end()) {
                hashFunctions.push_back(generatorIt->second());
            }
            // Note: You might want to handle the case where the key is not found.
            // For simplicity, I'll skip it here.
        }
        return hashFunctions;
    }
};
