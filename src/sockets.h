#ifndef SERVER_H
#define SERVER_H

// Declare the function for creating server and accepting client
int get_client_socket();

// Declare the function to handle client connections
void *handle_connection(void *client_socket_ptr);

// Declare the main function for the server logic
int server_main();

#endif // SERVER_H
