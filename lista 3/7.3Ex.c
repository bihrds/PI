//Calculadora com switch-case

#include <stdio.h>
#include <ctype.h>

int main()
{
    int Num1, Num2;
    printf ("Quais os numeros?");
    scanf ("%d %d", &Num1, &Num2);

    char Operador;
    printf ("Qual operação deseja realizar?");
    printf ("A - Adiçao \n");
    printf ("S - Subtraçao \n");
    printf ("M - Multiplicaçao \n");
    printf ("D - Divisao \n");
    scanf (" %c", &Operador);
    
    Operador=toupper(Operador);
    switch (Operador)
    {
    case 'A': printf ("A adição será igual a = %d", Num1 + Num2); break;
    case 'S': printf ("A subtração será igual a = %d", Num1 - Num2); break;
    case 'M': printf ("A multiplicação será igual a = %d", Num1 * Num2); break;
    case 'D': if (Num2 != 0)
                printf ("A divisão será igual a = %f",(float) Num1 / Num2);
            else 
                printf ("Tentativa de divisão por zero");
    default: printf ("Opção inválida!");
    }
return 0;
}