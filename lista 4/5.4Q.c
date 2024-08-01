/*Escreva um programa para ajudar Carla. O programa vai receber como entrada uma sequência de números, cada um em uma 
linha, representando o PH de cada solução. A última entrada vai ser o número - 1. Indicando que não há mais soluções para
serem analisadas e o programa pode encerrar sua execução.

Para cada solução o programa vai determinar sua acidez

Ácida(Ph<7); Básica(Ph>7); Neutra(Ph=7)*/

#include <stdio.h>

void calcPh (float numero){
    if (numero < 7)
        printf ("ACIDA \n");
    else
        if (numero > 7)
            printf ("BASICA \n");
        else 
            printf ("NEUTRA \n");
}

int main(){
    float nmrAnalisar;
    printf ("Qual numero de PH deseja analisar? \n");
    scanf ("%f", &nmrAnalisar);
    while (nmrAnalisar != -1)
    {
        calcPh(nmrAnalisar);
        scanf ("%f", &nmrAnalisar);
    }

    printf ("Programa encerrado! \n");
    
    return 0;

}