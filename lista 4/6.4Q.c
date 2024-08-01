/*O IBGE realizou um concurso para contratar pessoas para trabalhar no censo. Cada candidato fez uma prova de português 
com 50 questões, outra de matemática com 35 questões, e uma prova de redação.

Para ser aprovado, era necessário acertar pelo menos 80% da prova de português, 60% da prova de matemática e ter nota 
igual ou superior a 7 na redação.

Escreva um programa que receba como entrada, para cada candidato, a quantidade de questões certas em português 
e em matemática, e também e nota na redação e depois exiba quantos candidatos foram aprovados.

A entrada deve ser encerrada quando a quantidade de questões informada for inferior a zero*/

/*OBS: calculei a porcentagem necessaria por fora do código e já incrementei os acertos necessários
80% de 50= 40
60% de 35= 21 */

#include <stdio.h>

float verificarPort (float acertosPort){
    if (acertosPort >= 40)
        return 1;
    else 
        return 0;
}

float verificarMat (float acertosMat){
    if (acertosMat >= 21)
        return 1;
    else 
        return 0;
}

float verificarRed (float notaRed){
    if (notaRed >= 7)
        return 1;
    else 
        return 0;
}

int main(){
    int acertosPort, acertosMat , notaRed;
    int candidatosAprovados = 0;

    do{
        printf ("Quantas questoes o candidato acertou em portugues? \n");
        scanf ("%d", &acertosPort);
        if (acertosPort == 0) break; //Parar o laço.
        printf ("Quantas questoes o candidato acertou em matematica? \n");
        scanf ("%d", &acertosMat);
        printf ("Qual a nota do candidato em redacao? \n");
        scanf ("%d", &notaRed);

        float situacaoCandidatos;
        situacaoCandidatos = verificarPort(acertosPort) + verificarMat(acertosMat) + verificarRed(notaRed);

        if (situacaoCandidatos == 3){
            printf ("APROVADO \n");
            candidatosAprovados = candidatosAprovados + 1;}
        else
            printf ("REPROVADO \n");
        
    }

    while (acertosPort == 0);
    
    printf ("A quantidade de candidatos aprovados é de: %d", candidatosAprovados);

    return 0;
    
}