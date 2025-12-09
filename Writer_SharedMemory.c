#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    void *shared_memory;
    char buffer[100];

    // Create shared memory (key, size, permissions | create)
    shmid = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    printf("Shared memory key (ID): %d\n", shmid);

    // Attach shared memory
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat failed");
        return 1;
    }

    printf("Process attached at: %p\n", shared_memory);

    printf("Enter some data to write into shared memory:\n");
    read(0, buffer, 100);

    // Write data to shared memory
    strcpy(shared_memory, buffer);

    printf("Data written: %s\n", (char *)shared_memory);

    // Detach
    shmdt(shared_memory);

    return 0;
}
