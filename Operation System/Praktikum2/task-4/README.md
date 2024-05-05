## Tic Tac Toe

As a new computer science student, Satria has an idea to create a tic-tac-toe game that runs in the terminal. Tic-tac-toe is a game played by 2 players who take turns placing 'X' or 'O' marks until forming a horizontal, vertical, or diagonal line. To create this game, Satria needs 2 c programs:

- [game.c](./game.c): a game server, program to control the game
- [player.c](./player.c): a program to receive input and display output to the user

Here is the planned program scheme:

- a. Users can choose player type (‘X’ or ‘O’) based on commands from ‘player.c’ program. If a player type has already been chosen by another user, give a message “\<player type\> has already been taken, choose other player types”. Information regarding whether the player type has been chosen or not can be accessed through shared memory.

  Output example (**player.c**):

  ```
  Available player type:
  1. X
  2. O
  Enter your choice (1 or 2): 1
  'X' has already been taken, choose other player types

  Available player type:
  1. X
  2. O
  Enter your choice (1 or 2): 2
  ```

- b. Since it runs in the terminal, this program uses sequential cell numbers (1-9) from top left to bottom right to facilitate cell selection. The 'player.c' program will display the current tic-tac-toe board and prompt the user for input in the form of cell numbers according to their turns (player 'X' starts first). The input provided by the user is then sent to 'game.c' using a message queue. In 'game.c', print each message received from 'player.c' with a format like the one below.

  Output example (**player.c**):

  ```
  ----Game Started!----
  You play as 'X'

   1 | 2 | 3
  --- --- ---
   4 | 5 | 6
  --- --- ---
   7 | 8 | 9
  Select the corresponding cell number to choose a cell.

  Your turn
  Enter a cell number: 1
  ```

  Output example (**game.c**):

  ```
  New Message
  Sender: player X
  Message: 1
  New Message
  Sender: player O
  Message: 7
  New Message
  Sender: player X
  Message: 9
  ```

- c. In the next step, 'game.c' must check whether the user input is valid or not based on the current game board. Send an error message to the user if the selected cell number is not empty or outside the range of 1-9. Messages can be sent through the message queue with different 'mesg_type'.

  Output example (**player.c**):

  ```
  Player 'X' turn
   X |   |
  --- --- ---
     |   |
  --- --- ---
     |   |

  Your turn
  Enter a cell number: 11
  Wrong input, choose cell number 1-9
  Enter a cell number: 1
  Choose other cell, 1 is filled by 'X'
  ```

- d. If the input is valid, 'game.c' needs to update the value in the tic-tac-toe board and determine whether the game has ended or is still ongoing. The game is over if all boxes are filled (draw) or if there are symbols ('X' or 'O') forming a vertical, horizontal, or diagonal line. The updated tic-tac-toe board and game result (if it has ended) are then sent to 'player.c' to be displayed to the user.

  Output example (**player.c**):

  ```
  Your turn
  Enter a cell number: 6
  X | O |
  --- --- ---
  X | X | X
  --- --- ---
  O |   | O

  ---Game Finished!---
  You Win!
  ```

### Notes:

- To play the game, first run 'game.c'. Next, run 2 instances of the 'player.c' program, 1 for player 'X' and 1 for player 'O', as the user interfaces.

  Example:

  ![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/4684c310-53e1-445e-b18b-7c1e892179fe)

- For a simplicity, you can use different 'mesg_type' for each communication, as an example:

  - ‘mesg_type’ = 1, for message that goes to game server (game.c)
  - ‘mesg_type’ = 2, for message that goes to player ‘X’
  - ‘mesg_type’ = 3, for message that goes to player ‘O’

- There is no specific format or structure for the message, as long as it fulfils the requirements outlined in the question.

## Tic Tac Toe

Sebagai mahasiswa baru informatika, satria memiliki ide untuk membuat game tic-tac-toe yang berjalan di terminal. Tic-tac-toe merupakan permainan dengan 2 pemain yang secara bergantian menempatkan tanda 'X' atau 'O' hingga membentuk garis horizontal, vertikal, atau diagonal. Untuk membuat game ini, satria membutuhkan 2 program c:

- [game.c](./game.c): game server, program untuk mengontrol permainan
- [player.c](./player.c): program untuk menerima input dan menampilkan output pada pengguna

