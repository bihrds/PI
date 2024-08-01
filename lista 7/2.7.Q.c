
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char _Estaciona[30][14]; /*30 vagas, mantem placa com 7 caracteres, sinal + e 5 caracteres para hora */
float _Valor, _SomaTotal = 0;
int _QuantCarros[15];
char _Responsavel[21], _Iniciou = 0; // _ para representar variavel global.


void AbrirCaixa(){
    for ( int i = 6; i <= 20; i++)
    {
       _QuantCarros[i-6] = 0; // esse for inicializa na hora que o estacionamento abre e encerra quando ele fecha.
    }
    
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Test Drive <<< \n");
    printf("\n ABRINDO CAIXA \n");
    
    for (int i=0; i<30; i++)
        strcpy(_Estaciona[i],"LIVRE");
    printf("\n Qual o valor do estacionamento? ");
    scanf("%f",&_Valor);
    fflush(stdin); //limpar buffer, botar espaço no scanf.
    printf("Qual o nome do responsavel? ");
    scanf ("%[^\n]s", _Responsavel);

    _Iniciou=1;
}

void ClienteChega(){
    int Vaga, HoraInt;
    char Placa[8], Hora[5], Entrada[14], HoraAux[3];
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Test Drive <<< \n");
    printf("\n CHEGADA DE CLIENTE \n");
    if (_Iniciou){
        printf("\n CAIXA ABERTO Valor/h: %.2f", _Valor);
        printf("\n Responsavel: %s\n", _Responsavel);
        do{
            printf("Qual a vaga ocupada? \n");
            scanf("%d",&Vaga);

            if (strcmp(_Estaciona[Vaga-1],"LIVRE") != 0){
                printf("A vaga esta ocupada no momento, por favor escolher outra!");
            }
        }
        while (strcmp(_Estaciona[Vaga-1],"LIVRE") != 0);
        
        fflush(stdin);
        printf("Qual a placa do veiculo [7 digitos]? ");
        scanf ("%[^\n]s", Placa);
        strcpy(Entrada,Placa); // copia string placa em entrada.
        
        do{
            fflush(stdin);
            printf("Insira a hora da entrada [formato nn:nn], lembrando que funcionamos de 06:00h as 20:00h! \n");
            scanf ("%[^\n]s", Hora);
            HoraAux[0] = Hora[0];
            HoraAux[1] = Hora[1];
            HoraAux[2] = '\0';
            HoraInt = atoi(HoraAux);

            if (HoraInt < 6 || HoraInt > 20)
            {
                printf("Horario indisponivel! Não funcionamos no horario inserido, por favor insira um horario valido! \n");
            }
            
        }
        while (HoraInt < 6 || HoraInt > 20);

        _QuantCarros[HoraInt - 6] = _QuantCarros[HoraInt - 6] + 1;
    
        strcat(Entrada,"+"); //concatena string.
        strcat(Entrada,Hora);
        strcpy(_Estaciona[Vaga-1],Entrada); //diminue a vaga de acordo com a escolhida pelo cliente.
        printf("Chegada registrada com sucesso!\n");}
    
    else{
        printf("\n ERRO: Antes eh preciso abrir o caixa!\n");
        system("pause");}
}

/*EXERCÍCIO 02: Ajustar o módulo de saída do cliente, calculando e exibindo o valor
a pagar, lendo o valor pago e calculando o troco. Vocês podem fazer uma proposta
de cálculo de valor a pagar considerando horas completas e minutos extras (inferior
a 1 hora)*/

/*O sistema de cobrança do estacionamento que adotei foi semalhante ao ultilizado nos shoopings, 
se o tempo de uso for menor, igual a 20min o cliente não pagará, mas se ultrapassar esse limite ele paga a hora
normalmente, apos o limite a cada uma hora é multiplicado o valor*/

int TempoConvertido (int HoraEntrada, int HoraSaida, int MinutoEntrada, int MinutoSaida){
    
    return ((HoraSaida * 60) + MinutoSaida) - ((HoraEntrada * 60) + MinutoEntrada);
}

float ValorPagar (int HorarioTotal){

    float ValorEstacionamento;

    if (HorarioTotal <= 20){
	 ValorEstacionamento = 0;
    }

    else{
    	if (HorarioTotal % 60 == 0){
    		ValorEstacionamento = (HorarioTotal / 60) * _Valor;
    	}
    
	    else{
	    	ValorEstacionamento = ((HorarioTotal / 60) + 1) * _Valor;
	    
        }
    }

return ValorEstacionamento;

}

