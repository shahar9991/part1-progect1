#include <vector>
#include <string>
#include <functional>

class BloomFilter {
public:
    BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions)
        : bitArray(size, false), hashFunctions(hashFunctions) {}

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

private:
    std::vector<bool> bitArray;
    std::vector<std::function<size_t(const std::string&)>> hashFunctions;
};
