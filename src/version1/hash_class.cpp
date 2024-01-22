#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <functional>

class HashGenerator {
public:
    using HashFunction = std::function<size_t(const std::string&)>;

private:
    std::unordered_map<int, bool> hashFunctionFlags;

public:
    HashGenerator() {
        // Initialize hash function flags to false
        hashFunctionFlags[1] = false;
        hashFunctionFlags[2] = false;
    }

    // Function to update hash function flags to true based on user input
    void updateHashFlags(const std::vector<int>& userInputs) {
        for (int userInput : userInputs) {
            auto it = hashFunctionFlags.find(userInput);
            if (it != hashFunctionFlags.end()) {
                it->second = true;
            }
        }
    }

    // Function to collect keys where the values are true
    std::unordered_set<int> getTrueHashKeys() const {
        std::unordered_set<int> trueKeys;
        for (const auto& entry : hashFunctionFlags) {
            if (entry.second) {
                trueKeys.insert(entry.first);
            }
        }
        return trueKeys;
    }
};

int main() {
    HashGenerator hashGenerator;

    // Simulate user input
    std::vector<int> userInput = {1, 2};

    // Update hash function flags based on user input
    hashGenerator.updateHashFlags(userInput);

    // Collect keys where the values are true
    std::unordered_set<int> trueKeys = hashGenerator.getTrueHashKeys();

    // Print the true keys
    std::cout << "True Keys: ";
    for (int key : trueKeys) {
        std::cout << key << " ";
    }
    std::cout << "\n";

    return 0;
}
