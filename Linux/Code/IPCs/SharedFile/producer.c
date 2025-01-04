#include <stdio.h>      // printf, perror
#include <fcntl.h>      // open, write, close, fcntl, flock, perror
#include <unistd.h>     // getpid
#include <string.h>     // strlen

#include "shared_file.h"

#define DATASTRING  "Hello World\n"

int main()
{
    struct flock lock;          // File lock
    lock.l_whence = SEEK_SET;   // Seek from the beginging of the file
    lock.l_start = 0;           // Start at 1st byte in file
    lock.l_len = 0;             // Until EOF
    lock.l_pid = getpid();      // Current process id

    // 1. Open file (mode: read/write, create if not exist)
    int fd = open(FILENAME, O_RDWR | O_CREAT, 0666);
    if (fd < 0) {
        perror("[ERROR] Failed to open file to read/write");
        return -1;
    }

    // 2. Set the file lock before writing to file
    //    The lock here is Write lock (prevent any reading/writing while the file is writing)
    //    and this is an Exclusive Lock
    lock.l_type = F_WRLCK;
    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("[ERROR] Failed to get lock");

        // Close the file descriptor (in abnormal case)
        close(fd);
        return -1;
    }

    // 3. Write data to file
    write(fd, DATASTRING, strlen(DATASTRING));
    printf("Process %d has written to data file...\n", lock.l_pid);

    // 4. Release the file lock after writing finished
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("[ERROR] Failed to get unlock");

        // Close the file descriptor (in abnormal case)
        close(fd);
        return -1;
    }

    // 5. Close the file descriptor (in normal case)
    close(fd);

    return 0;
}
