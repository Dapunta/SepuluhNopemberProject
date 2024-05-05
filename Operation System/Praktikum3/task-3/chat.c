#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* DirektoriSaiki() {
    char* container_saiki = (char*)malloc(100 * sizeof(char));
    FILE *contfilename = fopen("/shared/workplace.txt", "r");
    fgets(container_saiki, sizeof(container_saiki), contfilename);
    container_saiki[strcspn(container_saiki, "\n")] = '\0';
    fclose(contfilename);
    return container_saiki;
}

void TulisPesan(int argc, char *argv[]) {
    char filename[100];
    char *target = argv[2];
    char *dir = DirektoriSaiki();
    sprintf(filename, "/shared/%s.txt", target);
    FILE *file = fopen(filename, "w");
    char *pesan = (char *)malloc(sizeof(char));
    for (int i = 3; i < argc; i++) {
        pesan = realloc(pesan, strlen(pesan) + strlen(argv[i]) + 2);
        strcat(pesan, argv[i]);
        strcat(pesan, " ");}
    printf("Pesan berhasil dikirim\n");
    fprintf(file, "%sfrom %s", pesan, dir);
    fclose(file);
    free(pesan);
    free(dir);
}

void BacaPesan(int argc, char *argv[]) {
    char filename[100], pesan[256];
    char *target = DirektoriSaiki();
    sprintf(filename, "/shared/%s.txt", target);
    FILE *file = fopen(filename, "r");
    fgets(pesan, sizeof(pesan), file);
    pesan[strcspn(pesan, "\n")] = '\0';
    printf("%s\n", pesan);
    fclose(file);
    free(target);
}

int main(int argc, char *argv[]) {
    if ( (argc>=4) && (strcmp(argv[1],"write")==0) ) TulisPesan(argc, argv);
    else if ( (argc==2) && (strcmp(argv[1],"read")==0) ) BacaPesan(argc, argv);
    return 0;
}
