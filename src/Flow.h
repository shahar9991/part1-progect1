#ifndef FLOW_H
#define FLOW_H

#include "HashGenerator.h"
#include "BloomFilter.h"

class Flow {
//private:
    static HashGenerator2 hashGenerator; // Declare the static member
//    static BloomFilter bloomFilter; // Declare the static member
    static std::vector<std::function<size_t(const std::string &)>> hashFunctions; // Declare the static member
    static BloomFilter* bloomFilter;





public:
    static void run(const char* buffer,char* response_buffer);

};


#endif // FLOW_H


