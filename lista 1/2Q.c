/*Exercício.Para a manutenção da saúde é indispensável que as pessoas mantenham o peso ideal e, assim, evitem a obesidade.
 Escrever programa para ler: peso atual, peso ideal e perda mensal; e exibir em quantos dias a pessoa alcançará o 
 peso ideal.*/

#include <stdio.h>

int main() 
{
    float pesoAtual, pesoIdeal, perdaMensal;
     printf ("Qual seu peso atual?");
        scanf ("%f", &pesoAtual);
     printf ("Qual peso ideal para você?");
        scanf ("%f", &pesoIdeal);
     printf ("Qual sua perda de peso mensal?");
        scanf ("%f", &perdaMensal);
        
    int diasNecessários;
    
    diasNecessários = (pesoIdeal-pesoAtual)/perdaMensal*30;
        
    printf ("Você consiguira alcançar seu peso ideal em %d dias", diasNecessários);
    
    
    return 0;
}