//Calcular a Hipotenusa,exemplo:

#include <stdio.h>
#include <math.h>

int main ()

{
    float hipotenusa, catetoB, catetoC;
    printf ("Qual o primeiro cateto?");
    scanf ("%f", &catetoB);
    printf ("Qual o segundo cateto?");
    scanf ("%f", &catetoC);
    
    hipotenusa = sqrt (catetoB*catetoB + catetoC*catetoC);
    printf ("A hipotenusa é %f", hipotenusa);
    
    return 0;
}