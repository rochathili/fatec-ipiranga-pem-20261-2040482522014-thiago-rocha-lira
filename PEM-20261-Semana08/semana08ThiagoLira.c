/*-------------------------------------------------------*
*                      FATEC Ipiranga                    *
* Disciplina: Programaçao Estruturada e Modular          *
*          Prof. Veríssimo                               *
*--------------------------------------------------------*
* Objetivo do Programa: Gestão de carga em logística     *
* Data - 23/04/2026                                      * 
* Autor: Thiago Rocha Lira                               *
*--------------------------------------------------------*/

#include <stdio.h>

void processarCarga(float *vetor, int tamanho)
{
    // Declaração das vairveis
    float soma = 0;
    float media;
    float limite;
    float *p;

    // somando os pesos
    for (int i = 0; i < tamanho; i++)
    {
        soma += vetor[i];
    }

    // calculando a média e o limite
    media = soma / tamanho;
    limite = media * 1.10;

    // processamento de pesos
    for (int i = 0; i < tamanho; i++)
    {
        p = &vetor[i];

        if (*p > limite)
        {
            *p = *p * 0.95;
        }
    }
}

int main()
{
    // declaração dos vetores
    float pesos[10] = {100, 120, 95, 130, 110, 90, 140, 105, 115, 125};

    int tamanho = 10;

    // impressão do vetor antes do processamento
    printf("Pré-processamento:\n");
    for (int i = 0; i < tamanho; i++)
    {
        // tratamento de saida para duas casa decimais
        printf("%.2f ", pesos[i]);
    }

    // invocando a função de processamento
    processarCarga(pesos, tamanho);

    // impressão do vetor pós-processamento
    printf("\n\nPós-procesamento:\n");
    for (int i = 0; i < tamanho; i++)
    {
        // tratamento de saida para duas casa decimais
        printf("%.2f ", pesos[i]);
    }

    return 0;
}   