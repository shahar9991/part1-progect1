#ifndef URLS_HANDLER_H
#define URLS_HANDLER_H

#include <vector>
#include <string>
#include "BloomFilter2.h"

class URLsHandler {
public:
    URLsHandler() = default;

    void processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter, map<string, IExecutable*> commands);
    void readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter, map<string, IExecutable*> commands);
};
#endif // URLS_HANDLER_H