#include <stdio.h>

void iniciarTabuleiro(char tabuleiro[3][3]){
    int k = 1;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = '0' + k;
            k++;
        }
    }
}

void desenharTabuleiro(char tabuleiro[3][3]){
    printf("\n");
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("| %c |", tabuleiro[i][j]);
            if(j == 2){
                printf("\n");
                printf("---------------\n");
            }
        }
    }
}

// Em trabalho
void popularCasa(char tabuleiro[3][3], int posicaoX, int posicaoY){
    if(tabuleiro[posicaoX][posicaoY] != ' '){
        printf("Campo já ocupado\n");
    }
}

int main(){
    char tabuleiro[3][3];

    iniciarTabuleiro(tabuleiro);
    desenharTabuleiro(tabuleiro);

    popularCasa(tabuleiro, 1, 1);

    return 0;
}