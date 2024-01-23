// URLsHandler.cpp
#include "URLsHandler1.h"
#include "BloomFilter2.h"  // Include the BloomFilter header
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

void URLsHandler::processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter, typename std::map<std::string, ICommand*>& commands) {
    for (const auto& url : urls) {
        std::cout << url << "\n";

        // Extract the URL number (1 or 2) from the string- it indicates the task to be done.
        //1 -> add the url to the bloom filter
        //2 -> check if the URL is in the bloom filter and is blacklisted
        int urlNumber = url[0] - '0';
        std::string restOfURL = url.substr(1);
        try {
             std::string urlKey = std::to_string(urlNumber);
            commands[urlKey]->execute(restOfURL); //try to execute the required task from the commands list.
        }
        catch(...){}
    }
    // for (const auto& url : urls) {
    //     // Extract the URL number (1 or 2) from the string
    //     int urlNumber = url[0] - '0';

    //     if (urlNumber == 1) {
    //         // Add the URL to the Bloom filter (excluding the first digit)
    //         std::string restOfURL = url.substr(1);
    //         bloomFilter.addURL(restOfURL);
    //     } else if (urlNumber == 2) {
    //         // Check if the URL (excluding the first digit) is blacklisted
    //         std::string restOfURL = url.substr(1);
    //         bloomFilter.isBlacklisted(restOfURL); 
    //     } 
    
    // }
}

void URLsHandler::readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter, typename std::map<std::string, ICommand*>& commands) {
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        urls.clear();  // Clear the vector before reading new URLs

        // Store the entire line as a single URL
        urls.push_back(input);

        // processURLs(size, args, urls, bloomFilter);
        processURLs(size, args, urls, bloomFilter, commands);
    }
}