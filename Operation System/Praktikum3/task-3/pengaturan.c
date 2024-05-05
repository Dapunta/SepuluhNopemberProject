#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define networks "my_network"

// Membuat Container Baru
void Create(char *container) {
    char arg[100];
    sprintf(arg, "docker run -dit --name %s -v shared_volume:/shared dockermessage", container); system(arg);
    printf("Container '%s' berhasil dibuat.\n", container);
}

// Menghapus Container
void Delete(char *container) {
    char arg[100];
    sprintf(arg, "docker rm -f %s", container); system(arg);
    printf("Container '%s' berhasil dihapus.\n", container);
}

// Menampilkan Semua Container
void Listing() {
    char arg[100];
    sprintf(arg, "docker ps -a"); system(arg);
}

// Login Container
void Login(char *container) {
    char arg1[100], arg2[100];
    sprintf(arg2, "docker exec -it %s sh -c 'echo \"%s\" > /shared/workplace.txt'", container, container); system(arg2);
    sprintf(arg1, "docker exec -it %s /bin/sh", container); system(arg1);
}

// Connect 2 Container
void Connect(char *container1, char *container2) {
    char arg1[100], arg2[100], arg3[100];
    sprintf(arg1, "docker network create %s", networks); system(arg1);
    sprintf(arg2, "docker network connect %s %s", networks, container1); system(arg2);
    sprintf(arg3, "docker network connect %s %s", networks, container2); system(arg3);
}

// Disconnect 2 Container
void Disconnect(char *container1, char *container2) {
    char arg1[100], arg2[100], arg3[100];
    sprintf(arg1, "docker network disconnect %s %s", networks, container1); system(arg1);
    sprintf(arg2, "docker network disconnect %s %s", networks, container2); system(arg2);
    sprintf(arg3, "docker network rm %s", networks); system(arg3);
}

// Reset (Biar Gampang)
void Reset(char *container1, char *container2) {
    char arg1[100], arg2[100], arg3[100], arg4[100], arg5[100], arg6[100], arg7[100];
    sprintf(arg1, "docker network disconnect %s %s", networks, container1); system(arg1);
    sprintf(arg2, "docker network disconnect %s %s", networks, container2); system(arg2);
    sprintf(arg3, "docker network rm %s", networks); system(arg3);
    sprintf(arg4, "docker rm -f %s", container1); system(arg4);
    sprintf(arg5, "docker rm -f %s", container2); system(arg5);
    sprintf(arg6, "docker container prune -f"); system(arg6);
    sprintf(arg7, "docker rmi -f dockermessage"); system(arg7);
}

int main(int argc, char *argv[]) {
    char *command = argv[1];
    char *container = (argc >= 3) ? argv[2] : "";
    if      (strcmp(command, "create") == 0)    Create(container);
    else if (strcmp(command, "delete") == 0)    Delete(container);
    else if (strcmp(command, "list") == 0)      Listing();
    else if (strcmp(command, "login") == 0)     Login(container);
    else if (strcmp(command, "connect") == 0)   Connect(argv[2], argv[3]);
    else if (strcmp(command, "unconnect") == 0) Disconnect(argv[2], argv[3]);
    else if (strcmp(command, "reset") == 0)     Reset(argv[2], argv[3]);
    else {printf("Invalid command!\n"); return 1;}
    return 0;
}
