/*Quantidade de bolas de sorvete, total da compra e troco,exemplo:*/

#include <stdio.h>

int main() 
{
    float vBola, vTotal, vPago;
    int qBolas;
    printf ("Quantas bolas de sorvete você deseja?");
    scanf ("%d", &qBolas);
    printf ("Quanto custa cada bola de sorvete?");
    scanf ("%f", &vBola);
    vTotal = vBola * qBolas;
    printf ("Valor total a ser pago é de R$%.2f.\n", vTotal);
    printf ("Qual o valor recebido?");
    scanf ("%f", &vPago);
    printf ("O troco será de R$%.2f", vPago-vTotal);
    return 0; }