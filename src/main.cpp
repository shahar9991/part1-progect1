//main 
#include "InputHandler.h"
#include "BloomFilter.h"
#include <iostream>
#include <functional>
#include <vector> 

int main(){
    map<string, IExecutable*> commands; //create an array of commands to execute
    InputHandler* inputHandler = new InputHandler;
    
    //initiate the Bloom Filter
    inputHandler->getSizeAndArgs();
    BloomFilter* bloomFilter = new BloomFilter(); //create the bloom filter

    //add executable commands to the commands list
    IExecutable* AddURL = new AddURL();
    commands["add URL"] = AddURL; //add a new URL adress to the bloom filter, to be blacklisted.

    IExecutable* IsBlackListed = new IsBlackListed();
    commands["is blacklisted"] = IsBlackListed; //check if a given URL adress is in the bloom filter and is blacklisted.

    //run the flow with the commands we created
    Flow flow(inputHandler, commands);
    flow.run();

    //delete all the objects we created on the heap
    delete bloomFilter;
    delete AddURL;
    delete IsBlackListed;
    for (int i = 0; i < arraySize; ++i) {
        delete commands[i];
    }
}