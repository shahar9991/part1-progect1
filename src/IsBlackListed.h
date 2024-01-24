// IsBlacklisted.h
#ifndef ISBLACKLISTED_H
#define ISBLACKLISTED_H

#include "ICommand.h"
#include "BloomFilter.h"
#include <string>

class IsBlacklisted : public ICommand {
public:
    IsBlacklisted(BloomFilter* filter);
    void execute(const std::string& url) override;

private:
    BloomFilter* bloomFilter;
};

#endif // ISBLACKLISTED_H