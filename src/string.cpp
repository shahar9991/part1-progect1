
#include "string.h"
#include <vector>
 #include <iostream> 
// function for the test vector
//---------------------------------------------------------------------------//
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
//---------------------------------------------------------------------------//

// this is the real input function-reading input from std::cin
#include <iostream>
// #include <sstream>
// #include <vector>
// #include <algorithm>

// // Function to print the real arguments (including size and ignoring duplicates)
// void printRealArgs(int size, const std::vector<int>& args) {
//     std::vector<int> distinctArgs;

//     // Iterate over the arguments and add only the first occurrence of each value
//     for (const auto& arg : args) {
//         if (std::find(distinctArgs.begin(), distinctArgs.end(), arg) == distinctArgs.end()) {
//             distinctArgs.push_back(arg);
//         }
//     }

//     std::cout << "Real Args: " << size << " ";
//     for (const auto& arg : distinctArgs) {
//         std::cout << arg << " ";
//     }
//     std::cout << "\n";
// }

// // Function to process URLs based on size and arguments
// void processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls) {
//     // Process the URLs based on the processed size and arguments
//     std::cout << "Processed URLs: ";
//     for (const auto& url : urls) {
//         std::cout << url << " ";
//     }
//     std::cout << "\n";
// }

// // Function to read size and arguments from the user
// void readSizeAndArgs(int& size, std::vector<int>& args) {
//     while (true) {
//         std::cout << "Enter the size and arguments (space-separated): ";
//         std::string input;
//         std::getline(std::cin, input);

//         std::istringstream ss(input);
//         ss >> size;

//         if (size <= 0) {
//             std::cout << "Invalid size. Please enter a valid input.\n";
//             continue;  // Restart the input process from the beginning
//         }

//         args.clear();  // Clear the previous arguments for a fresh start

//         int value;
//         while (ss >> value) {
//             if (value == 1 || value == 2) {
//                 args.push_back(value);
//             } else {
//                 std::cout << "Invalid argument. Please enter valid arguments.\n";
//                 args.clear();  // Clear the previous invalid arguments
//                 break;         // Restart the input process from the beginning
//             }
//         }

//         // If args is not empty, the input is valid, print real args and exit the loop
//         if (!args.empty()) {
//             // Print the real arguments (including size and ignoring duplicates)
//             printRealArgs(size, args);
//             break;
//         }
//     }
// }

// // Function to read URLs from the user
// void readURLs(int size, const std::vector<int>& args) {
//     while (true) {
//         // Read URLs
//         std::cout << "Enter the URL(s) (space-separated): ";
//         std::string input;
//         std::getline(std::cin, input);

//         std::istringstream url_ss(input);
//         std::string url_part;

//         std::vector<std::string> urls;

//         bool validURL = true;

//         while (url_ss >> url_part) {
//             if ((url_part == "1" && std::find(args.begin(), args.end(), 1) != std::end(args)) ||
//                 (url_part == "2" && std::find(args.begin(), args.end(), 2) != std::end(args))) {
//                 // If the URL part matches the processed arguments, it is valid
//                 std::string url = url_part;
//                 url_ss >> url_part;  // Read the rest of the URL
//                 url += " " + url_part;
//                 urls.push_back(url);
//             } else {
//                 // Invalid input, set flag to indicate bad URL
//                 validURL = false;
//                 break;
//             }
//         }

//         if (!validURL) {
//             std::cout << "Invalid URL format. Please enter valid URLs.\n";
//             // Continue to the next iteration
//             continue;
//         }

//         // Process the URLs or perform any necessary actions
//         processURLs(size, args, urls);
//         // Continue to the next iteration to read more URLs
//     }
// }


