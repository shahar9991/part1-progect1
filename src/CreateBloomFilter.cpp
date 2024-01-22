
class CreateBloomFilter : public IExecutable{
    private:
        std::vector<bool> bitArray;
        std::function<size_t(const std::string&)> hashFunction1;
        std::function<size_t(const std::string&)> hashFunction2;

    public:
        
};