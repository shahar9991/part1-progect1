// #ifndef URLS_HANDLER_H
// #define URLS_HANDLER_H

// #include <vector>
// #include <string>
// #include "BloomFilter2.h"

// class URLsHandler {
// public:
//     URLsHandler() = default;

//      void processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter, map<string, ICommand*> commands);
//     void readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter,map<string, ICommand*> commands);
// };
// #endif // URLS_HANDLER_H
#ifndef URLS_HANDLER_H
#define URLS_HANDLER_H

#include <vector>
#include <string>
#include "BloomFilter2.h"
#include "ICommand.h"
#include <map>  // Add this include for std::map

class URLsHandler {
public:
    URLsHandler() = default;

    void processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter, std::map<std::string, ICommand*>& commands);
    void readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter, std::map<std::string, ICommand*>& commands);
};
#endif // URLS_HANDLER_H
