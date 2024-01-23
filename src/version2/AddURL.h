// AddURL.h
#ifndef ADDURL_H
#define ADDURL_H

#include "ICommand.h"
#include "BloomFilter2.h"
#include <string>

class AddURL : public ICommand {
public:
    AddURL(BloomFilter* filter);
    void execute(const std::string& url) override;

private:
    BloomFilter* bloomFilter;
};

#endif // ADDURL_H

