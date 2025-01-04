#include <systemd/sd-daemon.h>

#include <iostream>
#include <unistd.h>
#include <signal.h>

int main() {
    // Notify systemd that the service is starting
    // sd_notify(0, "READY=1");

    // Simulate some work being done
    std::cout << "Service is running..." << std::endl;

    for (int i = 0; i < 2; ++i) {
        sleep(5);

        // Notify systemd that the service is still alive (WATCHDOG)
        sd_notify(0, "WATCHDOG=1");
    }

    // Notify systemd that the service is stopping (optional)
    sd_notify(0, "STOPPING=1");

    return 0;
}
