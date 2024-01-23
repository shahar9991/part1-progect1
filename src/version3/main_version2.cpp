#include "ArgsHandler1.h"
#include "URLsHandler1.h"
#include "BloomFilter2.h"
#include "IExecutable.h"
#include "AddURL.h"
#include "IsBlacklisted.h"
#include "HashGenerator2.h"  // Include the HashGenerator header
#include <iostream>
#include <unordered_set>
#include <functional>
#include <vector>

int main() {
    HashGenerator2 hashGenerator;
    int size;
    std::vector<int> args; //arguments vector

    ArgsHandler argsHandler;
    argsHandler.readSizeAndArgs(size,args); //get the arguments from the user

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

    map<string, IExecutable*> commands; //create an array of commands to execute

    //add executable commands to the commands list
    IExecutable* AddURL = new AddURL(bloomFilter);
    commands["1"] = AddURL; //add a new URL adress to the bloom filter, to be blacklisted.

    IExecutable* IsBlackListed = new IsBlackListed(bloomFilter);
    commands["2"] = IsBlackListed; //check if a given URL adress is in the bloom filter and is blacklisted.


    //loop forever
    while (true) {
        std::vector<std::string> urls;  // Declare the vector to store URLs
        URLsHandler urlsHandler;
        urlsHandler.readURLs(size, args, urls, bloomFilter, commands); //handle the urls
    }

    return 0;
}
