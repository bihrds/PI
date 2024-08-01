/*Há pessoas que precisam fazer tratamento de saúde contínuo (em comprimidos), a exemplo de reposição hormonal. 
Sabendo que uma pessoa deve fazer uso de X comprimidos ao mês e que em cada caixadesse há N unidades (comprimidos); 
escrever um programa em C onde se lê X e N e é exibido o número de caixas a serem adquiridas.*/

#include <stdio.h>

int Quociente (int Dividendo, int Divisor)
{
    float Divisao;
    Divisao = (float) Dividendo/Divisor;
    Divisao = ceil(Divisao);

    return(int)Divisao;
}

int main ()
{
int QMensal, QCaixas;
    printf ("Quantidade de comprimidos ao mês:");
     scanf ("%d", &QMensal);
    printf ("Quantidade de comprimidos em uma caixa:");
     scanf ("%d", &QCaixas);

    printf ("O número de caixas a serem adquiridas será: %d caixas", Quociente(QMensal,QCaixas));

return 0;
}