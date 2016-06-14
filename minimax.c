/* Eduardo Porto e Matheus Balke */
/* Pontifícia Universidade Católica do Rio Grande do Sul */
/* Junho de 2016 */
/* eduardo.porto@acad.pucrs.br e matheus.balke@acad.pucrs.br */
/* Trabalho final de Laboratório de Programação */

/*Implementa o algoritmo basico minimax para o jogo da velha. */

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
/*Retorna uma lista de movimentos possíveis no quadro
	e atualiza os valores de ponteiros no decorrer da lista.*/
move *find_moves(char **board, int *num_moves)
{
    int i, j;
    int count_moves = 0;
    /*Aloca um alista do número máximo de movimentos possíveis*/
    move *move_array = (move *) malloc(sizeof(move) * 9);
    for (i=0; i<9; i++) {
        move_array[i] = (move) malloc (sizeof(struct legal_move));
    }

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] == '-') { // Lugar vazio
                move_array[count_moves] -> hor = i;
                move_array[count_moves] -> vert = j;
                count_moves++;
            }
        }
    }

    *num_moves = count_moves;
    return move_array;
}
/*Faz uma copia identica do quadro. */

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
/*É o corpo do algoritmo minimax: Maximiza as possibilidades de ganhar
	e minimiza as possibilidades de perder a cada rodada assumindo uma
jogada perfeita do oponente */
int minimax_recurse(char **board, int player, int depth, move best_move)
{
    int i, j, hor, vert, alpha, subalpha;

    if (someone_wins(board, 'X')) { // computador ganhou
        return 1;
    } else if (someone_wins(board, 'O')) { // usuário ganhou
        return -1;
    } else if (game_over(board)) { // empate
        return 0;
    }

    if (player) { // computador é o jogador ativo
        alpha = -1;
    } else { // usuário e o jogador ativo
        alpha = 1;
    }

    int num_moves;
    move *moves = find_moves(board, &num_moves); // todos movimentos são possíveis

    for (i=0; i<num_moves; i++) {
        char **dummy_board = copy_board(board);

        hor = moves[i] -> hor;
        vert = moves[i] -> vert;

        update_board(dummy_board, hor, vert, player);

        /*Recursividade aplicada ao minimax em cada subvariação. */
        subalpha = minimax_recurse(dummy_board, !player, (depth + 1),
                                   best_move);

        if (player) { // vez do computador
            if (!depth && (alpha <= subalpha)) { // salva melhor movimento da jogada
                best_move -> hor = moves[i] -> hor;
                best_move -> vert = moves[i] -> vert;
            }
            alpha = max(alpha, subalpha); // maximiza
        } else { // vez do jogador
            alpha = min(alpha, subalpha); // minimiza
        }

        /* Evita  o disperdício de memória liberando o quadro. */
        for (j=0; j<3; j++) {
            free(dummy_board[j]);
        }
        free(dummy_board);
    }

    return alpha;
}
/*Chamado na main: Acha o melhor movimento usando o algoritmo
	minimax*/
int minimax(char **board, int curplayer, move best_move)
{
    return minimax_recurse(board, curplayer, 0, best_move);
}












