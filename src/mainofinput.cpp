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
    std::function<size_t(const std::string&)> hashFunction2;

    if (useHash1) {
        hashFunction1 = std::hash<std::string>();
    } else {
        hashFunction1 = [](const std::string&) -> size_t { return static_cast<size_t>(0); };
    }

    if (useHash2) {
        hashFunction2 = [hash1 = std::hash<std::string>()](const std::string& s) -> size_t {
            // Call std::hash twice
            return hash1(s) ^ hash1(s);
        };
    } else {
        hashFunction2 = [](const std::string&) -> size_t { return static_cast<size_t>(0); };
    }
    // Initialize BloomFilter using user inputs
    BloomFilter bloomFilter(size, hashFunction1, hashFunction2);

    std::cout << "Bloom filter created with size " << size << " and hash functions: ";
    if (useHash1) {
        std::cout << "Hash 1 ";
    }
    if (useHash2) {
        std::cout << "Hash 2 ";
    }
    std::cout << "\n";

    // Continuously read URLs from the user until an exit condition is met
    while (true) {
        std::vector<std::string> urls;  // Declare the vector to store URLs
        InputHandler::readURLs(size, args, urls, bloomFilter);

    return 0;
}

}

