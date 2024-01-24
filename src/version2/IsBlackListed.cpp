// IsBlackListed.cpp
#include "IsBlackListed.h"
#include "BloomFilter2.h"

IsBlacklisted::IsBlacklisted(BloomFilter* filter) : bloomFilter(filter) {}

void IsBlacklisted::execute(const std::string& url) {
    // Implement the execute function
    bloomFilter->isBlacklisted(url);
}