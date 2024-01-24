#include <vector>
#include <functional>
#include <iostream>
#include <unordered_set>

class AddURL : public IExecutable {
    private:
        BloomFilter2* bloomFilter;
    public:
        AddURL(BloomFilter2* bloomFilter)
        void execute(const std::string& url){}
}