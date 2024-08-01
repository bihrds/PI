/*7.Escrever um programa em C sobre investimento. Deve ser efetuada a leitura do valor inicial investido, 
do valor investido mensalmente e do tempo de investimento (desconsiderar juros) e retornar o valor final (montante) e o
valor do rendimento (montante – valor inicial investido). Deve ser aplicado um módulo(função) com dois parâmetros de saída.*/

#include <stdio.h>

void VFinalRendimento (float Inicial, float Investido, float Tempo,float *VFinal,float *Rendimento)
{
    *VFinal = Inicial + (Investido * Tempo);
    *Rendimento = (float) *VFinal - Inicial;
}

int main()
{
    float VInicial, VMensal, TempoInvestido;
    printf ("Qual o valor inicial do investimento?");
     scanf ("%f", &VInicial);
    printf ("Qual o valor investido mensalmente?");
     scanf ("%f", &VMensal);
    printf ("Qual o tempo de investimento?");
     scanf ("%f", &TempoInvestido);
    
    float VFinal, Rendimento;
    VFinalRendimento(VInicial,VMensal,TempoInvestido,&VFinal,&Rendimento);

    printf ("O valor final sera de R$%.2f e o valor do rendimento sera R$%.2f",VFinal , Rendimento);

}