#include <stdio.h>      // printf, per\nror
#include <stdlib.h>     // exit
#include <sys/mman.h>   // mmap, munmap, shm_open, shm_unlink
#include <semaphore.h>  // sem_open, sem_post, sem_close
#include <sys/stat.h>   // For mode constants
#include <fcntl.h>      // For O_* constants
#include <unistd.h>     // ftruncate
#include <string.h>     // strcpy

#include "shared_mem.h"

int shm_alloc(const char* key_name, const char* sem_name, const unsigned int size, const void* data)
{
    // Find a shared memory segment which is currently available
    int shm_idx = -1;
    for (int i = 0; i < MAX_SHM_NUM; i++) {
        if (g_shm_info_list[i].memptr == NULL) {
            shm_idx = i;
            break;
        }
    }
    // If all segment is being in use, return error
    if (shm_idx == -1) {
        return -1;
    }
    printf("Available shared memory segment has index: %d\n", shm_idx);

    // 1. Create and open a new, or open an existing, POSIX shared memory object
    int fd = shm_open(key_name,             // The system will create a backing file at /dev/shm/<key_name>
                      O_RDWR | O_CREAT,     // Mode: read/write, create if needed
                      ACCESS_PERMITSION);   // Access permissions
    if (fd < 0) {
        perror("[ERROR] Failed to open shared memory segment");
        return -1;
    }

    // 2. Allocate some bytes
    ftruncate(fd, size);

    // 3. Get a pointer to the shared memory
    caddr_t memptr = mmap(NULL,                     // Let system pick where to allocate memory in virtual address space
                          size,                     // How many bytes
                          PROT_READ | PROT_WRITE,   // Access protections
                          MAP_SHARED,               // Allocated memory is shareable among processes
                          fd,                       // File descriptor
                          0);                       // Offset: start at 1st byte
    if (memptr == (caddr_t)-1) {
        perror("[ERROR] Failed to get a pointer to the shared memory");
        return -1;
    }

    printf("Shared mem address: %p [0 ... %d]\n", memptr, size - 1);
    printf("Backing file: /dev/shm/%s\n", key_name);

    // 4. Create a new POSIX semaphore, or open an existing semaphore
    sem_t *semptr = sem_open(sem_name,              // Semaphore name (its file is store in the same directory as the backing file)
                             O_CREAT,               // Create the semaphore
                             ACCESS_PERMITSION,     // Protection perms
                             0);                    // Initial value (only this process can access the shared memory)
    if (semptr == (void *)-1) {
        perror("[ERROR] Failed to create/open semaphore");
        return -1;
    }

    // 5. Now let's write bytes to the memory
    memcpy(memptr, data, size);

    // 6. After finished writing, increase the semaphore so that reader processes can read
    if (sem_post(semptr) < 0) {
        perror("[ERROR] Failed to increase the semaphore for reader processes");
        return -1;
    }

    // Store to global shared memory info for later uses
    strcpy(g_shm_info_list[shm_idx].key_name, key_name);
    strcpy(g_shm_info_list[shm_idx].sem_name, sem_name);
    g_shm_info_list[shm_idx].size = size;
    g_shm_info_list[shm_idx].shm_fd = fd;
    g_shm_info_list[shm_idx].memptr = memptr;
    g_shm_info_list[shm_idx].semptr = semptr;

    return 0;
}

int shm_free(const char* key_name, const char* sem_name)
{
    // Find the shared memory segment which has the same key name as the input key name,
    // and the same semaphore name as the input semaphore name,
    unsigned int shm_idx;
    for (int i = 0; i < MAX_SHM_NUM; i++) {
        if ( memcmp(g_shm_info_list[i].key_name, key_name, strlen(key_name)) == 0 ) {
            shm_idx = i;
        }
        else {
            continue;
        }

        if ( memcmp(g_shm_info_list[shm_idx].sem_name, sem_name, strlen(sem_name)) != 0 ) {
            printf("[ERROR] Invalid semaphore name for that key name [%s : %s]\n", g_shm_info_list[shm_idx].sem_name, sem_name);
            return -1;
        }

        break;
    }
    printf("Ready to free shared memory segment of index: %d\n", shm_idx);

    // Free shared memory resource
    munmap(g_shm_info_list[shm_idx].memptr, g_shm_info_list[shm_idx].size);     // Prevent the writer from further access to the shared memory
    close(g_shm_info_list[shm_idx].shm_fd);                                     // Close the file descriptor
    sem_close(g_shm_info_list[shm_idx].semptr);                                 // Close the semaphore
    shm_unlink(key_name);                                                       // Unlink the backing file
    sem_unlink(sem_name);                                                       // Unlink the semaphore file

    // Reset global shared memory info
    memset(g_shm_info_list[shm_idx].key_name, 0, sizeof(g_shm_info_list[shm_idx].key_name));
    memset(g_shm_info_list[shm_idx].sem_name, 0, sizeof(g_shm_info_list[shm_idx].sem_name));
    g_shm_info_list[shm_idx].size = 0;
    g_shm_info_list[shm_idx].shm_fd = 0;
    g_shm_info_list[shm_idx].memptr = NULL;
    g_shm_info_list[shm_idx].semptr = NULL;
}

int main()
{
    char hello[256] = "Hello World";
    char intro[256] = "I am TriHo";
    unsigned int age = 20;

    shm_alloc(KEY_1, SEM_1, sizeof(hello), hello);
    shm_alloc(KEY_2, SEM_2, sizeof(intro), intro);
    shm_alloc(KEY_3, SEM_3, sizeof(age), &age);

    // Give the reader 10 seconds to read. Else, memory will be deleted right after started the writer process
    sleep(10);

    // Free resources
    shm_free(KEY_1, SEM_1);
    shm_free(KEY_2, SEM_2);
    shm_free(KEY_3, SEM_3);
}