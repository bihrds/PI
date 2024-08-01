/*Exercício.Faça um programa que leia um número inteiro e retorne seu antecessor e seu sucessor:*/

#include <stdio.h>

int main() 
{
    int numero;
    printf ("Qual numero você deseja saber o antecessor e o sucessor?");
    scanf ("%d", &numero);
    
    int numeroAntecessor = numero - 1;
    int numeroSucessor = numero + 1;
    
    printf ("%d %d", numeroAntecessor, numeroSucessor);
    
    return 0;
}
