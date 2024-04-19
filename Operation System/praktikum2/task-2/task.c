// [ MODULE & LIBRARY ]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <libgen.h>
#include <time.h>
#include <regex.h>

// [ GLOBAL VARIABLE ]

#define MAX_PATH_LEN 1024
#define MAX_TASKS 20
#define MAX_TASK_NAME_LENGTH 256
#define MAX_FILE_CONTENT_LENGTH 1024

char source_url[] = "https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0";
char current_path[MAX_PATH_LEN];
char old_folder_path[MAX_PATH_LEN];
char new_folder_path[MAX_PATH_LEN];
char tasks[MAX_TASKS][MAX_TASK_NAME_LENGTH];
int task_count = 0;

void Task_A();
void SetPath();
void Download();
void ExtractZip();
void Dump();
void RemoveDir();

void Task_B();
void ScanFile();
void Urutkan();
void YuanFunc();
void BubuFunc();
void ImageHandling();
void ImageDownload();
void Logger();

void Task_D();

// [ SOAL A ]

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

// [ SOAL B dan C ]

void Task_B() {
    pid_t pid;
    int status;
    ScanFile();
    for (int i = 0; i < 2; i++) {
        pid = fork();
        if (pid == -1) {
            perror("Fork failed");
            exit(EXIT_FAILURE);}
        if (pid == 0) {
            if (i == 0) {YuanFunc();}
            else {BubuFunc();}
            exit(EXIT_SUCCESS);}}
    for (int i = 0; i < 2; i++) {
        wait(&status);}
}

// Membaca Seluruh File Dalam Folder task
void ScanFile() {
    DIR *dir;
    struct dirent *entry;
    dir = opendir("./task");
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG && strstr(entry->d_name, ".txt") != NULL) {
            strcpy(tasks[task_count], entry->d_name);
            task_count++;}}
    Urutkan(tasks);
    closedir(dir);
}

// Mengurutkan File .txt Dari 0-19
void Urutkan(char tasks[][MAX_TASK_NAME_LENGTH]) {
    for (int i=0; i<task_count-1; i++) {
        for (int j=0; j<task_count-i-1; j++) {
            int numA = atoi(strstr(tasks[j], "_") + 1);
            int numB = atoi(strstr(tasks[j+1], "_") + 1);
            if (numA > numB) {
                char temp[MAX_TASK_NAME_LENGTH];
                strcpy(temp, tasks[j]);
                strcpy(tasks[j], tasks[j + 1]);
                strcpy(tasks[j + 1], temp);}}}
}

// Fungsi Yuan
void YuanFunc() {
    mkdir("./task/Yuan", 0777);
    for (int i = 0; i < task_count / 2; i++) {
        // printf("Yuan: %s\n", tasks[i]);
        char file_ori[MAX_PATH_LEN];
        char folder_tujuan[MAX_PATH_LEN];
        sprintf(file_ori, "./task/%s", tasks[i]);
        sprintf(folder_tujuan, "./task/Yuan/task%d", i);
        ImageHandling("Yuan", file_ori, folder_tujuan, i);}
}

// Fungsi Bubu
void BubuFunc() {
    mkdir("./task/Bubu", 0777);
    for (int i = task_count - 1; i >= task_count / 2; i--) {
        // printf("Bubu: %s\n", tasks[i]);
        char file_ori[MAX_PATH_LEN];
        char folder_tujuan[MAX_PATH_LEN];
        sprintf(file_ori, "./task/%s", tasks[i]);
        sprintf(folder_tujuan, "./task/Bubu/task%d", i);
        ImageHandling("Bubu", file_ori, folder_tujuan, i);}
}

void ImageHandling(const char *nama, const char *file_ori, const char *folder_tujuan, int task_id) {

    // Membuat Folder Untuk Tiap Task
    mkdir(folder_tujuan, 0777);

    // Download Image
    ImageDownload(nama, file_ori, folder_tujuan, task_id);

    // Memindahkan File .txt
    char dest_file[MAX_PATH_LEN];
    snprintf(dest_file, sizeof(dest_file), "%s/%s", folder_tujuan, basename(strdup(file_ori)));
    rename(file_ori, dest_file);
}

// Download Image
void ImageDownload(const char *nama, const char *file_ori, const char *folder_tujuan, int task_id) {

    int loop;
    char image_size[100], jenis[100], url[100];
    FILE *file = fopen(file_ori, "r");
    fscanf(file, "%d %s %s", &loop, image_size, jenis);
    fclose(file);
    sprintf(url, "https://source.unsplash.com/random/%s?%s\n", image_size, jenis);
    
    for (int i = 1; i <= loop; i++) {
        char image_name[100];
        sprintf(image_name, "%s/gambar%d.png", folder_tujuan, i);
        pid_t pid = fork();
        if (pid == 0) {
            execlp("wget", "wget", url, "-O", image_name, NULL);
            perror("execvp");
            exit(EXIT_FAILURE);}
        else if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);}
    }

    int status;
    while (wait(&status) > 0);

    // Catat Setiap Log
    Logger(nama, task_id, loop, jenis, image_size);
}

// Mencatat Ke recap.txt
void Logger(const char *nama, int task_id, int jumlah_image, const char *kategori_image, const char *resolusi) {
    time_t now;
    struct tm *local_time;
    char timestamp[20];
    time(&now);
    local_time = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", local_time);
    FILE *file = fopen("./task/recap.txt", "a");
    fprintf(file, "[%s]-[%s] Task %d completed, download %d %s images with %s resolution\n",
            timestamp, nama, task_id, jumlah_image, kategori_image, resolusi);
    fclose(file);
}

// [ SOAL C ]

// Simpan Sementara Jumlah Gambar Berdasar Jenis
typedef struct {
    char genre[20];
    int count;
} ImageGenre;

// Sortir Gambar Berdasar Jenis
void Task_D() {
    FILE *file;
    char line[1000];
    ImageGenre genres[100];
    int num_genres = 0;
    file = fopen("./task/recap.txt", "r");
    while (fgets(line, sizeof(line), file)) {
        // Mencari Kecocokan Dalam Baris Dengan regex
        char dicari[100];
        char *pattern = "download\\s+(.*?)\\s+images";
        regex_t regex;
        regmatch_t matches[2];
        regcomp(&regex, pattern, REG_EXTENDED);
        char *ptr = line;
        while (regexec(&regex, ptr, 2, matches, 0) == 0) {
            int jumlah;
            char genre[20];
            int start = matches[1].rm_so;
            int end = matches[1].rm_eo;
            sprintf(dicari, "%.*s", end - start, ptr + start);
            sscanf(dicari, "%d %s", &jumlah, genre);

            // Masukkan Data Ke Struct
            int found = 0;
            for (int i = 0; i < num_genres; i++) {
                if (strcmp(genres[i].genre, genre) == 0) {
                    genres[i].count += jumlah;
                    found = 1;
                    break;}}
            if (!found && num_genres < 100) {
                strcpy(genres[num_genres].genre, genre);
                genres[num_genres].count = jumlah;
                num_genres++;}

            ptr += end;}
        regfree(&regex);}
    fclose(file);

    // Simpan Ke File recap.txt
    int total_image = 0;
    FILE *save;
    save = fopen("./task/recap.txt", "a+");
    for (int i = 0; i < num_genres; i++) {
        fprintf(save, "%s: %d images\n", genres[i].genre, genres[i].count);
        total_image += genres[i].count;}
    fprintf(save, "total images: %d images\n", total_image);
    fclose(save);
}

int main() {
    // Task_A();
    // Task_B();
    // Task_D();
    return 0;
}
