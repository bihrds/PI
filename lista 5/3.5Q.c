/*D. Maria tem um ônibus que faz diariamente, das 8 as 18 
horas, o trajeto Rosa Elze – Atalaia. É feita 1 viagem por 
hora e D. Maria registra o número de passageiros de cada 
uma para identificar o horário com maior número de 
passageiros. Para tanto foi implementado e discutido em 
sala um programa em C. Efetuar ajustes nesse de forma 
que seja identificado o horário com menor número de 
passageiros, exibir o número médio de passageiros, a soma 
de passageiros do dia e o montante recebido por D. Maria, 
considerando que a passagem custa R$22,00. Aplicar for e 
pelo menos 1 função. */

//Ônibus UFS Atalaia - Qual melhor horário?

#include <stdio.h>

float mediaPassageiros (int numPassageiros){
    return (numPassageiros/11);}

float montanteRecebido (int numPassageiros){
    return (numPassageiros*22);}

int main()
{
    int horas, numPassageiros, maisPassageiros, melhorHorario, menosPassageiros, piorHorario;
    maisPassageiros = 0;
    menosPassageiros = 5000;
    int somaPassageiros=0;
    for (horas=8; horas<=18; horas++)
    {
        printf("Numero de passageiras de %d horas: \n",horas);
        scanf("%d",&numPassageiros);

        if (numPassageiros > maisPassageiros)
        {
            melhorHorario = horas;
            maisPassageiros = numPassageiros;
        }
        if (numPassageiros < menosPassageiros)
        {
            piorHorario = horas;
            menosPassageiros = numPassageiros;
        }
        
        somaPassageiros = somaPassageiros + numPassageiros;
    }
    
    float media = mediaPassageiros(somaPassageiros);
    float montante = montanteRecebido(somaPassageiros);

    printf("Horario de maior procura: %d horas e horario de menor procura: %d horas.\n",melhorHorario, piorHorario);
    printf("O numero medio de passageiros e de %.1f e a soma de passageiros do dia e %d. \n", media, somaPassageiros);
    printf("O montante recebido por D. Maria é de R$%.2f", montante);
    
    return 0;
}
