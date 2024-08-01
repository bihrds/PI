/* Na loja de Sr. Zé compras acima de R$300,00 podem ser parceladas em 
até 10 vezes, para tanto são aplicados juros simples de 10% ao mês, 
conforme o número de meses. Dado valor da compra, exibir o valor total 
e o valor das parcelas. Aplicar for e função.*/

#include <stdio.h>

void jurosSimples (float valor){

    float juros = valor * 0.1;

    float total = valor;

    float valorParcela;

    for (int mes= 1; mes <= 10; mes ++)
    {
        total = total + juros;
        valorParcela = total / mes;
        printf ("Pagamento em %d mes - Juros: R$%.2f - Total: R$%.2f - Parcela %dx R$%.2f \n", mes, juros, total, mes, valorParcela);
    }
}

int main ()
{
    float valorCompra;
    printf("Qual o valor da compra?");
    scanf("%f", &valorCompra);
    
    if (valorCompra > 300)
        jurosSimples(valorCompra);
    return 0;
}