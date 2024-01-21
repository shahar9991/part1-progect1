// InputHandler.cpp
#include "InputHandler.h"
#include <iostream>
#include <sstream>
#include <algorithm>

void InputHandler::printRealArgs(int size, const std::vector<int>& args) {
    std::vector<int> distinctArgs;
    for (const auto& arg : args) {
        if (std::find(distinctArgs.begin(), distinctArgs.end(), arg) == distinctArgs.end()) {
            distinctArgs.push_back(arg);
        }
    }

    std::cout << "Real Args: " << size << " ";
    for (const auto& arg : distinctArgs) {
        std::cout << arg << " ";
    }
    std::cout << "\n";
}

void InputHandler::processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter) {
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









void InputHandler::readSizeAndArgs(int& size, std::vector<int>& args) {
    while (true) {
        std::cout << "Enter the size and arguments (space-separated): ";
        std::string input;
        std::getline(std::cin, input);

        std::istringstream ss(input);
        ss >> size;

        if (size <= 0) {
            std::cout << "Invalid size. Please enter a valid input.\n";
            continue;
        }

        args.clear();

        int value;
        while (ss >> value) {
            if (value == 1 || value == 2) {
                args.push_back(value);
            } else {
                std::cout << "Invalid argument. Please enter valid arguments.\n";
                args.clear();
                break;
            }
        }

        if (!args.empty()) {
            printRealArgs(size, args);
            break;
        }
    }
}

void InputHandler::readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter) {
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


