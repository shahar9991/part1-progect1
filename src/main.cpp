//main 
#include "InputHandler.h"
#include "BloomFilter.h"
#include <iostream>
#include <functional>
#include <vector> 

int main(){
    const int arraySize = 3;
    IExecutable* commands[arraySize];

    IExecutable* CreateBloomFilter = new CreateBloomFilter();
    commands[0] = CreateBloomFilter;

    IExecutable* AddURL = new AddURL();
    commands[1] = AddURL;

    IExecutable* IsBlackListed = new IsBlackListed();
    commands[2] = IsBlackListed;

    Flow flow(commands);
    flow.run();

    delete CreateBloomFilter;
    delete AddURL;
    delete IsBlackListed;
}