/*Zelda e seus amigos tiveram uma brilhante ideia durante as aulas da monitoria da cadeira de introdução a programação:
que tal fazer um programa que, dado um número n(1 <- n <- 40) printa na tela os número de 1 até o número da iteração atual, 
sendo que serão feitas n iterações, como demonstrado no exemplo a seguir.

Supondo para n=5
(primeira iteração):1
(segunda iteração):1 2
(terceira iteração):1 2 3
(quarta iteração):1 2 3 4
(quinta iteração):1 2 3 4 5 */

#include <stdio.h>

void printarTela (int numeroDado){
    int iteracaoAtual = 1;
    int metaAtual = 1;

    while (metaAtual<=numeroDado)
    {
        while (iteracaoAtual<=metaAtual)
        {
            printf (" %d", iteracaoAtual);
            iteracaoAtual++;//Incrementa 1.
        }
        iteracaoAtual = 1;
        metaAtual++; //Incrementa 1.
        printf ("\n");
    }
    
}

int main(){
    int numeroDado;
    printf ("Qual numero deseja fazer iteracoes? \n");
    scanf ("%d", &numeroDado);

    if (numeroDado >= 1 && numeroDado <= 40)
        printarTela(numeroDado);
    else 
        printf ("Numero invalido! \n");
        

    return 0;
}