## Jess No Limit Push Rank

Jess No Limit is ready to make a comeback to the world of professional Mobile Legend esports. He had worked hard to pushrank up to Mythic Immortal and prove to the world that he was the most reliable player. When he and his team returned to training, they struggled to determine a suitable role for Jess No Limit. They need your help in this case, because there are so many ML heroes in the mobile legend dataset.

- a. Download the dataset using `kaggle datasets download -d irwansyah10010/mobilelegend` after successfully downloading in .zip file format, the next step is to extract the file. You do it in the [ayamgoreng.c](./ayamgoreng.c) file for all the work.

- b. Jess No Limit wants to know what heroes are the best of each role with calculations like the following:

  |   Role   |       Skillpoints Formula       |
  | :------: | :-----------------------------: |
  |   Tank   |               HP                |
  | Assassin |         Physical Attack         |
  | Fighter  |      HP + Physical Attack       |
  | Marksman | Physical Attack \* Attack Speed |
  |   Mage   |        Mana / Mana Regen        |
  | Support  |         Mana Regen + HP         |

  `ayamgoreng.c` should be able to **output all the best heroes in each role by default without arguments**, but also be able to display according to the **role given in the argument** at the time of program call (`./ayamgoreng [role]`). The hero data and its role can be seen in the identity.csv file, while the hero data and its attributes can be seen in the attribute-hero.csv file. Output information about the hero and his skillpoints with the format `The best hero is (hero name) with skillpoints (number of skillpoints)`.

- c. Jess No Limit realizes that your system is very useful and wants it to be accessible to his teammates. Therefore, you need to make the system into a Docker Container so that it can be easily distributed and run in other environments without the need to setup an environment from scratch. Create a Dockerfile that contains all the steps needed to setup the environment and determine how the application should run.

  After successfully creating a Docker-based system, Jess No Limit felt that this system would not only be useful for himself, but would also help his fans scattered around the world in recruiting high-potential players. However, one challenge arose: how could the fans access and use the system that had been created?

- d. Feeling called to help Jess No Limit further, you decide to publish the system's Docker Image to Docker Hub, a cloud service that allows you to share your Docker application worldwide. The output of this work is that your Docker file can be viewed publicly at `https://hub.docker.com/r/{Username}/joki-ml-bang`.

- e. Seeing how many fans Jess No Limit has, you are asked to scale the service using **Docker Compose** with 6 instances (for each role). Make sure each instance calls the program to display the best hero according to the role given in the argument. Name each instance the same as the role that will be displayed (mage instance, fighter instance, etc).

### Notes

- In point c, the command run on the docker file has no arguments and will display all roles

## Jess No Limit Push Rank

Jess No Limit sudah siap untuk comeback ke dunia professional esport Mobile Legend. Dia sudah bersusah payah untuk pushrank hingga ke Mythic Immortal dan membuktikan ke dunia bahwa dia adalah pemain yang paling handal. Ketika dia dan timnya kembali latihan, mereka kesulitan untuk menentukan role yang cocok bagi Jess No Limit. Mereka butuh bantuan kalian dalam hal ini, karena hero ML yang begitu banyak pada dataset mobile legend.

- a. Download dataset menggunakan `kaggle datasets download -d irwansyah10010/mobilelegend` setelah berhasil mendownload dengan format file .zip, langkah selanjutnya adalah mengekstrak file tersebut. Kalian melakukannya di dalam file [ayamgoreng.c](./ayamgoreng.c) untuk semua pengerjaannya

- b. Jess No Limit ingin mengetahui hero apa saja yang terbaik dari setiap role yang ada dengan perhitungan seperti berikut:

  |   Role   |        Rumus Skillpoints        |
  | :------: | :-----------------------------: |
  |   Tank   |               HP                |
  | Assassin |         Physical Attack         |
  | Fighter  |      HP + Physical Attack       |
  | Marksman | Physical Attack \* Attack Speed |
  |   Mage   |        Mana / Mana Regen        |
  | Support  |         Mana Regen + HP         |

  `ayamgoreng.c` harus bisa **mengoutputkan semua hero yang terbaik pada setiap role secara default tanpa argumen**, namun juga bisa menampilkan sesuai dengan **role yang diberikan pada argumen** pada saat pemanggilan program (`./ayamgoreng [role]`). Data hero beserta rolenya dapat dilihat pada file identitas.csv, sedangkan data hero beserta atributnya dapat dilihat pada file atribut-hero.csv. Keluarkan informasi mengenai hero dan skillpointsnya dengan format `Hero terbaik adalah (nama hero) dengan skillpoint (jumlah skillpoint)`.

- c. Jess No Limit menyadari bahwa sistem kalian sangat berguna dan ingin sistem ini bisa diakses oleh teman satu timnya. Oleh karena itu, kalian perlu menjadikan sistem yang dibuat ke sebuah Docker Container agar mudah di-distribute dan dijalankan di lingkungan lain tanpa perlu setup environment dari awal. Buatlah Dockerfile yang berisi semua langkah yang diperlukan untuk setup environment dan menentukan bagaimana aplikasi harus dijalankan.

  Setelah sukses membuat sistem berbasis Docker, Jess No Limit merasa bahwa sistem ini tidak hanya berguna untuk dirinya sendiri, tetapi juga akan akan membantu para fansnya yang terpencar di seluruh dunia dalam merekrut pemain berpotensi tinggi. Namun, satu tantangan muncul, yaitu bagaimana caranya para fans dapat mengakses dan menggunakan sistem yang telah diciptakan?

- d. Merasa terpanggil untuk membantu Jess No Limit lebih jauh, kalian memutuskan untuk mem-publish Docker Image sistem ke Docker Hub, sebuah layanan cloud yang memungkinkan kalian untuk membagikan aplikasi Docker kalian ke seluruh dunia. Output dari pekerjaan ini adalah file Docker kalian bisa dilihat secara public pada `https://hub.docker.com/r/{Username}/joki-ml-bang`.

- e. Melihat betapa banyaknya fans Jess No Limit, kalian diminta untuk menerapkan skala pada layanan menggunakan **Docker Compose** dengan instance sebanyak 6 (untuk setiap role). Pastikan setiap instance memanggil program untuk menampilkan hero terbaik sesuai dengan role yang diberikan pada argumen. Penamaan setiap instance sama dengan role yang akan ditampilkan (instance mage, instance fighter, dst).

### Notes

- Pada poin c, command yang dijalankan pada docker file tidak terdapat argumen dan akan menampilkan semua role
