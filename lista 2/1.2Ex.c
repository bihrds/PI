/*Exemplo 1 - Na construção de uma ponte, a ser efetuada em etapas, tem-se gastos com material de construção - GMaterial 
e com mão de obra - GMaoObra, bem como uma previsão dos gastos para finalizar todas as etapas - GTotal.
Construir programa em C, para dados GMaterial, GMaoObra e GTotal, exibir o percentual da obra que falta construir.*/

#include <stdio.h>

float RestanteObra (float Material,float MaoObra,float Total){
    
    float Parcial;
    Parcial= Material+MaoObra;
    
    float Restante;
    Restante= Total-Parcial;
   
return Restante/Total*100;

}

int main (){
    float GMaterial, GMaoObra, GTotal, QFalta;
        printf ("Quanto foi gasto até o momento em material?");
         scanf ("%f", &GMaterial);
        printf ("Quanto foi gasto até o momento em mão de obra?");
         scanf ("%f", &GMaoObra);
        printf ("Qual o gasto total com a ponte até o momento?");
         scanf ("%f", &GTotal);
    
    QFalta= RestanteObra(GMaterial,GMaoObra,GTotal);
    printf ("Falta para fanalizar a obra o equivalente a %.1f%%",QFalta);

return 0;

}