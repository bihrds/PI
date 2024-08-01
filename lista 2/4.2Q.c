/*Escrever um programa em C para ler uma temperatura em Celsius C e a retornar em Fahrenheit e em Kelvin. 
Fórmulas de conversão para Fahrenheit: F = (C * 9/5) + 32; para Kelvin: K = C + 273,5.Criar uma função para cada conversão.*/

#include <stdio.h>

float Converterf (float Celsius)
{
    float ConverterCelFah;
    ConverterCelFah= (Celsius*9/5)+32;
    return ConverterCelFah;
}

float ConverterK (float Celsius)
{
    float ConverterCelKel;
    ConverterCelKel= Celsius+273.5;
    return ConverterCelKel;
}

int main ()
{
    float TempCelsius;
    printf ("Temperatura em Celsius: ");
     scanf ("%f", &TempCelsius);
    printf ("A temperatura convertida em Fahrenheit será %.1f e em Kelvin será %.1f", Converterf(TempCelsius), ConverterK(TempCelsius));

    return 0;
}