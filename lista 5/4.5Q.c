/*Na disciplina “Programação Imperativa” há 50 alunos e 12 
avaliações. Para obtenção de aprovação o aluno deve ter no 
mínimo 5 notas maior ou igual a 7. Escrever programa para 
ler notas de cada um dos 50 alunos e identificar se foi 
aprovado.*/

#include <stdio.h>

int main ()

{
    float notasAlunos, somaNotas;
    int nmrAlunos;
    somaNotas = 0;
    for (nmrAlunos = 1; nmrAlunos <= 50; nmrAlunos ++)
    {
        printf("Quais as notas do aluno %d \n", nmrAlunos);
        for (int notas = 1; notas <= 12 ; notas++)
        {
            scanf ("%f", &notasAlunos);
            if (notasAlunos >= 7)
                somaNotas = somaNotas + 1;
        }
        if (somaNotas >= 5)
        {
            printf ("Aluno %d aprovado! \n", nmrAlunos);
        }
        else 
            printf ("Aluno %d reprovado! \n", nmrAlunos);
        
        somaNotas = 0;

    }

    return 0;
}