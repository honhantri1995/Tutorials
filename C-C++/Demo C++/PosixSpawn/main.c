#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <unistd.h>
#include <spawn.h>
#include <sys/wait.h>

extern char **environ;

int run_cmd(char *cmd)
{
    printf("Run command: %s\n", cmd);

    pid_t pid;
    char *argv[] = {"sh", "-c", cmd, NULL};

    int status = posix_spawn(&pid, "/bin/sh", NULL, NULL, argv, environ);
    if (status == 0) {
        printf("Child pid: %i\n", pid);
        do {
            if (waitpid(pid, &status, 0) != -1) {
                printf("status: %d\n", status);
                printf("WEXITSTATUS(status): %d\n", WEXITSTATUS(status));
                return status;
            } else {
                perror("Error");
                return -1;
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    } else {
        printf("status: %d\n", status);
        printf("strerror(status): %s\n", strerror(status));
        return status;
    }
}

void main(int argc, char* argv[])
{
    int ret = run_cmd(argv[1]);
    if (ret != 0) {
        perror("Error\n");
    }
    else {
        printf("OK\n");
    }
    return;
}