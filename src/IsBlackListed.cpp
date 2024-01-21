#pragma once

#include <vector>
#include <functional>
#include <string>

class IsBlackListed : public IExecutable {
private:
    std::vector<bool> bitArray;
    std::function<size_t(const std::string&)> hashFunction1;
    std::function<size_t(const std::string&)> hashFunction2;

public:
    void execute(const std::string& url){
        size_t index1 = hashFunction1(url) % bitArray.size();
        size_t index2 = hashFunction2(url) % bitArray.size();
        return bitArray[index1] && bitArray[index2];
    }
};