//Escrever programa em C para ler um número N e retornar N3 (N ao cubo), aplicando função (que calcula cubo).

#include <stdio.h>

int Cubo (int x)
{
    return x*x*x;
}

int main (){
    printf ("Número que deseja saber o cubo: ");
    int N;
    scanf ("%d", &N);
    printf ("Este numero ao cubo é igual a %d", Cubo(N));
}