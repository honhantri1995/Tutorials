#include <fcntl.h>      // open, read, close
#include <unistd.h>     // usleep, unlink
#include <stdlib.h>     // rand
#include <stdio.h>      // printf, perror
#include <string.h>     // strcpy

#include "named_pipe.h"
#include "message_IF.h"

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    // Open the pipe created by the writer. If the pipe have not created, report failed
    // Mode: Read-only
    // Note: open() will wait unless the pipe is opened (not created) at the writer side
    int fd = open(PIPE_NAME, O_RDONLY);
    if (fd < 0) {
        report_and_exit("[ERROR] Failed to open named pipe");
    }
    printf("Opened pipe\n");

    // Infinite loop to read from the pipe
    while (1)
    {
        // Array of received bytes read from the pipe
        char recv_bytes[PIPE_SIZE] = {0};

        // Read from the pipe
        // Note: Because this pipe is blocking, read() will wait if the pipe is empty
        ssize_t byte_count = read(fd, &recv_bytes, sizeof(recv_bytes));

        // If read error
        if (byte_count < 1) {
            report_and_exit("[ERROR] Failed to read byte from pipe");
        }
        // If end of steam
        else if (byte_count == 0) {
            break;
        }
        // If read normally
        else {
            printf("\nReceived byte count: %ld, message data: ", byte_count);

            char* p_recv_bytes = recv_bytes;            // Pointer to array of received bytes
            int left_byte_count = (int)byte_count;
            unsigned int msg_len = 0;
            char msg_data[MAX_MSG_LEN] = {0};

            // Array of received bytes might contain multiple messages,
            // so we need an inner loop to separate individual message (based on message length) from received bytes
            do {
                p_recv_bytes = p_recv_bytes + msg_len;                  // Update pointer to the next message

                // Parse recieved bytes and get individual message
                msg_len = *((unsigned int*)p_recv_bytes);               // Message length
                strcpy(msg_data, p_recv_bytes + sizeof(unsigned int));  // Message data
                printf("\"%s\", ", msg_data);

                left_byte_count -= msg_len;                     // Update byte count which is remained in the received bytes
            }
            while (left_byte_count > 0);
        }
    }

    // Clean up everything
    close(fd);          // Close pipe: generates an end-of-stream marker
    unlink(PIPE_NAME);  // Unlink from the implementing file

    return 0;
}