Berikut skema program yang telah direncanakan:

- a. Pengguna dapat memilih tipe pemain (‘X’ atau ‘O’) berdasarkan perintah dari program ‘player.c’. Jika tipe telah dipilih oleh pengguna sebelumnya, beri pesan "<tipe pemain> has already been taken, choose other player types". Informasi terkait apakah tipe pemain telah dipilih atau tidak, dapat diakses melalui shared memory.

  Contoh output (**player.c**):

  ```
  Available player type:
  1. X
  2. O
  Enter your choice (1 or 2): 1
  'X' has already been taken, choose other player types

  Available player type:
  1. X
  2. O
  Enter your choice (1 or 2): 2
  ```

- b. Karena berjalan di terminal, program ini menggunakan nomor kotak (1-9) yang berurutan dari kiri atas ke kanan bawah untuk memudahkan pemilihan kotak. Program 'player.c' akan menampilkan kotak tic tac toe saat ini dan meminta input pengguna berupa nomor kotak sesuai gilirannya (player 'X' memulai terlebih dahulu). Input yang diberikan pengguna kemudian dikirimkan ke 'game.c' menggunakan message queue. Pada ‘game.c’, tampilkan setiap pesan yang diterima dari ‘player.c’ dengan format seperti di bawah.

  Contoh output (**player.c**):

  ```
  ----Game Started!----
  You play as 'X'

  1 | 2 | 3
  --- --- ---
  4 | 5 | 6
  --- --- ---
  7 | 8 | 9
  Select the corresponding cell number to choose a cell.

  Your turn
  Enter a cell number: 1
  ```

  Contoh output (**game.c**):

  ```
  New Message
  Sender: player X
  Message: 1
  New Message
  Sender: player O
  Message: 7
  New Message
  Sender: player X
  Message: 9
  ```

- c. Selanjutnya, ‘game.c’ harus mengecek apakah input user sesuai atau tidak berdasarkan nilai kotak permainan saat ini. Kirimkan pesan error kepada pengguna jika nomor kotak yang dipilih tidak kosong atau diluar angka 1-9. Pesan dapat dikirimkan melalui message queue dengan ‘mesg_type’ yang berbeda.

  Contoh output (**player.c**):

  ```
  Player 'X' turn
  X |   |
  --- --- ---
    |   |
  --- --- ---
    |   |

  Your turn
  Enter a cell number: 11
  Wrong input, choose cell number 1-9
  Enter a cell number: 1
  Choose other cell, 1 is filled by 'X'
  ```

- d. Jika input valid, ‘game.c’ perlu mengubah nilai pada kotak tic-tac-toe dan memutuskan apakah permainan telah selesai atau masih berlanjut. Permainan telah selesai jika kotak telah terisi semua (seri) atau terdapat simbol (‘X’ atau ‘O’) yang membentuk garis vertikal, horizontal, maupun diagonal. Kotak tic tac toe yang telah diperbarui dan hasil akhir permainan (jika sudah berakhir) dikirimkan ke 'player.c' untuk kemudian ditampilkan kepada pengguna.

  Contoh output (**player.c**):

  ```
  Your turn
  Enter a cell number: 6
  X | O |
  --- --- ---
  X | X | X
  --- --- ---
  O |   | O

  ---Game Finished!---
  You Win!
  ```

### Notes:

- Untuk memainkannya, jalankan ‘game.c’ terlebih dahulu. Selanjutnya, jalankan 2 program 'player.c', 1 untuk player 'X' dan 1 untuk player 'O', sebagai antarmuka.

  Contoh:

  ![image](https://github.com/arsitektur-jaringan-komputer/Modul-Sisop/assets/54766683/4684c310-53e1-445e-b18b-7c1e892179fe)

- Untuk memudahkan, kalian dapat menggunakan ‘mesg_type’ yang berbeda untuk tiap komunikasi, sebagai contoh:

  - ‘mesg_type’ = 1, untuk pesan dari player ke game server
  - ‘mesg_type’ = 2, untuk pesan dari game server ke player 'X'
  - ‘mesg_type’ = 3, untuk pesan dari game server ke player 'O'

- Format atau struktur pesan dibebaskan asal dapat memenuhi poin-poin pada soal
