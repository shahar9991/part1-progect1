#include "Flow.h"
#include "ArgsHandler.h"
#include "URLsHandler.h"
#include "BloomFilter.h"
#include "HashGenerator.h"  // Include the HashGenerator header
#include <iostream>
#include <unordered_set>
#include <functional>
#include <vector>
#include <map>
#include "ICommand.h"
#include "AddURL.h"
#include "IsBlackListed.h"
#include <cstring>
#include <sstream>
//static global variables
HashGenerator2 Flow::hashGenerator;
std::vector<std::function<size_t(const std::string &)>> Flow::hashFunctions;
BloomFilter* Flow::bloomFilter = nullptr;

// this class create all the needed instances and run the program
void Flow::run(const char* buffer, char* response_buffer) {
    const char* buffer1;
    const char* buffer2;
    std::vector<std::string> separated;
    std::istringstream iss(buffer);
    std::string token;
    std::string bitsNumber;
    while (std::getline(iss, token, ',')) {
        separated.push_back(token);
    }
    std::string firstPart= separated[0];
    std::istringstream ss(firstPart);
    ss >> bitsNumber;
    int intBitsNumber = std::stoi(bitsNumber);
    if(intBitsNumber>2) {
        buffer1=buffer;
    }

    int size;
    std::vector<int> args;
    ArgsHandler argsHandler;

    argsHandler.readSizeAndArgs(size, args, buffer1); // Pass the client socket descriptor to readSizeAndArgs

    // Get the set of true keys from HashGenerator
    args = argsHandler.PrintRealArgs(size, args);
    hashGenerator.addTrueKeysToSet(args);
    const std::unordered_set<size_t> &trueKeysSet = hashGenerator.getTrueKeysSet();

    // Extract hash functions corresponding to true keys
    for (int key: args) {
        auto it = hashGenerator.getHashFunctionMap().find(key);
        if (it != hashGenerator.getHashFunctionMap().end()) {
            hashFunctions.push_back(it->second);
        }
    }

    if (!bloomFilter) {
        // Initialize bloomFilter here
        bloomFilter = new BloomFilter(intBitsNumber, hashFunctions);
    }
    std::map<std::string, ICommand *> commands;

    // Add executable commands to the commands list
    ICommand *addURLCommand = new AddURL(bloomFilter);
    commands["1"] = addURLCommand;

    ICommand *isBlackListedCommand = new IsBlacklisted(bloomFilter);
    commands["2"] = isBlackListedCommand;

    URLsHandler urlsHandler;
    std::string result;

    std::vector<std::string> urls;  // Declare the vector to store URLs
    urlsHandler.readURLs(size, args, urls, bloomFilter, commands, buffer, result);

    // Store the result in the response buffer
    strcpy(response_buffer, result.c_str());
    //  }

    delete addURLCommand;
    delete isBlackListedCommand;
}