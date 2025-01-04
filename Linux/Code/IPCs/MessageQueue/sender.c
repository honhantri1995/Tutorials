#include <sys/ipc.h>    // ftok
#include <sys/msg.h>    // msgget, msgsnd
#include <stdlib.h>     // exit
#include <stdio.h>      // printf, perror
#include <string.h>     // strcpy

#include "queue.h"

void report_and_exit(const char *msg)
{
    perror(msg);
    exit(-1);   // failure
}

int main()
{
    // 1. Convert a pathname and a project identifier to a System V IPC key
    key_t key = ftok(PATHNAME, PROJECT_ID);
    if (key < 0) {
        report_and_exit("[ERROR] Failed to get IPC key");
    }

    // 2. Get a System V message queue identifier by using IPC key
    // Mode: read/write for user/group/others; create if not exist, otherwise access
    int qid = msgget(key, 0666 | IPC_CREAT);
    if (qid < 0) {
        report_and_exit("[ERROR] Failed to get queue ID");
    }

    char *payloads[] = {"msg1", "msg2", "msg3", "msg4", "msg5", "msg6"};
    int types[] = {1, 1, 2, 2, 3, 3};   // Each must be > 0

    for (int i = 0; i < sizeof(types)/sizeof(types[0]); i++)
    {
        // 3. Build the message
        st_message msg;
        msg.type = types[i];
        strcpy(msg.payload, payloads[i]);

        // 4. Send the message to the queue
        // If sending succeeded, msgsnd() returns 0
        // IPC_NOWAIT: Return immediately if no message of the requested type is in the queue. The msgsnd() fails with errno ENOMSG
        int byte_count = msgsnd(qid, &msg, sizeof(msg), IPC_NOWAIT);
        if (byte_count < 0) {
            perror("[ERROR] Failed to send message to queue");
        }

        printf("%s sent as type %i\n", msg.payload, (int)msg.type);
    }

    return 0;
}