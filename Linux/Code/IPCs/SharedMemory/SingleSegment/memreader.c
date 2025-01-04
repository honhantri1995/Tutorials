#include <stdio.h>      // perror
#include <stdlib.h>     // exit
#include <sys/mman.h>   // mmap, munmap, shm_open, shm_unlink
#include <semaphore.h>  // sem_open, sem_post, sem_close
#include <sys/stat.h>   // For mode constants
#include <fcntl.h>      // For O_* constants
#include <unistd.h>     // ftruncate
#include <string.h>     // strlen

#include "shared_mem.h"

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    // 1. Create and open a new, or open an existing, POSIX shared memory object
    int fd = shm_open(BACKING_FILE,
                      O_RDWR,               // Mode: read/write
                      ACCESS_PERMITSION);   // Access permissions
    if (fd < 0) {
        report_and_exit("[ERROR] Failed to open shared memory segment");
    }

    // 2. Get a pointer to the shared memory
    caddr_t memptr = mmap(NULL,                   // Let system pick where to allocate memory in virtual address space
                          BYTE_SIZE,              // How many bytes
                          PROT_READ | PROT_WRITE, // Access protections
                          MAP_SHARED,             // Allocated memory is shareable among processes
                          fd,                     // File descriptor
                          0);                     // Offset: start at 1st byte
    if (memptr == (caddr_t)-1) {
        report_and_exit("[ERROR] Failed to get a pointer to the shared memory");
    }

    // 3. Create a new POSIX semaphore, or open an existing semaphore
    sem_t *semptr = sem_open(SEM_NAME,              // Semaphore name
                             O_CREAT,               // Create the semaphore
                             ACCESS_PERMITSION,     // Protection perms
                             0);                    // Initial value (only this process can access the shared memory)
    if (semptr == (void *)-1) {
        report_and_exit("[ERROR] Failed to create/open semaphore");
    }

    // 4. Wait for the writer to increase the semaphore
    if (!sem_wait(semptr)) {
        for (int i = 0; i < strlen(DATASTRING); i++) {
            write(STDOUT_FILENO, memptr + i, 1);    // Write one byte at a time to standard output
        }

        // 5. After finished reading, ...
        sem_post(semptr);
    }

    // 6. Clean up everything
    munmap(memptr, BYTE_SIZE);  // Prevent the writer from further access to the shared memory
    close(fd);                  // Close the file descriptor
    sem_close(semptr);          // Close the semaphore
    unlink(BACKING_FILE);       // Unlink the backing file (Note: It's "unlink", not "shm_unlink" as in the memwriter)
    unlink(SEM_NAME);           // Unlink the semaphore file (Note: It's "unlink", not "sem_unlink" as in the memwriter)

    return 0;
}