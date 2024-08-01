/*Escrever programa em C onde se lê o número total de alunos matriculados, o número máximo de
alunos por turma e exibir o número de turmas a serem formadas.*/

#include <stdio.h>

int Quociente (int Dividendo, int Divisor)
{
    float Divisao;
    Divisao = (float) Dividendo/Divisor; 
    Divisao = ceil(Divisao);

    return (int)Divisao;
}

int main ()
{
int NmrTotal,NmrMaximo,NmrTurmas;
    printf ("Número total de alunos matriculados:");
     scanf ("%d",&NmrTotal);
    printf ("Número máximo de alunos por turma:");
     scanf ("%d", &NmrMaximo);
    
    printf ("O número de turmas a serem formadas será de %d", Quociente(NmrTotal,NmrMaximo));

return 0;

}
