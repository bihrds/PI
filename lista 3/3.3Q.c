/*Escrever programa para ler as três notas de um aluno, calcular a média deste (média ponderada: primeira nota com peso 1,
segunda nota com peso 2 e terceira nota com peso 3) e determinar a situação do aluno: APROVADO – se média igual ou superior
a 7; EM RECUPERAÇÃO – se não aprovado e com média igual ou superior a 5; REPROVADO – quando média inferior a 5.*/

#include <stdio.h>

float calcularMediaPond (float primeiraNota, float segundaNota, float terceiraNota)
{
    return (primeiraNota*1 + segundaNota*2 + terceiraNota*3)/6;
}

int main ()
{
    float Nota1, Nota2, Nota3 ;
    printf ("Qual a primeira, segunda e terceira nota respctivamente?");
    scanf ("%f", &Nota1);
    printf ("Qual a primeira, segunda e terceira nota respctivamente?");
    scanf ("%f", &Nota2);
    printf ("Qual a primeira, segunda e terceira nota respctivamente?");
    scanf ("%f", &Nota3);

    float Media = calcularMediaPond(Nota1, Nota2, Nota3);

    if (Media >= 7)
        printf ("APROVADO");

    else 
        if (Media >= 5)
            printf ("EM RECUPERAÇÃO");
        
        else 
            printf ("REPROVADO");

    return 0;
}