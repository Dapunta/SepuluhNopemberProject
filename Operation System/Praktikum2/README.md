[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/o3jj1gXA)

<div align=center>

|    NRP     |             Name             |
| :--------: | :--------------------------: |
| 5025231055 | Thalyta Vius Pramesti        |
| 5025231187 | Dapunta Adyapaksi Ratyanasja |
| 5025231057 | Alif Nurrohman               |

<br><br>

# **Praktikum Modul 2<br>_(Module 2 Lab Work)_**

</div>

### Daftar Soal _(Task List)_

- [Task 1 - HORSECHAMP](/task-1/)
- [Task 2 - Tugas Akhir Yuan dan Bubu _(Yuan's and Bubu's Final Project)_](/task-2/)
- [Task 3 - Ramalan Cuaca Rama _(Rama's Weather Forecast)_](/task-3/)
- [Task 4 - Tic Tac Toe](/task-4/)

<br><br><br>

<div align=center>

# Laporan Resmi Praktikum Modul 2<br>_(Module 2 Lab Work Report)_

</div>

<br><br>

## Task 1
Disusun Oleh : [**Alif Nurrohman**](https://github.com/alifnurrohmans)  
Source Code : [task-1](https://github.com/sisop-its-s24/praktikum-modul-2-a04/blob/main/task-1/horsechamp.c)

### Problem A
- Penjelasan : Membuat Source Code untuk melakukan beberapa task berikut :
  - Mendownload file zip dari [URL](https://drive.google.com/uc?export=download&id=1gJkoTbiHZcJ1M36vqZPTrj3qTQkRMElQ) sesuai ketentuan soal
  - Mengekstrak isi file zip yang didalamnya terdapat horse_1.txt, horse_2.txt & horse_3.txt yang nantinya akan digunakan sebagai data perlombaan
 
- Alur Pengkodean :
  1. Membuat Pilihan Untuk User, apakah ingin menjalankan fitur 1 / 2 / 3
     ```c
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
      }
  
      if (pilihan == 3)
      {
      }
     ```
  2. Memanggil function HorseFetcher
     ```c
     HorseFetcher();
     ```
  3. Penjelasan isi function HorseFetcher
     - Membuat fork
       ```c
       pid_t child_id = fork();
       int status;
       ```
     - Pada saat child_id == 0 (artinya, ini adalah child), gunakan command Wget untuk mendownload
       ```c
       char *wgetCmd[] = {"wget", "https://drive.google.com/uc?export=download&id=1gJkoTbiHZcJ1M36vqZPTrj3qTQkRMElQ", "-O",         "horse.zip", NULL};
        if (execvp("wget", wgetCmd) == -1)
        {
            perror("Execvp download failed");
            exit(EXIT_FAILURE);
        }
       ```
     - Tunggu hingga selesai, else (artinya, ini adalah parent lagi), unzip file yang telah di download
       ```c
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
       ```
- Hasil Gambar :
<img width="472" alt="a" src="https://github.com/sisop-its-s24/praktikum-modul-2-a04/assets/162116740/445418fe-40c6-4521-88e1-8118cc8042e7">

- Tingkat Kesulitan : Mudah
### Problem B
- Penjelasan : Membuat Source Code untuk melakukan beberapa task berikut :
  - Mengambil isi file dari data yang sudah di download tadi
  - Menjalankan perlombaan dengan thread untuk melakukan pengecekan bilangan prima
  - Memasukkan hasil perlombaan ke dalam file HorseRace_{perlombaan}.txt

- Alur Pengkodean :
  1. Isi di pilihan 2, dengan kode inputan dan function yang dibutuhkan
     ```c
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
            fprintf(outputFile, "Date: %02d/%02d/%04d\n", local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year               + 1900);
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
     ```
  2. function baca file kuda, untuk mengambil seluruh data kuda dan memasukkan ke dalam struct
     ```c
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
     ```
  3. function *checkprime, untuk menjalankann thread dan memasukkan hasil perlombaan ke file txt
     ```c
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
     ```
  4. function tambahkanNomorDiawal, untuk menambahkan nomor urutan kuda dari awal sampai akhir sesuai kecepatan / juara
     ```c
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
     ```

- Hasil Gambar :
<img width="617" alt="b" src="https://github.com/sisop-its-s24/praktikum-modul-2-a04/assets/162116740/bda11fd9-36ec-4ecf-939b-a0601cf8612f">

- Tingkat Kesulitan : Sulit
### Problem C
- Penjelasan : Membuat Source Code untuk melakukan beberapa task berikut :
  - Menampilkan semua file hasil balapan
  - Meminta user untuk memilih file yang akan dilihat
  - Menampilkan isi file sesuai yang ingin user lihat

- Alur Pengkodean :
  1. Isi di pilihan 3, dengan function horseChampionLeaderboard
     ```c
     if (pilihan == 3)
      {
          const char *folderPath = ".";     // Path folder yang ingin dijelajahi (current directory)
          const char *prefix = "HorseRace"; // Awalan yang dicari pada nama file
  
          horseChampionLeaderboard(folderPath, prefix);
      }
     ```
    - isi function tersebut, akan mengambil semua data yang ada di dalam file txt dan menampilkanya
      ```c
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
      ```
- Hasil Gambar :
<img width="519" alt="c" src="https://github.com/sisop-its-s24/praktikum-modul-2-a04/assets/162116740/62637acc-7ac9-4ce3-bfb7-40a982e03201">

- Tingkat Kesulitan : Sedang
<br><br>

## Task 2
Disusun Oleh : [**Dapunta Adyapaksi Ratyanasja**](https://github.com/Dapunta)  
Source Code : [task-2](https://github.com/sisop-its-s24/praktikum-modul-2-a04/blob/main/task-2/task.c)

### Problem A
- Penjelasan : Membuat Source Code untuk melakukan beberapa task berikut :
  - Mendownload file zip dari [URL](https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0) yang telah ditentukan
  - Mengekstrak, kemudian menghapus file zip tersebut
  - Membuat folder `task`, kemudian memindahkan file tertentu (_berekstensi .txt_) ke folder tersebut
  - Hapus folder hasil ekstraksi sebelumnya
- Alur Pengkodean :
  - Fungsi **SetPath()** untuk membuat beberapa folder baru sebagai lokasi penyimpanan file
    - Mengatur direktori kerja saat ini
      ```C
      strcpy(current_path, ".");
      ```
    - Membuat folder `task` sebagai lokasi penyimpanan file hasil sortir
      ```c
      sprintf(new_folder_path, "%s/task", current_path);
      mkdir(new_folder_path, 0777);
      ```
    - Membuat folder `task_sisop` sebagai lokasi penyimpanan sementara file hasil ekstraksi
      ```c
      sprintf(old_folder_path, "%s/task_sisop", current_path);
      int status_old = mkdir(old_folder_path, 0777);
      ```
  - Fungsi **Download()** untuk download file zip
    ```c
    char *const wgetArgs[] = {"wget", source_url, "-O", "task_sisop.zip", NULL};
    execvp("wget", wgetArgs);
    ```
  - Fungsi **ExtractZip()** untuk ekstrak, simpan, dan hapus file zip
    - Ekstrak file zip, kemudian letakkan pada direktori `task_sisop`
      ```c
      char *const unzipArgs[] = {"unzip", "-q", "task_sisop.zip", "-d", old_folder_path, NULL};
      execvp("unzip", unzipArgs);
      ```
    - Hapus file zip awal
      ```c
      remove("task_sisop.zip");
      ```
  - Fungsi **Dump()** untuk mensortir file sesuai dengan ketentuan, kemudian memindahkannya
    - Mencari semua file yang berekstensi `.txt` pada direktori `task_sisop`
      ```c
      strstr(entry->d_name, ".txt");
      strncpy(data[(*index)], item_path, MAX_PATH_LEN);
      ```
    - Memindahkan file yang telah ditemukan ke folder `task`
      ```c
      snprintf(target_path, sizeof(target_path), "%s/%s", new_folder_path, strrchr(data[(*index)], '/') + 1);
      rename(data[(*index)], target_path);
      ```
  - Fungsi **RemoveDir()** untuk menghapus direktori `task_sisop` setelah semua file `.txt` berhasil dipindah ke direktori `task`
    ```c
    unlink(filePath);
    rmdir(dirPath);
    ```
- Tingkat Kesulitan : Mudah

### Problem B dan C
Problem B dan C dijalankan secara bersamaan. Setiap selesai mendownload sebuah task akan dicatat aktivitasnya
- Penjelasan : Membuat Source Code untuk melakukan beberapa task berikut :
  - Membagi tugas menjadi 2, Yuan 0-9, Bubu 19-10
  - Mendownload gambar sesuai dengan format dalam setiap task `.txt`
  - Menyimpan gambar hasil download ke folder masing-masing yang telah diurutkan
  - Mencatat setiap aktivitas ke recap.txt
- Alur Pengkodean :
  - Fungsi **ScanFile()** berguna untuk membaca seluruh file `.txt` yang ada pada folder `task`, kemudian menyimpan sementara pada variabel `tasks`
    ```c
    opendir("./task");
    strcpy(tasks[task_count], entry->d_name);
    ```
  - Fungsi **Urutkan()** untuk mengurutkan elemen dalam array `tasks`. Pada nama setiap task memiliki angka, mulai dari yang terkecil hingga terbesar
    ```c
    strcpy(temp, tasks[j]);
    strcpy(tasks[j], tasks[j + 1]);
    strcpy(tasks[j + 1], temp);
    ```
  - Fungsi **Task_B()** berguna untuk membagi task. 10 task pertama dikerjakan oleh Yuan sebagai parent, 10 task terakhir dikerjakan oleh Bubu sebagai child
    ```c
    pid = fork();
    if (pid == 0) {
      if (i == 0) {YuanFunc();}
      else {BubuFunc();}
      exit(EXIT_SUCCESS);}
    ```
  - Fungsi **YuanFunc()** dan **BubuFunc()** berguna untuk membagi 20 task menjadi 2. Yuan mengerjakan task 0 hingga 9, sedangkan Bubu mengerjakan task 19 hingga 10. Dalam 2 fungsi itu, masing-masing membuat sebuah folder baru dalam direktori `task` sesuai nama mereka sendiri. Kemudian melakukan looping untuk mendeklarasikan path folder tujuan untuk menyimpan gambar hasil download sesuai dengan nomor task-nya
    ```c
    mkdir("./task/Yuan", 0777);
    sprintf(folder_tujuan, "./task/Yuan/task%d", i);
    ```
    ```c
    mkdir("./task/Bubu", 0777);
    sprintf(folder_tujuan, "./task/Bubu/task%d", i);
    ```
  - Fungsi **ImageHandling()** dan **ImageDownload()** berguna untuk :
    - Membuat folder tujuan sesuai dengan nomor task
      ```c
      mkdir(folder_tujuan, 0777);
      ```
    - Membaca setiap file `.txt` untuk menentukan kriteria gambar yang akan diunduh
      ```c
      fscanf(file, "%d %s %s", &loop, image_size, jenis);
      ```
    - Menentukan nama dan lokasi penyimpanan gambar
      ```c
      sprintf(image_name, "%s/gambar%d.png", folder_tujuan, i);
      ```
    - Mendownload gambar
      ```c
      execlp("wget", "wget", url, "-O", image_name, NULL);
      ```
    - Memindahkan file task `.txt` yang ada dalam folder `task` menuju ke subfolder masing-masing nomor task
      ```c
      snprintf(dest_file, sizeof(dest_file), "%s/%s", folder_tujuan, basename(strdup(file_ori)));
      rename(file_ori, dest_file);
      ```
  - Fungsi **Logger()** berguna untuk mencatat setiap aktivitas task yang sukses dijalankan ke dalam file `recap.txt` yang diletakkan di dalam folder `task`
    ```c
    fprintf(file, "[%s]-[%s] Task %d completed, download %d %s images with %s resolution\n", timestamp, nama, task_id, jumlah_image, kategori_image, resolusi);
    ```
- Tingkat Kesulitan : Sulit

### Problem D
- Penjelasan : Membuat Source Code untuk menghitung jumlah gambar dari setiap kategori serta menghitung total gambar yang telah didownload ke dalam `recap.txt`
- Alur Pengkodean :
  - Membuat struct **ImageGenre** untuk menyimpan kategori gambar dan jumlahnya
  - Dalam fungsi **Task_D()** terdapat beberapa skema sebagai berikut :
    - Membuka file `recap.txt` kemudian membacanya per-baris
      ```c
      file = fopen("./task/recap.txt", "r");
      while (fgets(line, sizeof(line), file)) {
        doSomething...;
      }
      ```
    - Mencari teks yang diapit oleh kata 'download' dan 'images' menggunakan RegEx, kemudian memformatnya menjadi `jumlah` dan `genre`
      ```c
      char *pattern = "download\\s+(.*?)\\s+images";
      regex_t regex;
      regmatch_t matches[2];
      regcomp(&regex, pattern, REG_EXTENDED);
      sprintf(dicari, "%.*s", end - start, ptr + start);
      sscanf(dicari, "%d %s", &jumlah, genre);
      ```
    - Masukkan data `genre` (kategori gambar) dan `jumlah` (jumlah gambar) ke struct
      ```c
      strcpy(genres[num_genres].genre, genre);
      genres[num_genres].count = jumlah;
      genres[i].count += jumlah;
      ```
    - Hitung total gambar yang telah didownload
      ```c
      total_image += genres[i].count;
      ```
    - Tambahkan data struct dan total gambar ke file `recap.txt`
      ```c
      fprintf(save, "%s: %d images\n", genres[i].genre, genres[i].count);
      fprintf(save, "total images: %d images\n", total_image);
      ```
- Tingkat Kesulitan : Mudah

### Problem E
- Penjelasan : Zip folder Yuan dan Bubu menjadi 1, kemudian menyimpannya sebagai file `submission.zip` pada direktori `task`
- Alur Pengkodean :
  - Fungsi **Task_E()** berguna untuk zip folder Yuan dan Bubu
    ```c
    char *args[] = {"zip", "-r", "-q", "-9", "./task/submission.zip", "./task/Yuan", "./task/Bubu", NULL};
    execvp("zip", args);
    ```
- Tingkat Kesulitan : Mudah

### Screenshot
<p align="center"><img width="auto" height="30%" src="https://github.com/sisop-its-s24/praktikum-modul-2-a04/assets/76211798/ae1e1a01-56c4-4289-89df-96698865f878"></img>

<br><br>

## Task 3
Disusun Bersama  
Source Code : [task-3](https://github.com/sisop-its-s24/praktikum-modul-2-a04/blob/main/task-3/weather_manager.c)

### Problem A
- Penjelasan : Membuat Source Code untuk mendownload file zip, mengekstraknya, menaruhnya dalam direktori yang telah ditentukan, kemudian menghapus file aslinya
- Alur Pengkodean : 
  - Fungsi `Task_A()` berguna untuk melakukan beberapa task berikut :
    - Membuat folder `weather`
      ```c
      mkdir("./weather", 0777);
      ```
    - Memanggil beberapa fungsi
      ```c
      DownloadZip();
      Task_D("Berhasil download file..");
      ExtractZip();
      Task_D("Berhasil unzip file..");
      ```
    - Menghapus file zip yang telah didownload
      ```c
      remove("weather.zip");
      ```
  - Fungsi `DownloadZip()` berguna untuk mendownload file zip dari URL yang telah ditentukan
    ```c
    char *const wgetArgs[] = {"wget", source_url, "-O", "weather.zip", NULL};
    execvp("wget", wgetArgs);
    ```
  - Fungsi `ExtractZip()` berguna untuk mengekstrak file zip yang telah didownload ke dalam direktori `weather`
    ```c
    char *const unzipArgs[] = {"unzip", "-q", "weather.zip", "-d", "./weather", NULL};
    execvp("unzip", unzipArgs);
    ```
- Tingkat Kesulitan : Mudah

### Problem B
- Penjelasan : Membuat Source Code untuk mencari data yang tidak masuk akal pada kolom `suhu_udara`
- Alur Pengkodean : 
  - Inisialisasi 2 file, file asli dan file baru
    ```c
    char old_path[] = "./weather/kecamatanforecast.csv";
    char new_path[] = "./weather/new_kecamatanforecast.csv";
    FILE *old_file = fopen(old_path, "r");
    FILE *new_file = fopen(new_path, "w");
    ```
  - Membaca setiap baris dari file asli, kemudian mencari nilai `suhu_udara`
    ```c
    while (fgets(line, sizeof(line), old_file)) {
      while (token != NULL) {
        if (count == 3) {break;}
      }
    }
    ```
  - Memberikan suatu kondisi, jika suhu adalah `integer` dan `<=35`, maka baris tersebut akan dicetak ke file baru
    ```c
    if (strcmp("X",token)) {
      int suhu = atoi(token);
      if (suhu <= 35) {
        fprintf(new_file, "%s", cetak);
      }
    }
    ```
  - Menghapus file asli
    ```c
    remove(old_path);
    ```
  - Mengganti nama file baru dengan file asli
    ```c
    rename(new_path, old_path);
    ```
- Tingkat Kesulitan : Mudah

### Problem C
- Penjelasan : Membuat Source Code untuk mengelompokkan data berdasarkan `id_lokasi` menjadi beberapa file `.csv`
- Alur Pengkodean :
  - Membuat direktori `city_group`
    ```c
    mkdir("./city_group", 0777);
    ```
  - Inisialisasi file yang telah diperbarui
    ```c
    FILE *file = fopen("./weather/kecamatanforecast.csv", "r");
    ```
  - Membaca setiap baris dari file, kemudian mencari nilai `id_lokasi`
    ```c
    while (fgets(line, sizeof(line), file)) {
      char *token = strtok(line, ",");
      if (token == NULL) {continue;}
    }
    ```
  - Mencetak setiap baris ke file `.csv` baru sesuai dengan `id_lokasi`
    ```c
    sprintf(file_tujuan, "./city_group/city_%s.csv", token);
    FILE *files = fopen(file_tujuan, "a");
    fprintf(files, "%s", cetak);
    ```
- Tingkat Kesulitan : Mudah

### Problem D
- Penjelasan : Membuat Source Code untuk mencatat setiap aktivitas yang selesai dikerjakan
- Alur Pengkodean : 
  - Fungsi `Task_D()` berguna untuk mencatat aktivitas yang selesai dikerjakan ke dalam `logbook.txt`
    ```c
    FILE *file = fopen("logbook.txt", "a");
    fprintf(file, "[%s] %s\n", timestamp, pesan);
    ```
  - Fungsi ini dipanggil oleh fungsi lain ketika aktivitas selesai dilakukan, dengan mengirimkan parameter `pesan` yang berbeda-beda
- Tingkat Kesulitan : Mudah

### Screenshot
<p align="center"><img width="auto" height="30%" src="https://github.com/sisop-its-s24/praktikum-modul-2-a04/assets/76211798/6619d69d-7e67-4dee-9de2-6863c326625e"></img>

<br><br>

## Task 4
Disusun Oleh : [**Thalyta Vius Pramesti**](https://github.com/thalytav)<br>
Source Code : [task-4](https://github.com/sisop-its-s24/praktikum-modul-2-a04/blob/8c2856f290a03354dbf1cb520bc1aa42efc4d9a4/task-4/player.c)
### Problem A
- Penjelasan : Memilih tipe pemain (‘X’ atau ‘O’) berdasarkan perintah dari program ‘player.c’.
- Alur Pengkodean :
  ```c
  // Memilih nomor pemain dan mengirimkan PID ke server
  if (strcmp(a[1], "0") == 0)
  {
    int num1 = getpid();
    sprintf(pid, "%d", num1);
    write(sockfd, pid, sizeof(pid));
    read(sockfd, a, sizeof(a));
    printf("%s\n", a[0]);
  }
  // Mengirimkan PID ke server jika pemain adalah pemain kedua
  if (strcmp(a[1], "2") == 0)
  {
    int num2 = getpid();
    sprintf(pid, "%d", num2);
    write(sockfd, pid, sizeof(pid));
  }
  ```
- Tingkat Kesulitan : Sulit
### Problem B
- Penjelasan : Program 'player.c' menampilkan kotak tic tac toe saat ini dan meminta input pengguna berupa nomor kotak sesuai gilirannya serta pada ‘game.c’ menampilkan setiap pesan yang diterima dari ‘player.c’.
- Alur Pengkodean :
    ```c
    // Menampilkan papan permainan jika bukan giliran pemain
  if (strcmp(a[1], "1") != 0)
  {
    mapBoard(numberBoard);
    printf("\n    Number Board\n\n");
    for (;;)
    {
      printf("\nPlayer %d,Please enter the number of the grid where you want to place your '%c': \n", (strcmp(a[1], "1") == 0) ? 1 : 2, (strcmp(a[1], "1") == 0) ? 'X' : 'O');
      scanf("%s", clientWrite);
      choice = atoi(clientWrite);
      row = --choice / 3;
      column = choice % 3;
      if (choice < 0 || choice > 9 || playBoard[row][column] > '9' || playBoard[row][column] == 'X' || playBoard[row][column] == 'O')
        printf("Invalid Input. Please Enter again.\n\n");
      else
      {
        playBoard[row][column] = (strcmp(a[1], "1") == 0) ? 'X' : 'O';
        break;
      }
    }
    write(sockfd, clientWrite, sizeof(clientWrite));
    mapBoard(playBoard);
    printf("\nCurrent Play Board\n\n");
  }
  // Fungsi untuk menampilkan papan permainan
  void mapBoard(char playBoard[][3])
    {
    printf(" _________________\n");
    printf("|     |     |     | \n");
    printf("|  %c  |  %c  |  %c  |\n", playBoard[0][0], playBoard[0][1], playBoard[0][2]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", playBoard[1][0], playBoard[1][1], playBoard[1][2]);
    printf("|_____|_____|_____|\n");
    printf("|     |     |     |\n");
    printf("|  %c  |  %c  |  %c  |\n", playBoard[2][0], playBoard[2][1], playBoard[2][2]);
    printf("|_____|_____|_____|\n");
    }
  ```
- Tingkat Kesulitan : Sulit
### Problem C
- Penjelasan : Mengecek apakah input user sesuai atau tidak berdasarkan nilai kotak permainan saat ini
- Alur Pengkodean :
  ```c
  // Meminta input pemain jika bukan giliran pemain
      if (te == 0)
      {
        mapBoard(numberBoard);
        printf("\n    Number Board\n\n");
      }
      for (;;)
      {
        if (te == 0)
        {
          printf("\nPlayer %d, Now your turn .. Please enter the number of the square where you want to place your '%c': \n", (strcmp(a[1], "1") == 0) ? 1 : 2, (strcmp(a[1], "1") == 0) ? 'X' : 'O');
          scanf("%s", clientWrite);
          choice = atoi(clientWrite);
          row = --choice / 3;
          column = choice % 3;
          if (choice < 0 || choice > 9 || playBoard[row][column] > '9' || playBoard[row][column] == 'X' || playBoard[row][column] == 'O')
            printf("Invalid Input. Please Enter again.\n\n");
          else
          {
            playBoard[row][column] = (strcmp(a[1], "1") == 0) ? 'X' : 'O';
            break;
          }
        }
      }
      write(sockfd, clientWrite, sizeof(clientWrite));
      mapBoard(playBoard);
      printf("\nCurrent Play Board\n\n");
      ```
- Tingkat Kesulitan : Sulit
### Problem D
- Penjelasan : Mengubah nilai pada kotak tic-tac-toe dan memutuskan apakah permainan telah selesai atau masih berlanjut.
- Alur Pengkodean :
  ```c
  // Menampilkan pesan kemenangan atau seri
      if (te == 1)
      {
        printf("Player 1 Wins!!\n");
        exit(0);
      }
      if (te == 2)
      {
        printf("Player 2 Wins!!\n");
        exit(0);
      }
      if (te == 3)
      {
        printf("Match Drawn!! No Player Wins\n");
        exit(0);
      }
    }
    // Menerima data dari server
    if (read(sockfd, clientRead, sizeof(clientRead)) > 0)
    {
      memcpy(playBoard, clientRead, sizeof(playBoard));
      mapBoard(playBoard);
      printf("\nCurrent Play Board\n\n");
      input = '\n';
      // Menampilkan pesan kemenangan atau seri
      if (te == 1)
      {
        printf("Player 1 Wins!!\n");
        exit(0);
      }
      if (te == 2)
      {
        printf("Player 2 Wins!!\n");
        exit(0);
      }
      if (te == 3)
      {
        printf("Match Drawn!! No Player Wins\n");
        exit(0);
      }
    }
    else
    {
      // Menampilkan pesan kemenangan
      printf("You Win!! Thank You, Please Play Again :D\n");
      close(sockfd);
      exit(1);
    }
    ```
- Tingkat Kesulitan : Sulit

