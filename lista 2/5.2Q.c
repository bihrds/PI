/*Escrever um programa em C para ler o raio de um círculo e exibir em tela a área desse (círculo) usando a fórmula: 
Área = π . raio2. Usar um módulo/função para cálculo da área, outro módulo/função para cálculo do quadrado. 
E usar uma constante para definição de π. Recomenda-se o uso de função e/ou constante nativa, se houver.*/

#include <stdio.h>

int Quadrado (int r)
{
    return r*r;
}

const float PI = 3.14;

float AreaCirc (float x)
{
    float CalcAreaCirc;
    CalcAreaCirc = PI*Quadrado(x);
    return CalcAreaCirc;
}

int main ()
{
    float RaioCirc;
    printf ("Raio do circulo:");
    scanf ("%f", &RaioCirc);
    printf ("A area do circulo será %.1f",AreaCirc(RaioCirc));

    return 0;
}