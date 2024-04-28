# include "Flow.h"
#include "sockets.h" // Include the sockets header file
#include <iostream>

//this is the main run the flow
int main() {
    std::cout<<"hi";
    // Create and run the server
    int client_sock = get_client_socket();
    Flow::run(client_sock);
    return 0;
}