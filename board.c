/* Steven Rand */
/* August 27, 2012 */

/* Some useful functions on a tic-tac-toe board
   represented as a 2-D array: initialize an empty board,
   update the board appropriately after a move and
   print the board. */

/* Sets all squares on the board to '-', 
   meaning empty. For use at the beginning 
   of each new game. */
void init_board(char **board)
{
  int i, j;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      board[i][j] = '-';
    }
  }

  return;
}

/* Places an 'X' or an 'O' on the indicated square.
   If player is non-zero then the computer moves and 
   places an 'X'. If player equals zero then user 
   moves and places an 'O'. */
void update_board(char **board, int hor, int vert, int player)
{
  if (player) { // Computer's move
    board[hor][vert] = 'X';
  } else {      // User's move
    board[hor][vert] = 'O';
  }

  return;
}

/* Shows the board as a 3 x 3 grid with
   'X's and 'O's placed appropriately */
void print_board(char **board)
{
  int i, j;
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      putchar(board[i][j]);
      if (j == 2) {
	putchar('\n');
      }
    }
  }
  putchar ('\n');
  return;
}

