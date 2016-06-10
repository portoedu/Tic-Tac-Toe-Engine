/* Eduardo Porto e Matheus Balke */
/* Pontifícia Universidade Católica do Rio Grande do Sul */
/* Junho de 2016 */
/* eduardo.porto@acad.pucrs.br e matheus.balke@acad.pucrs.br */
/* Trabalho final de Laboratório de Programação */

#include <stdio.h>



/* Funções essenciais para a representação 2D do Jogo da velha :
 inicializar um tabuleiro vazio, atualizar o tabuleiro apropriadamente 
 após a jogada e printar o tabuleiro */


/* Faz com que todos os espaços preenchidos com '-' 
 signifiquem vazio. Para uso no início de cada jogo */

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

/* Aloca um 'X' ou um 'O' no espaço indicado.
 Se o jogador não for zero o computador se move e
 coloca um 'X'. Se o jogador for 0 então o utilizador s
 e move e coloca um 'O' */

void update_board(char **board, int hor, int vert, int player)
{
  if (player) { // Jogada do computador
    board[hor][vert] = 'X';
  } else {      // Jogada do utilizador
    board[hor][vert] = 'O';
  }

  return;
}

/* Mostra a grade 3 x 3 com 'X's e 'O's alocados apropriadamente */

void print_board(char **board)
{
      printf("\t\t\t\t\t\t\t\t ╔═════════════╗\n");
	  printf("\t\t\t\t\t\t\t\t╔╝             ╚╗   \n");
 	  printf("\t\t\t\t\t\t\t\t║  %2c |%2c |%2c   ║ \n", board[0][0], board[0][1], board[0][2]);
      printf("\t\t\t\t\t\t\t\t║  ---+---+---  ║\n");
      printf("\t\t\t\t\t\t\t\t║  %2c |%2c |%2c   ║ \n", board[1][0], board[1][1], board[1][2]);
      printf("\t\t\t\t\t\t\t\t║  ---+---+---  ║\n");
      printf("\t\t\t\t\t\t\t\t║  %2c |%2c |%2c   ║ \n", board[2][0], board[2][1], board[2][2]);
	  printf("\t\t\t\t\t\t\t\t╚╗             ╔╝ \n");
	  printf("\t\t\t\t\t\t\t\t ╚═════════════╝\n");
  putchar ('\n');
  return;
}
