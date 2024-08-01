/*Exercício.Escrever programa que receba a medida de dois ângulos internos de um triângulo, calcule e mostre a medida do terceiro ângulo;
sabendo que a soma dos ângulos internos de um triângulo é 180.*/

#include <stdio.h>

int main() 
{
    int angulo1, angulo2, angulo3;
     printf ("Qual o primeiro angulo em graus?");
        scanf ("%d", &angulo1);
     printf ("Qual o segundo angulo em graus?");
        scanf ("%d", &angulo2);
    
    angulo3 = 180 - angulo1 - angulo2;
    printf ("O valor do terceiro angulo do triangulo é %d", angulo3);
    
    return 0;
    
}