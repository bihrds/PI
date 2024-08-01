/*Escrever programa para exibir menu: U – unidade, D – dezena, C – centena, M – unidade de milhar e Z –dezena de milhar;
ler um número de 0 a 99.999 e deste identificar a unidade, ou a dezena, ou a centena, ou a unidade de milhar, ou a dezena 
de milhar; conforme a opção selecionada. Deve funcionar para o caso do usuário pressionar letras maiúsculas ou minúsculas.
Deve ser aplicado switch-case. Deve haver mensagem de erro para o caso do usuário selecionar opção não existente.
Deve ser modularizado.*/

#include <stdio.h>
#include <math.h>
#include <ctype.h>

int mostrarUnidade (int Numero)
{
    return (Numero%10);
}

int mostrarDezena (int Numero)
{
    return (Numero%100)/10;
}

int mostrarCentena (int Numero)
{
    return (Numero%1000)/100;
}

int mostrarUniMilhar (int Numero)
{
    return (Numero%10000)/1000;
}

int mostrarDezMilhar (int Numero)
{
    return Numero/10000;
}


int main ()
{
    int Numero;
    printf ("Qual o número de 0 a 99.999? ");
    scanf ("%d", &Numero);

    char Menu;
    printf ("Qual parte deseja identificar? \n");
    printf ("U - Unidade \n");
    printf ("D - Dezena \n");
    printf ("C - Centena \n");
    printf ("M - Unidade de Milhar \n");
    printf ("Z - Dezena de Milhar \n");
    scanf (" %c", &Menu);

    switch (Menu)
    {
    case 'u':
    case 'U': printf ("A unidade é %d \n", mostrarUnidade(Numero));break;
    case 'd':
    case 'D': printf ("A dezena é %d \n", mostrarDezena(Numero));break;
    case 'c':
    case 'C' : printf ("A centena é %d \n", mostrarCentena(Numero));break;
    case 'm':
    case 'M' : printf ("A unidade de milhar é %d \n", mostrarUniMilhar(Numero));break;
    case 'z':
    case 'Z' : printf ("A dezena de milhar é %d \n", mostrarDezMilhar(Numero));break;
    default: printf ("Opção selecionada não existe!");
    }
    
    return 0;
}