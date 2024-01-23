// URLsHandler.cpp
#include "URLsHandler1.h"
#include "BloomFilter2.h"  // Include the BloomFilter header
#include <iostream>
#include <sstream>
#include <vector>

void URLsHandler::processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter, map<string, IExecutable*> commands) {
    std::cout << "Processed URLs:\n";
    for (const auto& url : urls) {
        std::cout << url << "\n";

        // Extract the URL number (1 or 2) from the string- it indicates the task to be done.
        //1 -> add the url to the bloom filter
        //2 -> check if the URL is in the bloom filter and is blacklisted
        int urlNumber = url[0] - '0';
        std::string restOfURL = url.substr(1);
        try {
            commands[urlNumber]->execute(restOfURL); //try to execute the required task from the commands list.
        }
        catch(...){}
    }
}


void URLsHandler::readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter, map<string, IExecutable*> commands) {
    while (true) {
        std::cout << "Enter the URL(s) (space-separated): ";
        std::string input;
        std::getline(std::cin, input);

        urls.clear();  // Clear the vector before reading new URLs        
        urls.push_back(input); // Store the entire line as a single URL
        processURLs(size, args, urls, bloomFilter, commands);
    }
}