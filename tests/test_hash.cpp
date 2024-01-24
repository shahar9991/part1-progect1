// hash_generator_test.cpp
#include <gtest/gtest.h>
#include "../src/version2/HashGenerator2.cpp" // Include the code to be tested

// Test for the scenario when only HashFunction1 is used
TEST(HashGenerator2Test, AddTrueKeysToSet_HashFunction1) {
    HashGenerator2 hashGenerator;
    std::vector<int> hashFunctionKeys = {1};
    hashGenerator.addTrueKeysToSet(hashFunctionKeys);

    const auto& trueKeysSet = hashGenerator.getTrueKeysSet();
    EXPECT_TRUE(trueKeysSet.find(hashGenerator.getHashFunctionMap().at(1)("example_string")) != trueKeysSet.end());
}

// Test for the scenario when only HashFunction2 is used
TEST(HashGenerator2Test, AddTrueKeysToSet_HashFunction2) {
    HashGenerator2 hashGenerator;
    std::vector<int> hashFunctionKeys = {2};
    hashGenerator.addTrueKeysToSet(hashFunctionKeys);

    const auto& trueKeysSet = hashGenerator.getTrueKeysSet();
    EXPECT_TRUE(trueKeysSet.find(hashGenerator.getHashFunctionMap().at(2)("example_string")) != trueKeysSet.end());
}

// Test for the scenario when both HashFunction1 and HashFunction2 are used
TEST(HashGenerator2Test, AddTrueKeysToSet_MultipleHashFunctions) {
    HashGenerator2 hashGenerator;
    std::vector<int> hashFunctionKeys = {1, 2};
    hashGenerator.addTrueKeysToSet(hashFunctionKeys);

    const auto& trueKeysSet = hashGenerator.getTrueKeysSet();
    EXPECT_TRUE(trueKeysSet.find(hashGenerator.getHashFunctionMap().at(1)("example_string")) != trueKeysSet.end());
    EXPECT_TRUE(trueKeysSet.find(hashGenerator.getHashFunctionMap().at(2)("example_string")) != trueKeysSet.end());
}

// Test for the scenario when an empty set of hash function keys is provided
TEST(HashGenerator2Test, AddTrueKeysToSet_EmptyHashFunctionKeys) {
    HashGenerator2 hashGenerator;
    std::vector<int> hashFunctionKeys;
    hashGenerator.addTrueKeysToSet(hashFunctionKeys);

    const auto& trueKeysSet = hashGenerator.getTrueKeysSet();
    EXPECT_TRUE(trueKeysSet.empty());
}

// Test for the scenario when a duplicate hash function key is provided
TEST(HashGenerator2Test, AddTrueKeysToSet_DuplicateHashFunctionKey) {
    HashGenerator2 hashGenerator;
    std::vector<int> hashFunctionKeys = {1, 1};  // Duplicate key
    hashGenerator.addTrueKeysToSet(hashFunctionKeys);

    const auto& trueKeysSet = hashGenerator.getTrueKeysSet();
    EXPECT_TRUE(trueKeysSet.find(hashGenerator.getHashFunctionMap().at(1)("example_string")) != trueKeysSet.end());
    EXPECT_EQ(trueKeysSet.size(), 1);  // Should only contain unique keys
}