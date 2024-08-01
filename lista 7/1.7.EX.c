/*Implementar programa para ler números até
que o usuário tenha inserido (digitado)
valores cuja soma seja igual ou superior a S;
sendo S dado pelo usuário. Ao final, exibir
todos os números que foram considerados
para compor a soma S. No máximo pode
haver 20 valores. Este pode ser usado, por
exemplo, para organizar uma caixa com até 20
itens, a qual tem um peso limite S, correspondente
à soma dos itens.*/

#include <stdio.h>
#include <stdlib.h>

void exibeVetor(int V[], int quantItens){
    printf ("Os valores considerados sao: \n");
    for (int i = 0; i <= quantItens; i++)
        printf ("%d", V[i]);
    printf ("\n");
}

int main (){
    const int tamanho = 20;
    int soma = 0, S, cont = 0, vetor[tamanho];
    system ("cls");
    system ("color 60"); // 6 - amarelo, 0 - preto
    printf ("Qual o limite da soma?");
    scanf("%d",&S);
    while ((soma < S) && (cont < tamanho)){
        printf ("Digite um valor: ");
        scanf ("%d",&vetor[cont]);
        soma = soma + vetor[cont];
        cont++;
    }
    cont--;
    if (soma == S)
        printf ("Soma igual ao limite! \n");
    else if (soma > S)
        printf("Soma superior ao limite! \n");
        else 
            printf("Soma inferior ao limite! \n");
    if (cont+1 == tamanho)
        printf ("Quantidade de termos igual ao limite! \n");
    else
        printf ("Quantidade de termos menor  que o limite! \n");
    exibeVetor(vetor,cont);
    
    return 0;
    
}