#include <sys/ipc.h>    // ftok
#include <sys/msg.h>    // msgget, msgctl
#include <stdio.h>      // printf, perror
#include <stdlib.h>     // exit

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

    int types[] = {3, 1, 2, 1, 3, 2};   // Different than in sender

    for (int i = 0; i < sizeof(types)/sizeof(types[0]); i++)
    {
        st_message msg;

        // 3. Receive the message from the queue
        // IPC_NOWAIT: Return immediately if no message of the requested type is in the queue. The msgsnd() fails with errno ENOMSG
        // MSG_NOERROR: Truncate the message text if longer than msgsz bytes (and the truncated part will be lost)
        ssize_t byte_count = msgrcv(qid, &msg, sizeof(msg), types[i], MSG_NOERROR | IPC_NOWAIT);
        if (byte_count < 0) {
            perror("[ERROR] Failed to get message from queue");
            break;
        }

        printf("%s received as type %i\n", msg.payload, (int)msg.type);
    }

    // 4. Remove the queue
    if (msgctl(qid, IPC_RMID, NULL) < 0) {
        report_and_exit("[ERROR] Failed to remove queue");
    }

    return 0;
}