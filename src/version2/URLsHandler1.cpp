// URLsHandler.cpp
#include "URLsHandler1.h"
#include "BloomFilter2.h"  // Include the BloomFilter header
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>  // Include for std::isdigit

void URLsHandler::processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls, BloomFilter& bloomFilter, typename std::map<std::string, ICommand*>& commands) {
    for (const auto& url : urls) {
        // Extract the URL number (1 or 2) from the string- it indicates the task to be done.
        //1 -> add the url to the bloom filter
        //2 -> check if the URL is in the bloom filter and is blacklisted
        int urlNumber = url[0] - '0';
        std::string urlKey = std::to_string(urlNumber);
        std::string restOfURL = url.substr(1);
        if (commands.find(urlKey) != commands.end()) {
            try {
            
            commands[urlKey]->execute(restOfURL); //try to execute the required task from the commands list.
            }
            catch(...){}
        }
       
    }
}

void URLsHandler::readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter, typename std::map<std::string, ICommand*>& commands) {
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        urls.clear();  // Clear the vector before reading new URLs

        // Check if the input is only a number with optional spaces after
        size_t pos = 0;
        while (pos < input.size() && std::isdigit(input[pos])) {
            pos++;
        }

        if (pos > 0 && (pos == input.size() || (pos < input.size() && std::isspace(input[pos])))) {
            // If only a command number is provided, check if there is an actual URL following it
            while (pos < input.size() && std::isspace(input[pos])) {
                pos++;
            }

            if (pos < input.size()) {
                // Actual URL follows the command number
                urls.push_back(input);
            } else {
                // No URL provided after the command number, ask for the entire input again
                continue;
            }
        } else {
            // If the input is not only a number or is a valid command with a URL, process it
            urls.push_back(input);
        }

        processURLs(size, args, urls, bloomFilter, commands);
    }
}





