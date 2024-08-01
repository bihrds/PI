/*Escrever programa para :
a) ler o gabarito de uma prova com 20 questões objetivas
(respostas corretas, entre a e e);
b) ler nome do aluno, as respostas dadas por ele, definir sua
nota – cada questão vale 0,5 ponto;
c) limpar a tela, exibir nome do aluno, quantidade de respostas
corretas e nota.
d) perguntar ao usuário se deseja efetuar a correção de outra
prova e repetir os passos b, c e d; até que o usuário não
deseje efetuas outras correções.*/

#include <stdio.h>
#include <stdlib.h>

void lerVetor(char v[], int quantItens, char msg[]){
    for (int i = 0; i <= 19; i++){
        printf ("%s %d: ", msg, i+1);
        scanf (" %c", &v[i]);
    }
}

void exibeVetor(char v[], int quantItens){
    for (int i = 0; i <= 19; i++){
        printf ("%d. %c \n", i+1, v[i]);
    }
    
}

void defineNota(char v[]){
    float n = 0;
    char resposta;
    for (int i = 0; i <= 19; i++){
        printf ("Qual a resposta da questão %d?", i+1);
        scanf (" %c",&resposta);
        if (resposta == v[i])
            n = n + 0.5;
    }
return 0;
}

int main(){
    char gabarito[20];
    char nome[21];
    float nota;
    char outro;
    printf (">>> LEITURA DO GABARITO<<< \n")
    exibeVetor(gabarito,20);

    do
    {
        nota = 0;
        printf ("Qual o nome do aluno? ");
        fflush (stdin), gets(nome);
        nota = defineNota(gabarito);
        system ("cls");
        system ("color 60");
        printf ("Nome: %s \n", nome);
        printf ("Nota: %1.f \n", nota);
        fflush (stdin);
        printf ("Deseja verificar a nota de outro aluno?");
        scanf ("%c", &outro);
        if (outro != '1') break;
    } 
    
    while (1);

return 0;
}