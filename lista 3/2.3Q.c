/*Para conter o crescimento da quantidade de gatos abandonados na UFS, e seus consequentes prejuízos, surgiu o
projeto "CastraçãoSolidária", a partir do qual 4 veterinários experientes e 1 recém formado decidiram efetuar capturas e
castrações todos os dias úteis, sendo os animais capturados divididos igualitariamente entre os veterinários experientes,
e havendo sobras (não sendo possível uma divisão exata), o restante fica sob a responsabilidade do 5o veterinário – recém
formado. Por exemplo, se capturados 22 gatos, cada veterinário experiente fica com 5 castrações, e o recém formado fica
com 2. Se capturados 19, os experientes ficam com 4 e o formado recentemente fica com 3. Escrever programa em C para ler 
número de gatos capturados e exibir a distribuição das castrações entre os veterinários. Vale esclarecer que se
capturados 4 ou menos gatos, as castrações ficam sob a responsabilidade de todos os veterinários, em conjunto.*/

#include <stdio.h>

int dividirGatos (int gatosCapturados)
{
    return gatosCapturados/4;
}

int main ()
{
    int qntdDeGatos;
    printf ("Qual a quantidade de gatos capturados?");
    scanf ("%d", &qntdDeGatos);

    if (qntdDeGatos % 4==0 && qntdDeGatos >= 5)
        printf ("Cada veterinarios experiente ficara com %.2d", dividirGatos(qntdDeGatos));

    else 
        if (qntdDeGatos % 4!=0 && qntdDeGatos >= 5){
            printf ("O numero de gatos para cada veterinario experiente sera de %.2d \n", dividirGatos(qntdDeGatos));
            printf(" e o numero de gatos para o recem formado sera de %.2d",qntdDeGatos%4);
        }
        else 
            printf ("castracoes ficam sob a responsabilidade de todos os veterinarios, em conjunto");

    return 0;
}