#include "recursao.h"
#include <stdio.h>

void decToBin(int n)
{
    if (n > 0)
    {
        decToBin(n / 2);
        printf("%d", n % 2);
    }
}

int potencia(int base, int exp)
{
    if (exp == 0)
    {
        return 1;
    }
    else
    {
        return base * potencia(base, exp - 1);
    }
}

int somaDigitos(int n)
{
    if(n == 0){
        return 0;
    }
    else{
        return((n % 10) + somaDigitos(n / 10));
    }
}