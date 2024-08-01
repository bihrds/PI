/* Exemplo 2- Para efetuar compra online é preciso dispor de valor para cobrir o o valor do produto, bem como do valor do
frete. Para tanto é preciso poupar e contar com cupons de desconto sobre o frete. Construir programa em C para ler:
(a) valor final (produto e frete), (b) valor do cupom (desconto) para frete, e (c) quanto foi economizado; e retornar
 quanto falta em percentual para efetuar a compra.*/

#include <stdio.h>

float Restante (float Economia, float Cupom, float Total)
{

    float Parcial;
    Parcial = Economia + Cupom;

    float Restante;
    Restante = Total - Parcial;

    return Restante / Total * 100;
}
int main()
{

    float VFinal, VCupom, VEconomia, FPercentual;
    printf("Qual o valor final do produto incluindo o frete?");
    scanf("%f", &VFinal);
    printf("Qual o valor do cupom aplicado na compra?");
    scanf("%f", &VCupom);
    printf("Qual o valor economizado?");
    scanf("%f", &VEconomia);

    FPercentual = Restante(VEconomia, VCupom, VFinal);
    printf("Falta em percentual para finalizar a compra %.1f%%", FPercentual);

    return 0;
}