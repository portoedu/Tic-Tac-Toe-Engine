/* Steven Rand */
/* August 27, 2012 */
/* Main function for tic-tac-toe engine */

#include <stdlib.h>
#include <stdio.h>
#include "move.h"

void print_usage()
{
    printf("Bem vindo ao Jogo da Velha!\nVocê joga com 'O' e");
    printf(" o computador (eu) com 'X'\nPara fazer uma jogada, insira");
    printf(" o número da linha que gostaria\nde jogar (1, 2 ou 3");
    printf(" onde 1 é o topo do tabuleiro)");
    printf(" seguido por\nespaço e o número da coluna");
    printf("(também 1, 2 ou 3). Eu deixo você ir primeiro.\n");
    printf("Você não tem nem chance de me vencer, mas boa sorte igual...\n\n");

    return;
}

/* Prints and exits if the game is a draw */
void cats_game()
{
    printf("Cat's game. Thanks for playing.\n");
    \
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
            system("clear");
            printf("Sorry, that square does not exist.\n");
        } else if (board[hor][vert] != '-') {
            system("clear");
            printf("Sorry, that square is already occupied.\n");
        } else {
            system("clear");
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



