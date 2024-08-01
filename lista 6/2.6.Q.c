/*Escrever programa para ler um nome e, independente 
de como este foi escrito, exibir a inicial maiúscula e o 
restante minúscula. Sendo:
● Cadeia[P] = toupper(Cadeia[P]); 
Converte a letra da posição P da string 
Cadeia para maiúscula, da biblioteca ctype.h.
● Cadeia[P] = tolower(Cadeia[P]); 
Converte a letra da posição P da string 
Cadeia para minúscula, da biblioteca ctype.h.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    char nome[21];
    printf ("Qual nome você deseja deixar a incial em maiusculo?");
    scanf ("%s", nome);

    int tamanho=strlen(nome);

    nome[0]= toupper(nome[0]);

    for (int c = 1; c < tamanho; c++)
    {
        nome[c]= tolower(nome[c]);
    }

    printf ("O nome com a primeira letra maiscula ficara: %s", nome);
    return 0;
}