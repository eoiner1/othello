char flip(char board[64], char colour[1], char search[1], int arrayPosition, int direction)//A function to flip the appropriate pieces on the board
  {

    if(direction == 1)//Direction is chosen in relation to which way the markers are to be flipped, 1 is upward diagonal to the left
      {

        for(int i = arrayPosition-9;board[i] == search[0]; i -=9)//While the pieces are of the opposite colour moving upward diagonal to the left
          {
            board[i] = colour[0];//Change the piece to the players piece
          }
      }

    if(direction == 2)//Straight up
      {

        for(int i = arrayPosition-8;board[i] == search[0]; i -=8)//For all opposite colours straight up
          {
            board[i] = colour[0];//Flip pieces to players colour
          }
      }

    if(direction == 3)//Upward diagonal right
      {

        for(int i = arrayPosition-7;board[i] == search[0]; i -=7)//For all opposite colours upward diagonal right
          {
            board[i] = colour[0];//Flip to players colour
          }
      }

    if(direction == 4)//To the right
      {

        for(int i = arrayPosition-1;board[i] == search[0]; i -=1)//For all opposite colours to the right
          {
            board[i] = colour[0];//Flip to players colour
          }
      }

    if(direction == 5)//To the left
      {

        for(int i = arrayPosition+1;board[i] == search[0]; i +=1)//For all opposite colours to the bottom left
          {
            board[i] = colour[0];//Flip to players colour
          }
      }

    if(direction == 6)//Below to left
      {

        for(int i = arrayPosition+7;board[i] == search[0]; i +=7)//For all opposite colours below to the left
          {
            board[i] = colour[0];//Flip to players colour
          }
      }

    if(direction == 7)//Directly below
      {

        for(int i = arrayPosition+8;board[i] == search[0]; i +=8)//For all opposite colours directly below
          {
            board[i] = colour[0];//Flip to players colour
          }
      }

    if(direction == 8)//Below to right
      {

        for(int i = arrayPosition+9;board[i] == search[0]; i +=9)//For all below to the right
          {
            board[i] = colour[0];//Flip to players colour
          }
      }

  return board[64];//Return the new board
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

char flipCheck(char board[64], char colour[1], char search[1], int arrayPosition)//A function to check the positions needed to be flipped
{
  int j;//Declaring an integer for loops

  if((arrayPosition-9)>=0 && (arrayPosition-9)%8!=7 && board[arrayPosition-9] == search[0])//If the position to the upper left is the oppposite coloir
   {

    for(j=arrayPosition-9;j>=0&&j%8!=7;j -= 9)//Loop through all positions diagonal to upper left
      {

        if(board[j] == colour[0])//If we reach the players colour
          {
            flip(board, colour, search, arrayPosition, 1);//Use the flip function for that direction
          }

        else if(board[j] == ' ')//If we reach an empty spot, that direction is invalid
          {
            break;//Break from the loop
          }
      }
   }

  if((arrayPosition-8)>=0 && board[arrayPosition-8] == search[0])//If the position above is the opposite colour
   {

    for(j=arrayPosition-8;j>=0;j-=8)//loop through all positions above
      {

        if(board[j] == colour[0])//If we reach the players colour
          {
            flip(board, colour, search, arrayPosition, 2);//Use the flip function for that direction
          }

        else if(board[j] == ' ')//Otherwise
          {
            break;//Break
          }
     }
   }

  if((arrayPosition-7)>=0 && (arrayPosition-7)%8!=0 && board[arrayPosition-7] == search[0])//Up right
   {

    for(j=arrayPosition-7;j>=0&&j%8!=0;j-=7)//loop
      {

        if(board[j] == colour[0])//If players colour
          {
            flip(board, colour, search, arrayPosition, 3);//Flip function
          }

       else if(board[j] == ' ')//If empty
          {
            break;//Break
          }
      }
   }

  if((arrayPosition-1)%8!=7 && board[arrayPosition-1] == search[0])//To left
   {

    for(j=arrayPosition-1;j%8!=7;j-=1)//loop
      {

        if(board[j] == colour[0])//If players colour
          {
            flip(board, colour, search, arrayPosition, 4);//Flip function
          }

        else if(board[j] == ' ')//If space
          {
            break;//Break
          }
      }
   }

  if((arrayPosition+1)%8!=0 && board[arrayPosition+1] == search[0])//To right
   {

    for(j=arrayPosition+1;j%8!=0;j+=1)//Loop
      {

        if(board[j] == colour[0])//IF players colour
          {
            flip(board, colour, search, arrayPosition, 5);//Flip function
          }

        else if(board[j] == ' ')//If empty
          {
            break;//Break
          }
      }
   }

  if((arrayPosition+7)<=63 && (arrayPosition+7)%8!=7 && board[arrayPosition+7] == search[0])//Bottom left
   {

    for(j=arrayPosition+7;j<=63&&j%8!=7;j+=7)//loop
      {

        if(board[j] == colour[0])//IF players colour
          {
            flip(board, colour, search, arrayPosition, 6);//Flip function
          }

        else if(board[j] == ' ')//IF empty
          {
            break;//Break
          }
      }
   }

  if((arrayPosition+8)<=63 && board[arrayPosition+8] == search[0])//Below
   {

    for(j=arrayPosition+8;j<=63;j+=8)//loop
      {

        if(board[j] == colour[0])//If players colour
          {
            flip(board, colour, search, arrayPosition, 7);//Flip function
          }

        else if(board[j] == ' ')//IF empty
          {
            break;//Break
          }
      }
   }

  if((arrayPosition+9)<=63 && (arrayPosition+9)%8!=0 && board[arrayPosition+9] == search[0])//Bottom right
  {

    for(j=arrayPosition+9;j<=63&&j%8!=0;j+=9)//loop
      {

        if(board[j] == colour[0])//If players colour
          {
            flip(board, colour, search, arrayPosition, 8);//Flip function
          }

        else if(board[j] == ' ')//If empty
          {
            break;//Break
          }
      }
   }

  board[arrayPosition] = colour[0];//Flip the chosen piece to the players colour

  return board[64];//Return the new board
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void print(char board[64], char player1[20], char player2[20])//Function to print the board and score
{
  int white = 0;//Integer to count white pieces
  int black = 0;//Count Black
  int i;//variable for loops
  int j = 8;//Integer for loops
  int line = 1;//Integer to print line numbers
  int counter = 0;//Integer to count lines

  for(i=0;i<64;i++)//looping through board
    {

      if(board[i] == 'W')//If a position is white
        {
          white++;//Increase variable white
        }

      if(board[i] == 'B')//If black
        {
          black++;//Increase
        }
    }

  i=0;//Set i to 0

  printf("Score: %s (Black) %d:%d %s (White)\n", player1, black, white, player2);//Print score

  for(counter = 0; counter<17;counter++)//Loop for each line of the board
    {

      if(counter%2 == 0 && counter < 17)//If it is an even line
        {
          printf("   --- --- --- --- --- --- --- ---\n");//Print for appearance
        }

      else if(counter%2 != 0 && counter < 17)//Otherwise
        {
          printf("%d |", line++);//Print the line number and a line for appearance

          for(i=i;i<j;i++)//from 0 to less than j (8), i increasing
            {
              printf(" %c |", board[i]);//Print board piece
            }

          printf("\n");//Newline for appearance
          j = i+8;//Increase j to 8 more than i
        }
    }

  printf("    a   b   c   d   e   f   g   h");//Print x co-ordinates
 }

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

char initializeBoard(char board[64])//A function to initialize the board layout
{
  int i;//Integer i for loops

  for(i=0;i<64;i++)//For every board space
    {
      board[i] = ' ';//Initialize it as empty
    }

  //For the four middle pieces set them as wbbw as it is meant to be
  board[27] = 'W';
  board[28] = 'B';
  board[35] = 'B';
  board[36] = 'W';

  return board[64];//Return the board
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int availablePosition(char board[64], char colour[1])//Function to check if there is an available position on the board to play
{
  char search[10];//Variable for a  search piece

  //Search piece set to opposite of players
  if(colour[0] == 'W')
  {
    search[0] = 'B';
  }
  if(colour[0] == 'B')
  {
    search[0] = 'W';
  }

  int j;//Integer for loops

  for(int i = 0;i<64;i++)//For every board piece
    {

      if(board[i] == colour[0])/*If the board piece matches the players colour (Check if one of the immediate surrounding colours is the opposite colour (Search) and if so
                               check if follosing that piece in the same direction is a string of the opposite colour closed off by the an empty spot meaning a piece can be placed
                               there)*/
        {

          if((i-9)>=0 && (i-9)%8!=7 && board[i-9] == search[0])//Checking top left
            {

              for(j=i-9;j>=0&&j%8!=7;j -= 9)//loop
                {

                  if(board[j] == colour[0])//If closed by the players colour
                    {
                      break;//Break
                    }

                  else if(board[j] == ' ')//If closed by an empty space (A piece placed here is in a valid position)
                    {
                      return 1;//Rturn 1
                    }
                }
            }

          if((i-8)>=0 && board[i-8] == search[0])//Checking the same for straight above
            {

              for(j=i-8;j>=0;j-=8)
                {

                  if(board[j] == colour[0])
                    {
                      break;
                    }

                  else if(board[j] == ' ')
                    {
                      return 1;
                    }
                }
            }

          if((i-7)>=0 && (i-7)%8!=0 && board[i-7] == search[0])//Checking the same for up to the right
            {

              for(j=i-7;j>=0&&j%8!=0;j-=7)
                {

                  if(board[j] == colour[0])
                    {
                      break;
                    }

                  else if(board[j] == ' ')
                    {
                      return 1;
                    }
                }
            }

          if((i-1)%8!=7 && board[i-1] == search[0])//Checking the same for the left
            {

              for(j=i-1;j%8!=7;j-=1)
                {

              	   if(board[j] == colour[0])
                    {
                      break;
                    }

                  else if(board[j] == ' ')
                    {
                      return 1;
                    }
                }
            }

          if((i+1)%8!=0 && board[i+1] == search[0])//Checking the same for the right
            {

              for(j=i+1;j%8!=0;j+=1)
                {

                  if(board[j] == colour[0])
                    {
                      break;
                    }

                  else if(board[j] == ' ')
                    {
                      return 1;
                    }
                }
            }

          if((i+7)<=63 && (i+7)%8!=7 && board[i-7] == search[0])//Checking the same for the bottom left
            {

              for(j=i+7;j<=63&&j%8!=7;j-=7)
                {

                  if(board[j] == colour[0])
                    {
                      break;
                    }

                  else if(board[j] == ' ')
                    {
                      return 1;
                    }
                }
            }

          if((i+8)<=63 && board[i+8] == search[0])//Directly below
            {

              for(j=i+8;j<=63;j+=8)
                {

                  if(board[j] == colour[0])
                    {
                      break;
                    }

                  else if(board[j] == ' ')
                    {
                      return 1;
                    }
                }
            }

          if((i+9)<=63 && (i+9)%8!=0 && board[i+9] == search[0])//Below to the right
            {

              for(j=i+9;j<=63&&j%8!=0;j+=9)
                {

                  if(board[j] == colour[0])
                    {
                      break;
                    }

                  else if(board[j] == ' ')
                    {
                      return 1;
                    }
                }
            }
        }

     }

  return 0;//If none of these opetions are valid, return 0
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int validPosition(char board[64], int x, int y, char colour[1])//Function to check if the board place chosen by the user is valid, same premise as last function
{
  char search[1];//Creating a search Variable

  //Search is opposite to players colour
  if(colour[0] == 'W')
  {
    search[0] = 'B';
  }
  if(colour[0] == 'B')
  {
    search[0] = 'W';
  }

  int arrayPosition, j;//Creating two integers, arrayPosition is the spot the user picked, j for loops

  arrayPosition = (x-1)*8 + y;//Sum to change the coordinates to an integer in the array

  if(board[arrayPosition] != ' ')//If the chosen position is not empty return 0 as this is not a valid choice
    {
      return 0;
    }

  //Similar to last function however instead of checking every board position we just check the chosen position and we are looking for a line of search colours followed by the users
  //Colour
  if((arrayPosition-9)>=0 && (arrayPosition-9)%8!=7 && board[arrayPosition-9] == search[0])//If the position directly above to the left is the search colour
    {

      for(j=arrayPosition-9;j>=0&&j%8!=7;j -= 9)//Check the diagonal to the upper left
        {

          if(board[j] == colour[0])//If it reaches the users colour
            {
              return 1;//Return 1
            }

          else if(board[j] == ' ')//If it reaches an empty spot
            {
              break;//Break
            }
        }
    }

  if((arrayPosition-8)>=0 && board[arrayPosition-8] == search[0])//Same check for direcetly above
    {

      for(j=arrayPosition-8;j>=0;j-=8)
        {

          if(board[j] == colour[0])
            {
              return 1;
            }

          else if(board[j] == ' ')
            {
              break;
            }
        }
    }

  if((arrayPosition-7)>=0 && (arrayPosition-7)%8!=0 && board[arrayPosition-7] == search[0])//Above to the right
    {

      for(j=arrayPosition-7;j>=0&&j%8!=0;j-=7)
        {

          if(board[j] == colour[0])
            {
              return 1;
            }

          else if(board[j] == ' ')
            {
              break;
            }
        }
    }

  if((arrayPosition-1)%8!=7 && board[arrayPosition-1] == search[0])//To the left
    {

      for(j=arrayPosition-1;j%8!=7;j-=1)
        {

          if(board[j] == colour[0])
            {
              return 1;
            }

          else if(board[j] == ' ')
            {
              break;
            }
        }
    }

  if((arrayPosition+1)%8!=0 && board[arrayPosition+1] == search[0])//To right
    {

      for(j=arrayPosition+1;j%8!=0;j+=1)
        {

          if(board[j] == colour[0])
            {
              return 1;
            }

          else if(board[j] == ' ')
            {
              break;
            }
        }
    }

  if((arrayPosition+7)<=63 && (arrayPosition+7)%8!=7 && board[arrayPosition-7] == search[0])//Botom left
    {

      for(j=arrayPosition+7;j<=63&&j%8!=7;j+=7)
        {

          if(board[j] == colour[0])
            {
              return 1;
            }

          else if(board[j] == ' ')
            {
              break;
            }
        }
    }

  if((arrayPosition+8)<=63 && board[arrayPosition+8] == search[0])//Directly below
    {

      for(j=arrayPosition+8;j<=63;j+=8)
        {

          if(board[j] == colour[0])
            {
              return 1;
            }

          else if(board[j] == ' ')
            {
              break;
            }
        }
    }

  if((arrayPosition+9)<=63 && (arrayPosition+9)%8!=0 && board[arrayPosition+9] == search[0])//Below to right
    {

      for(j=arrayPosition+9;j<=63&&j%8!=7;j+=9)
        {

          if(board[j] == colour[0])
            {
              return 1;
            }

          else if(board[j] == ' ')
            {
              break;
            }
        }
    }

    else//Otherwise (If not a valid position)
    {
      return 0;//Return 0
    }
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int Play(char board[64], char colour[1], char player1[20])//A function for a move
{
  char search[1];//Creating a variable search

  //Search is the opposite colour to the player
  if(colour[0] == 'W')
  {
    search[0] = 'B';
  }
  if(colour[0] == 'B')
  {
    search[0] = 'W';
  }

  int x,y;//Variables x and y to store coordinates
  char letter[1];//Letter to translate the y coordinate

  printf("\n%s's turn (%c).\n", player1, colour[0]);//prompt
  printf("Enter The number of the square you would like to place a piece: ");
  scanf("%d", &x);//Scan the y coordinate to x
  printf("Enter The letter of the square you would like to place a piece: ");
  scanf(" %c", &letter[0]);//Scan the x coordinate to letters
  printf("\n");//Newline for appearance

  //Depending on which letter was given, y is assigned the corresponding integer value
  if(letter[0] == 'a')
  {
    y = 0;
  }
  else if(letter[0] == 'b')
  {
    y = 1;
  }
  else if(letter[0] == 'c')
  {
    y = 2;
  }
  else if(letter[0] == 'd')
  {
    y = 3;
  }
  else if(letter[0] == 'e')
  {
    y = 4;
  }
  else if(letter[0] == 'f')
  {
    y = 5;
  }
  else if(letter[0] == 'g')
  {
    y = 6;
  }
  else if(letter[0] == 'h')
  {
    y = 7;
  }

  int arrayPosition = (x-1)*8 + y;//X and y used to calculate the integer position in the array

  if(validPosition(board, x, y, colour) == 1)//If this is a valid position
    {
      flipCheck(board, colour, search, arrayPosition);//Check which pieces can be flipped (This function also calls flip to flip those pieces)
    }

  else//If it isnt a valid position
    {
      printf("Invalid Move, try again\n");//Prompt to user
      Play(board,colour, player1);//Play again
    }

  return board[64];//Return the board after the move
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int game(char board[64])//Function to check if the game is stil playable
{
  char White[1];//Character array white
  char Black[1];//Character array black
  White[0] = 'W';//Asign values
  Black[0] = 'B';

  if(availablePosition(board, White) !=1 && availablePosition(board, Black) != 1)//If there is no available position for white to play and no available position for black to play
    {
      return 0;//Return 0
    }

  else//Otherwise
    {
      return 1;//Return 1
    }
}
