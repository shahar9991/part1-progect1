#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>

using namespace std;

int get_client_socket() {
    const int server_port =54324;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return -1; // Return an error code
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return -1; // Return an error code
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return -1; // Return an error code
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock;
    client_sock = accept(sock, (struct sockaddr*)&client_sin, &addr_len);
    if (client_sock < 0) {
        perror("error accepting client");
        close(sock);
        return -1; // Return an error code
    }

    close(sock); // Close the server socket, as we only need the client socket
    std::cout<<client_sock;
    return client_sock;
}

void *handle_connection(void *client_socket_ptr) {
    int client_sock = *((int *)client_socket_ptr);
    char buffer[4096];
    int expected_data_len = sizeof(buffer);

    while (true) {
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            cout << "Client closed the connection\n";
            break;
        } else if (read_bytes < 0) {
            perror("error reading from client");
            break;
        } else {
            cout << "Read " << read_bytes << " bytes from client: " << buffer << endl;
        }

        int sent_bytes = send(client_sock, buffer, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
            break;
        }
    }

    close(client_sock);
    pthread_exit(NULL);
}


int main() {
    int client_sock = get_client_socket();
    if (client_sock < 0) {
        return 1; // Exit if an error occurred during socket creation or client acceptance
    }

    // Now you have the client socket (client_sock), you can proceed with your logic
    pthread_t tid;
    if (pthread_create(&tid, NULL, handle_connection, (void *)&client_sock) != 0) {
        perror("error creating thread");
        close(client_sock);
        return 1; // Exit if an error occurred during thread creation
    }

    pthread_join(tid, NULL); // Wait for the thread to finish
    return 0;
}