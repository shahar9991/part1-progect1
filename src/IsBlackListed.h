#pragma once

#include <vector>
#include <functional>
#include <string>

class IsBlackListed : public IExecutable {
private:
    BloomFilter* BloomFilter;

public:
    IsBlackListed(BloomFilter* BloomFilter);
    void execute(const std::string& url){};
};