#include <signal.h>     // sigemptyset, sigaction
#include <stdlib.h>     // exit
#include <stdio.h>      // puts, perror
#include <unistd.h>     // fork
#include <sys/wait.h>   // wait

void graceful(int signum)
{
    printf("Child confirming received signal: %d\n", signum);
    puts("Child about to terminate gracefully...");
    sleep(1);
    puts("Child terminating now...");

    // Fast-track notification of parent
    _exit(0);
}

void set_handler()
{
    struct sigaction current;
    sigemptyset(&current.sa_mask);      // Clear the signal set
    current.sa_flags = 0;               // Enable setting sa_handler, not sa_action
    current.sa_handler = graceful;      // Specify a handler

    // Register the handler
    sigaction(SIGTERM, &current, NULL);
}

void child_code()
{
    set_handler();

    // Loop until interrupted
    while(1) {
        sleep(1);
        puts("Child just woke up, but going back to sleep.");
    }
}

void parent_code(pid_t cpid)
{
    puts("Parent is sleeping so that the child can execute for a while...");
    sleep(5);

    // Try to terminate child
    if (-1 == kill(cpid, SIGTERM)) {
        perror("[ERROR] Failed to kill child process");
        exit(-1);
    }

    // Wait for child to terminate
    wait(NULL);
    puts("My child terminated, about to exit myself...");
}

int main()
{
    // Fork a child process
    pid_t pid = fork();
    if (pid < 0) {
        perror("[ERROR] Failed to fork child process");
        return -1;
    }

    // Child process
    if (0 == pid) {
        child_code();
    }
    // Parent process
    else {
        parent_code(pid);
    }

    return 0;
}