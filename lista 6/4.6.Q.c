/*Escrever programa para ler o nome de uma pessoa, 
composto por nome e sobrenome (entre nome e 
sobrenome há um espaço em branco). E exibir, 
sobrenome em maiúsculo, seguido de vírgula e do nome 
da pessoa. Efetuar essa operação para tantas entradas quantas 
o usuário desejar.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
    int tamanho;
    char resposta;
    char nome [21];
    char sobrenome [31];
    char nomeComposto[51];
    int i,c; //controladores incrementadores

    do
    {
        printf ("Digite o nome, faremos a magica por voce: \n");
        scanf(" %[^\n]s",nomeComposto);
        tamanho = strlen(nomeComposto);
        
        for (c = 0; nomeComposto[c] != ' '; c++)
        {
            nome[c]= nomeComposto[c];
        }
        nome[c]='\0';
        c++;
        for (i = 0 ; c < tamanho ; i++,c++)
        {
            sobrenome[i]= nomeComposto[c];
        }
        sobrenome[i]='\0';

        for (c = 0; c < i; c++)
        {
            sobrenome[c]= toupper(sobrenome[c]);
        }

       nome[0]= toupper(nome[0]);

        for (int c = 1; c < tamanho; c++)
        {
            nome[c]= tolower(nome[c]);
        }
    
        printf ("Com a magica ficou assim: %s,%s \n", sobrenome, nome);
        printf ("Deseja ver a magica em outro nome? \n (digite ""S"" ou ""N""): \n");
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