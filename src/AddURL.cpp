// AddURL.cpp
#include "AddURL.h"
#include "BloomFilter.h"

//this class exacute the addurl command.
AddURL::AddURL(BloomFilter* filter) : bloomFilter(filter) {}

void AddURL::execute(const std::string& url) {
    // Implement the execute function
    bloomFilter->addURL(url);
}
