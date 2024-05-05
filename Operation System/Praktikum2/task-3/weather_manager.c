// [ MODULE & LIBRARY ]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>
#include <time.h>

// [ GLOBAL VARIABLE ]
char source_url[] = "https://drive.usercontent.google.com/u/0/uc?id=1U1-9v9pJeX5MoofwoBHCcD9nA7YWy_np&export=download";

void Task_A();
void DownloadZip();
void ExtractZip();
void Task_B();
void Task_C();
void Task_D();

// Inisialisasi
void Task_A() {
    mkdir("./weather", 0777);
    DownloadZip();
    Task_D("Berhasil download file..");
    ExtractZip();
    Task_D("Berhasil unzip file..");
    remove("weather.zip");
}

// Download File Zip
void DownloadZip() {
    pid_t pid = fork();
    if (pid == 0) {
        char *const wgetArgs[] = {"wget", source_url, "-O", "weather.zip", NULL};
        execvp("wget", wgetArgs);
        perror("execvp");
        exit(EXIT_FAILURE);}
    else {
        int status;
        waitpid(pid, &status, 0);}
}

// Ekstrak File Zip
void ExtractZip() {
    pid_t pid = fork();
    if (pid == 0) {
        char *const unzipArgs[] = {"unzip", "-q", "weather.zip", "-d", "./weather", NULL};
        execvp("unzip", unzipArgs);
        perror("execvp");
        exit(EXIT_FAILURE);}
    else {
        int status;
        waitpid(pid, &status, 0);}
}

void Task_B() {
    char old_path[] = "./weather/kecamatanforecast.csv";
    char new_path[] = "./weather/new_kecamatanforecast.csv";
    FILE *old_file = fopen(old_path, "r");
    FILE *new_file = fopen(new_path, "w");
    char line[100], *token;
    // Membaca Setiap Baris
    while (fgets(line, sizeof(line), old_file)) {
        char cetak[100];
        strcpy(cetak, line);
        token = strtok(line, ",");
        int count = 0;
        // Mencari Suhu Abnormal
        while (token != NULL) {
            if (count == 3) {break;}
            token = strtok(NULL, ",");
            count++;}
        if (strcmp("X",token)) {
            int suhu = atoi(token);
            if (suhu <= 35) {fprintf(new_file, "%s", cetak);}
            else {
                char msg[100];
                sprintf(msg, "Berhasil drop row dengan suhu %d°C", suhu);
                Task_D(msg);}}
        else {Task_D("Berhasil drop row dengan suhu X°C");}}
    fclose(old_file);
    fclose(new_file);
    remove(old_path);
    rename(new_path, old_path);
}

void Task_C() {
    mkdir("./city_group", 0777);
    FILE *file = fopen("./weather/kecamatanforecast.csv", "r");
    char line[100];
    // Mengelompokkan ID Kota
    while (fgets(line, sizeof(line), file)) {
        char cetak[100];
        strcpy(cetak, line);
        char *token = strtok(line, ",");
        if (token == NULL) {continue;}
        if (strcmp("0",token)) {
            char file_tujuan[100];
            sprintf(file_tujuan, "./city_group/city_%s.csv", token);
            FILE *files = fopen(file_tujuan, "a");
            fprintf(files, "%s", cetak);
            fclose(files);}}
    fclose(file);
    Task_D("Berhasil melakukan group data..");
}

// Mencatat Setiap Aktivitas
void Task_D(const char *pesan) {
    time_t now;
    struct tm *local_time;
    char timestamp[20];
    time(&now);
    local_time = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", local_time);
    FILE *file = fopen("logbook.txt", "a");
    fprintf(file, "[%s] %s\n", timestamp, pesan);
    fclose(file);
}

int main() {
    Task_A();
    Task_B();
    Task_C();
    return(0);
}
