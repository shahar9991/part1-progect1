#include "InputHandler.h"

//this class represents the flow of the program- getting input from the user and calling the right functions.
class Flow{
    private:
        IExecutable* commands[]; //list of commands to execute.

    public:
        Flow(IExecutable* commands[]) : commands(commands) {}
        void run(){ //run the program
            while (true) {
                //InputHandler- get the input and make sure it is OK
                //according to the input- understand which command needs to be executed
                task = InputHandler();
                try {
                    commands[task]->execute();
                    }
                catch(...){}
            }
        }
}