// // FalsePositive.h
// #ifndef FALSE_POSITIVE_H
// #define FALSE_POSITIVE_H

// #include <unordered_set>
// #include <string>
// #include <iostream>

// class FalsePositiveDictionary {
// public:
//     void AddUrlToDict(const std::string& url);
//     bool SearchUrlInDict(const std::string& url) const;
//     void DisplayAllUrls() const; // New function to display all URLs

// private:
//     std::unordered_set<std::string> urlSet;
// };

// #endif // FALSE_POSITIVE_H
// FalsePositive.h
#ifndef FALSE_POSITIVE_H
#define FALSE_POSITIVE_H

#include <unordered_set>
#include <string>
#include <iostream>

class FalsePositiveDictionary {
public:
    void AddUrlToDict(const std::string& url);
    bool SearchUrlInDict(const std::string& url) const;
    void DisplayAllUrls() const; // Function to display all URLs (you can add this function)

private:
    std::unordered_set<std::string> urlSet;
};

#endif // FALSE_POSITIVE_H