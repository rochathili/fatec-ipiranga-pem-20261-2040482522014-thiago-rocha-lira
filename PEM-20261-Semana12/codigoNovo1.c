/*----------------------------------------------------------*
*                      FATEC Ipiranga                       *
* Disciplina: Programaçao Estruturada e Modular             *
*          Prof. Veríssimo                                  *
*-----------------------------------------------------------*
* Objetivo do Programa: Busca em profundidade(Recursividade)*
* Data - 24/04/2026                                         * 
* Autor: Thiago Lira                                        *
*-----------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_PASTAS 50
#define MAX_SUB 10
#define LIMITE_ALERTA 300.0

typedef struct Pasta {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    struct Pasta* subpastas[MAX_SUB];
    int qtd_sub;
} Pasta;

Pasta drive[MAX_PASTAS];

float processarHierarquia(Pasta* pasta, int nivel_atual, int limite_profundidade) {
    if (nivel_atual > limite_profundidade) {
        return 0;
    }

    Pasta* atual = pasta;

    (*atual).tamanho_total = (*atual).tamanho_proprio;

    for (int i = 0; i < (*atual).qtd_sub; i++) {
        (*atual).tamanho_total += processarHierarquia(
            (*atual).subpastas[i],
            nivel_atual + 1,
            limite_profundidade
        );
    }

    for (int i = 0; i < nivel_atual; i++) {
        printf("  ");
    }

    printf("|-- %s [%.2f GB]", (*atual).nome, (*atual).tamanho_total);

    if ((*atual).tamanho_total > LIMITE_ALERTA) {
        printf(" [!] ALERTA: GARGALO DETECTADO");
    }

    printf("\n");

    return (*atual).tamanho_total;
}

int main() {
    Pasta* p = drive;

    strcpy(p[0].nome, "RAIZ");
    p[0].tamanho_proprio = 10.0;
    p[0].qtd_sub = 2;

    strcpy(p[1].nome, "Projetos_TI");
    p[1].tamanho_proprio = 50.0;
    p[1].qtd_sub = 1;

    strcpy(p[2].nome, "Backups_Antigos");
    p[2].tamanho_proprio = 350.0;
    p[2].qtd_sub = 0;

    strcpy(p[3].nome, "Videos_Aulas");
    p[3].tamanho_proprio = 280.0;
    p[3].qtd_sub = 0;

    p[0].subpastas[0] = &p[1];
    p[0].subpastas[1] = &p[2];
    p[1].subpastas[0] = &p[3];

    int limite;
    printf("Defina o limite de profundidade do mergulho: ");
    scanf("%d", &limite);

    clock_t t;
    t = clock();

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE ---\n");
    processarHierarquia(&p[0], 0, limite);
    printf("-------------------------------------------\n");

    t = clock() - t;

    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}