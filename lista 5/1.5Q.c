/*Maria está fazendo a “Dieta de Saturno” para emagrecimento e a previsão é de que a perda de peso seja de 5 kg mensais. 
Ajustar programa em C para ler o peso inicial e o peso almejado, exibir o peso alcançado (em teoria) a cada mês, conforme 
o que prevê a dieta, e corrigir os erros que ocorrem quando o peso almejado não é múltiplo de 5, bem como quando o peso 
inicial é menor que o peso almejado. Aplicar for*/

#include <stdio.h>

int main () 
{
    float pesoInicial, pesoAlmejado, peso;
    printf ("Qual o peso inicial?");
    scanf ("%f", &pesoInicial);
    printf ("Qual o peso que deseja almejar?");
    scanf ("%f", &pesoAlmejado);
    peso= pesoInicial;
    
    for (int Mes; peso >= pesoAlmejado; Mes ++)
    {
        printf ("Mes %d: %.2f \n", Mes, peso);
        peso = peso - 5;

        if ((int)pesoAlmejado %5 != 0 && pesoAlmejado > peso && pesoAlmejado != (peso + 5))
            printf ("Mes %d: %.2f \n", Mes + 1, pesoAlmejado);
    }
return 0;
}