/* Eduardo Porto e Matheus Balke */
/* Pontifícia Universidade Católica do Rio Grande do Sul */
/* Junho de 2016 */
/* eduardo.porto@acad.pucrs.br e matheus.balke@acad.pucrs.br */
/* Trabalho final de Laboratório de Programação */

/*Funções evaluation do jogo da velha:
	determina caso todos os espaços estão ocupados,
	determina caso algum jogador ganhou*/

/* Retorna 1 se todos os espaços estão ocupados, então o
jogo terminou. */
int game_over(char **board)
{
    int i, j;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] == '-') { // Um espaço vazio existe.
                return 0;
            }
        }
    }

    return 1;
}
/* Função que ajudar a função someone_wins: checa para ver se todos três elementos
de uma lista são as letras dadas. */

int same_letter(char *line, char letter)
{
    int i;

    for (i=0; i<3; i++) {
        if (line[i] != letter) {
            return 0;
        }
    }

    return 1;
}

/* Retornar positivo se uma letra aparecer três vezes em uma linha
   e zero caso não. */
int someone_wins(char **board, char letter)
{
    /* Lidar com alguém ganhando em uma linha */
    if ((same_letter(board[0], letter)) || (same_letter(board[1], letter))
            || (same_letter(board[2], letter))) {
        return 1;
    }

    /* Lidar com alguém ganhando nas colunas. */
    int i;
    int j = -1;
    char column[3];

    while (j++ < 3) {
        for (i=0; i<3; i++) {
            column[i] = board[i][j];
        }
        if (same_letter(column, letter)) {
            return 1;
        }
    }

    /* Lidar com alguém ganhando nas diagonais
       usando método brute force. */
    if (((board[0][0] == letter) && (board[1][1] == letter) &&
            (board[2][2] == letter))
            || ((board [0][2] == letter) && (board[1][1] == letter)
                && (board[2][0] == letter))) {
        return 1;
    }

    return 0; // Ninguém ganhou ainda.
}






