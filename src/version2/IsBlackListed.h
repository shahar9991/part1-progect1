#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>

class IsBlackListed : public IExecutable {
    private:
        BloomFilter2* bloomFilter;
    public:
        void execute(const std::string& url){}
}