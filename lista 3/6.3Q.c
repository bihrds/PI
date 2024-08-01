/*Escrever um programa para ler o peso(massa) e altura de uma pessoa, calcular o indice de massa corporal e em 
seguida determinar o tipo de obesidade da pessoa de acordo com a tabela*/

#include <stdio.h>

float calcularIMC (float peso, float altura)
{
    return peso/(altura*altura);
}

int main()
{
    float Peso, Altura;
    printf ("Qual seu peso em kg? ");
    scanf ("%f", &Peso);
    printf ("Qual sua altura em metros? ");
    scanf ("%f", &Altura);

    float IMC = calcularIMC(Peso, Altura);

    if (IMC < 18.5)
        printf ("MAGREZA");
    else
        if (IMC <= 24.9)
            printf ("SAUDAVEL");
        else 
            if (IMC <= 29.9)
                printf ("SOBREPESO");
            else
                if (IMC <= 34.9)
                    printf ("OBESIDADE GRAU I");
                else
                    if (IMC <= 39.9)
                        printf ("OBESIDADE GRAU II (severa)");
                    else
                        printf ("OBESIDADE GRAU III (morbida)");

    return 0;
}