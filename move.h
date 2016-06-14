/* Eduardo Porto e Matheus Balke */
/* Pontifícia Universidade Católica do Rio Grande do Sul */
/* Junho de 2016 */
/* eduardo.porto@acad.pucrs.br e matheus.balke@acad.pucrs.br */
/* Trabalho final de Laboratório de Programação */

/* Move estruturas de dados para o jogo da velha */

typedef struct legal_move *move;

/* Um movimento é o espaço horizontal ou vertical do quadro(numerados 0 -2 ) e o lugar a ser posto */

struct legal_move {
    int hor;
    int vert;
};
