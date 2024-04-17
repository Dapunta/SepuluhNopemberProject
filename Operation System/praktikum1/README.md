[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/nyzv0V02)
<div align=center>

|    NRP     |             Name             |
| :--------: | :--------------------------: |
| 5025231055 | Thalyta Vius Pramesti        |
| 5025231187 | Dapunta Adyapaksi Ratyanasja |
| 5025231057 | Alif Nurrohman               |

# **Praktikum Modul 1 _(Module 1 Lab Work)_**

</div>

### Daftar Soal _(Task List)_
- [Task 1 - Tim Kawal Bubu _(Bubu's Monitoring Team)_](/task-1/)
- [Task 2 - Gabut Yuan _(Yuan's Boredom)_](/task-2/)
- [Task 3 - Magang Bubu _(Bubu's Internship)_](/task-3/)
- [Task 4 - LDR Isabel _(Isabel Sad Relationship)_](/task-4/)

### Daftar Jawaban
- [Task 1](#task-1) : [Problem A](#problem-a), [Problem B](#problem-b), [Problem C](#problem-c)
- [Task 2](#task-2) : [Problem A](#problem-a-1), [Problem B](#problem-b-1), [Problem C](#problem-c-1)
- [Task 3](#task-3) : [Problem A](#problem-a-2), [Problem B](#problem-b-2), [Problem C](#problem-c-2)
- [Task 4](#task-4)

<br><br>  

<div align=center>

# *Laporan Resmi Praktikum Modul 1<br>_(Module 1 Lab Work Report)_*

</div>

<br>

## Task 1
Disusun Oleh : [**Thalyta Vius Pramesti**](https://github.com/thalytav)

### Problem A
- Deskripsi : Menampilkan nama pengusul beserta departemennya yang memiliki judul proposal PKM lebih dari 20 kata dan memisahkan dengan spasi serta menghapus underscore.
- Source Code : [pkm-a.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-1/pkm-a.sh)
- Alur Pengkodean :
  1. Menggunakan perintah awk untuk memproses file DataPKM.tsv
  2. Memproses setiap baris data
  3. Menghitung jumlah kata dalam judul proposal
  4. Mencetak nama pengusul beserta departemennya
- Screenshot :
<p align="center"><img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/dcc045bb-fe9d-45ee-9eae-3143d06dc2b0"></img>

- Tingkat Kesulitan : Mudah

### Problem B
- Deskripsi : Menampilkan nama skema PKM yang paling diminati mahasiswa
- Source Code : [pkm-b.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-1/pkm-b.sh)
- Alur Pengkodean :
  1. Menggunakan perintah awk untuk memproses file DataPKM.tsv
  2. Menghitung jumlah proposal untuk setiap bidang penelitian
  3. Mengurutkan bidang penelitian berdasarkan jumlah proposal dari yang terbanyak hingga tersedikit
  4. Mencetak bidang penelitian dengan jumlah proposal terbanyak
- Screenshot :
<p align="center"><img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/3885e543-c277-4138-9c54-99b2ff7675c0"></img>

- Tingkat Kesulitan : Mudah

### Problem C
- Deskripsi : Menampilkan list mahasiswa yang mengajukan 2 proposal PKM serta pembimbingnya
- Source Code : [pkm-c.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-1/pkm-c.sh)
- Alur Pengkodean :
  1. Menggunakan perintah awk untuk memproses file DataPKM.tsv
  2. Menghitung jumlah proposal untuk tiap mahasiswa
  3. Menyimpan nama lengkap mahasiswa untuk setiap dosen pembimbing
  4. Mencetak nama lengkap mahasiswa yang mengajukan 2 proposal beserta nama dosen pembimbing
- Screenshot :
<p align="center"><img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/7848fa5c-96c3-4699-80da-e3d4fd73ef07"></img>

- Tingkat Kesulitan : Mudah

<br>

## Task 2
Disusun Oleh : [**Dapunta Adyapaksi Ratyanasja**](https://github.com/Dapunta)

### Problem A
- Deskripsi : Membuat Source Code Login untuk mencatat segala percobaan login
- Source Code : [yu_login.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-2/yu_login.sh)
- Alur Pengkodean :
  - Mengambil input username dan password dari pengguna
    ```bash
    read -p "Username : " username
    read -p "Password : " user_password
    ```
  - Mendeteksi file `data-pkm.csv` sebagai database dan file `log.txt` sebagai lokasi output
    ```bash
    file_path="../resources/data-pkm.csv"
    log_file="log.txt"
    ```
  - Melakukan looping untuk setiap baris dalam file, kemudian memberi kondisi jika **username** dan **password** yang telah diinput oleh user tadi cocok/tersedia dalam baris itu, maka user berhasil login
    ```bash
    while IFS=',' read -r no nama_pengusul...
      if [ "$nama_depan" == "$username" ]; then...
        if [ "$user_password" == "$password" ]; then...
    ```
  - Segala percobaan registrasi akan dicatat pada `log.txt`, baik yang berhasil maupun gagal
    ```bash
    logger() {
      echo "$(date +"%y/%m/%d %H:%M:%S") $1" >> "$log_file"
    }
    ```
- Screenshot :
<p align="center"><img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/ca390b0f-c6cf-4d91-b218-bbdf7b0d1dc2"></img>

- Tingkat Kesulitan : Mudah

### Problem B
- Deskripsi : Membuat Source Code Register untuk mencatat segala percobaan registrasi dan menambah data baru
- Source Code : [yu_register.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-2/yu_register.sh)
- Alur Pengkodean :
  - Mendeteksi file `data-pkm.csv` sebagai database dan file `log.txt` sebagai lokasi output
    ```bash
    file_path="../resources/data-pkm.csv"
    log_file="log.txt"
    ```
  - Mengambil input Nama_Pengusul, Departemen, Fakultas, Judul, Pendamping (NIDN), dan Skema dari user
    ```bash
    read -p "Nama Pengusul : " nama_pengusul
    read ...
    ```
  - Mengecek apakah username sudah ada dalam database, jika sudah maka tidak bisa mendaftar
    ```bash
    if grep -q ",${nama_pengusul}," $file_path; then
      echo "Registrasi Gagal! Username Sudah Ada."
    ```
  - Jika username belum terdaftar, user bisa melanjutkan proses registrasi, kemudian data baru akan ditambahkan ke file `data-pkm.csv`
    ```bash
    new_line=$(printf "\n%s,%s,%s,%s,%s,%s,%s" "$proposal_number" "$nama_pengusul" "$departemen" "$fakultas" "$judul" "$pendamping" "$skema")
    echo -n "$new_line" >> "$file_path"
    ```
  - Segala percobaan registrasi akan dicatat pada `log.txt`, baik yang berhasil maupun gagal
    ```bash
    logger() {
      echo "$(date +"%y/%m/%d %H:%M:%S") $1" >> "$log_file"
    }
    ```
- Screenshot :
<p align="center"><img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/3e72205e-a3a4-4763-b524-1c2c654f13d5"></img>

- Tingkat Kesulitan : Mudah

### Problem C
- Deskripsi : Membuat Source Code automasi untuk menyimpan username dan password ke dalam file lain
- Source Code : [yu_database.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-2/yu_database.sh)
- Alur Pengkodean :
  - Mendeteksi file `data-pkm.csv` sebagai source awal dan file `users.txt` sebagai lokasi output
    ```bash
    file_path="../resources/data-pkm.csv"
    log_file="users.txt"
    ```
  - Membaca setiap baris file untuk menemukan _username_ dan _password_
    ```bash
    while IFS=',' read -r no nama_pengusul...
      username=$(echo "$nama_pengusul"...
      ...
    ```
  - Menyimpan username dan password dalam file `users.txt`
    ```bash
    new=$(printf "\n%s,%s,%s" "$no" "$username" "$password")
    echo -n "$new" >> "$result"
    ```
  - Mengatur sistem automasi pada crontab. File bash tersebut akan dijalankan pada menit ke-0 setiap jamnya.
    ```bash
    0 * * * * chmod +x yu_database.sh && ./yu_database.sh
    ```
- Screenshot :
<p align="center"><img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/7492ccd4-d7c8-4fe8-ba0a-f5e911006ec4"></img>

- Tingkat Kesulitan :
  - File bash : Mudah
  - File cron : Sulit

<br>

## Task 3
Disusun Oleh : [**Alif Nurrohman**](https://github.com/alifnurrohmans)

### Problem A
- Deksripsi : Membuat File Log untuk Monitoring RAM dan Size Suatu Directory
- Source Code : [minute_log.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-3/minute_log.sh)
- Alur Pengkodean :
  - Membuat function monitor metrics, yang menjalankan :
    1. Mengambil nilai metrics ram
    ```bash
    ram_metrics=$(free -m | awk 'NR==2 {
    total_ram=$2;              # Nilai kolom kedua adalah Total RAM
    used_ram=$3;               # Nilai kolom ketiga adalah RAM yang digunakan
    free_ram=$4;               # Nilai kolom keempat adalah RAM yang tersedia atau bebas
    shared_ram=$5;             # Nilai kolom kelima adalah RAM yang digunakan untuk alokasi memori bersama
    buffer_ram=$6;             # Nilai kolom keenam adalah RAM yang digunakan untuk buffering data
    available_ram=$7;          # Nilai kolom ketujuh adalah RAM yang tersedia untuk penggunaan, termasuk yang bebas dan yang digunakan untuk buffering

    # Menggabungkan nilai-nilai di atas dalam satu string yang dipisahkan dengan koma (,)
    print total_ram "," used_ram "," free_ram "," shared_ram "," buffer_ram "," available_ram
    }')
    ```
    2. Mengambil nilai swap
    ```bash
    swap_metrics=$(free -m | awk 'NR==3 {
    swap_total=$2;      # Nilai kolom kedua adalah Total Swap
    swap_used=$3;       # Nilai kolom ketiga adalah Swap yang digunakan
    swap_free=$4;       # Nilai kolom keempat adalah Swap yang tersedia atau bebas

    # Menggabungkan nilai-nilai di atas dalam satu string yang dipisahkan dengan koma (,)
    print swap_total "," swap_used "," swap_free
    }')
    ```
    3. Mengambil path yang di monitor dan size nya
    ```bash
    directory_path="/home/anonymous"                                #directory yang akan di cek sizenya
    directory_size=$(du -sh $directory_path | awk '{print $1}')     #cek size dengan du -sh <path>
    ```
    4. Tampilkan hasil metrics ram, swap, path, dan sizenya sesuai format yang diberikan, yaitu : 
    "mem_total,mem_used,mem_free,mem_shared,mem_buff,mem_available,swap_total,swap_used,swap_free,path,path_size"
    ```bash
    echo "mem_total,mem_used,mem_free,mem_shared,mem_buff,mem_available,swap_total,swap_used,swap_free,path,path_size" >> /home/anonymous/metrics/metrics_$(date "+%Y%m%d%H%M%S").log
    echo "$ram_metrics, $swap_metrics, $directory_path, $directory_size" >> /home/anonymous/metrics/metrics_$(date "+%Y%m%d%H%M%S").log
    ```
  - Jalankan function yang sudah dibuat
  ```bash
  # Main function
  main() {
      monitor_metrics
  }
  
  main
  ```

- Screenshot : 
<p align="center"><img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/fac37444-bfb9-42c9-9ee7-7b6713cb1383"></img>

- Tingkat Kesulitan : Sedang


### Problem B
- Deksripsi : Menjalankan Script diatas otomatis setiap 1 Menit Sekali
- Source Code : [crontabs](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-3/crontabs)
- Membuat Crontab Seperti Berikut :
  ```bash
  * * * * * /home/anonymous/minute_log.sh  
  ```
- Tingkat Kesulitan : Mudah


### Problem C
- Deksripsi : Membuat Script untuk Aggregasi File minute_log.sh
- Source Code : [aggregate_minutes_to_hourly_log.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-3/aggregate_minutes_to_hourly_log.sh)
- Alur Pengkodean :
  1. Siapkan Nama file Log yang akan di Aggregasi dan Buat File Aggregasi Sesuai Format "metrics_agg_{YmdH}.log"
    ```bash
    # Mendapatkan waktu saat ini dalam format YmdH
    current_hour=$(date "+%Y%m%d%H")
    
    # Pola nama file log
    file_pattern="/home/anonymous/metrics/metrics_$current_hour*.log"
    
    # Mendapatkan direktori log
    log_dir="/home/anonymous/metrics"
    
    # Membuat file log untuk hasil agregasi
    aggregate_log_file="$log_dir/metrics_agg_$current_hour.log"
    
    # membuat file
    touch $aggregate_log_file
    ```
  2. Deklarasikan Variable yang Dibutuhkan
    ```bash
    jumlah_loop=0
    #untuk rata"
    mem_total=0
    mem_used=0
    mem_free=0
    mem_shared=0
    mem_buff=0
    mem_available=0
    swap_total=0
    swap_used=0
    swap_free=0
    
    path_size=0
    
    #untuk minimum
    min_mem_total=0
    min_mem_used=0
    min_mem_free=0
    min_mem_shared=0
    min_mem_buff=0
    min_mem_available=0
    min_swap_total=0
    min_swap_used=0
    min_swap_free=0
    min_path_size=0
    
    #untuk maximum
    max_mem_total=0
    max_mem_used=0
    max_mem_free=0
    max_mem_shared=0
    max_mem_buff=0
    max_mem_available=0
    max_swap_total=0
    max_swap_used=0
    max_path_size=0
    ```
  3. Looping Setiap File minute_log.sh dan Aggregasi (Minimum, Maximum, Average)
    ```bash
    # Loop melalui setiap file yang cocok dengan pola
    for file in $file_pattern; do
        # Pastikan file yang ada adalah file reguler
        if [ -f "$file" ]; then
            # Baca baris kedua dari file log
            line=$(head -n 2 "$file" | tail -n 1)
            
            # Atur IFS ke koma
            IFS=',' read -ra data <<< "$line"
    
            # konversi path size dari 60m > 60
            path_size_number=$(echo "${data[10]}" | sed 's/[^0-9]*//g')
    
            # mencari rata-rata
            # tambah nilai loop
            jumlah_loop=$((jumlah_loop+1))
            # Simpan setiap elemen ke dalam variabel
            mem_total=$((mem_total + ${data[0]}))
            mem_used=$((mem_used + ${data[1]}))
            mem_free=$((mem_free + ${data[2]}))
            mem_shared=$((mem_shared + ${data[3]}))
            mem_buff=$((mem_buff + ${data[4]}))
            mem_available=$((mem_available + ${data[5]}))
            swap_total=$((swap_total + ${data[6]}))
            swap_used=$((swap_used + ${data[7]}))
            swap_free=$((swap_free + ${data[8]}))
            path_size=$((path_size + path_size_number))
    
            # ambil data pertama untuk di cek data selanjutnya (khusus minimal)
            if [ $jumlah_loop -eq 1 ]; then 
                min_mem_total=${data[0]}
                min_mem_used=${data[1]}
                min_mem_free=${data[2]}
                min_mem_shared=${data[3]}
                min_mem_buff=${data[4]}
                min_mem_available=${data[5]}
                min_swap_total=${data[6]}
                min_swap_used=${data[7]}
                min_swap_free=${data[8]}
                min_path_size=${path_size_number}
            fi
    
            # min max
            if (( ${data[0]} < min_mem_total )); then min_mem_total=${data[0]}; fi
            if (( ${data[0]} > max_mem_total )); then max_mem_total=${data[0]}; fi
            if (( ${data[1]} < min_mem_used )); then min_mem_used=${data[1]}; fi
            if (( ${data[1]} > max_mem_used )); then max_mem_used=${data[1]}; fi
            if (( ${data[2]} < min_mem_free )); then min_mem_free=${data[2]}; fi
            if (( ${data[2]} > max_mem_free )); then max_mem_free=${data[2]}; fi
            if (( ${data[3]} < min_mem_shared )); then min_mem_shared=${data[3]}; fi
            if (( ${data[3]} > max_mem_shared )); then max_mem_shared=${data[3]}; fi
            if (( ${data[4]} < min_mem_buff )); then min_mem_buff=${data[4]}; fi
            if (( ${data[4]} > max_mem_buff )); then max_mem_buff=${data[4]}; fi
            if (( ${data[5]} < min_mem_available )); then min_mem_available=${data[5]}; fi
            if (( ${data[5]} > max_mem_available )); then max_mem_available=${data[5]}; fi
            if (( ${data[6]} < min_swap_total )); then min_swap_total=${data[6]}; fi
            if (( ${data[6]} > max_swap_total )); then max_swap_total=${data[6]}; fi
            if (( ${data[7]} < min_swap_used )); then min_swap_used=${data[7]}; fi
            if (( ${data[7]} > max_swap_used )); then max_swap_used=${data[7]}; fi
            if (( ${data[8]} < min_swap_free )); then min_swap_free=${data[8]}; fi
            if (( ${data[8]} > max_swap_free )); then max_swap_free=${data[8]}; fi
            
            # Periksa apakah path_size_number lebih kecil dari min_path_size
            if (( path_size_number < min_path_size )); then
                min_path_size=$path_size_number
            fi
    
            # Periksa apakah path_size_number lebih besar dari max_path_size
            if (( path_size_number > max_path_size )); then
                max_path_size=$path_size_number
            fi
        fi
    done
    ```
  4. Cari Rata" Setelah Dijumlahkan
    ```bash
    # hitung nilai rata"
    # Fungsi untuk melakukan perhitungan float menggunakan awk
    calc_float() {
        awk "BEGIN {printf \"%.2f\", $1}"
    }
    
    # Menghitung rata-rata dalam float
    avg_mem_total=$(calc_float "$mem_total/$jumlah_loop")
    avg_mem_used=$(calc_float "$mem_used/$jumlah_loop")
    avg_mem_free=$(calc_float "$mem_free/$jumlah_loop")
    avg_mem_shared=$(calc_float "$mem_shared/$jumlah_loop")
    avg_mem_buff=$(calc_float "$mem_buff/$jumlah_loop")
    avg_mem_available=$(calc_float "$mem_available/$jumlah_loop")
    avg_swap_total=$(calc_float "$swap_total/$jumlah_loop")
    avg_swap_used=$(calc_float "$swap_used/$jumlah_loop")
    avg_swap_free=$(calc_float "$swap_free/$jumlah_loop")
    avg_path_size=$(calc_float "$path_size/$jumlah_loop")
    ```
  5. Tampilkan Hasil Aggregasi Sesuai Format yang Diberikan kedalam File Aggregasi
    ```bash
    echo "type,mem_total,mem_used,mem_free,mem_shared,mem_buff,mem_available,swap_total,swap_used,swap_free,path,path_size"  >> "$aggregate_log_file"
    echo "Minimum,$min_mem_total,$min_mem_used,$min_mem_free,$min_mem_shared,$min_mem_buff,$min_mem_available,$min_swap_total,$min_swap_used,$min_swap_free,$log_dir,${min_path_size}M"  >> "$aggregate_log_file"
    echo "Maximum,$max_mem_total,$max_mem_used,$max_mem_free,$max_mem_shared,$max_mem_buff,$max_mem_available,$max_swap_total,$max_swap_used,$max_swap_free,$log_dir,${max_path_size}M"  >> "$aggregate_log_file"
    echo "Average,$avg_mem_total,$avg_mem_used,$avg_mem_free,$avg_mem_shared,$avg_mem_buff,$avg_mem_available,$avg_swap_total,$avg_swap_used,$avg_swap_free,$log_dir,${avg_path_size}M"  >> "$aggregate_log_file"
    ```

  6. Tambahkan Isi File Crontab Agar Dijalankan Setiap Jam atau di Menit 59 :
  ```bash
  59 * * * * /home/anonymous/aggregate_minutes_to_hourly_log.sh 
  ```
     
- Tingkat Kesulitan : Sulit

### Problem C
- Deksripsi : Membuat Script untuk Aggregasi File minute_log.sh
- Source Code : [aggregate_minutes_to_hourly_log.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-3/aggregate_minutes_to_hourly_log.sh)
- Alur Pengkodean :
  a. Siapkan Nama File yang Dibutuhkan
    ```bash
    #!/bin/bash
    # Mendapatkan tanggal dan jam saat ini dalam format YmdH
    current_datetime=$(date "+%Y%m%d%H")
    
    # Nama file untuk menyimpan semua log metrics aggregasi dalam satu file .gz
    backup_file="backup_metrics_${current_datetime}.gz"
    
    # Pola nama file log yang ingin Anda agregasikan
    file_pattern="/home/anonymous/metrics/metrics_agg_${current_datetime:0:8}*.log" #0:8 artinya ambil 8 huruf pertama
    
    # Mendapatkan direktori log
    log_dir="/home/anonymous/metrics"
    ```
  b. Tampilkan
    ```bash
    # Menggabungkan semua file log yang cocok dengan pola ke dalam satu file
    cat $file_pattern | gzip > "$log_dir/$backup_file"
    
    echo "Logs aggregated and saved to $log_dir/$backup_file"
    ```
- Tingkat Kesulitan : Mudah

### Problem E
- Deksripsi : Membuat Akses File Hanya Untuk User Yang Membuat
- Source Code :
  ```bash
  sudo setfacl -R -m u::r-x /home/anonymous/metrics 
  ```
- Tingkat Kesulitan : Mudah

<br>

## Task 4
Disusun Bersama
- Deskripsi :
  - Problem A : Membuat Source Code untuk mendownload gambar _Mingyu Seventeen_ setiap 5 jam sekali dengan path dan format file yang telah ditentukan
  - Problem B : Membuat Source Code untuk menyatukan folder yang telah dibuat menjadi file zip setiap 10 jam sekali
  - Problem C : Membuat Source Code untuk menghapus semua folder dan zip setiap hari pada pukul 02.00
  - Problem D : Membuat Source Code untuk mendownload gambar Levi dan Eren secara bergantian setiap hari
- Source Code : [isabel.sh](https://github.com/sisop-its-s24/praktikum-modul-1-a04/blob/main/task-4/isabel.sh)
- Run Code Manually :
  - Problem A
    ```bash
    bash path_to_file/isabel.sh 1
    ```
  - Problem B
    ```bash
    bash path_to_file/isabel.sh 2
    ```
  - Problem C
    ```bash
    bash path_to_file/isabel.sh 3
    ```
  - Problem D
    ```bash
    bash path_to_file/isabel.sh 4
    ```
- Alur Pengkodean :
  - `Problem A`
    - File bash diexecute dengan menambahkan argumen 1
    - Program akan membaca waktu saat dijalankan, dengan menyimpannya ke variabel `time_`
    - Program akan membuat path menuju folder untuk menyimpan kumpulan gambar yang akan didownload. Jika folder sudah tersedia, maka program akan membuat path baru sesuai dengan loopnya.
    - Program akan mendownload gambar sebanyak jumlah yang telah ditentukan dengan kondisi waktunya kemudian akan menyimpannya ke dalam folder yang telah dibuat
  - `Problem B`
    - File bash diexecute dengan menambahkan argumen 2
    - Program mendeteksi file zip. Jika file zip sudah tersedia, maka program akan membuat file zip baru dengan nama sesuai loop setelahnya
    - Program akan membaca semua folder yang ada dalam path, kemudian menyatukannya ke dalam file zip tadi.
  - `Problem C`
    - File bash diexecute dengan menambahkan argumen 3
    - Program akan menghapus semua folder dan file zip yang ada dalam path
  - `Problem D`
    - File bash diexecute dengan menambahkan argumen 4
    - Program akan membaca waktu saat dijalankan, dengan menyimpannya ke variabel `date_` dan `tanggal`
    - Program membuat folder `AttackOnTitan`. Jika folder sudah tersedia, maka skip
    - Program akan mendownload gambar dengan ketentuan :
      - Jika tanggal genap, maka mendownload gambar Levi
      - Jika tanggal ganjil, maka mendownload gambar Eren
    - Program akan menyimpan gambar yang telah didownload ke dalam folder `AttackOnTitan`
- Screenshot :
<p align="center">
<img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/0a1db6c7-61f8-465f-b4e9-01ee25a8a82c"></img>
<img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/7e7ef96d-afd1-4637-aedf-2dd5aae9c90c"></img>
<img width="80%" height="auto" src="https://github.com/sisop-its-s24/praktikum-modul-1-a04/assets/76211798/b3aba3ef-2f04-42b0-84a2-933646ad0a17"></img>

- Tingkat Kesulitan :
  - File bash : Mudah
  - File cron : Sulit
