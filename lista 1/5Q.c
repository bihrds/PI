/*Exercío.Escrever programa em C para solicitar ao usuário a distância que ele pretende
correr e sua velocidade média esperada. Exibir o tempo estimado de exercício
(corrida).*/

#include <stdio.h>

int main() 
{
    float distanciaPercorrer, velocidadeMedia;
     printf ("Qual distância você pretender percorrer?(em km)\n");
        scanf ("%f", &distanciaPercorrer);
    printf ("Qual a velocidade média esperada?(em km/h)\n");
        scanf ("%f", &velocidadeMedia);
        
    int tempoEstimado;
    tempoEstimado = distanciaPercorrer/velocidadeMedia;
    
     printf ("O tempo estimado de exercício é de %d horas!", tempoEstimado);

    return 0;
}