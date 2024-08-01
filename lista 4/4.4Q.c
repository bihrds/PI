/*Escrever programa , sem aplicar resto de divisão (%) e valor do quociente (/), para calcular a quantidade
de meses contidos numa dada quantidade de dias. Considerar que todos os meses são compostos por 30 dias
e desprezar o montante de dias que não formam pelo menos um mês completo (resto).*/

#include <stdio.h>

int calcMeses (int quantidadeDias){

    int quantidadeMeses = 0;

    while (quantidadeDias >= 30)
    {
        quantidadeDias = quantidadeDias - 30;
        quantidadeMeses = quantidadeMeses + 1;
    }

    return (quantidadeMeses);
    
}

int main(){

    int qntDias;
    printf ("Qual a quantidade de dias? \n");
    scanf ("%d", &qntDias);

    printf ("A quantidade de meses sera de %d", calcMeses(qntDias));

    return 0;
}