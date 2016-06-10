/* Steven Rand */
/* August 27, 2012 */
/* Main function for tic-tac-toe engine */

#include <stdlib.h>
#include <stdio.h>
#include "move.h"
#include <time.h>

void print_usage()
{
	system("clear");

    printf("Então isto é um desafio? Eu contra você?!\nVocê joga com 'O' e");
    printf(" eu jogarei com 'X'\nPara fazer uma jogada, insira");
    printf(" o número da linha que gostaria\nde jogar (1, 2 ou 3");
    printf(" onde 1 é o topo do tabuleiro)");
    printf(" em seguida tecle 'ENTER'\ne então o número da coluna");
    printf("(também 1, 2 ou 3). Eu deixo você ir primeiro.\n");
    printf("Você não tem nem chance de me vencer, mas boa sorte igual...\n\n");



    return;
}

/* Prints and exits if the game is a draw */
void cats_game()
{


  int v;
	srand(time(NULL));
	v = rand() %3 + 1;
	
	switch(v){
	case 1: printf("Empatar é fácil, quero ver ganhar...\n");
	break;
	case 2: printf("Ganhei? Não? Ah...empatei.\n");
	break;
	default: printf("É...foi um empate, quem sabe você não tenta jogar truco?\n");}

  exit(v);

}

/* Prints and exits if the computer wins */
void ai_wins()
{

  int v;
	srand(time(NULL));
	v = rand() %5 + 1;
	
	switch(v){
	case 1: printf("Minha dica é: parar de tentar. Afinal, você não consegue ganhar de um monte de bits.\n");
	break;
	case 2: printf("Eu avisei que não tinha como ganhar, mas não, ninguém escuta o computador mesmo...\n");
	break;
	case 3: printf("E foi dessa maneira que o espertão perdeu pra um algoritmo de computador...NUM JOGO DA VELHA.\n");
	break;
	case 4: printf("Vai tentando, vai que alguma hora...Não, não tem como mesmo.\n");
	break;
	default: printf("Nunca ganharam de mim, e mesmo assim insistem em ficar tentando...\n");}

  exit(v);

}

void cabecario(){

system("clear");

printf("\n\n\t\t           ██╗ ██████╗  ██████╗  ██████╗     ██████╗  █████╗     ██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗   \n");
printf("\t\t           ██║██╔═══██╗██╔════╝ ██╔═══██╗    ██╔══██╗██╔══██╗    ██║   ██║██╔════╝██║     ██║  ██║██╔══██╗  \n");
printf("\t\t           ██║██║   ██║██║  ███╗██║   ██║    ██║  ██║███████║    ██║   ██║█████╗  ██║     ███████║███████║  \n");
printf("\t\t      ██   ██║██║   ██║██║   ██║██║   ██║    ██║  ██║██╔══██║    ╚██╗ ██╔╝██╔══╝  ██║     ██╔══██║██╔══██║  \n");
printf("\t\t      ╚█████╔╝╚██████╔╝╚██████╔╝╚██████╔╝    ██████╔╝██║  ██║     ╚████╔╝ ███████╗███████╗██║  ██║██║  ██║  \n");
printf("\t\t       ╚════╝  ╚═════╝  ╚═════╝  ╚═════╝     ╚═════╝ ╚═╝  ╚═╝      ╚═══╝  ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝  \n\n\n");
}

void umjogador(char **board){
	system("clear");
	print_usage();
    int hor, vert, alpha;
    move best_move = (move) malloc (sizeof(struct legal_move));
	 print_board(board);

	while (!game_over(board) && (!someone_wins(board, 'X'))) {
		printf("Digite a linha: ");
        scanf("%i", &hor);
		hor -= 1;
		if(hor < 0 || hor > 2){
			printf("\nLinha inserida é invalida!\n");}
		else {
			printf("Digite a coluna: ");
			scanf("%i", &vert);
		    vert -= 1;
		    if ((vert > 2) || (vert < 0)){
		        printf("Ops, esta coluna é inválida.\n");
		    } else if (board[hor][vert] != '-') {
		        printf("Opa, este lugar já está ocupado!\n");
		    } else {
		        system("clear");
		        update_board(board, hor, vert, 0);
		        printf("A posição depois de sua última jogada:\n");
		        print_board(board);
		        alpha = minimax(board, 1, best_move);
		        update_board(board, best_move -> hor, best_move -> vert, 1);
		        printf("A posição depois da última jogada do computador:\n");
		        print_board(board);
		    }
		} 
    }
	if (someone_wins(board, 'X')) {
        ai_wins();
    } else {
        cats_game();
    }
}


int main()
{
    /* Set up global variables: board and best move */
    int i, caso;
    char **board = (char **) malloc (sizeof(char *) * 3);
    for (i=0; i<3; i++) {
        board[i] = (char *) malloc (sizeof(char) * 3);
    }
	
	cabecario();
    /* Begin the game by printing usage instructions and
       initializing the board */
    
    init_board(board);
    /* Play the game */

	printf("\t\t\t\t\t\t Escolha uma opção de jogo: \n");
	printf("\t\t\t\t\t\t |1- Um jogador\n");
	printf("\t\t\t\t\t\t |2- Dois jogadores\n");
	scanf("%d", &caso);
	switch(caso){
    case 1:
		  	umjogador(board);
			break;
	case 2:
			
			break;
	default: printf("Inválido"); 
	}


    return 0; // control should never reach here
}



