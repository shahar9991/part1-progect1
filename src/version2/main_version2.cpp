#include "ArgsHandler1.h"
#include "URLsHandler1.h"
#include "BloomFilter2.h"
#include "HashGenerator2.h"  // Include the HashGenerator header
#include <iostream>
#include <unordered_set>
#include <functional>
#include <vector>
#include <map>
#include "ICommand.h"
#include "AddURL.h"
#include "IsBlackListed.h"

int main() {
    
     HashGenerator2 hashGenerator;
     int size;
     std::vector<int> args;

     ArgsHandler argsHandler;
     argsHandler.readSizeAndArgs(size,args);

     // Get the set of true keys from HashGenerator
     args = argsHandler.PrintRealArgs(size,args);
     hashGenerator.addTrueKeysToSet(args);
     const std::unordered_set<size_t>& trueKeysSet = hashGenerator.getTrueKeysSet();

     // Extract hash functions corresponding to true keys
     std::vector<std::function<size_t(const std::string&)>> hashFunctions;
     for (int key : args) {
         auto it = hashGenerator.getHashFunctionMap().find(key);
         if (it != hashGenerator.getHashFunctionMap().end()) {
             hashFunctions.push_back(it->second);
         }
     }                   

     // Create a BloomFilter instance with hash functions
     BloomFilter bloomFilter(size, hashFunctions);
     std::map<std::string, ICommand*> commands;

    // Add executable commands to the commands list
    ICommand* addURLCommand = new AddURL(&bloomFilter);
    commands["1"] = addURLCommand;

    ICommand* isBlackListedCommand = new IsBlacklisted(&bloomFilter);
    commands["2"] = isBlackListedCommand;

     while (true) {
        std::vector<std::string> urls;  // Declare the vector to store URLs
         URLsHandler urlsHandler;
        urlsHandler.readURLs(size, args, urls, bloomFilter,commands);
     }

     delete addURLCommand;
     delete isBlackListedCommand;

    return 0;
}


