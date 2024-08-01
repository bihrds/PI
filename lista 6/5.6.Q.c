/*Na universidade “DuSabiTudu” os alunos são identificados por 
matrículas compostas por 10 dígitos. Os 4 primeiros dígitos 
correspondem ao ano em que o aluno entrou na instituição. 
Assim, todos os alunos cujas matriculas iniciam por 2012 
ingressaram no curso superior no ano de 2012. Os dígitos 5 e 6 da 
matrícula correspondem ao curso; sendo: 97 para agroecologia e 
99 para gerontologia. Escrever programa para ler a matricula de 
100 alunos inscritos no programa “CienciasAlémDasFronteiras” e 
identificar quantos alunos ingressaram num dado ano A no curso 
de gerontologia. Aplicar função definida pelo programador.*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>



int identificarCurso (char numMatricula[], char numAno[]){
    if (numMatricula[0] == numAno[0] && numMatricula[1] == numAno[1] && numMatricula[2] == numAno[2] && numMatricula[3] == numAno[3] && numMatricula[4] == '9' && numMatricula[5] == '9')
        return 1;
    else
        return 0;
}

int main (){
    int somaAlunos;
    char ano[5];
    char matricula[11];

    printf ("De qual ano deseja saber o número de alunos que ingressaram no curso de gerontologia? \n");
    scanf ("%s", ano);
    printf ("Quais os numeros das matriculas que deseja conferir? \n");

    somaAlunos = 0;

    for (int i = 0; i < 100; i++)
    {
        scanf ("%s", matricula);
        somaAlunos = identificarCurso(matricula,ano) + somaAlunos;
        
    }
    
    printf (" A quantidade de alunos inscritos no programa CienciasAlemDasFronteiras no ano de %s e no curso de gerontologia e: %d \n", ano, somaAlunos);

    return 0;
}