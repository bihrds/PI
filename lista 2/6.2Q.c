/*Escrever um programa em C para ler peso em kg e altura em m. Calcular e exibir o IMC da pessoa considerando 
IMC = peso / altura2. Para cálculo de IMC usar função, e nessa aplicar função de cálculo da potência (seja definida 
pelo programação ou nativa).*/

#include <stdio.h>

float Potenciacao (float x)
{
float Potencia;
Potencia = pow(x,2);
return Potencia;
} 

float IMC (float Peso, float Altura)
{
    float CalcularImc;
    CalcularImc= Peso/ (Potenciacao(Altura));
    return CalcularImc;
}

int main ()
{
    float QPeso, QAltura;
    printf ("Qual seu peso em Kg? ");
    scanf ("%f", &QPeso);
    printf ("Qual sua altura? ");
    scanf ("%f", &QAltura);
    printf ("Seu IMC é: %.1f", IMC(QPeso,QAltura));
    return 0;
}