// IsBlackListed.cpp
#include "IsBlackListed.h"
#include "BloomFilter.h"

IsBlacklisted::IsBlacklisted(BloomFilter* filter) : bloomFilter(filter) {}

std::string IsBlacklisted::execute(const std::string& url) {
    // Implement the execute function
    return bloomFilter->isBlacklisted(url);
}

