#define ACCESS_PERMITSION       0644    // read, write, execute for owner/group/other
#define MAX_SHM_NUM             100     // Max number of shared memory segment the program allows

// Keys of shared memory
#define KEY_1                   "shm_1"
#define KEY_2                   "shm_2"
#define KEY_3                   "shm_3"

// Names of semaphore
#define SEM_1                   "sem_1"
#define SEM_2                   "sem_2"
#define SEM_3                   "sem_3"

// All neccessary info for a shared memory segment
typedef struct
{
    caddr_t memptr;
    int shm_fd;
    sem_t* semptr;
    char key_name[256];
    char sem_name[256];
    unsigned int size;
} shm_info;

// Array to store all shared memory segments of the program
shm_info g_shm_info_list[MAX_SHM_NUM];