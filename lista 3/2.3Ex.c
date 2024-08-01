//Programa para ler o número é PAR ou ÍMPAR

#include <stdio.h>

int main ()
{
    int N;
    printf ("Digite um número:");
    scanf ("%d",&N);

    if (N % 2==0)
        printf ("%d é par", N);

    else
        printf ("%d é impar", N);

return 0;

}