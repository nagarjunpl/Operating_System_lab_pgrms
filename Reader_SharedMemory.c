#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int shmid;
    void *shared_memory;

    // Access the existing shared memory (do NOT use IPC_CREAT)
    shmid = shmget((key_t)2345, 1024, 0666);
    if (shmid == -1) {
        perror("shmget failed");
        return 1;
    }

    printf("Shared memory key (ID): %d\n", shmid);

    // Attach memory
    shared_memory = shmat(shmid, NULL, 0);
    if (shared_memory == (void*)-1) {
        perror("shmat failed");
        return 1;
    }

    printf("Process attached at: %p\n", shared_memory);

    printf("Data read from shared memory: %s\n", (char*)shared_memory);

    // Detach
    shmdt(shared_memory);

    // Optional: delete shared memory
    // shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
