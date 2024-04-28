
#ifndef FALSE_POSITIVE_H
#define FALSE_POSITIVE_H

#include <unordered_set>
#include <string>
#include <iostream>

class FalsePositiveDictionary {
public:
    void AddUrlToDict(const std::string& url);
    bool SearchUrlInDict(const std::string& url) const;
    void PrintDictionary() const; // Function to print the dictionary


private:
    std::unordered_set<std::string> urlSet;
};

#endif // FALSE_POSITIVE_H