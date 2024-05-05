#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

struct permintaanklien {
    char username[50];
    char containername[50];
    char imagename[50];
    char perintah[100];
    char volume[50];
    int numclients;
};

int main() {
    key_t key = ftok("server.c", 'R');
    int shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    struct permintaanklien *shared_memory = (struct permintaanklien *)shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Enter your username: ");
    scanf("%s", shared_memory->username);
    while (strlen(shared_memory->username) == 0) {
        printf("Username already exists. Please enter a different username: ");
        scanf("%s", shared_memory->username);
    }
    shared_memory->numclients--;
    printf("Enter container name: ");
    scanf("%s", shared_memory->containername);
    printf("Enter image name: ");
    scanf("%s", shared_memory->imagename);
    printf("Enter start command: ");
    scanf("%s", shared_memory->perintah);
    printf("Enter volume: ");
    scanf("%s", shared_memory->volume);
    while (shared_memory->numclients > 0) {
        sleep(1);
    }
    shmdt((void *)shared_memory);
    return 0;
}