void ClienteSai(){
    int Vaga;
    char Placa[8], Entrada[14], Hora[3], Min[3], HoraSaida[3], MinSaida[3], Saida[5];
    int H, M, HSaida, MSaida, TempoTotal; //hora, minuto e segundo
    float ValorCliente, ValorTotal, ValorTroco;
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Test Drive <<< \n");
    printf("\n SAIDA DE CLIENTE \n");
    if (_Iniciou){
        printf("\n CAIXA ABERTO Valor/h: %.2f", _Valor);
        printf("\n Responsavel: %s\n\n", _Responsavel);
        printf("Qual a vaga ocupada? ");
        scanf("%d",&Vaga);
        strcpy(Entrada,_Estaciona[Vaga-1]);

        for (int i=0; i<7; i++)
            Placa[i] = toupper(Entrada[i]); 
    
        do{
            fflush(stdin);
            printf("\n Qual o horario de saida [formato nn:nn] do veiculo com a placa %s? ",Placa);
            fflush(stdin);
            scanf ("%[^\n]s", Saida);
            HoraSaida[0] = Saida[0];
            HoraSaida[1] = Saida[1];
            HoraSaida[2] = '\0';
            HSaida = atoi(HoraSaida);

            if (HSaida < 6 || HSaida > 20)
            {
                printf("Horario indisponivel! Não funcionamos no horario inserido, por favor insira um horario valido! \n");
            }
            
        }
        while (HSaida < 6 || HSaida > 20);

        Hora[0] = Entrada[8];
        Hora[1] = Entrada[9];
        Hora[2] = '\0';
        H = atoi(Hora); // converte string em inteiro
        Min[0] = Entrada[11];
        Min[1] = Entrada[12];
        Min[2] = '\0';
        M = atoi(Min); // converte string em inteiro

        MinSaida[0] = Saida[2];
        MinSaida[1] = Saida[3];
        MinSaida[2] = '\0';
        MSaida = atoi(MinSaida); // converte string em inteiro

        TempoTotal= TempoConvertido(H, HSaida,M,MSaida);

        ValorTotal= ValorPagar(TempoTotal);
        fflush(stdin);
        printf("O valor total a ser pago é R$%.2f",ValorTotal);

        _SomaTotal= _SomaTotal+ValorTotal;

        printf("\n Qual o valor pago pelo cliente? \n");
        fflush(stdin);
        scanf("%f", &ValorCliente);

        ValorTroco= ValorCliente - ValorTotal;
        printf("\n O valor do troco sera de R$%.2f",ValorTroco);

        strcpy(_Estaciona[Vaga-1],"LIVRE");

        } //if (Iniciou)
        
    else{
        printf("\n ERRO: Antes eh preciso abrir o caixa!\n");
        system("pause");}

    }

/*EXERCÍCIO 03: O estacionamento funciona de 6 às 20 horas. Deve ser mantido
num array auxiliar o quantitativo de carros com entrada em cada horário. No
módulo FecharCaixa, exibir em tela relatório com esses quantitativos. E havendo
carros no estacionamento, exibir alerta ao utilizador.
EXERCÍCIO 04: Ajustar o módulo de entrada do cliente de forma a atualizar o
array auxiliar citado na questão anterior.*/

void FecharCaixa(){
    int RestaCarro = 0, MaiorIndice = 6, MaiorValor = 0;
    printf("Quantidade de carros pela hora: \n"); 
    for ( int i = 6; i <= 20; i++)
    {
        printf("As %d horas, tinham %d carros no estacionamento! \n", i, _QuantCarros[i-6]);
        if (_QuantCarros[i-6] > MaiorValor)
        {
            MaiorIndice = i;
            MaiorValor = _QuantCarros[i-6];
        }
    }

    for (int i=0; i<30; i++) //varrer as vagas para ver se estão livres.
        if (strcmp(_Estaciona[i], "LIVRE") != 0) // compara duas strings.
        {
            RestaCarro = 1;
            break; // como ja sei que resta carro, eu encerro meu laço.
        }
    if (RestaCarro == 1)
    {
        printf("Atenção!Nosso horario de funcionamento encerrou! Ainda restam carros no estacionamento!! \n");
    }

    printf("O horário de maior fluxo do dia foi %dhr e a o valor total arrecadado do dia foi %.2f! \n", MaiorIndice, _SomaTotal);

}

/*EXERCÍCIO 05: No relatório emitido a partir do FecharCaixa exibir o horário
com maior número de entradas e a soma dos valores recebidos ao longo do dia.*/

int main(){
    int Op;
    do{
       printf("\n >>> Estacionamento <<< \n");
       printf(" >>> Test Drive <<< \n");
       printf("\n 1 - Abrir Caixa");
       printf("\n 2 - Chegada de Cliente");
       printf("\n 3 - Saida de Cliente");
       printf("\n 4 - Fechar Caixa");
       printf("\n\n Qual a opcao desejada? ");
        do{
           scanf("%d",&Op);
           if ((Op < 1) || (Op > 4)){
               printf("\n ERRO: Opcao invalida!");
               printf("\n Qual a opcao desejada? ");}
           else break;
        }
        while (1);
        switch (Op) {
            case 1: AbrirCaixa(); break;
            case 2: ClienteChega(); break;
            case 3: ClienteSai(); break;
            case 4: FecharCaixa(); break;}
        }
        
    while (Op != 4);

return 0;}