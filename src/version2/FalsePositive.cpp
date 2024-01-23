// FalsePositive.cpp
#include <ostream>
#include <iostream>
#include "FalsePositive.h"

void FalsePositiveDictionary::AddUrlToDict(const std::string& url) {
    auto result = urlSet.insert(url);
    if (result.second) {
        std::cout << "Added URL: " << url << std::endl;
    } else {
        std::cout << "URL already exists in the set." << std::endl;
    }
}

bool FalsePositiveDictionary::SearchUrlInDict(const std::string& url) const {
    bool found = (urlSet.find(url) != urlSet.end());
    std::cout << "Searching for URL: " << url << ", Found: " << std::boolalpha << found << std::endl;
    return found;
}

void FalsePositiveDictionary::DisplayAllUrls() const {
    std::cout << "All URLs in the set:\n";
    for (const auto& url : urlSet) {
        std::cout << url << "\n";
    }
}

// #include "FalsePositive.h"

// void FalsePositiveDictionary::AddUrlToDict(const std::string& url) {
//     auto result = urlSet.insert(url);
//     if (result.second) {
//         std::cout << "Added URL: " << url << std::endl;
//     } else {
//         std::cout << "URL already exists in the set." << std::endl;
//     }
// }

// bool FalsePositiveDictionary::SearchUrlInDict(const std::string& url) const {
//     return (urlSet.find(url) != urlSet.end());
// }
// void FalsePositiveDictionary::DisplayAllUrls() const {
//     std::cout << "All URLs in False Positive Dictionary:\n";
//     for (const auto& url : urlSet) {
//         std::cout << url << "\n";
//     }
// }