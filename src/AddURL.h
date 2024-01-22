#pragma once

#include <vector>
#include <functional>
#include <string>

class AddURL : public IExecutable {
private:
    BloomFilter* bloomFilter;

public:
    AddURL(BloomFilter* bloomFilter) : bloomFilter(bloomFilter){};
    void execute(){};
};