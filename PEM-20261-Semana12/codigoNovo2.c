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

#define LIMITE_ALERTA 300.0

typedef struct Pasta {
    char nome[50];
    float tamanho_proprio;
    float tamanho_total;
    struct Pasta* subpastas[10];
    int qtd_sub;
} Pasta;

Pasta drive[50];

void processarIterativo(Pasta* p) {

    for (int i = 0; i < p[0].qtd_sub; i++) {
        Pasta* filho = p[0].subpastas[i];

        for (int j = 0; j < filho->qtd_sub; j++) {
            Pasta* neto = filho->subpastas[j];
            neto->tamanho_total = neto->tamanho_proprio;
        }
    }

    for (int i = 0; i < p[0].qtd_sub; i++) {
        Pasta* filho = p[0].subpastas[i];

        filho->tamanho_total = filho->tamanho_proprio;

        for (int j = 0; j < filho->qtd_sub; j++) {
            filho->tamanho_total += filho->subpastas[j]->tamanho_total;
        }
    }

    p[0].tamanho_total = p[0].tamanho_proprio;

    for (int i = 0; i < p[0].qtd_sub; i++) {
        p[0].tamanho_total += p[0].subpastas[i]->tamanho_total;
    }

    for (int i = 0; i < 3; i++) {
        Pasta* atual = &p[i];

        printf("|-- %s [%.2f GB]", atual->nome, atual->tamanho_total);

        if (atual->tamanho_total > LIMITE_ALERTA) {
            printf(" [!] ALERTA: GARGALO DETECTADO");
        }

        printf("\n");
    }
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

    clock_t t;
    t = clock();

    printf("\n--- RELATORIO DE HIERARQUIA INTELIGENTE ---\n");
    processarIterativo(p);
    printf("-------------------------------------------\n");

    t = clock() - t;

    double tempo_execucao = ((double)t) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao: %f segundos\n", tempo_execucao);

    return 0;
}