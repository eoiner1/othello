#include <stdio.h>//Including the standard input output function
#include "functions.h"//Including my functions for the main function
#include <time.h>//Including a function for the time

int main(void)//The main funtion
{
  time_t t;//Variable t used to write the time to the resutlts file
  time(&t);

  FILE * fp;//File pointer for the results file
  fp = fopen ("othello-results.txt", "w");//Opening the results file for writing

  int numTurns = 0;//Variable for tracking the number of turns
  char player1[20];//Character array to store the name of player 1
  char player2[20];//Character array to store the name of player 2

  printf("***Welcone to Othello!***\n");//Prompt to user
  printf("Enter the name of Player 1 (Black):");//Asking to input player 1s name
  scanf("%s", &player1);//Scanning in name to variable
  printf("Enter the name of Player 2 (White):");//Same again with player 2
  scanf("%s", &player2);
  printf("\n");//New line for appearance

  char colour[1];//Creating a variable to store the colour piece of each player
  char board[64];//Creating a character array to represent the board

  initializeBoard(board);//Function to initialize the board
  print(board, player1, player2);//Function to print the board

  while(game(board) == 1)//While there is an available move for either player
   {

    if(numTurns % 2 == 0)//If the number of turns is even (Blacks turn)
     {
      colour[0] = 'B';//The colour is black

        if(availablePosition(board, colour) == 1)//If there is an available position
          {
            Play(board, colour, player1);//Call function play
            print(board, player1, player2);//Print the board
            numTurns++;//Increment number of turns
            printf("\n");//Newline for appearance
          }

        else//Otherwise
          {
            numTurns++;//Increment numsongs
          }
     }

    else//If the turn is odd
     {
      colour[0] = 'W';//Colour is white

        if(availablePosition(board, colour) == 1)//If there is an available position
          {
            Play(board, colour, player2);//Call function play
            print(board, player1, player2);//Print board
            numTurns++;//Increment Numturns
            printf("\n");//Newline for appearance
          }

        else//Otherwise
          {
            numTurns++;//Increment Numsongs
          }
     }
   }

  int b = 0;//Declaring an integer b to 0
  int w = 0;//Declaring an integer w to 0

  for(int i=0;i<64;i++)//A loop from 0 to 63
   {

     if(board[i] == 'B')//If the spot on the board contains a B
      {
        b++;//Increment b
      }

     else if(board[i] == 'W')//If the spot contains W
      {
        w++;//Increment w
      }
   }

  if(b>w)//If there are more black pieces than white pieces on the board
    {
      printf("\n%s wins with %d places on the board while %s only has %d\n", player1, b, player2, w);//Print to user
      fprintf(fp, "%s\n%s won, score %d:%d", ctime(&t), player1, b, w);//Write to file
    }

  else if(w>b)//Otherwise if white is greater than black
    {
      printf("\n%s wins with %d places on the board while %s only has %d\n", player2, w, player1, b);//Write to user
      fprintf(fp, "%s\n%s won, score %d:%d", ctime(&t), player2, w, b);//Write to file
    }
}
