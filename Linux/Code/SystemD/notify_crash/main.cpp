#include <systemd/sd-daemon.h>

#include <iostream>
#include <unistd.h>
#include <signal.h>

int main() {
    // Notify systemd that the service is starting
    sd_notify(0, "READY=1");

    // Simulate some work being done
    std::cout << "Service is running..." << std::endl;

    // You can simulate periodic work by sleeping or doing actual work
    for (int i = 0; i < 2; ++i) {
        sleep(5); // Simulate work by sleeping

        sd_notify(0, "WATCHDOG=1");
    }

    // Trigger a crash
    int* pointer = nullptr;
    int value = *pointer;

    // Notify systemd that the service is stopping (optional)
    sd_notify(0, "STOPPING=1");

    return 0;
}




