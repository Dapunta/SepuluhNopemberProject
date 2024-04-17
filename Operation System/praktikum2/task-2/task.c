#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_PATH_LEN 256

char source_url[] = "https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0";
char current_path[MAX_PATH_LEN];
char old_folder_path[MAX_PATH_LEN];
char new_folder_path[MAX_PATH_LEN];

void Task_A();
void SetPath();
void Download();
void ExtractZip();
void Move();

void Task_A()
{
    SetPath();
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        Download();
        exit(0);
    }
    else if (child_pid > 0)
    {
        int status;
        waitpid(child_pid, &status, 0); // Menunggu anak proses untuk menyelesaikan unduhan
        child_pid = fork();
        if (child_pid == 0)
        {
            ExtractZip();
            exit(0);
        }
        else if (child_pid > 0)
        {
            waitpid(child_pid, &status, 0); // Menunggu anak proses untuk menyelesaikan ekstraksi

            Move();
        }
        else
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    printf("Done.\n");
    return 0;
}

void SetPath()
{

    struct stat st;
    strcpy(current_path, ".");

    sprintf(old_folder_path, "%s/task_sisop", current_path);
    if (stat(old_folder_path, &st) == -1)
    {
        if (mkdir(old_folder_path, 0777) == -1)
        {
            perror("Gagal Membuat Folder task_sisop");
            exit(EXIT_FAILURE);
        }
        Download();
    }

    sprintf(new_folder_path, "%s/task", current_path);
    if (stat(new_folder_path, &st) == -1)
    {
        if (mkdir(new_folder_path, 0777) == -1)
        {
            perror("Gagal Membuat Folder task");
            exit(EXIT_FAILURE);
        }
    }
}

void Download()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // Download File Zip
        char *const wgetArgs[] = {"wget", source_url, "-O", "task_sisop.zip", NULL};
        execvp("wget", wgetArgs);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        {
            fprintf(stderr, "Download Gagal\n");
            exit(EXIT_FAILURE);
        }
        // Pindahkan File Zip
        char *const mvArgs[] = {"mv", "task_sisop.zip", current_path, NULL};
        execvp("mv", mvArgs);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else
    {
        perror("Gagal Fork");
        exit(EXIT_FAILURE);
    }
}

void ExtractZip()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        // Ekstrak File Zip
        char *const unzipArgs[] = {"unzip", "-q", "task_sisop.zip", "-d", old_folder_path, NULL};
        execvp("unzip", unzipArgs);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        int status;
        waitpid(pid, &status, 0);
        if (!WIFEXITED(status) || WEXITSTATUS(status) != 0)
        {
            fprintf(stderr, "Gagal Ekstrak\n");
            exit(EXIT_FAILURE);
        }
        // Hapus File Zip
        remove("task_sisop.zip");
    }
    else
    {
        perror("Gagal Fork");
        exit(EXIT_FAILURE);
    }
}

void Move()
{
    pid_t child_pid = fork();
    if (child_pid == 0)
    {
        execl("/bin/mv", "mv", old_folder_path, new_folder_path, (char *)NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    }
    else if (child_pid > 0)
    {
        int status;
        waitpid(child_pid, &status, 0); // Menunggu anak proses untuk menyelesaikan pemindahan
    }
    else
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
}

int main()
{
    Task_A();
}