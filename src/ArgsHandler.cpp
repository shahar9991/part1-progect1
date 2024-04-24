#include "ArgsHandler.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <unistd.h> //include for read. can we use it???

// Function to filter out duplicate values in the args vector
// and return a vector containing distinct values
std::vector<int> ArgsHandler::PrintRealArgs(int size, const std::vector<int>& args) {
    std::vector<int> distinctArgs;
    for (const auto& arg : args) {
        if (std::find(distinctArgs.begin(), distinctArgs.end(), arg) == distinctArgs.end()) {
            distinctArgs.push_back(arg);
        }
    }
//todo response for client?
    return distinctArgs;
}
// Trim whitespace from the beginning of a string
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) {
        return ""; // No non-whitespace characters
    }
    return str.substr(start);
}
//Function to read size and arguments from user input
void ArgsHandler::readSizeAndArgs(int& size, std::vector<int>& args,const char* buffer) {
   while (true) {
       std::string input;
       std::string data;
       std::vector<std::string> separated;
       //todo get from socket
       //std::getline(std::cin, input);
       //char buffer[4096];

       //int read_bytes = read(client_sock, buffer, sizeof(buffer));

//       if (read_bytes < 0) {
//           // Error reading from socket
//           perror("Error reading from socket");
//           break;
//
//       } else if (read_bytes == 0) {
//           // Connection closed by client
//           std::cout << "Connection closed by client\n";
//           break;
//       }

       // Append received data to the input string
       data=buffer;

//       for (int i = 0; i < read_bytes; ++i) {
//           std::cout << buffer[i];
//       }
//       std::cout << std::endl;
//       std::cout<<"data\n";
//       std::cout<<data;

       std::istringstream iss(data);
       std::string token;
       while (std::getline(iss, token, ',')) {
           separated.push_back(token);
       }

       // Check if the first part contains only digits
       //std::istringstream sizeStream(separated[0]);
       // Check if the first part contains only digits
       std::string firstPart= separated[0];
       firstPart.erase(remove_if(firstPart.begin(),
                                                           firstPart.end(), isspace), firstPart.end());
       //std::string firstPart = trim(separated[0]); // Trim whitespace
       //std::cout << firstPart << std::endl;
       std::istringstream sizeStream(firstPart);
       sizeStream >> std::noskipws >> std::ws;
       char c;
       bool allDigits = true;

       // Check if all characters are digits
       while (sizeStream >> c) {
           if (!std::isdigit(c)) {
               allDigits = false;
               break;
           }
       }
       if (allDigits) {
           input=separated[0];
           std::cout<<"size and args "<<input<<std::endl;
       } else{
           return;
       }

       std::istringstream ss(input);
       ss >> size;
       std::cout << "size: " << size << std::endl;

       // Check if the entered size is valid
       if (size <= 0) {
           continue;

       }

       args.clear();

       int value;
       while (ss >> value) {
           // Check if the entered argument is valid (1 or 2)
           if (value == 1 || value == 2) {
               args.push_back(value);
           } else {
               // If an invalid argument is encountered, reset args and break
               args.clear();
               break;
           }
       }
       // If args is not empty, the input is valid, break from the loop
       if (!args.empty()) {

           PrintRealArgs(size, args);
           break;
       }

   }
}
