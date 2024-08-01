/*Escrever programa para ler uma palavra P qualquer 
com até 20 caracteres e identificar quantas vogais P 
apresenta. Aplicar função definida pelo programador 
Efetuar essa operação para tantas strings quantas o usuário 
desejar.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int verVogal (char letra){
    if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
        return 1;
    else
        return 0;
}

int main (){
    int tamanho;
    int somaVogal;
    char resposta;
    char palavra[21];

    do
    {
        printf ("Qual palavra voce deseja saber a quantidade de vogais?");
        scanf ("%s", palavra);
        tamanho = strlen(palavra);
        somaVogal = 0;
        for (int c = 0; c < tamanho; c++)
        {
            palavra[c]= tolower(palavra[c]);//Se alguma palavra vim maiscula, deixa tudo miniscula.
            somaVogal = verVogal(palavra[c]) + somaVogal;
        }
    
        printf ("A quantidade de vogais dessa palavra e: %d \n", somaVogal);
        printf ("Deseja ver a quantidade de vogais de outra palavra? \n (digite ""S"" ou ""N""): \n");
        scanf (" %c", &resposta);
        while (resposta != 'S' && resposta != 'N' ){
            printf ("Comando nao reconhecido \n");
            printf ("Digite ""S"" ou ""N""): \n");
            scanf (" %c", &resposta);
            }
    }

    while (resposta == 'S');

    return 0;
}