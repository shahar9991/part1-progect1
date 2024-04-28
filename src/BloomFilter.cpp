#include "BloomFilter.h"
#include "FalsePositive.h"

// bloom filter class

BloomFilter::BloomFilter(size_t size, const std::vector<std::function<size_t(const std::string&)>>& hashFunctions)
        : bitArray(size, false), hashFunctions(hashFunctions) {
    falsePositiveDict = new FalsePositiveDictionary();  // Initialize the FalsePositiveDictionary


}

BloomFilter::~BloomFilter() {
    delete falsePositiveDict;
}
// Definition of BloomFilter functions
std::string BloomFilter::isBlacklisted(const std::string& url) const {
    bool foundInDict = false;
    std::string result;
    // Check if the URL is present in the FalsePositiveDictionary
    foundInDict = falsePositiveDict->SearchUrlInDict(url);
    falsePositiveDict->PrintDictionary();
    // Iterate over hash functions and check bitArray
    bool anyBitFalse = false;
    std::cout<<"foundInDict"<<foundInDict<<std::endl;
    for (const auto& hashFunction : hashFunctions) {
        std::cout<<"loopppp \n";
        size_t index = hashFunction(url) % bitArray.size();
        std::cout << "Setting index2 " << index << " to true for URL2: " << url<<std::endl;
        if (!bitArray[index]) {
            anyBitFalse = true; // If any bit is false, set anyBitFalse to true
            break;  // Exit the loop if a false bit is found
        }
    }

    // Print the result
   // std::cout << (anyBitFalse ? "" : "true ") << (foundInDict ? "true" : "false") << std::endl;
    result=  std::string((anyBitFalse ? "" : "true ")) + std::string((foundInDict ? "true" : "false"));
    std::cout<<"resultttt "<<result<<std::endl;
    return result;

}

//std::string BloomFilter::isBlacklisted(const std::string& url) const {
//    bool foundInDict = false;
//    std::string result;
//
//    // Check if the URL is present in the FalsePositiveDictionary
//    foundInDict = falsePositiveDict->SearchUrlInDict(url);
//
//    // Calculate hash value and index using std::hash<std::string>
//    size_t index = std::hash<std::string>{}(url) % bitArray.size();
//
//    // Print the index and set the result accordingly
//    std::cout << "Setting index " << index << " to true for URL: " << url << std::endl;
//   // result = (bitArray[index] ? "false" : "true") + (foundInDict ? "true" : "false");
//
//    std::cout << "Result: " << result << std::endl;
//
//    return result;
//}

void BloomFilter::addURL(const std::string& url) {
    falsePositiveDict->AddUrlToDict(url);
    falsePositiveDict->PrintDictionary();
    std::cout<<"addUrl\n";
    for (const auto& hashFunction : hashFunctions) {
        std::cout<<"before index\n";
        size_t index = hashFunction(url) % bitArray.size();
        std::cout << "Setting index1 " << index << " to true for URL1: " << url << std::endl;
        // Only set the bit to true if it is not already true
        if (!bitArray[index]) {
            bitArray[index] = true;
           }
      }
}