#include <stdio.h>      // printf, perror
#include <fcntl.h>      // open, write, close, fcntl, flock, perror
#include <unistd.h>     // getpid

#include "shared_file.h"

int main()
{
    struct flock lock;          // File lock
    lock.l_type = F_WRLCK;      // Write lock
    lock.l_whence = SEEK_SET;   // Seek from the beginging of the file
    lock.l_start = 0;           // Start at 1st byte in file
    lock.l_len = 0;             // Until EOF
    lock.l_pid = getpid();      // Current process id

    // 1. Open file (mode: read only)
    int fd = open(FILENAME, O_RDONLY);
    if (fd < 0) {
        perror("[ERROR] Failed to open file to read");
        return -1;
    }

    // 2. Get file lock
    //    If it is not unlocked, return
    fcntl(fd, F_GETLK, &lock);
    if (lock.l_type != F_UNLCK) {
        perror("[ERROR] File is still write locked");

        // Close the file descriptor (in abnormal case)
        close(fd);
        return -1;
    }

    // 3. Set the file lock before reading
    //    The lock here is Read lock (prevent any writing while the file is reading)
    //    and this is a Shared Lock, so other processes can also read the file during the locking
    lock.l_type = F_RDLCK;
    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("[ERROR] Failed to get a read-only lock");

        // Close the file descriptor (in abnormal case)
        close(fd);
        return -1;
    }

    // 4. Read the bytes (they happen to be ASCII codes) one at a time
    char buffer;
    while (read(fd, &buffer, sizeof(buffer)) > 0) {         // 0 signals EOF
        // write(STDOUT_FILENO, &buffer, sizeof(buffer));   // Write one byte to the standard output
        printf("%c", buffer);
    }

    // 5. Release file lock after reading
    lock.l_type = F_UNLCK;
    if (fcntl(fd, F_SETLK, &lock) < 0) {
        perror("[ERROR] Failed to get unlock");

        // Close the file descriptor (in abnormal case)
        close(fd);
        return -1;
    }

    // 6. Close the file descriptor (in normal case)
    close(fd);

    return 0;
}
