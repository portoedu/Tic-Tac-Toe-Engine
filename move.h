/* Steven Rand */
/* August 27, 2012 */
/* Move data structure for tic-tac-toe engine */

typedef struct legal_move *move;

/* A move is the horizontal and vertical indeces of the 
   board (numbered 0-2) and the letter to be placed */
struct legal_move {
  int hor;
  int vert;
};
