#define PROJECT_ID          123         // Any positive integer
#define PATHNAME            "queue.h"   // Any existing, accessible file
#define MAX_MSG_LEN         512

typedef struct
{
    long type;                          // Must be of type long
    char payload[MAX_MSG_LEN + 1];      // Max bytes for the message
} st_message;