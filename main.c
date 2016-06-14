
/* Eduardo Porto e Matheus Balke */
/* Pontifícia Universidade Católica do Rio Grande do Sul */
/* Junho de 2016 */
/* eduardo.porto@acad.pucrs.br e matheus.balke@acad.pucrs.br */
/* Trabalho final de Laboratório de Programação */

//Este programa deve ser aberto em Full-Screen

#include <stdlib.h>
#include <stdio.h>
#include "move.h"
#include <time.h>

void ultimos(char** board, int a){
FILE* arquivo;
char c [51];

arquivo = fopen("ganhadores.txt", "a");
printf("Jogador %i, digite seu nome: ", a);
scanf(" %s", c);

fprintf(arquivo,"O(a) jogador(a) %s ganhou com a seguinte jogada:\n", c);
fprintf(arquivo,"\t\t\t ╔═════════════╗                                                    \n");
fprintf(arquivo,"\t\t\t╔╝             ╚╗                                                   \n");
fprintf(arquivo,"\t\t\t║  %2c |%2c |%2c   ║         \n", board[0][0], board[0][1], board[0][2]);
fprintf(arquivo,"\t\t\t║  ---+---+---  ║                                                   \n");
fprintf(arquivo,"\t\t\t║  %2c |%2c |%2c   ║         \n", board[1][0], board[1][1], board[1][2]);
fprintf(arquivo,"\t\t\t║  ---+---+---  ║                                                   \n");
fprintf(arquivo,"\t\t\t║  %2c |%2c |%2c   ║         \n", board[2][0], board[2][1], board[2][2]);
fprintf(arquivo,"\t\t\t╚╗             ╔╝                                                   \n");
fprintf(arquivo,"\t\t\t ╚═════════════╝                                                    \n");

fclose(arquivo);
}

void enter(){
printf("\n\n\n\n\t\t\t\t\t\t\t              ╔═══════════╗\n");
    printf("\t\t\t\t\t\t\t              ║           ║\n");
    printf("\t\t\t\t\t\t\t              ║        ║  ║\n");
    printf("\t\t\t\t\t\t\tPRESSIONE     ╚══╗     ║  ║    PARA CONTINUAR\n");
    printf("\t\t\t\t\t\t\t                 ║     ║  ║\n");
    printf("\t\t\t\t\t\t\t                 ║  ◄══╝  ║\n");
    printf("\t\t\t\t\t\t\t                 ║        ║\n");
    printf("\t\t\t\t\t\t\t                 ╚════════╝\n");
}

void credit(){

system("clear");
printf("\t\t\t\t\t**CRÉDITOS**\n");
printf("\n\n\tEstrutura Original: sjrand (GitHub: https://github.com/sjrand)\n");
printf("\tOtimização e modularização: Eduardo Porto e Matheus Balke\n");
printf("\tDesenvolvido na Pontifícia Universidade do Rio Grande do Sul\n");
printf("\tSob maestria de Marco Mangan\n");
printf("\tFinalizado em Junho de 2016\n");
printf("\n\tPRESSIONE ENTER PARA CONTINUAR\n");
getchar();
getchar();

}
	


 void leiaarq(){
	char n;
	FILE *arquivo;
	system("clear");
	arquivo = fopen("ganhadores.txt", "r");
	while (!feof(arquivo)) {
		fscanf(arquivo, "%c", &n);
		printf("%c", n);
		
	}
	fclose(arquivo);
	printf("\n\nPRESSIONE ENTER PARA CONTINUAR\n");
	getchar();
	getchar();
}


