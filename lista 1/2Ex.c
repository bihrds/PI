/*Valor a ser pago em uma flor, em um buque, valor do pagamento e troco, exemplo:*/

#include <stdio.h>

int main() 
{
    float vRosa, vBuque, vPago;
    int qRosa;
    printf ("Qual a quantidade de rosas?");
    scanf ("%d", &qRosa);
    printf ("Qual o valor da rosa?");
    scanf ("%f", &vRosa);
    vBuque = vRosa*qRosa;
    printf ("O valor total a pagar é R$%.2f.\n", vBuque);
    printf ("Qual o valor pago?");
    scanf ("%f", &vPago);
    printf ("O troco será de R$%.2f.", vPago-vBuque);
    
    return 0;
}