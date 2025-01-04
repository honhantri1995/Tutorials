#include <unistd.h>     // read, write, pipe, fork, sleep
#include <fcntl.h>      // fcntl
#include <stdlib.h>     // exit
#include <stdio.h>      // printf
#include <errno.h>      // errno

#define READ_END        0
#define WRITE_END       1
#define BUFFER_SIZE     512

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

void child_read(int pipeFDs[])
{
    int read_byte;
    char buf[BUFFER_SIZE];

    // Child reads, doesn't write
    close(pipeFDs[WRITE_END]);

    while (1)
    {
        read_byte = read(pipeFDs[READ_END], buf, BUFFER_SIZE);

        // If error
        if (read_byte < 0) {
            if (errno == EAGAIN) {
                printf("[ERROR] Pipe is empty\n");
                sleep(1);   // Prevent child from printing too many logs while parent is sleeping
            }
            else {
                report_and_exit("[ERROR] Child failed to read from pipe");
            }
        }
        // If finished (child received EOF, or parent exits)
        else if (read_byte == 0) {
            printf("Child received EOF. All bytes are read\n");

            // Close the read end
            close(pipeFDs[READ_END]);
        }
        // If read normally
        else {
            printf("Child read %s\n", buf);
        }
    }
}

void parent_write(int pipeFDs[])
{
    // Parent writes, doesn't read
    close(pipeFDs[READ_END]);

    char* msg1 = "hello";
    char* msg2 = "bye";

    // Write "hello" 3 times in 3-second interval
    for (int i = 0; i < 3; i++) {
        write(pipeFDs[WRITE_END], msg1, BUFFER_SIZE);
        printf("Parent wrote %s\n", msg1);

        // Let the parent sleep for a while to see what the child will do
        sleep(3);
    }

    // Write "bye" one time
    write(pipeFDs[WRITE_END], msg2, BUFFER_SIZE);
    printf("Parent wrote %s\n", msg2);

    // Close the write end (generate EOF)
    close(pipeFDs[WRITE_END]);
    printf("Parent generated EOF and closed write end\n");
}

int main()
{
    int pipeFDs[2];         // 2 file descriptors (read end and write end of a pipe)

    // Create an unnamed pipe
    if (pipe(pipeFDs) < 0) {
        report_and_exit("[ERROR] Failed to create pipes");
    }

    // Set read end as non-blocking
    // So instead of blocking and waiting for the write end, the read end will keep running and enter case empty pipe
    if (fcntl(pipeFDs[READ_END], F_SETFL, O_NONBLOCK) < 0) {
        report_and_exit("[ERROR] Failed to set pipe non-blocking");
    }
    /* Note:
        If the pipe is blocking (by default), the program output will be:
            Parent wrote hello
            Child read hello
            Parent wrote hello
            Child read hello
            Parent wrote hello
            Child read hello
            Parent wrote bye
            Parent generated EOF and closed write end
            Child read bye
            Child received EOF. All bytes are read
            [ERROR] Child failed to read from pipe
            : Bad file descriptor
            Program ended
    */

    // Fork a child process
    pid_t cpid = fork();
    if (cpid < 0) {
        report_and_exit("[ERROR] Failed to fork child process");
    }

    // If child process
    if (0 == cpid) {
        child_read(pipeFDs);
    }
    // If parent process
    else {
        parent_write(pipeFDs);
    }

    // Wait for child generate EOF
    sleep(1);
    printf("Program ended\n");

    return 0;
}

/* Program output:
        Parent wrote hello
        Child read hello
        [ERROR] Pipe is empty
        [ERROR] Pipe is empty
        [ERROR] Pipe is empty
        Parent wrote hello
        Child read hello
        [ERROR] Pipe is empty
        [ERROR] Pipe is empty
        [ERROR] Pipe is empty
        Parent wrote hello
        Child read hello
        [ERROR] Pipe is empty
        [ERROR] Pipe is empty
        [ERROR] Pipe is empty
        Parent wrote bye
        Parent generated EOF and closed write end
        Child read bye
        Child received EOF. All bytes are read
        [ERROR] Child failed to read from pipe
        : Bad file descriptor
        Program ended
*/