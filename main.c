#include <stdio.h>

void print(char board[64], char player1[20], char player2[20])
{
int white = 0;
int black = 0;
int i;
int j = 8;
int line = 1;
int counter = 0;
for(i=0;i<64;i++)
{
  if(board[i] == 'W')
  {
    white++;
  }
  if(board[i] == 'B')
  {
    black++;
  }
}
i=0;
printf("Score: %s (Black) %d:%d %s (White)\n", player1, black, white, player2);
for(counter = 0; counter<17;counter++)
{
if(counter%2 == 0 && counter < 17)
{
 printf("   --- --- --- --- --- --- --- ---\n");
}
else if(counter%2 != 0 && counter < 17)
{
  printf("%d |", line++);
  for(i=i;i<j;i++)
  {
    printf(" %c |", board[i]);
  }
  printf("\n");
  j = i+8;
}
}
printf("    a   b   c   d   e   f   g   h");

}

char initializeBoard(char board[64])
{
  int i;
 for(i=0;i<64;i++)
 {
   board[i] = ' ';
 }
 board[27] = 'W';
 board[28] = 'B';
 board[35] = 'B';
 board[36] = 'W';

return board[64];

}

int validMove(char board, int x, int y)
{

}

int main(void)
{
  char player1[20];
  char player2[20];
  printf("***Welcone to Othello!***\n");
  printf("Enter the name of Player 1 (Black):");
  scanf("%s", &player1);
  printf("Enter the name of Player 2 (White):");
  scanf("%s", &player2);
  printf("\n");

  char board[64];
  initializeBoard(board);
  print(board, player1, player2);

}
