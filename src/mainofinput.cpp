// mainofinput.cpp

#include "InputHandler.h"
#include "BloomFilter.h"
#include <iostream>
#include <functional>
#include <vector>  // Add this include for vector

int main() {
    int size;
    std::vector<int> args;

    // Use InputHandler to get user input
    InputHandler::readSizeAndArgs(size, args);

    // Decide which hash functions to use based on user input
    bool useHash1 = std::find(args.begin(), args.end(), 1) != args.end();
    bool useHash2 = std::find(args.begin(), args.end(), 2) != args.end();

    // Define hash functions based on user input
    std::function<size_t(const std::string&)> hashFunction1 = std::hash<std::string>();
    std::function<size_t(const std::string&)> hashFunction2 = std::hash<std::string>();

    if (!useHash1) {
        hashFunction1 = [](const std::string&) -> size_t { return static_cast<size_t>(0); };
    }

    if (!useHash2) {
        hashFunction2 = [](const std::string&) -> size_t { return static_cast<size_t>(0); };
    }

    // Initialize BloomFilter using user inputs
    BloomFilter bloomFilter(size, hashFunction1, hashFunction2);

    std::cout << "Bloom filter created with size " << size << " and hash functions.\n";

    // Continuously read URLs from the user until an exit condition is met
    while (true) {
        std::vector<std::string> urls;  // Declare the vector to store URLs
        InputHandler::readURLs(size, args, urls);

        // Check if the URLs are blacklisted
        for (const auto& url : urls) {
            if (bloomFilter.isBlacklisted(url)) {
                std::cout << "URL '" << url << "' is blacklisted.\n";
            } else {
                std::cout << "URL '" << url << "' is not blacklisted.\n";
            }
        }

        // Add an exit condition (e.g., entering an empty string)
        std::cout << "Enter another set of URLs or press Enter to exit: ";
        std::string exitInput;
        std::getline(std::cin, exitInput);

        if (exitInput.empty()) {
            break;
        }
    }

    return 0;
}
