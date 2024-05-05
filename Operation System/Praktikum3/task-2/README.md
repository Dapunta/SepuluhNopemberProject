## BNBWT

<div align=center>

![unnamed](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/2dbce2c6-9a0e-497b-9c66-6a984d03d9b4)

</div>

Ben White, a footballer who dazzles with his skills on the pitch, is confidently performing as a key player for Arsenal. One day, he performed so badly against Munich that it made one of the gods of the isekai world, Justok, very angry. Justok forcibly sent Ben White to his world called Aztec, to be taken and punished by the Pillar Men.

Ben White was told to choose 1 of 3 punishments, the first of which was horse racing with Funny Valentine, having coffee with Giorno at his Requiem Domain, and saving the city of Morioh Cho from Pucci's siege. With full awareness, Ben White chose the last option. Ben White was then bestowed with a skill from Justok, named _**[!!! ZA COMPOSE!!!]**_.

![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/9c062d65-709d-47ef-b744-d84716d611e8)

This skill could grant any request in that world, ranging from weapons, magic, standpower, etc. Everything could be made as long as the request was wrapped in a request. Everything could be made as long as the request was wrapped in a service docker container. However, he doesn't know what service is good to be able to take Morioh Cho from Pucci. He also asks you, the citizens of Morioh Cho, to work together to help Ben White compose his docker compose.

- a. Create 2 files, namely [server.c](./server.c) and [client.c](./client.c).

  When `server.c` is first run, it will prompt the user to type in how many clients to serve (range 1-5).

  When `client.c` is first run, it prompts the user to type in a username. This username is then sent to the server, to check whether it already exists or not. If it already exists, it will ask for another prompt to type in the username until it is received by the server.

- b. When all the clients needed by the server have been collected, each client will start to be given a prompt to type in the required service, namely `Container Name`, `Image Used`, `Container Startup Command`, and `Volume`. The order in which clients send service requests to the server is determined by the time they register. Example: If username ragnar registers first, followed by username towel, then ragnar will send the request first, followed by towel, and so on.

- c. After all service requests from the client are collected, the server then combines them into a docker compose file. Then run the docker compose file that was created earlier

- d. Not until there, after the previous docker compose is finished running, `client.c` will ask for another prompt from the user. The prompt given is in accordance with point (b). If each client does the same thing at point (b), then the server will generate a new docker compose file. Then the container that has been run before will be destroyed, which will then be replaced by the latest service that has been requested from the client earlier.

### Notes:

- For `client.c` and `server.c` communication, you are free to use any type of IPC.
- It is forbidden to use `system()`

## BNBWT

<div align=center>

![unnamed](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/2dbce2c6-9a0e-497b-9c66-6a984d03d9b4)

</div>

Ben White, seorang pesepakbola yang mempesona dengan keahliannya di lapangan, tampil percaya diri sebagai pemain kunci untuk Arsenal. Suatu hari, dia tampil sangat buruk saat melawan Munchen, sehingga membuat salah satu dewa di dunia isekai, Justok, sangat marah. Justok pun mengirim paksa Ben White ke dunia nya yang bernama Aztec, untuk dibawa dan dihukum oleh Pillar Men.

Ben White disuruh memilih 1 dari 3 hukuman, yang pertama adalah balap kuda dengan Funny Valentine, ngopi bareng Giorno di Domain Requiem miliknya, dan menyelamatkan kota Morioh Cho dari kepungan Pucci. Dengan kesadaran penuh, Ben White memilih opsi terakhir. Ben White lalu dianugerahi skill dari Justok, bernama _**[!!! ZA COMPOSE !!!]**_.

![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/9c062d65-709d-47ef-b744-d84716d611e8)

Skill ini bisa mengabulkan segala permintaan apapun di dunia tersebut, mulai dari senjata, sihir, standpower, dsb. Semua dapat dibuat asalkan permintaan tersebut dibungkus dalam sebuah service docker container. Namun, dia tidak tahu service apa yang bagus untuk bisa merebut Morioh Cho dari Pucci. Dia pun meminta kalian, para warga Morioh Cho, untuk bekerjasama membantu Ben White menyusun docker compose nya.

- a. Buatlah 2 file, yaitu [server.c](./server.c) dan [client.c](./client.c).

  Disaat `server.c` pertama kali dijalankan, dia akan meminta prompt user untuk mengetikkan berapa banyak client yang akan dilayani (range 1-5).

  Disaat `client.c` pertama kali dijalankan, dia akan meminta prompt user untuk mengetikkan username. Username ini kemudian dikirim ke server, untuk di check apakah sudah ada sebelumnya atau tidak. Jika sudah ada, maka akan meminta prompt lagi untuk mengetikkan username sampai diterima oleh server.

- b. Ketika semua client yang dibutuhkan oleh server telah terkumpul, setiap client akan mulai diberikan prompt untuk mengetikkan service yang dibutuhkan, yaitu `Nama Container`, `Image yang Digunakan`, `Perintah Saat Kontainer Dimulai`, dan `Volume`. Urutan client yang mengirimkan request service ke server ditentukan dari waktu mereka register. Contoh: Jika username ragnar registrasi pertama kali, lalu diikuti username towel, maka ragnar yang akan mengirim request terlebih dahulu, lalu diikuti towel, dst.

- c. Setelah semua request service dari client terkumpul, server lalu menggabungkannya menjadi sebuah file docker compose. Lalu jalankan file docker compose yang dibuat tadi

- d. Tidak sampai situ, setelah docker compose sebelumnya selesai dijalankan, `client.c` akan meminta prompt lagi dari user. Prompt yang diberikan sesuai dengan point (b). Jika setiap client melakukan hal yang sama pada point (b), maka server akan menghasilkan file docker compose yang baru. Lalu container yang telah dijalankan sebelumnya akan dihancurkan, yang kemudian akan digantikan oleh service terbaru yang telah di request dari client tadi.

### Notes:

- Untuk komunikasi `client.c` dan `server.c`, kalian bebas mau menggunakan IPC jenis apapun.
- Dilarang menggunakan `system()`
