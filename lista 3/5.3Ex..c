/*Numa loja web os valores dos fretes são calculados em conformidade com os totais das compras. 
Se valor da compra é até R$300,00 (inclusive), o frete corresponde a 35% desta; para valores maiores, o frete é
de 20% do valor desta. Escrever programa para ler valor da compra e exibir valor final, com frete.*/

#include <stdio.h>

int main ()
{
    float ValorCompra;
    printf ("Qual o valor da compra?");
    scanf ("%f", &ValorCompra)

    ValorCompra = ValorCompra <= 300 ? ValorCompra * 1.35 : ValorCompra * 1.20;

    printf ("Valor final sera: %.2f", ValorCompra);

    return 0;
}