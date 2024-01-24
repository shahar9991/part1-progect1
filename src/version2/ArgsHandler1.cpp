#include "ArgsHandler1.h"
#include <iostream>
#include <sstream>
#include <algorithm>


std::vector<int> ArgsHandler::PrintRealArgs(int size, const std::vector<int>& args) {
    std::vector<int> distinctArgs;
    for (const auto& arg : args) {
        if (std::find(distinctArgs.begin(), distinctArgs.end(), arg) == distinctArgs.end()) {
            distinctArgs.push_back(arg);
        }
    }

    return distinctArgs;
}


void ArgsHandler::readSizeAndArgs(int& size, std::vector<int>& args) {
    while (true) {
        std::string input;
        std::getline(std::cin, input);

        std::istringstream ss(input);
        ss >> size;

        if (size <= 0) {
            continue;
        }

        args.clear();

        int value;
        while (ss >> value) {
            if (value == 1 || value == 2) {
                args.push_back(value);
            } else {
                args.clear();
                break;
            }
        }

        if (!args.empty()) {
            PrintRealArgs(size, args);
            break;
        }
    }
}

