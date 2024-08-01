//Calcula media e ver se está aprovado ou reprovado,exemplo:

#include <stdio.h>
#include <math.h>
int main ()
{
    float nota, frequencia;
        printf ("Nota: ");
            scanf ("%f", &nota);
        printf ("Frequência: ");
            scanf ("%f", &frequencia);
    
    if (nota >= 5.0 && frequencia >= 75) {
        printf ("Aprovado\n");
         
    }
    else {
        printf ("Não Aprovado\n");
    }
}