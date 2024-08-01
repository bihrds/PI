//Ajustar o código dado de forma que seja exibida o número da compra.
//Jk evitar "estouro" de cartão de crédito.

#include <stdio.h>

void ValidaCompra (float *L, int *N)
{
    float D;
    printf ("Debito: ");
    scanf ("%f", &D);

    if (*L - D >= 0) {
        printf ("Compra possivel! \n");
        *L = *L - D;
        printf ("Compra numero %d \n",*N);}
    else 
        printf ("Compra ""estourara"" o cartão! \n");
    printf ("Limite restante: %.2f \n\n", *L);}

int main(){
    float Limite;
    printf ("Qual o limite do cartao?");
    scanf ("%f", &Limite);

    int N;
    N=1;
    
    while (Limite > 0){
        ValidaCompra(&Limite,&N);
        N= N+1;
    }
    printf ("Seu limite de compras acabou! ");
    
    return 0;
}