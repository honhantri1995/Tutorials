#define MAX_MSG_LEN         512

typedef struct
{
    unsigned int len;           // Message length
    char data[MAX_MSG_LEN];     // Message data
} st_message;
