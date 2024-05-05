#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h> // Untuk pid_t
#include <time.h>
#include <dirent.h> // Untuk akses direktori

#define MAX_KUDA 200
#define BUFFER_SIZE 256
#define MAX_LINE_LENGTH 1000

void HorseFetcher()
{
    pid_t child_id = fork();
    int status;

    if (child_id < 0)
    {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }

    if (child_id == 0)
    {
        char *wgetCmd[] = {"wget", "https://drive.google.com/uc?export=download&id=1gJkoTbiHZcJ1M36vqZPTrj3qTQkRMElQ", "-O", "horse.zip", NULL};
        if (execvp("wget", wgetCmd) == -1)
        {
            perror("Execvp download failed");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        while (wait(&status) > 0)
        {
            // menunggu proses selesai
        }
        // Proses anak untuk ekstraksi
        char *const unzipCmd[] = {
            "unzip", "horse.zip", "-d", ".",
            NULL};

        if (execvp("unzip", unzipCmd) == -1)
        {
            perror("Execvp unzip failed");
            exit(EXIT_FAILURE);
        }
    }
}

typedef struct
{
    int posisi;
    char kuda[20];
    char pemilik[20];
    int poin;
    char hasilFileLomba[20];
    char nomorLomba[20];
} kuda;

int isPrime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void *checkPrime(void *arg)
{
    kuda *myKuda = (kuda *)arg;

    FILE *file = fopen(myKuda->hasilFileLomba, "a");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        pthread_exit(NULL);
    }

    fprintf(file, "%s %d\n", myKuda->kuda, myKuda->poin);
    pthread_exit(NULL);
}

int bacaFileKuda(const char *namaFile, kuda daftarKuda[], const char *hasilFileLomba, const char *nomorLomba)
{
    FILE *file = fopen(namaFile, "r");
    if (file == NULL)
    {
        perror("Gagal membuka file");
        exit(EXIT_FAILURE);
    }

    int jumlahKuda = 0;
    char buffer[BUFFER_SIZE];

    srand(time(NULL));

    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        buffer[strcspn(buffer, "\n")] = '\0';

        char *token = strtok(buffer, ":");
        if (token != NULL)
        {
            strncpy(daftarKuda[jumlahKuda].kuda, token, sizeof(daftarKuda[jumlahKuda].kuda) - 1);
            daftarKuda[jumlahKuda].kuda[sizeof(daftarKuda[jumlahKuda].kuda) - 1] = '\0';

            strcpy(daftarKuda[jumlahKuda].nomorLomba, nomorLomba);
            strcpy(daftarKuda[jumlahKuda].hasilFileLomba, hasilFileLomba);
            token = strtok(NULL, ":");
            if (token != NULL)
            {
                strncpy(daftarKuda[jumlahKuda].pemilik, token, sizeof(daftarKuda[jumlahKuda].pemilik) - 3);
                daftarKuda[jumlahKuda].pemilik[sizeof(daftarKuda[jumlahKuda].pemilik) - 3] = '\0';

                int poin;
                int duplikat;
                do
                {
                    poin = rand() % 4000 + 1;
                    duplikat = 0;
                    for (int i = 0; i < jumlahKuda; i++)
                    {
                        if (daftarKuda[i].poin == poin)
                        {
                            duplikat = 1;
                            break;
                        }
                    }
                } while (duplikat);

                daftarKuda[jumlahKuda].posisi = jumlahKuda + 1;
                daftarKuda[jumlahKuda].poin = poin;

                jumlahKuda++;
                if (jumlahKuda >= MAX_KUDA)
                {
                    break;
                }
            }
        }
    }

    fclose(file);
    return jumlahKuda;
}

void tambahkanNomorDiAwal(const char *namaFile)
{
    FILE *inputFile, *tempFile;
    char line[MAX_LINE_LENGTH];
    int lineNumber = 0;

    // Buka file untuk dibaca
    inputFile = fopen(namaFile, "r");
    if (inputFile == NULL)
    {
        perror("Gagal membuka file input");
        exit(EXIT_FAILURE);
    }

    // Buka file untuk ditulis (sebagai file sementara)
    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL)
    {
        perror("Gagal membuka file output");
        exit(EXIT_FAILURE);
    }

    // Baca setiap baris dari file
    int i = 0;
    while (fgets(line, sizeof(line), inputFile) != NULL)
    {
        lineNumber++;

        if (lineNumber >= 5)
        {
            i += 1;
            // Jika baris ke-5 atau setelahnya, tambahkan angka di awal
            fprintf(tempFile, "%d. %s", i, line);
        }
        else
        {
            // Jika sebelum baris ke-5, tulis ulang tanpa perubahan
            fprintf(tempFile, "%s", line);
        }
    }

    // Tutup file
    fclose(inputFile);
    fclose(tempFile);

    // Ganti file input dengan file sementara (output)
    if (remove(namaFile) != 0)
    {
        perror("Gagal menghapus file input");
        exit(EXIT_FAILURE);
    }
    if (rename("temp.txt", namaFile) != 0)
    {
        perror("Gagal mengubah nama file output");
        exit(EXIT_FAILURE);
    }

    printf("Perlombaan selesai dan disimpan di file %s\n", namaFile);
}

