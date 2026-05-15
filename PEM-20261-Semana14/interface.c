#include "interface.h"
#include <stdio.h>

void exibirMenu(void)
{
    printf("\n========================================\n");
    printf("   Calculadora Cientifica (CUCC)\n");
    printf("========================================\n");
    printf("1. Converter Decimal para Binario\n");
    printf("2. Calcular Potencia\n");
    printf("3. Somar Digitos de um Numero\n");
    printf("0. Fechar o programa\n");
    printf("========================================\n");
}

int capturarEscolhaUsuario(void)
{
    int escolha;
    printf("Escolha uma opcao: ");
    scanf("%d", &escolha);
    return escolha;
}

int receberNumero(void)
{
    int numero;
    printf("Insira um numero inteiro: ");
    scanf("%d", &numero);
    return numero;
}