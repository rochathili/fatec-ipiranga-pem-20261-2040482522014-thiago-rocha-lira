#include <stdio.h>
#include <string.h>

#define TAM 8

// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tab[TAM][TAM][5]) {
    int i, j;

    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            strcpy(tab[i][j], "--");
        }
    }

    // Peões
    for (j = 0; j < TAM; j++) {
        strcpy(tab[1][j], "PP"); // pretas
        strcpy(tab[6][j], "PB"); // brancas
    }

    // Torres
    strcpy(tab[0][0], "TP"); strcpy(tab[0][7], "TP");
    strcpy(tab[7][0], "TB"); strcpy(tab[7][7], "TB");

    // Cavalos
    strcpy(tab[0][1], "CP"); strcpy(tab[0][6], "CP");
    strcpy(tab[7][1], "CB"); strcpy(tab[7][6], "CB");

    // Bispos
    strcpy(tab[0][2], "BP"); strcpy(tab[0][5], "BP");
    strcpy(tab[7][2], "BB"); strcpy(tab[7][5], "BB");

    // Rainha
    strcpy(tab[0][3], "RP");
    strcpy(tab[7][3], "RB");

    // Rei
    strcpy(tab[0][4], "KP");
    strcpy(tab[7][4], "KB");
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tab[TAM][TAM][5]) {
    int i, j;
    printf("\n");
    for (i = 0; i < TAM; i++) {
        for (j = 0; j < TAM; j++) {
            printf("%s ", tab[i][j]);
        }
        printf("\n");
    }
}

// Função para mover peça
void mover(char tab[TAM][TAM][5], int li, int ci, int lf, int cf) {
    strcpy(tab[lf][cf], tab[li][ci]);
    strcpy(tab[li][ci], "...");
}

int main() {
    char tab[TAM][TAM][5];

    inicializarTabuleiro(tab);

    printf("Posição inicial:\n");
    imprimirTabuleiro(tab);

    // Jogada 1
    mover(tab, 6, 4, 4, 4); // e2 -> e4
    mover(tab, 1, 4, 3, 4); // e7 -> e5
    printf("\nJogada 1:\n");
    imprimirTabuleiro(tab);

    // Jogada 2
    mover(tab, 7, 5, 3, 1); // bispo f1 -> c4
    mover(tab, 0, 1, 2, 2); // cavalo b8 -> c6
    printf("\nJogada 2:\n");
    imprimirTabuleiro(tab);

    // Jogada 3
    mover(tab, 7, 3, 3, 7); // dama d1 -> h5
    mover(tab, 0, 6, 2, 5); // cavalo g8 -> f6
    printf("\nJogada 3:\n");
    imprimirTabuleiro(tab);

    // Jogada 4 (Xeque Mate)
    mover(tab, 3, 7, 1, 5); // dama h5 -> f7
    printf("\nJogada 4 - Xeque Mate:\n");
    imprimirTabuleiro(tab);

    return 0;
}