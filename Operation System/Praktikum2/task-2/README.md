## Yuan's and Bubu's Final Project

Yuan and Bubu have been tasked with downloading images by their lecturer, but with a few challenges. They are given a folder containing random files. In this folder, there are several files containing instructions regarding the images that Yuan and Bubu have to download.

- a. Firstly, they need to download a zip file from the [following link](https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0), extract it, and then delete the zip file. After that, they have to create a new folder named “task” and move the files related to the instructions into the “task” folder. The related files have names starting with "**task\_{id}**" and have a **txt** extension. Then delete the previous zip result folder. Here's the structure of the "task" folder:

  ```
  task/
  ├── task_0_2CtQxvh068.txt
  ├── task_1_zWjksQCero.txt
  ├── task_2_s7MsIw5hHW.txt
  └── etc
  ```

- b. Yuan and Bubu efficiently divide the tasks by working on them simultaneously **(overlapping)** and divide it equally. Yuan will work on tasks from the beginning, while Bubu from the end. For example, if there are 20 tasks, Yuan will start from task0-task1-etc and Bubu will start from task19-task18-etc. Then create a file “rekap.txt” which stores a log each time they finish a task (criteria for each task will be explained in point c), with the following format:

  ```
  [{time}]-[{name}] Task {id} completed, download {amount} {category} images with {resolution} resolution
  ```

  For example:

  ```
  [2024-03-24 17:06:54]-[Yuan] Task 0 completed, download 1 nature images with 200x150 resolution
  [2024-03-24 17:06:58]-[Bubu] Task 19 completed, download 3 city images with 250x200 resolution
  ```

- c. Yuan and Bubu find instructions in each txt task file with the format "**{amount} {resolution} {category}**". They have to download images according to the specified amount, resolution, and category. For example, if task0 contains "5 250x150 music", they download 5 images sized 250x150 in the music category. The images are downloaded from [unsplash.com](unsplash.com) and stored alongside each task's txt file based on the person who does the task according to the following folder structure as follows:

  ```
  task/
  ├── Yuan/
  │ ├── task0/
  │ │ ├── task_0_2CtQxvh068.txt
  │ │ ├── image1.png
  │ │ ├── image2.png
  │ │ └── etc.
  │ ├── task1/
  │ ├── ...
  │ └── task9/
  ├── Bubu/
  │ ├── task19/
  │ ├── task18/
  │ ├── ...
  │ └── task10/
  └── rekap.txt
  ```

- d. After all tasks are completed, they add the number of images from each category to "rekap.txt". and on the last line, add the total number of downloaded images, for example:

  ```
  music: 20 images
  city: 10 images
  total images: 30 images
  ```

- e. As the tasks are ready to be submitted, zip Yuan and Bubu's folders into one zip file named submission.zip and **DO NOT DELETE** the original folder, leaving the folder structure as follows:

  ```
  task/
  ├── Yuan/
  ├── Bubu/
  ├── submission.zip
  └── rekap.txt
  ```

### Notes:

- **DO NOT USE SYSTEM() IN THIS QUESTION.**

- Use `exec()` and `fork()` to do all the above processes.

- The task program is executed once for all the points above.

- The images downloaded for each task are random images but must match the criteria starting from the
  number of images, size and image category.

- Point d is the number of images for each category from all tasks, it is not allowed to output
  categories that have been written previously.

- Only the [task.c](./task.c) and [recap.txt](./recap.txt) files are pushed on github.

## Tugas Akhir Yuan dan Bubu

Yuan dan Bubu ditugaskan untuk mengunduh gambar oleh dosennya, namun dengan beberapa tantangan. Mereka diberikan satu folder yang berisikan file random. Dimana pada folder tersebut, terdapat beberapa file yang berisi petunjuk terkait gambar yang harus diunduh oleh Yuan dan Bubu.

