
#include "string.h"
#include <vector>
 #include <iostream> 
// function for the test 
bool isValidInputFormat(int size, const std::vector<int>& args) {
    // Check if the size is greater than 0
    if (size <= 0) {
        return false;
    }

    // Check if additional arguments are valid (1 or 2)
    for (int arg : args) {
        if (arg != 1 && arg != 2) {
            return false;
        }
    }

    // If all checks pass, return true
    return true;
}

// this is the real input function-Function for reading input from std::cin
#include <vector>
#include <sstream>
#include <iostream>

bool readInputFromUser(int& size, std::vector<int>& args) {
    // Read input as a string
    std::string input;
    std::cout << "Enter the size and additional arguments (space-separated): ";
    std::getline(std::cin, input);

    // Use a stringstream to parse the input
    std::istringstream ss(input);

    // Read the size
    ss >> size;

    // Check if the size is greater than 0
    if (size <= 0) {
        return false;
    }

    int arg;
    while (ss >> arg) {
        if (arg != 1 && arg != 2) {
            // Only 1 and 2 are valid, ask for new arguments
            std::cout << "Invalid argument " << arg << ". Please enter valid arguments.\n";
            args.clear();  // Clear the previous invalid arguments
            return readInputFromUser(size, args);  // Recursively ask for new input
        }
        args.push_back(arg);
    }

    // Check if at least one argument is provided
    if (args.empty()) {
        return false;
    }

    // If all checks pass, return true
    std::cout << "\nvalid\n";

    return true;
}