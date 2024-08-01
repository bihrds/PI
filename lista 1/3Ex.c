/*Exercício- O Governo planeja, em 2026, atribuir 2 aumentos no salário mínimo, um em janeiro (de 20%) 
e outro em julho (de 35%) em relação ao salário de 2025. Escrever  programa para ler o valor do mínimo 
em 2025 e exibir os valores dos dois novos salários.exemplo*/

#include <stdio.h>

int main() 
{
    float Salario;
    printf ("Qual o valor do salário em 2025?");
    scanf ("%f", &Salario);
    float salarioJan, salarioJun;
    salarioJan = Salario * 1.2;
    salarioJun = Salario * 1.35;
    printf ("Em janeiro/2026 o salário será de R$%0.2f e em junho/2026 será de R$%0.2f", salarioJan, salarioJun);
    
    return 0;
}