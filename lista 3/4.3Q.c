/*Faça um programa para ler um número inteiro, positivo de três dígitos, e gerar outro número formado pelos dígitos 
invertidos do número lido. (Ex: Numero Lido = 123; Numero Gerado = 321) Em seguida informar: NÚMERO GERADO MAIOR QUE 
NÚMERO LIDO ou NÚMERO LIDO MAIOR QUE NÚMERO GERADO, ou ainda, NÚMERO GERADO IGUAL AO NÚMERO LIDO.*/

#include <stdio.h>

int inverter (int numeroInverter)
{
    int numeroGerado = 0;
    int centena = numeroInverter/100;
    int dezena = (numeroInverter - centena * 100)/10;
    int unidade = numeroInverter - centena * 100 - dezena * 10;

    numeroGerado = unidade*100 + dezena*10 + centena;
    return numeroGerado;
}

int main ()
{
    int numeroInteiro;
    printf ("Qual numero inteiro deseja inverter?");
    scanf ("%d", &numeroInteiro);

    int ResulNumeroGerado = inverter(numeroInteiro);

    if (ResulNumeroGerado > numeroInteiro)
        printf (" %d , NUMERO GERADO MAIOR QUE NUMERO LIDO", ResulNumeroGerado);

    else 
        if (numeroInteiro > ResulNumeroGerado)
            printf (" %d , NUMERO LIDO MAIOR QUE NUMERO GERADO", ResulNumeroGerado);

        else 
            printf (" %d , NUMERO GERADO IGUAL AO NUMERO LIDO", ResulNumeroGerado);

    return 0;
}
