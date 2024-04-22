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

//Function to read size and arguments from user input
void ArgsHandler::readSizeAndArgs(int& size, std::vector<int>& args, int client_sock) {
   while (true) {
       std::string input;
       //todo get from socket
       //std::getline(std::cin, input);
       char buffer[4096];
       int read_bytes = read(client_sock, buffer, sizeof(buffer));
       if (read_bytes < 0) {
           // Error reading from socket
           perror("Error reading from socket");
           break;
       } else if (read_bytes == 0) {
           // Connection closed by client
           std::cout << "Connection closed by client\n";
           break;
       }
       // Append received data to the input string
       input.append(buffer, read_bytes);

       std::istringstream iss(input);
       std::string token;
       std::vector<std::string> tokens;

       // Split the input by comma
       while (std::getline(iss, token, ',')) {
           tokens.push_back(token);
       }

       // Parse the first token as size and the rest as args
       std::istringstream argsStream(tokens[0]);
       argsStream >> size;
       int argValue;
       while (argsStream >> argValue) {
           args.push_back(argValue);
       }

//       std::istringstream ss(input);
//       ss >> size;

       // Check if the entered size is valid
       if (size <= 0) {
           continue;
       }

       args.clear();

       int value;
       while (argValue >> value) {
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
