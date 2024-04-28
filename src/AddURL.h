// AddURL.h
#ifndef ADDURL_H
#define ADDURL_H

#include "ICommand.h"
#include "BloomFilter.h"

class AddURL : public ICommand {
public:
    AddURL(BloomFilter* filter);
    std::string execute(const std::string& url) override;
private:
    BloomFilter* bloomFilter;
};

#endif // ADDURL_H
