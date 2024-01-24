#include "ArgsHandler1.h"
#include <iostream>
#include <sstream>
#include <algorithm>

// Function to filter out duplicate values in the args vector
// and return a vector containing distinct values
std::vector<int> ArgsHandler::PrintRealArgs(int size, const std::vector<int>& args) {
    std::vector<int> distinctArgs;
    for (const auto& arg : args) {
        if (std::find(distinctArgs.begin(), distinctArgs.end(), arg) == distinctArgs.end()) {
            distinctArgs.push_back(arg);
        }
    }

    return distinctArgs;
}

// ArgsHandler.cpp

void ArgsHandler::readSizeAndArgs(int& size, std::vector<int>& args, std::istream& input) {
    while (true) {
        std::string userInput;
        std::getline(input, userInput);

        std::istringstream ss(userInput);
        ss >> size;

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
            // PrintRealArgs(size, args); // Commented out to avoid side effects during testing
            break;
        }
    }
}






// Function to read size and arguments from user input
//void ArgsHandler::readSizeAndArgs(int& size, std::vector<int>& args) {
//    while (true) {
//        std::string input;
//        std::getline(std::cin, input);
//        std::istringstream ss(input);
//        ss >> size;
//
//        // Check if the entered size is valid
//        if (size <= 0) {
//            continue;
//        }
//
//        args.clear();
//
//        int value;
//        while (ss >> value) {
//            // Check if the entered argument is valid (1 or 2)
//            if (value == 1 || value == 2) {
//                args.push_back(value);
//            } else {
//                // If an invalid argument is encountered, reset args and break
//                args.clear();
//                break;
//            }
//        }
//
//        // If args is not empty, the input is valid, break from the loop
//        if (!args.empty()) {
//            PrintRealArgs(size, args);
//            break;
//        }
//
//    }
//

//}