- a. Pertama-tama, mereka harus mengunduh sebuah file zip dari [link berikut](https://dl.dropboxusercontent.com/scl/fi/gmy0qvbysh3h7vdexso9k/task_sisop.zip?rlkey=ism9qfjh82awg2tbtzfbrylg4&dl=0), kemudian mengekstraknya dan menghapus file zip tersebut. Setelah itu, mereka harus membuat folder baru dengan nama “task” dan memindahkan file yang berkaitan dengan petunjuk ke dalam folder “task”. File yang berkaitan memiliki penamaan dengan awalan "**task\_{id}**" dan berekstensi **txt**. Lalu hapus folder hasil zip sebelumya. Berikut struktur folder “task”:

  ```
  task/
  ├── task_0_2CtQxvh068.txt
  ├── task_1_zWjksQCero.txt
  ├── task_2_s7MsIw5hHW.txt
  └── dst.
  ```

- b. Yuan dan Bubu membagi tugas secara efisien dengan mengerjakannya secara bersamaan **(overlapping)** dan membaginya sama banyak. Yuan akan mengerjakan task dari awal, sementara Bubu dari akhir. Misalnya, jika ada 20 task, Yuan akan memulai dari task0-task1-dst dan Bubu akan memulai dari task19-task18-dst. Lalu buatlah file “recap.txt” yang menyimpan log setiap kali mereka selesai melakukan task (kriteria setiap task akan dijelaskan di poin c), dengan format sebagai berikut:

  ```
  [{time}]-[{name}] Task {id} completed, download {jumlah} {kategori} images with {resolusi} resolution
  ```

  Contoh :

  ```
  [2024-03-24 17:06:54]-[Yuan] Task 0 completed, download 1 nature images with 200x150 resolution
  [2024-03-24 17:06:58]-[Bubu] Task 19 completed, download 3 city images with 250x200 resolution
  ```

- c. Yuan dan Bubu menemukan petunjuk dalam setiap file task txt dengan format "**{jumlah} {resolusi} {kategori}**". Mereka harus mengunduh gambar sesuai dengan jumlah, resolusi, dan kategori yang disebutkan. Contohnya, jika task0 berisi "5 250x150 music", mereka mengunduh 5 gambar berukuran 250x150 dalam kategori music. Gambar diunduh dari [unsplash.com](unsplash.com) dan disimpan bersama file txt setiap task berdasarkan orang yang mengerjakan task sesuai struktur folder sebagai berikut:

  ```
  task/
  ├── Yuan/
  │   ├── task0/
  │   │   ├── task_0_2CtQxvh068.txt
  │   │   ├── gambar1.png
  │   │   ├── gambar2.png
  │   │   └── dst.
  │   ├── task1/
  │   ├── ...
  │   └── task9/
  ├── Bubu/
  │   ├── task19/
  │   ├── task18/
  │   ├── ...
  │   └── task10/
  └── rekap.txt
  ```

- d. Setelah semua tugas selesai, mereka menambahkan jumlah gambar dari setiap kategori ke dalam "recap.txt". dan pada baris terakhir tambahkan jumlah seluruh gambar yg di unduh, contoh:

  ```
  music: 20 images
  city: 10 images
  total images: 30 images
  ```

- e. Karena tugas sudah siap dikumpulkan, zip folder Yuan dan Bubu menjadi satu zip bernamakan submission.zip dan **JANGAN HAPUS** folder aslinya sehingga menyisakan struktur folder sebagai berikut:

```
task/
├── Yuan/
├── Bubu/
├── submission.zip
└── recap.txt
```

### Catatan:

- **DILARANG MENGGUNAKAN SYSTEM() PADA SOAL INI.**

- Gunakan `exec()` dan `fork()` untuk melakukan semua proses di atas.

- Program task dijalankan satu kali untuk seluruh poin di atas.

- Gambar yang diunduh setiap task merupakan gambar random namun harus sesuai dengan kriteria mulai dari
  jumlah gambar, ukuran, dan kategori gambar.

- Poin d merupakan jumlah gambar setiap kategori dari seluruh task, tidak diperbolehkan mengoutputkan
  kategori yang sudah ditulis sebelumnya.

- Hanya file [task.c](./task.c) dan [recap.txt](./recap.txt) yang dikumpulkan di github.
