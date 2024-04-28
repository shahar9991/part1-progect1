#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "Flow.h"
#include <cstring>
#include <sstream>


using namespace std;

int temp=0;
bool hashFunctionsInitialized = false;

void *handle_connection(void *client_socket_ptr) {
    int client_sock = *((int *) client_socket_ptr);
    char buffer[4096];
    while (true) {
        memset(buffer, 0, sizeof(buffer));
        int read_bytes = recv(client_sock, buffer, sizeof(buffer), 0);
        if (read_bytes == 0) {
            // Client disconnected
            break;
        } else if (read_bytes < 0) {
            perror("error reading from client");
            break;
        } else {
            // Process the received data
            std::string result;
            char response_buffer[4096];
            std::vector<std::string> separated;
            std::istringstream iss(buffer);
            std::string token;
            std::string bitsNumber;
            while (std::getline(iss, token, ',')) {
                separated.push_back(token);
            }
            std::string firstPart= separated[0];
            std::istringstream ss(firstPart);
            ss >> bitsNumber;
            int intBitsNumber = std::stoi(bitsNumber);

            std::cout << "temp: " << temp << std::endl;
            if(temp<intBitsNumber) {
                temp=intBitsNumber;
            }
            std::cout << "size1: " << bitsNumber << std::endl;
//            HashGenerator2 hashGenerator;
//            std::vector<std::function<size_t(const std::string &)>> hashFunctions;


            Flow::run(buffer, response_buffer);

            // Send the response back to the client
            int sent_bytes = send(client_sock, response_buffer, read_bytes, 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
                break;
            }
        }
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
