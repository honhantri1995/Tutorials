#include <sys/types.h>  // mkfifo
#include <sys/stat.h>   // mkfifo
#include <fcntl.h>      // open, write, close
#include <unistd.h>     // usleep, unlink
#include <stdlib.h>     // rand
#include <stdio.h>      // printf, perror
#include <string.h>     // strcpy

#include "named_pipe.h"
#include "message_IF.h"

#define MAX_LOOP        1000

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

    // Build message 1
    st_message msg1;
    msg1.len = sizeof(st_message);
    strcpy(msg1.data, "Message 1");

    // Build message 2
    st_message msg2;
    msg2.len = sizeof(st_message);
    strcpy(msg2.data, "Message 2");

    // Finite loop to write message to pipe
    for (int i = 0; i < MAX_LOOP; i++)
    {
        write(fd, &msg1, sizeof(msg1));
        printf("Sent msg1\n");

        write(fd, &msg2, sizeof(msg2));
        printf("Sent msg2\n");
        // usleep(100);       // 0.1 ms
    }

    // Clean up everything
    close(fd);          // Close pipe: generates an end-of-stream marker
    unlink(PIPE_NAME);  // Unlink from the implementing file

    return 0;
}