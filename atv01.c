#include <stdio.h>
#include <string.h>

int main() {
    char frase[100];
    int palavras = 0;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';

    int tamanho = strlen(frase);

    for(int i = 0; i < tamanho; i++){
        if(frase[i] == ' '){
            palavras++;
        }
    }

    printf("Número de palavras: %d\n", palavras + 1);

    return 0;
}