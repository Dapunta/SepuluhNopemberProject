#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

struct permintaanklien {
    char username[50];
    char containername[50];
    char imagename[50];
    char perintah[100];
    char volume[50];
    int numclients;
};

void createDockerCompose(struct permintaanklien *clientRequests, int numclients) {
    FILE *composeFile = fopen("docker-compose.yml", "w");
    if (composeFile == NULL) {
        perror("Error opening file");
        exit(1);
    }
    fprintf(composeFile, "version: '3'\n\nservices:\n");
    for (int i = 0; i < numclients; i++) {
        fprintf(composeFile, "  %s:\n", clientRequests[i].containername);
        fprintf(composeFile, "    image: %s\n", clientRequests[i].imagename);
        fprintf(composeFile, "    command: %s\n", clientRequests[i].perintah);
        fprintf(composeFile, "    volumes:\n");
        fprintf(composeFile, "      - %s\n", clientRequests[i].volume);
        fprintf(composeFile, "\n");
    }
    fclose(composeFile);
}

int main() {
    key_t key = ftok("server.c", 'R');
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }
    struct permintaanklien *shared_memory = (struct permintaanklien *)shmat(shmid, NULL, 0);
    if (shared_memory == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Enter number of clients to serve (1-5): ");
    scanf("%d", &shared_memory->numclients);
    while (shared_memory->numclients > 0) {
        sleep(1);
    }
    createDockerCompose(shared_memory + 1, shared_memory->numclients);
    pid_t pid = fork();
    if (pid == 0) {
        char *args[] = {"docker-compose", "up", "-d", NULL};
        execvp("docker-compose", args);
        perror("execvp");
        exit(1);
    } else if (pid < 0) {
        perror("fork");
        exit(1);
    } else {
        waitpid(pid, NULL, 0);
        shmdt((void *)shared_memory);
        shmctl(shmid, IPC_RMID, NULL);
    }
    return 0;
}
