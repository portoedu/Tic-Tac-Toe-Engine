/* Steven Rand */
/* August 27, 2012 */
/* Implements a basic minimax algorithm for
   the tic-tac-toe engine. No pruning or heuristic
   evaluation function is necessary for tic-tac-toe. */

#include <stdlib.h>
#include "move.h"

int max(int a, int b)
{
  if (a >= b) {
    return a;
  } else {
    return b;
  }
}

int min(int a, int b)
{
  if (a >= b) {
    return b;
  } else {
    return a;
  }
}

/* Returns an array of legal moves on the given board
   and updates the value at the pointer to the length
   of the array */
move *find_moves(char **board, int *num_moves)
{
  int i, j;
  int count_moves = 0;

  /* Allocate an array for the maximum number of legal moves */
  move *move_array = (move *) malloc(sizeof(move) * 9);
  for (i=0; i<9; i++) {
    move_array[i] = (move) malloc (sizeof(struct legal_move));
  }

  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      if (board[i][j] == '-') { // empty square
	move_array[count_moves] -> hor = i;
	move_array[count_moves] -> vert = j;
	count_moves++;
      }
    }
  }
  
  *num_moves = count_moves;
  return move_array;
}

/* Makes an identical copy of the given board */
char **copy_board(char **board1)
{
  int i, j;

  char **board2 = (char **) malloc (sizeof(char *) * 3);
  for (i=0; i<3; i++) {
    board2[i] = (char *) malloc (sizeof(char) * 3);
  }
  
  for (i=0; i<3; i++) {
    for (j=0; j<3; j++) {
      board2[i][j] = board1[i][j];
    }
  }
    
  return board2;
}

/* Does the body of the work for the minimax algorithm: Seeks to 
   maximize possible gain and minimize possible loss at each turn
   assuming perfect play by the opponent. */
int minimax_recurse(char **board, int player, int depth, move best_move)
{
  int i, j, hor, vert, alpha, subalpha;

  if (someone_wins(board, 'X')) { // computer wins
    return 1;
  } else if (someone_wins(board, 'O')) { // user wins
    return -1;
  } else if (game_over(board)) { // tie
    return 0;
  }

  if (player) { // computer is active player
    alpha = -1;
  } else { // user is active player
    alpha = 1;
  }
  
  int num_moves;
  move *moves = find_moves(board, &num_moves); // all legal moves

  for (i=0; i<num_moves; i++) {
    char **dummy_board = copy_board(board);

    hor = moves[i] -> hor;
    vert = moves[i] -> vert;
    
    update_board(dummy_board, hor, vert, player);

    /* Recursively apply minimax to each subvariation */
    subalpha = minimax_recurse(dummy_board, !player, (depth + 1),
			       best_move); 

    if (player) { // computer's turn
      if (!depth && (alpha <= subalpha)) { // save best move at root
	best_move -> hor = moves[i] -> hor;
	best_move -> vert = moves[i] -> vert;
      }
      alpha = max(alpha, subalpha); // maximize
    } else { // user's turn
      alpha = min(alpha, subalpha); // minimize
    }
   
    /* Avoid a memory leak by freeing boards */ 
    for (j=0; j<3; j++) {
      free(dummy_board[j]);
    }
    free(dummy_board);  
  }

  return alpha;
}

/* Called in main: Finds the best move by starting the minimax
   algorithm at a depth of 0, i.e., the position on the board
   at the time of applying the algorithm */
int minimax(char **board, int curplayer, move best_move)
{
  return minimax_recurse(board, curplayer, 0, best_move);
}


	
	
  
    
    
    
    

  

