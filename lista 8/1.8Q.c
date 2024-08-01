
// Atividade Frezzer.

#include <stdio.h>

    int _Frz, _Crc; // _ para representar variavel global.


    char _nomeFreezer [7][5] = {{"Deia"}, //String referente aos nomes dos freezers.
                                {"Sul"},
                                {"NSul"},
                                {"Frio"},
                                {"Fri"},
                                {"Lux"}
    };

    float _matrizFreezer [4][6] = { {385,534,309,546,503,477}, //Capacidade
                                    {12,12,12,3,24,12}, //Garantia
                                    {35.9,72.1,46.2,74.3,78,96}, //Economia
                                    {-28,-18,-18,-18,-22,-18} //Temperatura
    };

// 1- Exibir levantamento.
   void exibeMatriz(int L,int C){ //função para exibir matriz
        printf("                      "); // Para alinhar os nomes dos freezer.
        for(int j=0; j<C; j++){
                printf("%s ",_nomeFreezer[j]);
        }
        
        printf("\n");

        for(int i=0; i<L; i++){
            if (i==0) printf("Capacidade (litros) ");
            if (i==1) printf("Garantia (meses) ");
            if (i==2) printf("Economia (KWh/mês) ");
            if (i==3) printf("Temperatura Min (C) ");
            for (int j=0; j<C; j++)
                printf("%6.1f",_matrizFreezer[i][j]);
            printf("\n");
        }
}

// 2- Dados de um frezzer.
    void selecionarFreezer (){
        printf("Qual freezer deseja selecionar os dados? \n");
        scanf("%d",&_Frz);
    }

    void exibirFreezer(int Linha){
        printf ("Dados do freezer %s: \n", _nomeFreezer[_Frz-1]);
        for(int i=0; i<Linha; i++){ // Quantidade de caracteristicas de um freezer
            if (i==0) printf("Capacidade (litros): \n");
            if (i==1) printf("Garantia (meses): \n");
            if (i==2) printf("Economia (KWh/mês): \n");
            if (i==3) printf("Temperatura Min (C): \n");
            printf ("%.1f \n", _matrizFreezer[i][_Frz-1]); //Coluna fixa.
    }
}

// 3- Dados de uma caracteristica.
    void selecionarCaracteristica (){
        printf("Qual caracteristica deseja selecionar os dados? \n");
        scanf("%d",&_Crc);
    }

    void exibirCaracteristica (int Coluna){
        printf ("%s :  \n"); // Para exibir  matriz escolhida antes.
        for(int j=0; j<Coluna; j++){ // Quantidade de caracteristicas de um freezer.
            printf ("%.1f \n", _nomeFreezer[_Crc-1], _matrizFreezer[_Crc-1][j]); //Linha fixa.
    }
}


// 4- Alterar dado.
    void alterarDado () {
        selecionarFreezer();
        selecionarCaracteristica();
        printf("\n Qual o novo valor? \n");
        scanf("%f", &_matrizFreezer[_Crc-1][_Frz-1]);
    }

// 5,6,7,8- Exibir melhor.
    void calcularMelhor(int C){
        int indiceMaior = 0, indiceTemperatura = 0;
        float valorMaior = _matrizFreezer[C][0], temperaturaMaior = _matrizFreezer[3][0]; 
        
        for (int i=0; i<5; i++)
        {
            if (valorMaior < _matrizFreezer[C][i + 1] && C <= 2){ // Só vai fazer isso se opção escolhida for diferente de temperatura
                valorMaior = _matrizFreezer[C][i + 1];
                indiceMaior = i + 1;
            }
            if (temperaturaMaior > _matrizFreezer[3][i + 1] && C == 3)
            {
                temperaturaMaior = _matrizFreezer[3][i + 1];
                indiceTemperatura = i + 1;
            }
            
        }
        
        if (C==0) printf("O freezer melhor em capacidade e: %s \n", _nomeFreezer[indiceMaior]);
        if (C==1) printf("O freezer melhor em garantia e: %s \n", _nomeFreezer[indiceMaior]);
        if (C==2) printf("O freezer melhor em economia e: %s \n", _nomeFreezer[indiceMaior]);
        if (C==3) printf("O freezer melhor em temperatura e: %s \n", _nomeFreezer[indiceTemperatura]);
    }

int main () {

    int Op, Parada = 0;

    do{
        printf("\n");

        printf("Digite 1 para exibir matriz! \n");
    
        printf("Digite 2 para exibir dados de um freezer! \n");

        printf("Digite 3 para exibir dados de uma caracterista! \n");

        printf("Digite 4 para alterar dados de um freezer! \n");

        printf("Digite 5 para exibir o melhor freezer em capacidade \n");

        printf("Digite 6 para exibir o melhor freezer em garantia \n");

        printf("Digite 7 para exibir o melhor freezer em economia \n");

        printf("Digite 8 para exibir o melhor freezer em temperatura \n");

        printf("Digite 9 para sair \n");

        scanf ("%d", &Op);
        
        switch (Op){
            case 1: exibeMatriz(4,6);
            break;

            case 2: selecionarFreezer();
                    exibirFreezer(4);
            break;

            case 3: selecionarCaracteristica();
                    exibirCaracteristica(6);
            break;

            case 4: alterarDado ();
            break;

            case 5: calcularMelhor(0);
            break;

            case 6: calcularMelhor(1);
            break;

            case 7: calcularMelhor(2);
            break;

            case 8: calcularMelhor(3);
            break;

            case 9: Parada = 1; //encerra o programa.
            break;} 
    }
    while (Parada == 0);

    return 0;
}