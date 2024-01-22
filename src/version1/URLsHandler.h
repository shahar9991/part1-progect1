// URLsHandler.h
#pragma once

#include <vector>
#include <string>
#include "BloomFilter.h"

class URLsHandler {
public:
    URLsHandler() = default;

    void processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter);
    void readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter);
};