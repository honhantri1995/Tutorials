#include <fcntl.h>      // open, read, close
#include <unistd.h>     // usleep, unlink
#include <stdlib.h>     // rand
#include <stdio.h>      // printf, perror

#include "named_pipe.h"

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

    unsigned total_byte_count = 0;

    // Infinite loop to read from the pipe
    while (1)
    {
        int recv_bytes;

        // Read from the pipe
        // Note: Because this pipe is blocking, read() will wait if the pipe is empty
        ssize_t byte_count = read(fd, &recv_bytes, INTEGER_SIZE);
        printf("Received bytes: %d\n", recv_bytes);

        // If read error
        if (byte_count < 0) {
            report_and_exit("[ERROR] Failed to read bytes from pipe");
        }
        // If end of steam
        else if (byte_count == 0) {
            break;
        }
        // If read normally
        else {
            // Read a 4-byte int value
            total_byte_count++;
        }
    }

    printf("In total, received %u bytes.\n", total_byte_count);

    // Clean up everything
    close(fd);          // Close pipe: generates an end-of-stream marker
    unlink(PIPE_NAME);  // Unlink from the implementing file

    return 0;
}