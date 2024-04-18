// [ MODULE & LIBRARY ]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>

// [ GLOBAL VARIABLE ]
#define MAX_PATH_LEN 1024
char source_url[] = "https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0";
char current_path[MAX_PATH_LEN];
char old_folder_path[MAX_PATH_LEN];
char new_folder_path[MAX_PATH_LEN];

// [ SOAL A ]

void Task_A();
void SetPath();
void Download();
void ExtractZip();
void Dump();
void RemoveDir();

void Task_A() {
    char data[MAX_PATH_LEN][MAX_PATH_LEN];
    int index = 0;
    const char *folder_path = "./task_sisop";
    SetPath();
    Download();
    ExtractZip();
    Dump(folder_path, data, &index);
    RemoveDir(folder_path);
    printf("\n\nDone.\n");
}

// Mengatur Direktori
void SetPath() {
    struct stat st;

    // Workspace File Utama
    strcpy(current_path, ".");

    // Membuat Folder task Jika Belum Ada
    sprintf(new_folder_path, "%s/task", current_path);
    int status_new = mkdir(new_folder_path, 0777);
    if (status_new != 0) {
        perror("Gagal Membuat Folder task");
        exit(EXIT_FAILURE);}

    // Membuat Folder task_sisop Jika Belum Ada
    sprintf(old_folder_path, "%s/task_sisop", current_path);
    int status_old = mkdir(old_folder_path, 0777);
    if (status_old != 0) {
        perror("Gagal Membuat Folder task_sisop");
        exit(EXIT_FAILURE);}
}

// Download Dan Simpan File Zip
void Download() {
    pid_t pid = fork();
    if (pid == 0) {
        // Download File Zip
        char *const wgetArgs[] = {"wget", source_url, "-O", "task_sisop.zip", NULL};
        execvp("wget", wgetArgs);
        perror("execvp");
        exit(EXIT_FAILURE);}
    else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Download Gagal\n");
            exit(EXIT_FAILURE);}}
    else {
        perror("Gagal Fork");
        exit(EXIT_FAILURE);}
}

// Ekstrak Dan Simpan File Hasil Ekstraksi
void ExtractZip() {
    pid_t pid = fork();
    if (pid == 0) {
        // Ekstrak File Zip
        char *const unzipArgs[] = {"unzip", "-q", "task_sisop.zip", "-d", old_folder_path, NULL};
        execvp("unzip", unzipArgs);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0) {
            fprintf(stderr, "Gagal Ekstrak\n");
            exit(EXIT_FAILURE);}

        // Hapus File Zip
        remove("task_sisop.zip");}
    else {
        perror("Gagal Fork");
        exit(EXIT_FAILURE);}
}

// Dump File .txt
void Dump(const char *folder_path, char data[][MAX_PATH_LEN], int *index) {
    DIR *dir;
    struct dirent *entry;
    dir = opendir(folder_path);

    // Membaca Semua Folder
    while ((entry = readdir(dir)) != NULL) {
        char item_path[MAX_PATH_LEN];
        snprintf(item_path, sizeof(item_path), "%s/%s", folder_path, entry->d_name);
        struct stat statbuf;
        if (stat(item_path, &statbuf) == -1) {
            continue;}
        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                Dump(item_path, data, index);}}
        else {
            // Mensortir File .txt
            if (strstr(entry->d_name, ".txt") != NULL) {
                strncpy(data[(*index)], item_path, MAX_PATH_LEN);
                printf("\n%s",data[(*index)]);

                // Memindahkan Ke Folder task
                char target_path[MAX_PATH_LEN];
                snprintf(target_path, sizeof(target_path), "%s/%s", new_folder_path, strrchr(data[(*index)], '/') + 1);
                rename(data[(*index)], target_path);

                (*index)++;}}}
    closedir(dir);
}

// Menghapus Direktori task_sisop
void RemoveDir(const char *dirPath) {
    DIR *dir = opendir(dirPath);
    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {

        // Skip Direktori . dan ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;}
        char filePath[PATH_MAX];
        snprintf(filePath, sizeof(filePath), "%s/%s", dirPath, entry->d_name);

        // Periksa Tipe (Folder/File)
        struct stat statbuf;
        stat(filePath, &statbuf);

        // Jika Tipe Folder/Direktori --> Rekursif
        if (S_ISDIR(statbuf.st_mode)) {
            RemoveDir(filePath);}

        // Jika Tipe File --> Hapus File
        else {unlink(filePath);}}

    closedir(dir);
    // Hapus Direktori Jika Sudah Tidak Ada File Tersisa
    rmdir(dirPath);
}

int main() {
    Task_A();
    return 0;
}