int letrapranum(char a) {
    int b;
    switch (a) {
    case '1':
        b = 1;
        break;
    case '2':
        b = 2;
        break;
    case '3':
        b = 3;
        break;
    case '4':
	b = 4;
	break;
	case '5':
	b = 5;
	break;
    default:
        b =0;
    }

    return b;
}

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
void print_usage2() {
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

/* Printa e sai se o jogo der empate */
void cats_game()
{
    int v;
    srand(time(NULL));
    v = rand() %3 + 1;

    switch(v) {
    case 1:
        printf("Empatar é fácil, quero ver ganhar...\n");
        break;
    case 2:
        printf("Ganhei? Não? Ah...empatei.\n");
        break;
    default:
        printf("É...foi um empate, quem sabe você não tenta jogar truco?\n");
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t              ╔═══════════╗\n");
    printf("\t\t\t\t\t\t\t              ║           ║\n");
    printf("\t\t\t\t\t\t\t              ║        ║  ║\n");
    printf("\t\t\t\t\t\t\tPRESSIONE     ╚══╗     ║  ║    PARA CONTINUAR\n");
    printf("\t\t\t\t\t\t\t                 ║     ║  ║\n");
    printf("\t\t\t\t\t\t\t                 ║  ◄══╝  ║\n");
    printf("\t\t\t\t\t\t\t                 ║        ║\n");
    printf("\t\t\t\t\t\t\t                 ╚════════╝\n");

    getchar();
    getchar();

}

/* Printa e sai se o computador ganhar */
void ai_wins()
{

    int v;
    srand(time(NULL));
    v = rand() %5 + 1;

    switch(v) {
    case 1:
        printf("Minha dica é: parar de tentar. Afinal, você não consegue ganhar de um monte de bits.\n");
        break;
    case 2:
        printf("Eu avisei que não tinha como ganhar, mas não, ninguém escuta o computador mesmo...\n");
        break;
    case 3:
        printf("E foi dessa maneira que o espertão perdeu pra um algoritmo de computador...NUM JOGO DA VELHA.\n");
        break;
    case 4:
        printf("Vai tentando, vai que alguma hora...Não, não tem como mesmo.\n");
        break;
    default:
        printf("Nunca ganharam de mim, e mesmo assim insistem em ficar tentando...\n");
    }


    enter();


    getchar();
    getchar();

}

void cabecario() {

    system("clear");

    printf("\n\n\t\t           ██╗ ██████╗  ██████╗  ██████╗     ██████╗  █████╗     ██╗   ██╗███████╗██╗     ██╗  ██╗ █████╗   \n");
    printf("\t\t           ██║██╔═══██╗██╔════╝ ██╔═══██╗    ██╔══██╗██╔══██╗    ██║   ██║██╔════╝██║     ██║  ██║██╔══██╗  \n");
    printf("\t\t           ██║██║   ██║██║  ███╗██║   ██║    ██║  ██║███████║    ██║   ██║█████╗  ██║     ███████║███████║  \n");
    printf("\t\t      ██   ██║██║   ██║██║   ██║██║   ██║    ██║  ██║██╔══██║    ╚██╗ ██╔╝██╔══╝  ██║     ██╔══██║██╔══██║  \n");
    printf("\t\t      ╚█████╔╝╚██████╔╝╚██████╔╝╚██████╔╝    ██████╔╝██║  ██║     ╚████╔╝ ███████╗███████╗██║  ██║██║  ██║  \n");
    printf("\t\t       ╚════╝  ╚═════╝  ╚═════╝  ╚═════╝     ╚═════╝ ╚═╝  ╚═╝      ╚═══╝  ╚══════╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝  \n\n\n");
}

int jogada(char** board, char a) {
    int hor, vert;
    char hc, vc;
    printf("Digite a linha: ");
    scanf(" %c", &hc);
    hor = letrapranum(hc);
    hor -= 1;
    if(hor < 0 || hor > 2) {
        printf("\nLinha inserida é invalida!\n");
    }
    else {
        printf("Digite a coluna: ");
        scanf(" %c", &vc);
        vert = letrapranum(vc);
        vert -= 1;
        if ((vert > 2) || (vert < 0)) {
            printf("\nOps, esta coluna é inválida.\n");
        } else if (board[hor][vert] != '-') {
            printf("\nOpa, este lugar já está ocupado!\n");
        } else {
            update_board(board, hor, vert, a);
            return 1;
        }
    }
    return 0;

}


void umjogador(char **board) {
    system("clear");
    print_usage1();
    int hor, vert, alpha;
    move best_move = (move) malloc (sizeof(struct legal_move));
    print_board(board);

    while (!game_over(board) && (!someone_wins(board, 'X'))) {
        if (jogada(board,0)) {
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
void doisjogadores(char **board) {
    system("clear");
    print_usage2();
    print_board(board);
    while ((!game_over(board) && (!someone_wins(board, 'O')))) {
        while(1) {
            printf("\n\t\t\tVez de jogador 1:\n");
            if (jogada(board,'X')) {
                break;
                //print_board(board)
            }
        }
        if(game_over(board) || someone_wins(board, 'X'))
            break;
        system("clear");
        print_board(board);

        while (1) {
            printf("\n\t\t\tVez de jogador 2:\n");
            if(jogada(board,0)) {
                break;
            }
        }
        system("clear");
        print_board(board);
    }
    system("clear");
    print_board(board);
    if (someone_wins(board, 'X')) {
        printf("\t\t\t\t\t\t\t\tJogador 1 ganhou!\n");

	enter();

        getchar();
		ultimos(board, 1);
    } else if (someone_wins(board, 'O'))  {
        printf("\t\t\t\t\t\t\t\tJogador 2 ganhou!\n");

	enter();


        getchar();
		ultimos(board, 2);
    } else{
        printf("\t\t\t\t\t\t\t\tFoi um empate!\n");

    	enter();
    	getchar();
	getchar();
}
	

}

int main()
{

    /* Gera variáveis globais : board e melhor jogada */

    int i, caso, exit=0;
    char num;

    char **board = (char **) malloc (sizeof(char *) * 3);
    for (i=0; i<3; i++) {
        board[i] = (char *) malloc (sizeof(char) * 3);
    }


    while (exit != 5) {
        cabecario();
        /* Inicia o jogo printando as instruções de uso e inicializando o tabuleiro */

        init_board(board);
        /* Joga o jogo */

        printf("\t\t\t\t\t\t Escolha uma opção de jogo: \n");
        printf("\t\t\t\t\t\t |1- Um jogador\n");
        printf("\t\t\t\t\t\t |2- Dois jogadores\n");
		printf("\t\t\t\t\t\t |3- Ganhadores Anteriores\n");
		printf("\t\t\t\t\t\t |4- Créditos\n");
        printf("\t\t\t\t\t\t |5- Sair\n");
        scanf(" %c", &num);
        caso= letrapranum(num);
        switch(caso)
	 {
        case 1:
            umjogador(board);
            break;
        case 2:
            doisjogadores(board);
            break;
	case 3:
		leiaarq(); 
		break;        
	case 4:
            credit();
            break;
	case 5:
			system("clear");
			exit = 5;
			break;
        default:
            printf("Inválido");
        }
    }

    return 0; // Controle nunca deve chegar aqui
}
