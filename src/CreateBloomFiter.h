
class CreateBloomFilter : public IExecutable{
    private:
        std::vector<bool> bitArray;
        std::function<size_t(const std::string&)> hashFunction1;
        std::function<size_t(const std::string&)> hashFunction2;

    public:
        CreateBloomFilter(size_t size, std::function<size_t(const std::string&)> hash1, std::function<size_t(const std::string&)> hash2);
};