// FalsePositive.cpp
#include <ostream>
#include <iostream>
#include "FalsePositive.h"
//this class contain set to contain the url that added by user.
//add url to the set
void FalsePositiveDictionary::AddUrlToDict(const std::string& url) {
    auto result = urlSet.insert(url);
}
// search if a url is in the set 
bool FalsePositiveDictionary::SearchUrlInDict(const std::string& url) const {
    bool found = (urlSet.find(url) != urlSet.end());
    return found;
}



