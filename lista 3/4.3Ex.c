//Aumento salarial

#include <stdio.h>

const int TaxaJan = 20;
const int TaxaJul = 35;

float aumentoPercentual (float vInicial, char Mes){
    if ( Mes == '1')
        return vInicial * (1 + (float) TaxaJan/100);
    else
        return vInicial * (1 + (float) TaxaJul/100);
    }

int main ()
{
    float salario;
    printf ("Qual o valor do salario no ano anterior?");
    scanf ("%f", &salario);

    float SJan, SJul;
        SJan = aumentoPercentual(SalarioMinimo,TaxaJan);
        SJul = aumentoPercentual(SalarioMinimo,TaxaJul);

    printf ("O valor do salario em Janeiro do novo ano sera de %.2f", SJan);
    printf ("O valor do salario em julho do novo ano sera de %.2f", SJul);

    return 0;
}
