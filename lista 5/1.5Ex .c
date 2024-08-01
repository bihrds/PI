#include <stdio.h>

int main ()
{
    int N, Cont;
    printf ("De qual numero deseja saber a tabuada?");
    scanf ("%d", &N);
    for (Cont=0; Cont<=10; Cont++)
        printf ("%d x %d = %d \n", N,Cont, N*Cont);

return 0;
}