/*Sabendo-se que Y=toupper(X) corresponde a 
função em C (biblioteca ctype.h) que atribui à 
variável Y do tipo char o valor da variável X
(também do tipo char) em maiúsculo. 
Escrever programa para ler uma palavra com até 20 
caracteres e exibi-la com letras maiúsculas. 
Exemplos: dado brasileiro, retorna BRASILEIRO. 
Dado Nordeste, retorna NORDESTE*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    char palavra[21];
    printf ("Qual palavra de você deseja deixar em maiusculas?");
    scanf ("%s", palavra);

    int tamanho=strlen(palavra);

    for (int c = 0; c < tamanho; c++)
    {
        palavra[c]= toupper(palavra[c]);
    }

    printf ("A palavra maiscula ficara: %s", palavra);
    return 0;

}