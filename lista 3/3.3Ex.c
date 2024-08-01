//Escrever programa para ler o valor de um salário e atribuir aumento de 50% caso este seja igual ou inferior a R$850,00.

#include <stdio.h>

int main ()
{
    float salario;
    printf ("Qual o valor do salario?");
    scanf ("%f", &salario);

    if (salario <= 850)
    {  
        salario = salario * 1.5;
        printf("salario sera de R$%.2f\n", salario);
    
    return 0;}
}