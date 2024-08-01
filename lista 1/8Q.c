/*Exercío.Escrever um programa em C para calcular a área de um retângulo. O usuário deve fornecer o comprimento e a largura desse.*/

#include <stdio.h>

int main() 
{
   int comprimentoRetangulo, larguraRetangulo, areaRetangulo;
    printf ("Qual o comprimento do retângulo?(em cm)\n");
        scanf ("%d", &comprimentoRetangulo);
    printf ("Qual a largura do retângulo?(em cm)\n");
        scanf ("%d", &larguraRetangulo);
    
    areaRetangulo = comprimentoRetangulo*larguraRetangulo;
    
    printf ("A área do retângulo em questão é de %d cm", areaRetangulo);
   
    return 0;
}
