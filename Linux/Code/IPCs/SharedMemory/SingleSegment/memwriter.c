#include <stdio.h>      // printf, perror
#include <stdlib.h>     // exit
#include <sys/mman.h>   // mmap, munmap, shm_open, shm_unlink
#include <semaphore.h>  // sem_open, sem_post, sem_close
#include <sys/stat.h>   // For mode constants
#include <fcntl.h>      // For O_* constants
#include <unistd.h>     // ftruncate
#include <string.h>     // strcpy

#include "shared_mem.h"

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    // 1. Create and open a new, or open an existing, POSIX shared memory object
    int fd = shm_open(BACKING_FILE,         // The system will create a backing file at /dev/shm/<BACKING_FILE>
                      O_RDWR | O_CREAT,     // Mode: read/write, create if needed
                      ACCESS_PERMITSION);   // Access permissions
    if (fd < 0) {
        report_and_exit("[ERROR] Failed to open shared memory segment");
    }

    // 2. Allocate some bytes
    ftruncate(fd, BYTE_SIZE);

    // 3. Get a pointer to the shared memory
    caddr_t memptr = mmap(NULL,                   // Let system pick where to allocate memory in virtual address space
                          BYTE_SIZE,              // How many bytes
                          PROT_READ | PROT_WRITE, // Access protections
                          MAP_SHARED,             // Allocated memory is shareable among processes
                          fd,                     // File descriptor
                          0);                     // Offset: start at 1st byte
    if (memptr == (caddr_t)-1) {
        report_and_exit("[ERROR] Failed to get a pointer to the shared memory");
    }

    printf("Shared mem address: %p [0 ... %d]\n", memptr, BYTE_SIZE - 1);
    printf("Backing file: /dev/shm/%s\n", BACKING_FILE);

    // 4. Create a new POSIX semaphore, or open an existing semaphore
    sem_t *semptr = sem_open(SEM_NAME,              // Semaphore name (its file is store in the same directory as the backing file)
                             O_CREAT,               // Create the semaphore
                             ACCESS_PERMITSION,     // Protection perms
                             0);                    // Initial value (only this process can access the shared memory)
    if (semptr == (void *)-1) {
        report_and_exit("[ERROR] Failed to create/open semaphore");
    }

    // 5. Now let's write some bytes to the memory
    strcpy(memptr, DATASTRING);

    // 6. After finished writing, increase the semaphore so that reader processes can read
    if (sem_post(semptr) < 0) {
        report_and_exit("[ERROR] Failed to increase the semaphore for reader processes");
    }

    // Give the reader 5 seconds to read. Else, memory will be deleted right after started the writer process
    sleep(5);

    // 7. Clean up everything
    munmap(memptr, BYTE_SIZE);  // Prevent the writer from further access to the shared memory
    close(fd);                  // Close the file descriptor
    sem_close(semptr);          // Close the semaphore
    shm_unlink(BACKING_FILE);   // Unlink the backing file
    sem_unlink(SEM_NAME);       // Unlink the semaphore file

    return 0;
}