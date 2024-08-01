/*Escrever programa para: 
(a) exibir menu: 1 – area, 2 – perímetro e 3 – diagonal; 
(b) ler medida de lado de um quadrado; 
(c) exibir a informação solicitada pelo usuário conforme opção de menu selecionada.
Deve haver mensagem de erro para o caso do usuário selecionar opção não existente. Deve ser modularizado.*/

#include <stdio.h>
#include <math.h>

float calcArea (float lado)
{
    return lado*lado;
}

float calcPerimetro (float lado)
{
    return lado*4;
}

float calcDiagonal (float lado)
{
    return lado*sqrt(2);
}

int main()
{
    int Menu;
    printf ("Digite 1 para area, 2 para perimetro e 3 para diagonal! \n");
    scanf ("%d", &Menu);

    float ladoQuadrado;
    printf ("Digite a medida do lado em metros! \n");
    scanf ("%f", &ladoQuadrado);


    switch (Menu)
    {
    case 1: printf ("area sera = %.2f metros", calcArea(ladoQuadrado)); break;
    case 2: printf ("perimetro sera = %.2f metros", calcPerimetro(ladoQuadrado)); break;
    case 3: printf ("diagonal sera = %.2f metros", calcDiagonal(ladoQuadrado)); break;
    default: printf ("Opção não existe!");
    }

return 0;

}