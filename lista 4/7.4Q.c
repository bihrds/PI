/*O IBGE realizou um concurso para contratar pessoas para trabalhar no censo. Cada candidato fez uma prova de português 
com 50 questões, outra de matemética com 35 questões, e uma prova de redação.

Para ser aprovado, era necessário acertar pelo menos 80% da prova de português, 60% da prova de matemática e ter nota 
igual ou superior a 7 na redação.

Escreva um programa que receba como entrada, para cada candidato, a quantidade de questês certas em português 
e em matemática, e também e nota na redação e depois exiba quantos candidatos foram aprovados.

Escrever programa com saída mais elegante. Por exemplo, perguntar ao usuário se desejar sair, oferecendo as opções:
S – Sim ou N - Não.*/

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
    char entradaCandidato;
    int candidatosAprovados = 0;
    do{
        printf ("Quantas questoes o candidato acertou em portugues? \n");
        scanf ("%d", &acertosPort);
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

        
        printf ("Deseja ver a situacao de outro candito? (digite ""S"" ou ""N""): \n");
            scanf (" %c", &entradaCandidato);
            while (entradaCandidato != 'S' && entradaCandidato != 'N' ){
                printf ("Comando nao reconhecido \n");
                printf ("Digite ""S"" ou ""N""): \n");
                scanf (" %c", &entradaCandidato);
                }
    }

    while (entradaCandidato == 'S');
    
    printf ("A quantidade de candidatos aprovados é de: %d", candidatosAprovados);

    return 0;
    
}