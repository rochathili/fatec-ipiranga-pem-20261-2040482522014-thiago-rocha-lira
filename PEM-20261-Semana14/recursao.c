#include "recursao.h"

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
    if(exp == 0){
        return 1;
    } 
    else
    {
        return base * potencia(base, exp-1);
    }
}