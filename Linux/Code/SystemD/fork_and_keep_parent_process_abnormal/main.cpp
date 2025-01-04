#include <systemd/sd-daemon.h>

#include <iostream>
#include <unistd.h>     // fork, sleep
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
    }
}

int main() {
    std::cout << "Service " << getpid() << " is running..." << std::endl;

    daemonize();

    // Notify systemd that the service is ready from both parent and child processes
    sd_notify(0, "READY=1");
    std::cout << "Service " << getpid() << " notified READY=1" << std::endl;

    // Simulate work in the child process
    for (int i = 0; i < 4; ++i) {
        sleep(5);

        // Notify systemd that the service is alive (WATCHDOG) from both parent and child processes
        sd_notify(0, "WATCHDOG=1");
        std::cout << "Service " << getpid() << " notified WATCHDOG=1" << std::endl;
    }

    return 0;
}