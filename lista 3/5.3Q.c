/*Faça um programa para verificar se determinado número inteiro lido N é divisível por A ou B, mas não simultaneamente 
pelos dois valores dados. São A e B, bem como N, dados pelo usuário. Atendendo a condição estabelecida, emitir mensagem 
“ATENDE CONDIÇÃO”; caso contrário, exibir: “NÃO ATENDE CONDIÇÃO”.*/
#include <stdio.h>

int main ()
{
    int numeroInteiro;
    printf ("Qual o numero inteiro? ");
    scanf ("%d", &numeroInteiro);

    int A, B;
    printf ("Qual o primeiro numero? ");
    scanf ("%d", &A);
    printf ("Qual o segundo numero? ");
    scanf ("%d", &B);

    if (numeroInteiro % A==0 && numeroInteiro % B==0)
        printf ("NAO ATENDE CONDICAO");
    
    else 
        if (numeroInteiro % A==0 || numeroInteiro % B==0)
            printf ("ATENDE CONDICAO");

        else 
            printf("NAO ATENDE CONDICAO");

    return 0;
}