
#ifndef FALSE_POSITIVE_H
#define FALSE_POSITIVE_H

#include <unordered_set>
#include <string>
#include <iostream>

class FalsePositiveDictionary {
public:
    void AddUrlToDict(const std::string& url);
    bool SearchUrlInDict(const std::string& url) const;
    
private:
    std::unordered_set<std::string> urlSet;
};

#endif // FALSE_POSITIVE_H