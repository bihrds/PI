/*O Governo planeja, no novo ano, atribuir 2
aumentos no salário mínimo, um em janeiro
(de 20%) e outro em julho (de 35%) em relação
ao salário de ano anterior. Escrever programa
para ler o valor do mínimo do ano anterior e
exibir os valores dos dois novos salários.
Observar que os aumentos não são cumulativos.*/


#include <stdio.h>
#include <math.h>

const int TaxaJan = 20;
const int TaxaJul = 35;

float aumentoPercentual (float vInicial, int Aumento)
{
    return vInicial * (1 + (float) Aumento/100);
}

int main ()
{
    float SalarioMinimo;
    printf ("Qual o valor do salário mínimo no ano anterior?");
    scanf ("%f",&SalarioMinimo);

    float SJan, SJul;
        SJan = aumentoPercentual(SalarioMinimo,TaxaJan);
        SJul = aumentoPercentual(SalarioMinimo,TaxaJul);

printf ("O valor do salário mínimo em Janeiro do novo ano será de R$%.2f",SJan);
printf ("\n e em Julho do novo ano será de R$%.2f",SJul);

return 0;
}