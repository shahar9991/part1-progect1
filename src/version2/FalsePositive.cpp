// FalsePositive.cpp
#include <ostream>
#include <iostream>
#include "FalsePositive.h"

void FalsePositiveDictionary::AddUrlToDict(const std::string& url) {
    auto result = urlSet.insert(url);
    if (result.second) {
        std::cout << "Added URL: " << url << std::endl;
    }
}

bool FalsePositiveDictionary::SearchUrlInDict(const std::string& url) const {
    bool found = (urlSet.find(url) != urlSet.end());
    // std::cout << "Searching for URL: " << url << ", Found: " << std::boolalpha << found << std::endl;
    return found;
}



