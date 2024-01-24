#ifndef ARGS_HANDLER1_H
#define ARGS_HANDLER1_H

// ArgsHandler.h
#pragma once
#include <vector>
#include <string>

class ArgsHandler {
public:
    ArgsHandler() = default;

    // void printRealArgs(int size, const std::vector<int>& args);
   // void readSizeAndArgs(int& size, std::vector<int>& args);
    void readSizeAndArgs(int& size, std::vector<int>& args, std::istream& input);
    std::vector<int> PrintRealArgs(int size, const std::vector<int>& args);
};

#endif // ARGS_HANDLER1_H
