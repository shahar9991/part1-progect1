// InputHandler.h
#pragma once

#include <vector>
#include <string>
#include "BloomFilter.h"  // Include the BloomFilter header

class InputHandler {
public:
    static void printRealArgs(int size, const std::vector<int>& args);
    static void processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter);
    static void readSizeAndArgs(int& size, std::vector<int>& args);
    static void readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter);
};
