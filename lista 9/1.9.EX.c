/*Escrever programa em C para ler nome, 3 notas e
frequência (em percetual) dos 80 alunos do projeto
AprendaProgramação, calcular a média destes (média da
turma) e emitir em tela a situação final de cada aluno.

São aprovados todos os que ficam com média (aritmética
simples) acima da média da turma e têm frequência acima
de 65%.

Deve ser exibido o nome de cada aluno, seguido das
notas, média e da situação final: APROVADO ou
REPROVADO.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int _quantAlunos = 3; // mudar para 80.

struct infAlunos
{
    char nome[21];
    float nota1;
    float nota2;
    float nota3;
    float frequencia;
} rgAlunos;

float calcularMediaAri (float valores, float quantValores)
{
    return valores/quantValores;
}

int main (){
    typedef struct infAlunos tpSt;
    tpSt alunos[80];
    float soma=0;
    float valores, mediaAluno[80];
    for ( int i = 0; i < _quantAlunos; i++)
    {
        printf ("Nome do aluno(a): \n");
        scanf (" %[^\n]s", alunos[i].nome);
        printf ("Nota 1: \n");
        scanf ("%f", &alunos[i].nota1);
        printf ("Nota 2: \n");
        scanf ("%f", &alunos[i].nota2);
        printf ("Nota 3: \n");
        scanf ("%f", &alunos[i].nota3);
        printf ("Frequencia em percentual: \n");
        scanf ("%f", &alunos[i].frequencia);  

        valores = alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3;
        mediaAluno[i] = calcularMediaAri(valores,3); 
        soma = soma + mediaAluno[i];
    }

    float mediaTurma = calcularMediaAri(soma,_quantAlunos);

    for (int i = 0; i < _quantAlunos; i++)
    {
        printf ("\n Nome: %s \n Nota1: %.2f \n Nota2: %.2f \n Nota3: %.2f\n Media: %.2f \n" , alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].nota3, mediaAluno[i]);
        if (mediaAluno[i] > mediaTurma && alunos[i].frequencia)
        {
            printf ("SITUACAO: APROVADO \n \n");
        }
        else 
            printf ("SITUACAO: REPROVADO \n \n");
        
    }
    
    return 0;

}
