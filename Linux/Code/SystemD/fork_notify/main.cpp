#include <systemd/sd-daemon.h>

#include <iostream>
#include <unistd.h>     // fork, sleep
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <csignal>
#include <cstdlib>      // exit

void daemonize() {
    // Fork the process
    pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Fork failed" << std::endl;
        exit(EXIT_FAILURE);
    } 
    
    if (pid > 0) {
        std::cout << "Service " << pid << " was forked succcessfully from service " << getpid() << std::endl;
        std::cout << "Service " << getpid() << " will be stopped here" << std::endl;
        exit(EXIT_SUCCESS); // Parent exits
    }

    // Create a new session and detach from the terminal
    // if (setsid() < 0) {
    //     std::cerr << "Could not create a new session" << std::endl;
    //     exit(EXIT_FAILURE);
    // }

    // // Fork again to ensure the daemon cannot acquire a terminal
    // pid = fork();
    // if (pid < 0) {
    //     std::cerr << "Fork failed" << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // if (pid > 0) {
    //     exit(EXIT_SUCCESS); // First child exits
    // }

    // // Change the working directory to root
    // chdir("/");

    // // Set new file permissions
    // umask(0);

    // Close standard file descriptors
    // close(STDIN_FILENO);
    // close(STDOUT_FILENO);
    // close(STDERR_FILENO);

    // Redirect stdout and stderr to a log file
    // int logFile = open("/var/log/forking_service.log", O_RDWR | O_CREAT | O_APPEND, 0600);
    // dup2(logFile, STDOUT_FILENO);
    // dup2(logFile, STDERR_FILENO);
    // close(logFile);
}

int main() {
    std::cout << "Service " << getpid() << " is running..." << std::endl;

    daemonize();

    // Notify systemd that the service is ready
    sd_notify(0, "READY=1");
    std::cout << "Service " << getpid() << " notified READY=1" << std::endl;

    // Simulate work in the child process
    for (int i = 0; i < 4; ++i) {
        sleep(5);

        // Notify systemd that the service is alive (WATCHDOG)
        sd_notify(0, "WATCHDOG=1");
        std::cout << "Service " << getpid() << " notified WATCHDOG=1" << std::endl;
    }

    return 0;
}