/*Exercío.Criar um programa em C que converta a temperatura de Celsius para
Fahrenheit. Solicite ao usuário a temperatura em Celsius e exiba o resultado em Fahrenheit. Pesquise e escreva, como comentário, a regra de conversão usada.*/

#include <stdio.h>

int main() 
{
    int temperaturaCelsius, temperaturaFahrenheit;
     printf ("Qual a temperatura em Celsius deseja converter para Fahrenheit?\n");
        scanf ("%d", &temperaturaCelsius);
        
    /*Para convertermos temperaturas em Celsius para Fahrenheit, multiplicamos a temperatura em ºC por 1,8 e 
    somamos 32 ao resultado.*/
     
     temperaturaFahrenheit = (temperaturaCelsius * 1.8) + 32;
     
     printf ("A temperatura em Fahrenheit é %d", temperaturaFahrenheit);
     
     return 0;
}