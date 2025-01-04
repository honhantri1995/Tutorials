#include <sys/types.h>  // mkfifo
#include <sys/stat.h>   // mkfifo
#include <fcntl.h>      // open, write, close
#include <unistd.h>     // usleep, unlink
#include <stdlib.h>     // rand
#include <stdio.h>      // printf, perror

#include "named_pipe.h"

#define MAX_LOOP        5       // Outer loop
#define CHUNK_SIZE      2       // How many written at a time

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    // Create a named pipe
    // Mode: read/write for user/group/others
    if (mkfifo(PIPE_NAME, 0666) < 0) {
        report_and_exit("[ERROR] Failed to create a named pipe");
    }

    // Open the pipe
    // Mode: Write-only, create if not exist
    // Note: open() will wait unless the pipe is opened at the reader side
    int fd = open(PIPE_NAME, O_CREAT | O_WRONLY);
    if (fd < 0) {
        report_and_exit("[ERROR] Failed to open the named pipe");
    }
    printf("Opened pipe\n");

    // Once the pipe is opened at both the writer and the reader,
    // the writer starts writing to the pipe
    for (int i = 0; i < MAX_LOOP; i++)
    {
        for (int j = 0; j < CHUNK_SIZE; j++)
        {
            int chunk[INTEGER_SIZE];
            for (int k = 0; k < INTEGER_SIZE; k++)
            {
                chunk[k] = rand();
            }

            ssize_t byte_count = write(fd, chunk, sizeof(chunk));
            if (byte_count > 0) {
                printf("Sent bytes: %d %d %d %d\n", chunk[0], chunk[1], chunk[2], chunk[3]);
            }
            else {
                report_and_exit("[ERROR] Failed to write bytes to pipe");
            }
        }

        // Pause a random number of ms for realism
        usleep((rand() % 250) + 1); // 250 ms
    }

    // In total, 768000 4-byte integer values are written to the pipe
    printf("In total, %i bytes sent to the pipe.\n", MAX_LOOP * CHUNK_SIZE * INTEGER_SIZE);

    // Clean up everything
    close(fd);          // Close pipe: generates an end-of-stream marker
    unlink(PIPE_NAME);  // Unlink from the implementing file

    return 0;
}