void horseChampionLeaderboard(const char *folderPath, const char *prefix)
{
    DIR *directory;
    struct dirent *entry;
    int count = 0;

    // Buka direktori
    directory = opendir(folderPath);

    if (directory == NULL)
    {
        fprintf(stderr, "Error: Tidak dapat membuka direktori %s\n", folderPath);
        exit(EXIT_FAILURE);
    }

    // Menyimpan nama file yang sesuai dengan prefix
    char files[100][256]; // Maksimal 100 file dengan panjang nama file maksimal 256 karakter

    // Baca setiap entri dalam direktori
    while ((entry = readdir(directory)) != NULL)
    {
        // Dapatkan nama file dari entri
        const char *fileName = entry->d_name;

        // Periksa apakah nama file diawali dengan prefix yang diinginkan
        if (strncmp(fileName, prefix, strlen(prefix)) == 0)
        {
            strcpy(files[count], fileName);
            count++;
        }
    }

    // Tutup direktori setelah selesai
    closedir(directory);

    // Jika tidak ada file yang sesuai dengan prefix
    if (count == 0)
    {
        printf("Tidak ada file dengan awalan \"%s\" dalam folder %s\n", prefix, folderPath);
        return;
    }

    // Tampilkan daftar file yang sesuai dengan prefix
    printf("Daftar File Perlombaan : \n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. %s\n", i + 1, files[i]);
    }

    // Meminta pengguna memilih nomor file untuk dibuka
    int selection;
    printf("\nPilih nomor file untuk dibuka (1-%d): ", count);
    scanf("%d", &selection);

    // Validasi pilihan pengguna
    if (selection < 1 || selection > count)
    {
        printf("Pilihan tidak valid.\n");
        return;
    }

    // Buka file yang dipilih
    const char *selectedFile = files[selection - 1];
    char filePath[256];
    snprintf(filePath, sizeof(filePath), "%s/%s", folderPath, selectedFile);

    // Buka file dan tampilkan isinya di terminal
    FILE *file = fopen(filePath, "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error: Tidak dapat membuka file %s\n", selectedFile);
        exit(EXIT_FAILURE);
    }

    printf("\nIsi file %s:\n", selectedFile);
    char line[256];
    while (fgets(line, sizeof(line), file) != NULL)
    {
        printf("%s", line);
    }

    // Tutup file setelah selesai
    fclose(file);
}

int main()
{
    printf("HORSECHAMP Horse Racing Competition Program \n");
    printf("1. Fetch Horse Data  \n");
    printf("2. Start Horse Race \n");
    printf("3. Show Winners\n");
    printf("Masukkan Perintahmu Dengan Angka (1,2,3) : \n");
    int pilihan;
    scanf("%d", &pilihan);
    if (pilihan == 1)
    {
        HorseFetcher();
    }
    if (pilihan == 2)
    {
        char perintah2a[50];
        char perintah2b[20];
        char perintah2c[20];
        printf("Masukkan Nama File Data Kuda (.txt) : ");
        scanf("%s", perintah2a);
        printf("Masukkan Nama File Hasil cth (HorseRace_1.txt) : ");
        scanf("%s", perintah2b);
        printf("Masukkan Lomba Keberapa? (1/2/3,dst) : ");
        scanf("%s", perintah2c);

        kuda daftarKuda[MAX_KUDA];
        int jumlahKuda;

        jumlahKuda = bacaFileKuda(perintah2a, daftarKuda, perintah2b, perintah2c);

        // masukkan header hasil.txt
        // Menyimpan data kuda yang berhasil dibaca ke dalam file
        FILE *outputFile = fopen(perintah2b, "w");
        if (outputFile == NULL)
        {
            perror("Gagal membuka file output");
            exit(EXIT_FAILURE);
        }

        time_t current_time = time(NULL);
        struct tm *local_time = localtime(&current_time);
        fprintf(outputFile, "----- HORSE CHAMPIONSHIP %s -----\n", perintah2c);
        fprintf(outputFile, "Date: %02d/%02d/%04d\n", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900);
        fprintf(outputFile, "Time: %02d:%02d:%02d\n\n", local_time->tm_hour, local_time->tm_min, local_time->tm_sec);

        fclose(outputFile);

        printf("Data kuda berhasil dibaca dan di proses di lomba %s\n", perintah2b);

        // Memulai proses fork
        pid_t child_pid = fork();

        if (child_pid == -1)
        {
            perror("Gagal dalam fork");
            exit(EXIT_FAILURE);
        }
        else if (child_pid == 0)
        {
            // Ini adalah proses anak

            // jalankan thread untuk memasukkan data setiap kuda
            pthread_t threads[MAX_KUDA];

            // Memulai thread untuk setiap kuda
            for (int i = 0; i < jumlahKuda; i++)
            {
                int ret = pthread_create(&threads[i], NULL, checkPrime, (void *)&daftarKuda[i]);
                if (ret)
                {
                    fprintf(stderr, "Error - pthread_create() return code: %d\n", ret);
                    exit(EXIT_FAILURE);
                }
            }

            // Menunggu semua thread selesai
            for (int i = 0; i < jumlahKuda; i++)
            {
                pthread_join(threads[i], NULL);
            }

            exit(EXIT_SUCCESS); // Keluar dari proses anak setelah selesai
        }
        else
        {
            // Ini adalah proses induk
            // Tunggu proses anak selesai
            int status;
            waitpid(child_pid, &status, 0);

            // Setelah semua thread selesai, jalankan tambahkanNomorDiAwal
            tambahkanNomorDiAwal(perintah2b);
        }
    }

    if (pilihan == 3)
    {
        const char *folderPath = ".";     // Path folder yang ingin dijelajahi (current directory)
        const char *prefix = "HorseRace"; // Awalan yang dicari pada nama file

        horseChampionLeaderboard(folderPath, prefix);
    }
    printf("Selesai\n");
}
