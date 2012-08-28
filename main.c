/* Steven Rand */
/* August 27, 2012 */
/* Main function for tic-tac-toe engine */

#include <stdlib.h>
#include <stdio.h>

#include "move.h"

#include "board.c"
#include "eval.c"
#include "minimax.c"

void print_usage()
{
  printf("Hi, welcome to tic-tac-toe as implemented by");
  printf(" Steven Rand\non August 27 and 28 of 2012. You are 'O' and");
  printf(" the computer is 'X.'\nTo play a move, please insert the");
  printf(" row number in which you would like\nto play (1, 2 or 3");
  printf(" where 1 is at the top of the board)");
  printf(" followed by a\nspace and then the column number");
  printf("(also 1, 2 or 3). You get to go first.\n");
  printf("You will not be able to win, but good luck anyway!\n\n");

  return;
}

/* Prints and exits if the game is a draw */
void cats_game()
{
  printf("Cat's game. Thanks for playing.\n");\
  exit(1);
}

/* Prints and exits if the computer wins */
void ai_wins()
{
  printf("I win. Bow before your robot overlord.\n");
  exit(1);
}

int main()
{
  /* Set up global variables: board and best move */
  int i;
  char **board = (char **) malloc (sizeof(char *) * 3);
  for (i=0; i<3; i++) {
    board[i] = (char *) malloc (sizeof(char) * 3);
  }

  /* Begin the game by printing usage instructions and 
     initializing the board */
  print_usage();
  init_board(board);
  
  /* Play the game */
  int hor, vert, alpha;
  move best_move = (move) malloc (sizeof(struct legal_move));

  print_board(board);

  while (!game_over(board) && (!someone_wins(board, 'X'))) {
    scanf("%d %d", &hor, &vert); 
    hor -= 1; // adjust input values to match array indeces
    vert -= 1;
    if ((hor > 2) || (vert > 2) || (hor < 0) || (vert < 0)) { 
      printf("Sorry, that square does not exist.\n");
    } else if (board[hor][vert] != '-') { 
      printf("Sorry, that square is already occupied.\n");
    } else {
      update_board(board, hor, vert, 0);
      printf("The position after your last move:\n");
      print_board(board);
      alpha = minimax(board, 1, best_move);
      update_board(board, best_move -> hor, best_move -> vert, 1);
      printf("The position after the computer's last move:\n");
      print_board(board);
    }
  }

  if (someone_wins(board, 'X')) {
    ai_wins();
  } else {
    cats_game();
  }

  return 0; // control should never reach here
}
    

  
