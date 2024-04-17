## Gabut Yuan _(Yuan's Boredom)_

Yuan sedang gabut dan lagi makan toge. Setelah kenyang, dia ingin menambah suatu kerjaan baru. Dia sebagai panitia KSN ingin membuat suatu website yang handle login dan register untuk proposal PKM. [File](/resources/data-pkm.csv) yang digunakan sama seperti di nomor 1, hanya saja Yuan ingin memodifikasi file ini:

_Yuan is feeling idle and is currently eating bean sprouts. After feeling full, he wants to add a new task. As a committee member of KSN, he wants to create a website that handles login and registration for PKM proposals. The [file](/resources/data-pkm.csv) used is the same as in question 1, however, Yuan wants to modify this file:_

- a. Yuan ingin membuat file bash login bernama [yu_login.sh](./yu_login.sh) untuk memastikan bahwa peserta yang telah ada di dalam file .csv tersebut, dapat langsung melakukan login, tanpa perlu register. Apabila loginnya sukses, maka akan masuk ke log.txt. Berikut format untuk login:

  _a. Yuan wants to create a bash login file named [yu_login.sh](./yu_login.sh) to ensure that participants already listed in a .csv file can directly log in without needing to register. If the login is successful, the details will be logged into log.txt. Here's the format for the login:_

  - Memasukkan username. Username didapatkan dari kata pertama pada kolom nama_pengusul

    _Yuan wants to adjust the bash login script to include a process where the username is derived from the first word of the nama_pengusul column in a .csv file._

  - Memasukkan password. Password didapatkan dari fakultas+nipd_dosen_pendamping

    Misal: `FTEIC0030016403`

    _Yuan intends to incorporate a step for password entry in the bash script, where the password is constructed by concatenating the faculty name with the mentor's NIPD._

    _Example: `FTEIC0030016403`_

  - Setiap percobaan login akan tercatat pada log.txt dengan format `YY/MM/DD hh:mm:ss MESSAGE`

    _Every login attempt will be recorded in log.txt with the format `YY/MM/DD hh:mm:ss MESSAGE`._

    Dengan MESSAGE berupa:

    _With the following MESSAGE:_

    `LOGIN: SUCCESS USER_NAME is logged in`

    Atau

    _Or_

    `LOGIN: ERROR Failed login attempt on USER_NAME`

- b. Yuan juga ingin membuat file bash register bernama [yu_register.sh](./yu_register.sh) untuk handle peserta baru yang ingin upload proposal. Data baru ini akan langsung disimpan dalam file .csv tersebut. Ketentuannya adalah:

  _b. Yuan also wants to create a bash file named yu_register.sh to handle new participants who want to upload proposals. This new data will be directly saved in the .csv file. The requirements are:_

  - Memasukkan nama_pengusul, asal departemen, fakultas, judul proposal, dosen pendamping (nidn), skema pkm. (Sesuaikan dengan file .csv)

    _Enter the proposer's name (nama_pengusul), home department (asal_departemen), faculty (fakultas), proposal title (judul_proposal), mentoring lecturer (NIDN) (dosen_pendamping (NIDN)), and PKM scheme (skema_pkm). (Align with the .csv file)_

  - Setiap percobaan register akan tercatat pada log.txt dengan format `YY/MM/DD hh:mm:ss MESSAGE`

    _Every registration attempt will be recorded in log.txt with the format `YY/MM/DD hh:mm:ss MESSAGE`._

    Dengan MESSAGE berupa:

    _With the following MESSAGE:_

    `REGISTER: SUCCESS USER_NAME is registered. Proposal PROPOSAL_NUMBER is added`

    Atau

    _Or_

    `REGISTER: ERROR USER_NAME is already existed`

- c. Yuan tidak ingin capek. Dia membuat automasi di file bash bernama [yu_database.sh](./yu_database.sh) untuk dapat membuat file users.txt guna menyimpan username dan password dari para peserta. Ketentuannya adalah:

  _c. Yuan doesn't want to get tired. He's creating automation in a bash file named [yu_database.sh](./yu_database.sh) to generate a users.txt file for storing usernames and passwords of the participants. The requirements are:_

  - File users.txt akan diupdate setiap 1 jam sekali

    _The users.txt file will be updated every 1 hour._

  - Simpan konfigurasi cron pada file [crontabs](./crontabs)

    _Save the cron configuration in the [crontabs](./crontabs) file._
