// IsBlackListed.h
#ifndef ISBLACKLISTED_H
#define ISBLACKLISTED_H

#include "ICommand.h"
#include "BloomFilter.h"

class IsBlacklisted : public ICommand {
public:
    IsBlacklisted(BloomFilter* filter);
    std::string execute(const std::string& url) override;
private:
    BloomFilter* bloomFilter;
};

#endif // ISBLACKLISTED_H
