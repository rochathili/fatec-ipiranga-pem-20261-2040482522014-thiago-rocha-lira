#include <stdio.h>

void iniciarTabuleiro(char tabuleiro[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = 'O';
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

int main(){
    char tabuleiro[3][3];
    
    iniciarTabuleiro(tabuleiro);
    desenharTabuleiro(tabuleiro);

    return 0;
}