// ArgsHandler.h
#pragma once

#include <vector>
#include <string>
class ArgsHandler {
public:
    ArgsHandler() = default;

    void printRealArgs(int size, const std::vector<int>& args);
    void readSizeAndArgs(int& size, std::vector<int>& args);
};