## Volume Expansion

<div align=center>

![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/452666b4-1a84-41ac-a855-6689b275880b)

</div>

Dhafin really likes the anime Jujutsu Kaisen. One day he fell asleep and found himself becoming Yuji. He then thought of the name of a technique that could fight Sukuna's domain, so that he would not have the fate of Gojo. Dhafin then thought of a technique. Why not seal Sukuna into a docker container that is isolated from the outside world. With this reference, Dhafin wanted to create a project, where 2 or more containers could send messages to each other. Dhafin named this technique _**[!!! VOLUME EXPANSION!!!].**_ When Dhafin was almost finished making the technique _**[!!! VOLUME EXPANSION!!!],**_ suddenly he was attacked by Kashimo lightning so that he woke up from his sleep. Dhafin then regretted that the algorithm for making _**[!!! VOLUME EXPANSION!!!]**_ had been lost in his dreams. So please make Dhafin's dream come true.

- a. Create a [chat.c](./chat.c) program that can write messages and read messages in a file. where the message to be written must be run using multithread, **so that 1 thread represents 1 word**. example:

  - for chat : ./chat write hello I'm dhafin.txt

    thread 1 processes the word hello

    thread 2 processes the word I'm

  - for read: ./chat read dhafin.txt

  ![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/8c27b46a-77c4-4c86-9915-20f808add8e8)

- b. Create a Docker Image that contains `chat.c` that has been created previously and has also been compiled with gcc (aka compile the c program must be in the Dockerfile) and name it **dockermessage**.

  ![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/5d0586d4-77c5-4792-a641-dd852449a607)

- c. Then create a [pengaturan.c](./pengaturan.c) that can create a new unique container and delete the container from the host, with the docker image that you have previously created using the Dockerfile. example:

  - to create a container with the name dhafin: `./pengaturan create dhafin`

  - to delete the container dhafin: `./pengaturan delete dhafin`

  - to view all available containers `./pengaturan list`

  - to login or log into the container `./pengaturan login dhafin`

- d. Modify `chat.c` and rebuild it into docker image `dockermessage:v2` to be able to send chats to other containers and add arguments to `pengaturan.c` to be able to connect and uncoonnect a container. (In order for a container to chat with the destination container, the container that wants to chat must first connect to the destination container. And when a container is created, it automatically has a message box that other containers can read and send messages to). example:

  - to connect container dhafin to container wahid: `./pengaturan connect dhafin wahid`

  - to unconnect container dhafin to container wahid: `./pengaturan unconnect dhafin wahid`

  - when the user is in container dhafin and wants to send a message to container wahid: `./chat write hello friend wahid`

    Note: the destination container is always the last argument

  - when the user is in container wahid and wants to send a message to dhafin: `./chat write hello friend dhafin`

    Note: the destination container is always the last argument

  - to view the contents of the message box in the current container: `./chat read`

  _connect first to be able to send messages, then when unconnect cannot send messages_

  _later the message will be seen in the message box in a format like this:_

  `[message content] from [sender name], the sender name must be the same as the sender container name`

## Volume Expansion

<div align=center>

![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/452666b4-1a84-41ac-a855-6689b275880b)

</div>

Dhafin sangat suka dengan anime Jujutsu Kaisen. Suatu hari dia tertidur dan mendapati dirinya menjadi Yuji. Dia lalu memikirkan nama teknik yang dapat melawan domain milik Sukuna, agar dirinya tidak bernasib seperti Gojo. Dhafin lalu memikirkan suatu teknik. Mengapa tidak menyegel Sukuna kedalam docker container yang terisolasi dari dunia luar. Dengan referensi tersebut, Dhafin ingin membuat project, dimana 2 buah container atau lebih dapat saling mengirim pesan satu sama lain. Dhafin menamai teknik ini _**[!!! VOLUME EXPANSION !!!].**_ Saat Dhafin sudah hampir selesai membuat teknik _**[!!! VOLUME EXPANSION !!!],**_ tiba-tiba dia diserang petir Kashimo sehingga dia bangun dari tidurnya. Dhafin kemudian sangat menyesal karena algoritma pembuatan _**[!!! VOLUME EXPANSION !!!]**_ sudah hilang di mimpinya. Jadi tolong wujudkan mimpi Dhafin agar menjadi kenyataan.

- a. Buatlah program [chat.c](./chat.c) yang dapat menulis pesan dan membaca pesan pada sebuah file. dimana pesan yang akan ditulis harus dijalankan menggunakan multithread, **sehingga 1 thread mewakili 1 kata**. contoh:

  - untuk chat : ./chat write halo saya dhafin.txt

    thread 1 mengolah kata halo

    thread 2 mengolah kata saya

  - untuk read: ./chat read dhafin.txt

  ![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/8c27b46a-77c4-4c86-9915-20f808add8e8)

- b. Buatlah Docker Image yang didalamnya berisi `chat.c` yang telah dibuat sebelumnya dan juga sudah tercompile dengan gcc (alias compile program c nya harus pada Dockerfile) dan beri nama **dockermessage**.

  ![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/5d0586d4-77c5-4792-a641-dd852449a607)

- c. Lalu buatlah [pengaturan.c](./pengaturan.c) yang dapat membuat container baru yang unik dan menghapus container tersebut dari host, dengan docker image yang telah kalian buat sebelumnya menggunakan Dockerfile. contoh:

  - untuk membuat container dengan nama dhafin: `./pengaturan create dhafin`

  - untuk menghapus container dhafin: `./pengaturan delete dhafin`

  - untuk melihat semua container yang tersedia `./pengaturan list`

  - untuk login atau masuk ke dalam container `./pengaturan login dhafin`

- d. Modifikasi `chat.c` dan build ulang menjadi docker image `dockermessage:v2` agar dapat mengirim chat ke container lain dan tambahkan argument pada pengaturan.c agar dapat connect dan uncoonnect sebuah container. (agar container dapat chat dengan container tujuan, container yang ingin chat harus connect terlebih dahulu ke container tujuan. Dan ketika sebuah container terbuat, secara otomatis dia juga memiliki kotak pesan yang nantinya dapat dia read dan dikirimi pesan oleh container lain). contoh:

  - untuk connect container dhafin ke container wahid: `./pengaturan connect dhafin wahid`

  - untuk unconnect container dhafin ke container wahid: `./pengaturan unconnect dhafin wahid`

  - ketika user sedang dalam container dhafin dan ingin mengirim pesan ke container wahid: `./chat write halo teman wahid`

    Note: container tujuan selalu menjadi argument terakhir

  - ketika user sedang dalam container wahid dan ingin mengirim pesan ke dhafin: `./chat write halo teman dhafin`

    Note: container tujuan selalu menjadi argument terakhir

  - untuk melihat isi kotak pesan di container saat ini: `./chat read`

  _connect dulu agar dapat kirim pesan, lalu ketika unconnect tidak bisa kirim pesan_

  _nantinya pesan akan terlihat dalam kotak pesan dalam format seperti ini:_

  `[isi pesan] from [nama pengirim], nama pengirim harus sama dengan nama container pengirim`
