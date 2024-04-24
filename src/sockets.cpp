
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "Flow.h"

using namespace std;

void *handle_connection(void *client_socket_ptr) {
    int client_sock = *((int *)client_socket_ptr);
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        close(client_sock);
    } else if (read_bytes < 0) {
        perror("error reading from client");
    } else {
        cout<<buffer<<std::endl;
        Flow::run(buffer);
    }
    int sent_bytes = send(client_sock, buffer, read_bytes, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
    close(client_sock);
    pthread_exit(NULL);
}

int main() {
    const int server_port = 54322;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
        return 1;
    }

    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
        return 1;
    }

    while (true) {
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock;
        client_sock = accept(sock, (struct sockaddr*)&client_sin, &addr_len);
        if (client_sock < 0) {
            perror("error accepting client");
            // delete client_sock;
            continue;
        }

        pthread_t tid;
        if (pthread_create(&tid, NULL, handle_connection, (void *)&client_sock) != 0) {
            perror("error creating thread");
            //delete client_sock;
            close(client_sock);
        }
    }

    close(sock);
        return 0;
}