#ifndef HASH_GENERATOR2_H
#define HASH_GENERATOR2_H

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <functional>

class HashGenerator2 {
public:
    using HashFunction = std::function<size_t(const std::string&)>;

private:
    std::unordered_map<int, HashFunction> hashFunctionMap;
    std::unordered_set<size_t> trueKeysSet;

public:
    HashGenerator2();

    void addTrueKeysToSet(const std::vector<int>& hashFunctionKeys);

    const std::unordered_map<int, HashFunction>& getHashFunctionMap() const;

    const std::unordered_set<size_t>& getTrueKeysSet() const;
};

#endif // HASH_GENERATOR2_H
