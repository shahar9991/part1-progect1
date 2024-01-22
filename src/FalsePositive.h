//
// Created by user on 21/01/2024.
//
#ifndef FALSE_POSITIVE_H
#define FALSE_POSITIVE_H

#include <unordered_map>
#include <string>
using namespace std;
class FalsePositiveDictionary {
public:
    // Function to add a URL to the dictionary
    string addURL(const std::string& url, const std::string& data);

    // Function to search a URL in the dictionary
    bool searchURL(const std::string& url);

    // Function to display the contents of the dictionary
    void displayDictionary() const;

private:
    // Internal storage for the dictionary
    std::unordered_map<std::string, std::string> dictionary;
};

#endif // FALSE_POSITIVE_H

