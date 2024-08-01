/*Exercío.Escrever programa em C para solicitar um valor monetário em reais, o câmbio
real - dólar, e exiba o valor em dólar.*/

#include <stdio.h>

int main() 
{
    float valorMonetario, valorCambio, valorDolar;
     printf ("Qual o valor monetário em reais?\n");
        scanf ("%f", &valorMonetario);
    printf ("Qual o valor do câmbio de real-dólar\n?");
        scanf ("%f", &valorCambio);
    
    valorDolar = valorMonetario / valorCambio;
    
     printf ("O valor em dolár será de %.2f", valorDolar);

    return 0;
}