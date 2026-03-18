#include <stdio.h>
#include <string.h>

// Definição da estrutura Cachorro
struct Cachorro {
    char nome[50];
    int idade;
    char raca[50];
};

// Função para exibir os dados do cachorro
void exibirCachorro(struct Cachorro c) {
    printf("Nome: %s\n", c.nome);
    printf("Idade: %d anos\n", c.idade);
    printf("Raça: %s\n", c.raca);
}

// Função principal
int main() {
    struct Cachorro meuCachorro;

    // Atribuindo valores
    strcpy(meuCachorro.nome, "Rex");
    meuCachorro.idade = 5;
    strcpy(meuCachorro.raca, "Labrador");

    // Exibindo dados
    exibirCachorro(meuCachorro);

    return 0;
}