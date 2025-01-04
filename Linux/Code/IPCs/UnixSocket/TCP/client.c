#include <sys/socket.h>     // socket, bind, listen, accept
#include <netinet/tcp.h>    // sockaddr_in
#include <arpa/inet.h>      // htonl
#include <unistd.h>         // write, close
#include <netdb.h>          // gethostbyname
#include <stdlib.h>         // exit
#include <stdio.h>          // printf, perror
#include <string.h>         // strlen

#include "socket.h"

const char *books[] = {"War and Peace",
                       "Pride and Prejudice",
                       "The Sound and the Fury"};

#define MAX_REQUEST_NUM     3

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    // Create a socket
    int sockfd = socket(AF_INET,     // Socket type: network socket
                        SOCK_STREAM, // Reliable, bidirectional, flexible payload size
                        0);          // Let the system picks underlying protocol (TCP because of SOCK_STREAM)
    if (sockfd < 0) {
        report_and_exit("[ERROR] Client failed to create socket");
    }

    // [Optional if the server chooses IP as INADDR_ANY] Get the host address
    struct hostent *hptr = gethostbyname(LOCALHOST_ADDR);
    if (!hptr) {
        close(sockfd);  // Close the socket
        report_and_exit("[ERROR] Client failed to get host address");
    }

    // [Optional if the server chooses IP as INADDR_ANY] If not the same socket type as in server
    if (hptr->h_addrtype != AF_INET) {
        close(sockfd);  // Close the socket
        report_and_exit("[ERROR] Bad address family");
    }

    // Get server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    // server_addr.sin_addr.s_addr = ((struct in_addr *)hptr->h_addr_list[0])->s_addr;  // W1: General way
    server_addr.sin_addr.s_addr = inet_addr(LOCALHOST_ADDR);                            // W2: Specify localhost
    server_addr.sin_port = htons(PORT_NO);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);  // Close the socket
        report_and_exit("[ERROR] Client failed to connect to server");
    }
    printf("Client connected to server at IP %i, about to write some stuff...\n", ntohl(server_addr.sin_addr.s_addr));

    // Finite loop to send request to server and receive response from server
    for (int i = 0; i < MAX_REQUEST_NUM; i++)
    {
        // Build request
        char snd_buffer[BUFFER_SIZE + 1] = {0};
        strcpy(snd_buffer, books[i]);

        // Send request to client
        ssize_t byte_count = write(sockfd, snd_buffer, strlen(snd_buffer));

        // If send normally
        if (byte_count > 0) {
            printf("Client request: %s\n", snd_buffer);

            char recv_buffer[BUFFER_SIZE + 1] = {0};

            // Receive response from server and print out
            // By default, blocking WAIT: The client does nothing until received something from server
            byte_count = read(sockfd, recv_buffer, sizeof(recv_buffer));

            // If receive normally
            if (byte_count > 0) {
                printf("Server response: %s\n", recv_buffer);
            }
            // If error
            else {
                close(sockfd);  // Close the socket
                report_and_exit("[ERROR] Client failed to read response from server");
            }
        }
        // If error
        else {
            close(sockfd);      // Close the socket
            report_and_exit("[ERROR] Client failed to send request to server");
        }
    }

    printf("Client done, about to exit");

    // Close the socket
    close(sockfd);

    return 0;
}