#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define SIZE sizeof(struct sockaddr_in)

int play();
int menu(void);
int te = 0;
void catcher(int sig);
void mapBoard(char playBoard[][3]);
void help(void);
void playerWinhandler(int signum);

int main(void)
{
  while (1)
  {
    switch (menu())
    {
    case 1:
    {
      printf("\nYou selected Play Option\n\n");
      play();
      break;
    }
    case 2:
    {
      printf("\nYou selected Help Option\n\n");
      help();
      break;
    }
    case 3:
    {
      printf("\nYou are quitting\n\n");
      exit(0);
      break;
    }
    default:
    {
      printf("\nInvalid menu choice\n\n");
      break;
    }
    }
  }
}

int play(void)
{
  void result(char[], char[]);
  static struct sigaction act;
  act.sa_handler = SIG_IGN;
  sigfillset(&(act.sa_mask));
  sigaction(SIGTSTP, &act, 0);
  signal(SIGUSR1, playerWinhandler);
  signal(SIGUSR2, playerWinhandler);

  struct sockaddr_in server = {AF_INET, 8001};
  server.sin_addr.s_addr = inet_addr("127.0.0.1");

  int sockfd, i;
  int row, column, choice;
  int iclientRead;
  char input;
  char a[2][40];
  char pid[4];
  char clientRead[3][3];
  char clientWrite[1];

  char numberBoard[3][3] = {
      {'1', '2', '3'},
      {'4', '5', '6'},
      {'7', '8', '9'}};

  char playBoard[3][3] = {
      {' ', ' ', ' '},
      {' ', ' ', ' '},
      {' ', ' ', ' '}};

  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
  {
    perror("Socket Call Failed");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr *)&server, SIZE) == -1)
  {
    perror("Connect Call Failed");
    exit(1);
  }

  read(sockfd, a, sizeof(a));
  printf("%s\n", a[0]);

  if (strcmp(a[1], "0") == 0)
  {
    int num1 = getpid();
    sprintf(pid, "%d", num1);
    write(sockfd, pid, sizeof(pid));
    read(sockfd, a, sizeof(a));
    printf("%s\n", a[0]);
  }

  if (strcmp(a[1], "2") == 0)
  {
    int num2 = getpid();
    sprintf(pid, "%d", num2);
    write(sockfd, pid, sizeof(pid));
  }

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
  for (input = 'x';;)
  {
    int b[2][40];
    if (input == '\n')
    {
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
    if (read(sockfd, clientRead, sizeof(clientRead)) > 0)
    {
      memcpy(playBoard, clientRead, sizeof(playBoard));
      mapBoard(playBoard);
      printf("\nCurrent Play Board\n\n");
      input = '\n';
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
      printf("You Win!! Thank You, Please Play Again :D\n");
      close(sockfd);
      exit(1);
    }
  }
}

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

void catcher(int sig)
{
  printf("Sorry...you can quit only after your chance is over! \n");
}

int menu(void)
{
  int reply;
  printf("			    Play Grid Menu  				  \n ");
  printf("--------------------------------------------------------------------------\n");
  printf("Enter 1 to Play.\n\n");
  printf("Enter 2 for Help.\n\n");
  printf("Enter 3 to Quit.\n\n");
  scanf("%d", &reply);
  return reply;
}

void playerWinhandler(int signum)
{
  if (signum == SIGUSR1)
  {
    te = 1;
  }
  if (signum == SIGUSR2)
  {
    te = 2;
  }
  if (signum == 1)
  {
    te = 3;
  }
}

void help(void)
{
  printf("Tic-tac-toe, also called wick wack woe (in some Asian countries) and noughts and crosses (in the British Commonwealth countries) and X's and O's in the Republic of Ireland, is a pencil-and-paper game for two players, X and O, who take turns marking the spaces in a 3×3 grid. The player who succeeds in placing three respective marks in a horizontal, vertical, or diagonal row wins the game.\n\n");
}
