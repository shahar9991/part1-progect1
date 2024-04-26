
#ifndef URLS_HANDLER_H
#define URLS_HANDLER_H

#include <vector>
#include <string>
#include "BloomFilter.h"
#include "ICommand.h"
#include <map>  // Add this include for std::map

class URLsHandler {
public:
    URLsHandler() = default;

    void processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter, std::map<std::string, ICommand*>& commands,std::string& result);
    void readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter, std::map<std::string, ICommand*>& commands,const char* buffer,std::string& result);
};
#endif // URLS_HANDLER_H
