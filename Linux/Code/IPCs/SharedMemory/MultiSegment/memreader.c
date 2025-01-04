#include <stdio.h>      // per\nror
#include <stdlib.h>     // exit
#include <sys/mman.h>   // mmap, munmap, shm_open, shm_unlink
#include <semaphore.h>  // sem_open, sem_post, sem_close
#include <sys/stat.h>   // For mode constants
#include <fcntl.h>      // For O_* constants
#include <unistd.h>     // ftruncate
#include <string.h>     // strlen

#include "shared_mem.h"

int shm_get(const char* key_name, const char* sem_name, const unsigned int size, void* data)
{
    // 1. Create and open a new, or open an existing, POSIX shared memory object
    int fd = shm_open(key_name,
                      O_RDWR,               // Mode: read/write
                      ACCESS_PERMITSION);   // Access permissions
    if (fd < 0) {
        perror("[ERROR] Failed to open shared memory segment");
        return -1;
    }

    // 2. Get a pointer to the shared memory
    caddr_t memptr = mmap(NULL,                   // Let system pick where to allocate memory in virtual address space
                          size,                   // How many bytes
                          PROT_READ | PROT_WRITE, // Access protections
                          MAP_SHARED,             // Allocated memory is shareable among processes
                          fd,                     // File descriptor
                          0);                     // Offset: start at 1st byte
    if (memptr == (caddr_t)-1) {
        perror("[ERROR] Failed to get a pointer to the shared memory");
        return -1;
    }

    // 3. Create a new POSIX semaphore, or open an existing semaphore
    sem_t *semptr = sem_open(sem_name,              // Semaphore name
                             O_CREAT,               // Create the semaphore
                             ACCESS_PERMITSION,     // Protection perms
                             0);                    // Initial value (only this process can access the shared memory)
    if (semptr == (void *)-1) {
        perror("[ERROR] Failed to create/open semaphore");
        return -1;
    }

    // 4. Wait for the writer to increase the semaphore
    if (!sem_wait(semptr)) {
        // Get data from shared memory
        memcpy(data, memptr, size);

        // 5. After finished reading, ...
        sem_post(semptr);
    }

    // 6. Clean up everything
    munmap(memptr, size);        // Prevent the reader from further access to the shared memory
    close(fd);                   // Close the file descriptor
    sem_close(semptr);           // Close the semaphore
    unlink(key_name);            // Unlink the backing file (Note: It's "unlink", not "shm_unlink" as in the memwriter)
    unlink(sem_name);            // Unlink the semaphore file (Note: It's "unlink", not "sem_unlink" as in the memwriter)

    return 0;
}

int main()
{
    char hello[256];
    char intro[256];
    unsigned int age;

    shm_get(KEY_1, SEM_1, sizeof(hello), hello);
    printf("%s\n", hello);

    shm_get(KEY_2, SEM_2, sizeof(intro), intro);
    printf("%s\n", intro);

    shm_get(KEY_3, SEM_3, sizeof(age), &age);
    printf("%i\n", age);
}