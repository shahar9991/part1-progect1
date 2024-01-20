// InputHandler.cpp
#include "InputHandler.h"
#include <iostream>
#include <sstream>
#include <algorithm>

void InputHandler::printRealArgs(int size, const std::vector<int>& args) {
    std::vector<int> distinctArgs;
    for (const auto& arg : args) {
        if (std::find(distinctArgs.begin(), distinctArgs.end(), arg) == distinctArgs.end()) {
            distinctArgs.push_back(arg);
        }
    }

    std::cout << "Real Args: " << size << " ";
    for (const auto& arg : distinctArgs) {
        std::cout << arg << " ";
    }
    std::cout << "\n";
}

void InputHandler::processURLs(int size, const std::vector<int>& args, const std::vector<std::string>& urls) {
    std::cout << "Processed URLs: ";
    for (const auto& url : urls) {
        std::cout << url << " ";
    }
    std::cout << "\n";
}

void InputHandler::readSizeAndArgs(int& size, std::vector<int>& args) {
    while (true) {
        std::cout << "Enter the size and arguments (space-separated): ";
        std::string input;
        std::getline(std::cin, input);

        std::istringstream ss(input);
        ss >> size;

        if (size <= 0) {
            std::cout << "Invalid size. Please enter a valid input.\n";
            continue;
        }

        args.clear();

        int value;
        while (ss >> value) {
            if (value == 1 || value == 2) {
                args.push_back(value);
            } else {
                std::cout << "Invalid argument. Please enter valid arguments.\n";
                args.clear();
                break;
            }
        }

        if (!args.empty()) {
            printRealArgs(size, args);
            break;
        }
    }
}

void InputHandler::readURLs(int size, const std::vector<int>& args, std::vector<std::string>& urls) {
    while (true) {
        std::cout << "Enter the URL(s) (space-separated): ";
        std::string input;
        std::getline(std::cin, input);

        std::istringstream url_ss(input);
        std::string url_part;

        urls.clear();  // Clear the vector before reading new URLs

        bool validURL = true;

        while (url_ss >> url_part) {
            if ((url_part == "1" && std::find(args.begin(), args.end(), 1) != std::end(args)) ||
                (url_part == "2" && std::find(args.begin(), args.end(), 2) != std::end(args))) {
                std::string url = url_part;
                url_ss >> url_part;
                url += " " + url_part;
                urls.push_back(url);
            } else {
                validURL = false;
                break;
            }
        }

        if (!validURL) {
            std::cout << "Invalid URL format. Please enter valid URLs.\n";
            continue;
        }

        processURLs(size, args, urls);
    }
}
