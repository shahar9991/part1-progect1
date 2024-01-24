# part1-project1
link to the repository: https://github.com/shahar9991/part1-progect1.git

## How To Compile And Run The Code:
+ **Prepare the files:** make sure you clone the repository locally with all the cpp and header files.
+ **Compile the code:** open the terminal and make sure the path is to the project's src directory.
  run the command: **"g++ -o BloomFilterApp main.cpp Flow.cpp ArgsHandler.cpp URLsHandler.cpp HashGenerator.cpp BloomFilter.cpp FalsePositive.cpp ICommand.cpp AddURL.cpp IsBlackListed.cpp"**
+ **Run the code:** after compiling successfully, to run the code, in the terminal run the command: **"./BloomFilterApp"**

## Our Work Process:
First, we read toghether the assignment and identified the tasks that need to be done. We used Jira to manage the tasks.
We started with writing tests for the basic functions of the project, such as getting input from the user.
Then we implemented the functions in a simple way so that they pass the tests.
We built the logical flow of the project (classes and functions) and when the code passed all the tests we refactored it. 


### The Refactors We Did
+ **We refactored the hash functions:** In the initial version (version 0) of our code, we had a naive implementation of hash functions that were tightly coupled with the implementation of the Bloom filter. This coupling meant that any changes or additions to the hash functions were directly tied to the Bloom filter, limiting the flexibility and maintainability of our code.
+ In version 1, we made a significant improvement by separating these concerns into two distinct classes: one for hash functions and another for the Bloom filter. This separation allows us to decouple the hash functions from the specific implementation details of the Bloom filter.
+ Now, in version 1, we have the freedom to expand and modify our hash functions independently of the Bloom filter. We can dynamically add as many hash functions to the dataset as needed without being constrained by the Bloom filter's structure. This architectural improvement not only enhances the modularity of our code but also facilitates future enhancements, making it easier to adapt to changing requirements or incorporate new hash functions seamlessly.

+ **We implemented the command design pattern:** We created an interface called IExecutable which has a function "execute" and two classes that implement it: AddURL and IsBlacklisted. 
these two classes have a bloom filter as a member, and this bloom filter object stores the data structure of the filter and the hash functions.
With this design pattern we can execute the wanted command easily.

+ **We implemented a few principles:**
  + **Single responsibility principle-** we divided the code to many classes and functions, each is short and has one clear responsibility.
  + **Open/Closed principle-** by dividing the code to different classes and functions, we can easily add extentions by adding more functions. Implementing the command design pattern also implements this principle.
  + **Interface Segregation Principle-** our IExecutable interface only has one function.
  
