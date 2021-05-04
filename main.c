#include <stdio.h>

void print(char board[64])
{

int i = 0;
int j = i+8;
int line = 1;
int counter = 0;
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

int main(void)
{
  char board[64];
  initializeBoard(board);
  print(board);
}
