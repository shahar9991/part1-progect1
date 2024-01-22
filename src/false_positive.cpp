//
// Created by user on 21/01/2024.
//

 // if bloom  filter==true:
 //put in dict all the lighten urls,

 //create dict
 //add url to dict
 //check if url is in dict
#include "FalsePositive.h"
#include <iostream>
using namespace std;
string FalsePositiveDictionary::addURL(const std::string& url, const std::string& data) {
    // Check if the URL already exists in the dictionary
    if (dictionary.find(url) == dictionary.end()) {
        // If not, add the URL to the dictionary
        dictionary[url] = data;
        std::cout << "Added URL: " << url << std::endl;
        return "added";
    } else {
        std::cout << "URL already exists in the dictionary." << std::endl;
        return "exist";
    }
}

bool FalsePositiveDictionary::searchURL(const std::string& url) {
// Check if the URL already exists in the dictionary
    if (dictionary.find(url) == dictionary.end()) {
        std::cout << "(Not Blacklisted)\n";
        return false;
    }
    else{
        std::cout << "(Blacklisted)\n";
        return true;
    }
}

void FalsePositiveDictionary::displayDictionary() const {
    // Display the contents of the dictionary
    std::cout << "Dictionary Contents:" << std::endl;
    for (const auto& entry : dictionary) {
        std::cout << "URL: " << entry.first << ", Data: " << entry.second << std::endl;
    }
}
