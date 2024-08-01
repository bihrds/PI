/*Implementar programa para ler total de vendas, de um
determinado mês, dos 300 vendedores da “Matura”,
calcular a média de vendas do grupo de vendedores, e
exibir quantos vendedores apresentaram desempenho
(vendas) abaixo da média.*/

#include <stdio.h>
#include <stdlib.h>

int calcMedia (int totalVendas){
    return (totalVendas/5);
}

int main (){
    float valorVendas, vendedoresMatura[300]; //vetor quantidade de vendedores
    int i; // indicie, incrementador
    int soma = 0, somaMedia = 0;

    for (i = 0; i < 300; i++){
        printf ("Qual o total de vendas do vendedor %d?", i);
        scanf ("%f", &valorVendas);
        vendedoresMatura[i] = valorVendas;
        soma = soma + valorVendas;
    }

    float media;
    media = calcMedia(soma);

    for (i = 0; i < 300; i++){
        if (vendedoresMatura[i] < media){
            somaMedia = somaMedia + 1;
        }
    }
    
    printf("%d vendedores apresentaram desempenho abaixo da media!", somaMedia);
}