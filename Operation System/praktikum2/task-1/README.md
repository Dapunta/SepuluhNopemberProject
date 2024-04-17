## HORSECHAMP Horse Racing Competition Program

<div align=center>

![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/70e255f6-741c-4ff0-80a0-7f0310391103)

</div>

DJumanto is a brilliant developer who has created many cool codes. Currently, he wants to create a new project called "horsechamp", a program for horse racing competitions named [horsechamp.c](./horsechamp.c). This program has several main functions:

**HorseFetcher**: Functions to fetch horse data from here and store it in files on the computer.

**HorseRaceHooray**: Functions to conduct horse races using a file containing the data of the horses that will compete as a parameter.

**HorseChampionLeaderboard**: Functions as a display of winners from previous matches.

**Main**: Functions as an interactive terminal for users with the following options:

- Fetch Horse Data (To fetch horse data from the internet)

- Start Horse Race (To conduct horse races using horse data available in one file)

- Show Winners (To display winners from previous horse race matches)

### Tasks:

- a. Create the **HorseFetcher** function, which is tasked with fetching horse data from the internet and storing it in files named horse_1.txt, horse_2.txt, horse_3.txt, and so on. The horses and it’s owner are separated by “:”, for example “Morioh:DJumanto”, DJumanto is the owner of Morioh.

- b. Create the **HorseRaceHooray** function, which is tasked with conducting horse races. The function use one of the horse data that you fetch before as parameter. Use threading to run the race. Each horse will perform prime number calculation with random numbers between 1 and 4000. The horse that completes the calculation first will occupy a higher position than other horses. After the race is completed, save the race results in the format HorseRace\_(race number).txt. An example of the file contents format is as follows:

  ```
  ai: horse position
  H: Horse Name
  O: Horse Owner Name
  X: Number used by the horse to guess whether the number is prime or not
  ```

  An example output is as follows:

  ```
  ----Horse Race (Which race is being held)------
  Date: DD/MM/YYYY
  Time: HH/MM/SS

  ai. H O X
  ai+1. H O X
  ai+2. H O X
  etc..
  a+n. H O X
  ```

- c. Create the **HorseChampionLeaderboard** function, which is tasked with displaying the winners of previous matches. Provide options for users to choose which race they want to see the results of. An example of options:

  ```
  Choose your Horse Race history:

  Horse Race 1
  Horse Race 2
  Horse Race 3
  Horse Race 4
  etc..
  ```

  The output format is as follows:

  ```
  ai: position order
  H: horse name
  O: owner name
  N: Number used to guess
  ```

  An example output is as follows:

  ```
  ----HORSE CHAMPIONSHIP (Which race is being held)----
  Date: DD/MM/YYYY
  Time: HH/MM/SS

  ai. H O X
  ai+1. H O X
  ai+2. H O X
  ai+3. H O X
  etc…
  ai+n. H O X
  ```

## Program Lomba Balapan Kuda HORSECHAMP

<div align=center>

![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/70e255f6-741c-4ff0-80a0-7f0310391103)

</div>

DJumanto adalah seorang pengembang hebat yang telah menciptakan banyak kode keren. Saat ini, ia ingin membuat sebuah proyek baru yang disebut "horsechamp", sebuah program untuk lomba balapan kuda bernama [horsechamp.c](./horsechamp.c). Program ini memiliki beberapa fungsi utama:

**HorseFetcher**: Berfungsi untuk mengambil data kuda dari sini dan menyimpannya di komputer.

**HorseRaceHooray**: Berfungsi untuk melaksanakan balapan kuda dengan menggunakan file yang berisi data kuda yang akan bertanding sebagai parameter.

**HorseChampionLeaderboard**: Berfungsi sebagai penampil pemenang dari pertandingan yang telah terjadi sebelumnya.

**Main**: Berfungsi sebagai terminal interaktif untuk pengguna dengan pilihan-pilihan berikut:

- Fetch Horse Data (Untuk mengambil data kuda dari internet)

- Start Horse Race (Untuk melaksanakan balapan kuda menggunakan data kuda yang ada dalam satu file)

- Show Winners (Untuk menampilkan pemenang dari pertandingan kuda yang telah terjadi sebelumnya)

### Tugas:

- a. Buatlah fungsi **HorseFetcher**, yang bertugas mengambil data kuda dari internet dan menyimpannya dalam file dengan nama horse_1.txt, horse_2.txt, horse_3.txt, dan seterusnya. Kuda dan pemilik kuda dipisahkan dengan “:”, sebagai contoh “Morioh:DJumanto”, DJumanto adalah pemilik dari kuda Morioh

- b. Buatlah fungsi **HorseRaceHooray**, yang bertugas melaksanakan balapan kuda. Parameter yang diguakan adalah salah satu file kuda yang telah kalian fetch sebelumnya. Gunakan thread untuk menjalankan perlombaan tersebut. Setiap kuda akan melakukan perhitungan bilangan prima dengan angka acak antara 1 sampai 4000. Kuda yang menyelesaikan perhitungan lebih awal akan menempati posisi lebih tinggi dari kuda lainnya. Setelah perlombaan selesai, simpan hasil lomba dalam format HorseRace\_(nomor lomba).txt.

  Contoh format isi file adalah sebagai berikut:

  ```
  ai: posisi kuda
  H: Nama Kuda
  O: Nama Pemilik Kuda
  X: Angka yang digunakan kuda untuk menebak apakah angka tersebut prima atau tidak
  ```

  Contoh hasil output:

  ```
  ----Horse Race (Lomba keberapa dilaksanakan)------
  Date: DD/MM/YYYY
  Time: HH/MM/SS

  ai. H O X
  ai+1. H O X
  ai+2. H O X
  etc..
  a+n. H O X
  ```

- c. Buatlah fungsi **HorseChampionLeaderboard**, yang bertugas menampilkan pemenang dari pertandingan-pertandingan sebelumnya. Berikan opsi kepada pengguna untuk memilih lomba mana yang ingin dilihat hasilnya. Contoh opsi:

  ```
  Choose your Horse Race history:

  1. Horse Race 1
  2. Horse Race 2
  3. Horse Race 3
  4. Horse Race 4
  etc..
  ```

  Hasil output memiliki format sebagai berikut:

  ```
  ai: urutan posisi
  H: nama kuda
  O: nama pemilik
  N: Angka yang digunakan untuk menebak
  ```

  Contoh output adalah seperti berikut:

  ```
  ----HORSE CHAMPIONSHIP (lomba keberapa dilaksanakan)----
  Date: DD/MM/YYYY
  Time: HH/MM/SS

  ai. H O X
  ai+1. H O X
  ai+2. H O X
  ai+3. H O X
  etc…
  ai+n. H O X
  ```
