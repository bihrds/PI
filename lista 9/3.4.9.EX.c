/*(03) Pesquisar método de classificação de dados diferente do trabalhado em sala de aula, recursivo, 
e apresentar de forma semelhante à do slide 64 

(04) implementá-lo aplicando a vetor composto por 25 palavras
(previamente definidas e desordenadas).*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void copiar(char S[25][30],char E[25][30],int a,int b,int n) {
    int i;
    for(i=1;i<=n;i++) {
        strcpy(S[a++],E[b++]);
    }
}

void merge(char S[25][30],char E[25][30], int inicio, int meio, int final)
{
    int i=inicio, j=meio+1, k=inicio;
    while (i <= meio && j <= final)  {
        	if(strcmp(E[i],E[j]) <= 0)	strcpy(S[k++],E[i++]); // compara e ordena o vetor auxiliar 
        	else							strcpy(S[k++],E[j++]);
    }
    if(i>meio) 	copiar (S,E,k,j,final - j + 1) ;
	else 		copiar (S,E,k,i,meio - i + 1) ;
	copiar(E,S,inicio,inicio,final-inicio+1) ; //une novamente os elementos ordenados no vetor original
}

void mergeSort(char S[25][30],char E[25][30], int inicio, int final) {
    if (inicio < final)        {
        int meio = inicio+(final-inicio)/2;
        mergeSort(S,E, inicio, meio);
        mergeSort(S,E, meio+1, final);
        merge(S,E, inicio,meio,final);
    }
}

int main(){
    char auxiliar[25][30];
    char vetor[25][30]= {
                        {"Sergipe"}, {"Alagoas"}, {"Bahia"}, {"Pernambuco"}, {"Paraiba"},
                        {"Rio Grande do Norte"}, {"Maranhao"}, {"Piaui"}, {"Ceara"},{"Para"},
                        {"Rondonia"}, {"Roraima"}, {"Amapa"}, {"Amazonas"}, {"Tocantins"},
                        {"Acre"}, {"Mato Grosso"}, {"Mato Grosso do Sul"}, {"Goias"}, {"Minas Gerais"}, 
                        {"Espirito Santo"}, {"Sao Paulo"}, {"Santa Catarina"}, {"Rio de Janeiro"}, {"Parana"}
    };

    mergeSort(auxiliar,vetor, 0, 24);
    for (int i = 0; i <= 24; i++)
    {
        printf("%s \n", vetor[i]);
    }
    
}