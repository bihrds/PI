/*8.Escrever um programa em C para ler um valor V em reais, taxa de câmbio fixa de dólar e taxa de câmbio fixa de euro 
e exibir em tela os correspondentes a V em dólar e em euro. Para tanto, criar função F em que dados valor e taxa de câmbio,
retorna o valor convertido. Criar módulo com aplicação de F, parâmetros de entrada e dois parâmetros de saída: valor em
dólar e valor em euro.*/

#include <stdio.h>

void RealCambio (float VReal, float VCambioDolar, float VCambioEuro, float *ConverterDolar, float *ConverterEuro)
{
    *ConverterDolar = VReal*VCambioDolar;
    *ConverterEuro = VReal*VCambioEuro;
}

int main ()
{
    float VReais, CambioDolar, CambioEuro;
    printf ("Valor em reais: ");
    scanf ("%f", &VReais);
    printf ("Taxa de câmbio fixa em dolar: ");
    scanf ("%f", &CambioDolar);
    printf ("Taxa de câmbio fixa em euro: ");
    scanf ("%f", &CambioEuro);

    float ConverterDolar, ConverterEuro;
    RealCambio(VReais,CambioDolar,CambioEuro,&ConverterDolar,&ConverterEuro);

    printf ("O valor convertido em dolar sera %.2f e em euro sera %.2f",ConverterDolar,ConverterEuro);
}