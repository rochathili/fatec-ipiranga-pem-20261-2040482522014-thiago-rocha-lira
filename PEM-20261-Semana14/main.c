/*----------------------------------------------------------*
*                      FATEC Ipiranga                       *
* Disciplina: Programaçao Estruturada e Modular             *
*          Prof. Veríssimo                                  *
*-----------------------------------------------------------*
* Objetivo do Programa: Conversor e calculadora cient. CUCC *
* Data - 15/05/2026                                         * 
* Autor: Thiago Rocha Lira                                  *
*-----------------------------------------------------------*/
#include <stdio.h>
#include "recursao.h"
#include "interface.h"

int main() {
    int opcao;
    int numero, base, exp, resultado;

    do {
        exibirMenu();
        opcao = capturarEscolhaUsuario();

        switch (opcao) {
            case 1:
                numero = receberNumero();
                printf("Representacao Binaria: ");
                decToBin(numero);
                printf("\n");
                break;

            case 2:
                base = receberNumero();
                exp = receberNumero();
                resultado = potencia(base, exp);
                printf("Resultado da potencia: %d\n", resultado);
                break;

            case 3:
                numero = receberNumero();
                resultado = somaDigitos(numero);
                printf("A soma dos algarismos e: %d\n", resultado);
                break;

            case 0:
                printf("Saindo do sistema... Ate logo!\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        
    } while (opcao != 0);

    return 0;
}