/*Faça um programa para ler N números inteiros e positivos e de cada um desses apresente o fatorial. 
O cálculo do fatorial deve ser efetuado por meio de função elaborada pelo programador.*/

#include <stdio.h>

int fatorial (int nmr)
{
    if (nmr == 0)
        return 1;
    for (int i = nmr; i > 1; i--)
    {
        nmr =  nmr * (i - 1);
    }
    return nmr;
}

int main ()
{
    int numero;
    printf ("Qual o numero?");
    scanf ("%d", &numero);

    int calcFatorial = fatorial(numero);
    printf ("O fatorial do numero dado e %d", calcFatorial);

    return 0;
}