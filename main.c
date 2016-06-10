/* Steven Rand */
/* August 27, 2012 */
/* Main function for tic-tac-toe engine */

#include <stdlib.h>
#include <stdio.h>
#include "move.h"
#include <time.h>

void print_usage1()
{
	system("clear");
	putchar ('\n');
    printf("\t\t\t\t\t ╔══════════════════════════════════════════════════════════════════╗ \n");
 printf("\t\t\t\t\t╔╝                                                                  ╚╗\n");
 printf("\t\t\t\t\t║   Então isto é um desafio? Eu contra você?! Você joga com 'O' e    ║\n");
 printf("\t\t\t\t\t║   eu jogarei com 'X'. Para fazer uma jogada, insira                ║\n"); 
 printf("\t\t\t\t\t║   o número da linha que gostaria de jogar (1, 2 ou 3               ║\n");
 printf("\t\t\t\t\t║   onde 1 é o topo do tabuleiro)                                    ║\n");
 printf("\t\t\t\t\t║   em seguida tecle 'ENTER' e então o número da coluna              ║\n");
 printf("\t\t\t\t\t║   (também 1, 2 ou 3). Eu deixo você ir primeiro.                   ║\n");
 printf("\t\t\t\t\t║   Você não tem nem chance de me vencer, mas boa sorte igual...     ║\n");
 printf("\t\t\t\t\t╚╗                                                                  ╔╝\n");
 printf("\t\t\t\t\t ╚══════════════════════════════════════════════════════════════════╝ \n");


    return;
}
void print_usage2(){
	system("clear");
	putchar ('\n');
 printf("\t\t\t\t  ╔════════════════════════════════════════════════════════════════════════════════════╗ \n");
 printf("\t\t\t\t ╔╝                                                                                    ╚╗\n");
 printf("\t\t\t\t ║    O Jogador 1 joga com 'X' e o Jogador 2 joga com 'O'.                              ║\n");
 printf("\t\t\t\t ║   Para jogar, insira o número da linha (1, 2 ou 3, onde 1 é o topo do tabuleiro)     ║\n");
 printf("\t\t\t\t ║    seguido por 'ENTER' e então o número da coluna (1, 2 ou 3 também).                ║\n");
 printf("\t\t\t\t ╚╗                                                                                    ╔╝\n");
 printf("\t\t\t\t  ╚════════════════════════════════════════════════════════════════════════════════════╝ \n");
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

int jogada(char** board, char a){
		int hor, vert;
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
				update_board(board, hor, vert, a);
				return 1;
			}
		}
	return 0;
	
}


void umjogador(char **board){
	system("clear");
	print_usage1();
    int hor, vert, alpha;
    move best_move = (move) malloc (sizeof(struct legal_move));
	 print_board(board);

	while (!game_over(board) && (!someone_wins(board, 'X'))) {
				if (jogada(board,0)){
		        system("clear");
		        printf("A posição depois de sua última jogada:\n");
		        print_board(board);
		        alpha = minimax(board, 1, best_move);
		        update_board(board, best_move -> hor, best_move -> vert, 1);
		        printf("A posição depois da última jogada do computador:\n");
		        print_board(board);
		}		    
	}
		
    
	if (someone_wins(board, 'X')) {
        ai_wins();
    } else {
        cats_game();
    }
}
	void doisjogadores(char **board){
		system("clear");
		print_usage2();
		print_board(board);
			while ((!game_over(board) && (!someone_wins(board, 'O')))) {
				while(1){				
				printf("\n\t\t\tVez de jogador 1:\n");	
				if (jogada(board,'X')){
					break;
						//print_board(board)
				}
				}
				if(game_over(board) || someone_wins(board, 'X'))
					break;		
					system("clear");	
				print_board(board);
				
				while (1){	
					printf("\n\t\t\tVez de jogador 2:\n");	
				if(jogada(board,0)){
					break;
				}
			}
				system("clear");
				print_board(board);
			}
	
	print_board(board);
	if (someone_wins(board, 'X')) {
        printf("\tJogador 1 ganhou!\n");
    } else
		if (someone_wins(board, 'O'))  {
     	printf("\tJogador 2 ganhou!\n");
    }else 
	printf("\tFoi um empate!\n");

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
			doisjogadores(board);
			break;
	default: printf("Inválido"); 
	}


    return 0; // control should never reach here
}



