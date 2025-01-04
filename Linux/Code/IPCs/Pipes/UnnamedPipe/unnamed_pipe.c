#include <sys/wait.h>   // wait
#include <stdio.h>      // perror
#include <stdlib.h>     // exit
#include <unistd.h>     // read, write, pipe, _exit, fork
#include <string.h>     // strlen

#define READ_END    0
#define WRITE_END   1

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    int pipeFDs[2];                                     // 2 file descriptors (read end and write end of a pipe)
    char buf;                                           // 1-byte buffer
    const char *msg = "Hello World\n";                  // bytes to write

    // Create a pipe without any name
    if (pipe(pipeFDs) < 0) {
        report_and_exit("[ERROR] Failed to create pipes");
    }

    // Fork a child process
    pid_t cpid = fork();
    if (cpid < 0) {
        report_and_exit("[ERROR] Failed to fork child process");
    }

    // If child process
    if (0 == cpid)
    {
        close(pipeFDs[WRITE_END]);                      // Child reads, doesn't write

        // Read until end of byte stream
        while (read(pipeFDs[READ_END], &buf, 1) > 0) {
            write(STDOUT_FILENO, &buf, sizeof(buf));    // Echo to the standard output
        }

        close(pipeFDs[READ_END]);                       // Close the read end: all done

        _exit(0);                                       // Exit and notify parent at once
    }
    // If parent process
    else
    {
        close(pipeFDs[READ_END]);                       // Parent writes, doesn't read

        // Write the bytes to the pipe
        write(pipeFDs[WRITE_END], msg, strlen(msg));
    
        close(pipeFDs[WRITE_END]);                      // Done writing: generate EOF

        wait(NULL);                                     // Wait for child to exit
                                                        // Note: The NULL could be replaced with the address of an integer to hold the child’s exit status

        exit(0);                                        // Exit normally
    }

    return 0;
}