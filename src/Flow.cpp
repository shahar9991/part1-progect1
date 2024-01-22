#include "InputHandler.h"
#include <iostream>

//this class represents the flow of the program- getting input from the user and calling the right functions.
class Flow{
    private:
        map<string, IExecutable*> commands; //map of commands to execute.
        InputHandler* inputHandler;

    public:
        Flow(InputHandler* inputHandler, map<string, IExecutable*> commands;) : inputHandler(inputHandler), commands(commands) {}
        void run(){ //run the program
            while (true) {
                //InputHandler- get the input and make sure it is OK
                //according to the input- understand which command needs to be executed
                std::string task = InputHandler->handle_input();
                try {
                    commands[task]->execute(); //try to execute the required task from the commands list.
                    }
                catch(...){}
            }
        }
}