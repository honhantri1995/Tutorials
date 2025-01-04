#include <sys/socket.h>     // socket, bind, listen, accept
#include <netinet/tcp.h>    // sockaddr_in
#include <arpa/inet.h>      // htonl
#include <unistd.h>         // close
#include <stdlib.h>         // exit
#include <stdio.h>          // printf, perror
#include <string.h>         // strcpy

#include "socket.h"

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    // Create a socket
    int fd = socket(AF_INET,     // Socket type: network socket
                    SOCK_STREAM, // Reliable, bidirectional, flexible payload size
                    0);          // Let the system picks underlying protocol (TCP because of SOCK_STREAM)
    if (fd < 0) {
        report_and_exit("[ERROR] Server failed to create socket");
    }

    // Build a server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;                               // Socket type: network socket
    // server_addr.sin_addr.s_addr = htonl(INADDR_ANY);             // W1: Any IP (host-to-network conversion). Bind to all interfaces - not just "localhost"
    server_addr.sin_addr.s_addr = inet_addr(LOCALHOST_ADDR);        // W2: Localhost IP. Note: This server cannot work with another machine
    server_addr.sin_port = htons(PORT_NO);                          // Port number (host-to-network conversion)

    // Bind the socket to the server address
    if (bind(fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(fd);  // Close server socket
        report_and_exit("[ERROR] Server failed to bind socket to server address");
    }
    printf("Server binded its socket to address %i and port %i\n", ntohl(server_addr.sin_addr.s_addr), ntohs(server_addr.sin_port));

    // Prepare to accept client connection. Allow the server to retry several times if failed.
    if (listen(fd, MAX_CONNECT_RETRY_COUNT) < 0) {
        close(fd);  // Close server socket
        report_and_exit("[ERROR] Server failed to listen for client requests");
    }
    printf("Server is listening clients...\n");

    struct sockaddr_in client_addr;                                    // client address
    int len = sizeof(client_addr);                                     // address length could change

    // Accept client connection
    // By default, blocking WAIT: The server does nothing until a client attempts to connect and then proceeds
    int client_fd = accept(fd, (struct sockaddr*)&client_addr, &len);
    if (client_fd < 0) {
        close(fd);  // Close server socket
        report_and_exit("[ERROR] Server failed to accept client");
    }
    puts("Server accepted client connection");

    // Infinite loop to receive requests from client
    while (1)
    {
        char recv_buffer[BUFFER_SIZE + 1] = {0};

        // Receive request from client
        // By default, blocking WAIT: The server does nothing until received something from client
        int byte_count = read(client_fd, recv_buffer, sizeof(recv_buffer));

        // If receive normally
        if (byte_count > 0) {
            printf("Client request: %s\n", recv_buffer);

            // Build response
            char snd_buffer[BUFFER_SIZE + 1] = {0};
            strcpy(snd_buffer, "OK");

            // Send response back to client
            byte_count = write(client_fd, snd_buffer, sizeof(snd_buffer));

            // If send normally
            if (byte_count > 0 ) {
                printf("Server response: %s\n", snd_buffer);
            }
            // If error
            else {
                close(fd);          // Close server socket
                close(client_fd);   // Close client socket
                report_and_exit("[ERROR] Server failed to send response to client");
            }
        }
        // If error
        else {
            close(fd);          // Close server socket
            close(client_fd);   // Close client socket
            report_and_exit("[ERROR] Server failed to read request from client");
        }
    }

    // Close all sockets
    close(fd);
    close(client_fd);

    return 0;
}