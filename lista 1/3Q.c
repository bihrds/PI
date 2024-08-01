/*Exercício.Ler ano da primeira vacina da criança e a periocidade da vacina e exibir em que outros anos a criança 
deve tomar as próximas doses, sabendo que são 4 doses no total.*/

#include <stdio.h>

int main() 
{
    int primeiraVacina, periocidadeVacina, tomarNovamente;
     printf ("Em que ano a criança tomou a primeira vacina?\n");
        scanf ("%d", &primeiraVacina);
     printf ("Qual o intervalo pedido de uma vacina para outra?\n");
        scanf ("%d", &periocidadeVacina);
    
     printf ("%d %d %d",primeiraVacina + periocidadeVacina, primeiraVacina + 2*periocidadeVacina, primeiraVacina + 3*periocidadeVacina);

    return 0;
}