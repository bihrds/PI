/*Ajustar o código dado de forma que seja identificado tambem quando a meta da vaquinha for ultrapassada, passando a 
haver duas mensagens de retorno ao usuario, e para, sempre que houver uma doação, exibir o valor parcial alcançado*/

//Jk faz vaquinha para proteção animal

#include <stdio.h>

int main(){
    float Meta, Doacao, Soma=0;
    printf ("Meta da vaquinha: \n");
    scanf ("%f", &Meta);

    do{
        printf ("Valor da doacao: \n");
        scanf ("%f", &Doacao);
        Soma = Soma + Doacao;
        printf ("O valor parcial alcancado da doacao é %.2f \n",Soma);
    }
    while (Soma<Meta);
        printf ("A meta da vaquinha foi alcancada! \n");
        if (Soma > Meta)
            printf ("A meta da vaquinha foi ultrapassada! \n");

    return 0;   
}