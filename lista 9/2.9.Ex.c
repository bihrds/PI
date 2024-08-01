/*Ajustar o subprograma considerando que o vetor deve ser composto por
strings:*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int bbinaria (char* chave, int inicio, int fim, char vetor[30][30]) {
    int resultado;
    if (fim < inicio)
        return -1;
    else {
        int meio = (inicio + fim)/2;
        resultado = (strcmp(vetor[meio], chave));
        if (resultado == 0)
            return meio;
        else{
            if (resultado == (-1))
                return bbinaria (chave, meio+1, fim, vetor);
            else
                return bbinaria (chave, inicio, meio-1, vetor);}
    }
}

int main(){
    char chave[21];
    char vetor[30][30]= {
                        {"Hoseok"},
                        {"Jimin"},
                        {"Jin"},
                        {"Jungkook"},
                        {"Namjoon"},
                        {"Taehyung"},
                        {"Yoongi"}
    };
    
    int busca;
    printf ("Insira sua string: \n");
    scanf (" %s", chave);
    busca = bbinaria(chave, 0, 6, vetor);

    if (busca == (-1))
    {
        printf ("Essa string %s nao foi encontrada! \n", chave);
    }
    else
        printf ("String localizada na posicao! %d \n", busca);
    
    return 0;

}