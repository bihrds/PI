/*Ler notas de alunos e identificar se cada um foi aprovado.Considerar como sistema de avaliação: em principio, 3 notas; 
são aprovados os alunos com media 7; para os alunos com media acima de 3, é possibilitado fazer 4 avaliação,  então a 
média passa a ser 5 para obtenção da aprovação. Após a identificação de que um aluno foi aprovado, ou não; deve ser 
questionado se o usário(do programa) deseja verificar situação de outro aluno*/

#include <stdio.h>

float calcMedia (float notaUm, float notaDois, float notaTres){
    return (notaUm + notaDois + notaTres)/3;
}

int main (){
    
    float Nota1, Nota2, Nota3;
    char entradaUsuario;

    do{
        printf ("Qual a primeira nota? \n");
        scanf ("%f", &Nota1);
        printf ("Qual a segunda nota? \n");
        scanf ("%f", &Nota2);
        printf ("Qual a terceira nota? \n");
        scanf ("%f", &Nota3);

        float Media= calcMedia(Nota1,Nota2,Nota3);

        if (Media >= 7)
            printf ("Aprovado! \n");
        else
            if (Media > 3)
                printf ("Pode fazer quarta avaliacao \n");
            else 
                printf ("Reprovado \n");

        
        printf ("Deseja ver a situacao de outro aluno? (digite ""S"" ou ""N""): \n");
        scanf (" %c", &entradaUsuario);
        while (entradaUsuario != 'S' && entradaUsuario != 'N' ){
            printf ("Comando nao reconhecido \n");
            printf ("Digite ""S"" ou ""N""): \n");
            scanf (" %c", &entradaUsuario);
            }
        
    }
    while (entradaUsuario == 'S');
    
    printf ("Programa encerrado! \n");

    return 0;
}