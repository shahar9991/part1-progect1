// URLsHandler.cpp
#include "URLsHandler.h"
#include "BloomFilter.h"  // Include the BloomFilter header
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cctype>  // Include for std::isdigit
#include <unistd.h> //include for read. can we use it???
#include <algorithm>
//this class handle the urls adresses from the user first check if the url is leagal then excute the command. 
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


void URLsHandler::readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls, BloomFilter& bloomFilter, typename std::map<std::string, ICommand*>& commands,const char* buffer) {
    while (true) {
        // std::string input;
        std::string data;
        std::vector<std::string> separated;
        //todo socket
        // std::getline(std::cin, input);

        // Clear the vector before reading new URLs
        urls.clear();

//        char buffer[4096];
//        int read_bytes = read(client_sock, buffer, sizeof(buffer));
//        if (read_bytes < 0) {
//            // Error reading from socket
//            perror("Error reading from socket");
//            break;
//        } else if (read_bytes == 0) {
//            // Connection closed by client
//            std::cout << "Connection closed by client\n";
//            break;
//        }
//        // Append received data to the input string
//        // input.append(buffer, read_bytes);
//        data.append(buffer, read_bytes);
        data=buffer;
        std::istringstream iss(data);
        std::string token;
        while (std::getline(iss, token, ',')) {
            separated.push_back(token);
        }
        // Check if the first part contains only digits
        std::string firstPart= separated[0];
        firstPart.erase(remove_if(firstPart.begin(),
                                  firstPart.end(), isspace), firstPart.end());
        //std::string firstPart = trim(separated[0]); // Trim whitespace
        std::cout <<"first part: "<< firstPart << std::endl;
        std::istringstream sizeStream(firstPart);
        sizeStream >> std::noskipws >> std::ws;
        char c;
        bool allDigits = true;

        // Check if all characters are digits
        while (sizeStream >> c) {
            if (!std::isdigit(c)) {
                std::cout<<"false";
                allDigits = false;
                break;
            }
        }

        if (allDigits) {
            // If it contains only digits, erase the first element
            separated.erase(separated.begin());
            for (const auto &input: separated) {                    // Check if the input is empty
                if (input.empty()) {
                    // If input is empty, continue to the next iteration to read new input
                    continue;
                }

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
            }
            for (int i = 0; i < urls.size(); ++i) {
                std::cout<<"urls: "<<urls[i]<<std::endl;
            }

            //gets an array of urls and checks them according to the number attached
            processURLs(size, args, urls, bloomFilter, commands);
        }
    }
        // Close the client socket after exiting the loop
   //     close(client_sock);
    }








