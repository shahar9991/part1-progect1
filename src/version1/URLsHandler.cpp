// URLsHandler.cpp
#include "URLsHandler.h"
#include "BloomFilter.h"  // Include the BloomFilter header
#include <iostream>
#include <sstream>

void URLsHandler::processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter) {
    std::cout << "Processed URLs:\n";
    for (const auto& url : urls) {
        std::cout << url << "\n";

        // Extract the URL number (1 or 2) from the string
        int urlNumber = url[0] - '0';

        if (urlNumber == 1) {
            // Add the URL to the Bloom filter (excluding the first digit)
            std::string restOfURL = url.substr(1);
            bloomFilter.addURL(restOfURL);
            std::cout << "(Added to Bloom Filter)\n";
        } else if (urlNumber == 2) {
            // Check if the URL (excluding the first digit) is blacklisted
            std::string restOfURL = url.substr(1);
            if (bloomFilter.isBlacklisted(restOfURL)) {
                std::cout << "(Blacklisted)\n";
            } else {
                std::cout << "(Not Blacklisted)\n";
            }
        } else {
            std::cout << "(Invalid URL format)\n";
        }
    }
}

void URLsHandler::readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter) {
    while (true) {
        std::cout << "Enter the URL(s) (space-separated): ";
        std::string input;
        std::getline(std::cin, input);

        urls.clear();  // Clear the vector before reading new URLs

        // Store the entire line as a single URL
        urls.push_back(input);

        processURLs(size, args, urls, bloomFilter);
    }
}