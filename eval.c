/* Steven Rand */
/* August 27, 2012 */
/* Evaluation functions for tic-tac-toe engine:
   determine whether or not all squares are occupied,
   determine whether or not the given player has won */

/* Returns non-zero if all squares are occupied, i.e.,
   the game has ended. Makes no determination on result. */
int game_over(char **board)
{
  int i, j;

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      if (board[i][j] == '-') { // an empty square exists
	return 0;
      }
    }
  }

  return 1;
}

/* Helper function for someone_wins function below: checks
   to see if all three elements of an array are the given
   letter */
int same_letter(char *line, char letter)
{
  int i;

  for (i=0; i<3; i++) {
    if (line[i] != letter) {
      return 0;
    }
  }
  
  return 1;
}

/* Determines whether or not there has been a result:
   positive if the given letter appears thrice in a line
   and zero if not. */
int someone_wins(char **board, char letter)
{
  /* Handles someone winning on a row */
  if ((same_letter(board[0], letter)) || (same_letter(board[1], letter))
      || (same_letter(board[2], letter))) {
    return 1;
  }
  
  /* Handles someone winning on a column */
  int i;
  int j = -1;
  char column[3];

  while (j++ < 3) {
    for (i=0; i<3; i++) {
      column[i] = board[i][j];
    }
    if (same_letter(column, letter)) {
      return 1;
    } 
  }

 /* Handles someone winning on a diagonal
    using brute force method */
  if (((board[0][0] == letter) && (board[1][1] == letter) &&
       (board[2][2] == letter))
      || ((board [0][2] == letter) && (board[1][1] == letter)
	  && (board[2][0] == letter))) {
    return 1;
  }

  return 0; // no one has won yet
}
      

      
  

  
