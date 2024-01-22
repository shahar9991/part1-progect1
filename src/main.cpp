//main 
#include "InputHandler.h"
#include "BloomFilter.h"
#include <iostream>
#include <functional>
#include <vector> 

int main(){
    const int arraySize = 3;
    IExecutable* commands[arraySize]; //create an array of commands to execute

    //add executable commands to the commands list
    IExecutable* CreateBloomFilter = new CreateBloomFilter();
    commands[0] = CreateBloomFilter; //create the bloom filter

    IExecutable* AddURL = new AddURL();
    commands[1] = AddURL; //add a new URL adress to the bloom filter, to be blacklisted.

    IExecutable* IsBlackListed = new IsBlackListed();
    commands[2] = IsBlackListed; //check if a given URL adress is in the bloom filter and is blacklisted.

    //run the flow with the commands we created
    Flow flow(commands);
    flow.run();

    //delete all the objects we created on the heap
    delete CreateBloomFilter;
    delete AddURL;
    delete IsBlackListed;
    for (int i = 0; i < arraySize; ++i) {
        delete commands[i];
    }
}