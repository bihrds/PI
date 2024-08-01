/*No "Motos Zondas":
1. ao encerrar o expediente, havendo motos cujos serviços não
foram concluídos (status 0 ou status 1), guardar dados em arquivo
auxiliar. - ok

2. ao iniciar a execução do código, inicializar o array de registros
com os dados guardados no arquivo auxiliar. - ok

3. em outro arquivo auxiliar, contendo: data e valor recebido no dia;
ao encerrar expediente - ok

4. criar outra opção (no menu) com “histórico financeiro” para exibir
dados desse e total (soma dos valores recebidos) - ok

5. ao exibir o histórico financeiro, além do total, exibir a data em que
houve maior valor de venda. - ok */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct RegMoto{
	char Nome[20];
	char Modelo[10];
	char Placa[8];
	char Status;
	char Defeito[50];
	float Preco;};
struct RegMoto VZonda[50];

struct Financeiro{ /* Para auxiliar na função historico financeiro, onde pede para exibir data de maior venda e pode ser 
considerada uma melhoria do codigo, pois facilita na hora de ler e escrever os dados no arquivo*/
  char Data[15];
  float Valor;
};
struct Financeiro Historico;



int Quant=-1; //Controla o preenchimento do vetor


int compareStrings(char * Str1, char * Str2 ) { //strc 
	int vfinal = strlen(Str1);
	for(int i=0;i<vfinal;i++){
		if (Str1[i]<Str2[i])	return (-1);
		else if (Str1[i]>Str2[i])	return 1;	
	}
	return 0;	
}

void IniciarArray(FILE *ArqAux){ // Passa todos os dados do arquivo para minha struct MotosZonda
    fseek(ArqAux, 0, SEEK_SET); // fseek - reposiciona o arquivo na hora da leitura e escrita do mesmo
    while (fread(&VZonda[Quant + 1], sizeof(struct RegMoto), 1, ArqAux) == 1) { // fread - lê o arquivo
      printf ("%s \n",VZonda[Quant + 1].Nome);
      Quant ++;
      }
  }


/*(1) Solicitar Serviço – quando se insere os dados supracitados, e também os campos
status com valor zero sinalizando que o serviço ainda não foi feito, preço, também iniciado com zero.
Este deve estar em loop.*/

void SolicitaServico(){
  char auxiliar[8];
  char Sair='S';
  do{
	fflush(stdin);
    printf("\n\n >>> Motos Zonda <<< \n\n");
    Quant=Quant+1;
    printf("Qual o nome do cliente? ");
    scanf(" %[^\n]",VZonda[Quant].Nome);
    printf("Qual o modelo da moto? ");
    scanf(" %[^\n]",VZonda[Quant].Modelo);
    printf("Qual a placa da moto? ");
    scanf(" %[^\n]",auxiliar);
    strcpy(VZonda[Quant].Placa,auxiliar);
    printf("Qual o defeito da moto? ");
    scanf(" %[^\n]",VZonda[Quant].Defeito);
    VZonda[Quant].Status='0';
   
    VZonda[Quant].Preco=0;
    
    VZonda[Quant].Placa[7]='\0';
  
    printf("\n\n Deseja inserir novo servico? S|N ");
    scanf(" %c",&Sair);
    Sair=toupper(Sair);
   }
  while (Sair!='N');

}

/*(2) Iniciar Serviço – quando o status de uma dada moto (placa) é iniciado pelo
mecânico e o status passa a ser um. */

void IniciaServico(){
  char P[8]; 
  printf("Placa da moto para iniciar servico: ");
  scanf(" %s",P);
  int Pos=-1; //posição da moto P no vetor
  //busca da moto para iniciar serviço
  for (int Cont=0; Cont<=Quant; Cont++){
    if (compareStrings(VZonda[Cont].Placa,P)==0)  Pos=Cont; 
  }
  if (Pos==-1)
    printf("Moto nao cadastrada!");
  else{
    printf("\n Cliente %d: %s", Pos+1, VZonda[Pos].Nome);
    printf("\n Modelo: %s", VZonda[Pos].Modelo);
    printf("\n Placa: %s", VZonda[Pos].Placa);
     printf("\n Defeito: %s ", VZonda[Pos].Defeito);
    VZonda[Pos].Status='1';
    printf("\n Status: %c",VZonda[Pos].Status);
    if (VZonda[Pos].Preco==0)
      printf("\n Preco: NAO DEFINIDO");       
    else
      printf("\n Preco: %.2f",VZonda[Pos].Preco);}
}

/*(3) Remover Solicitação – para o caso do proprietário desistir de
esperar, o que somente é permitido se o serviço não tiver iniciado, e o status passa a ser dois, dada a
placa da moto.*/

void RemoverSolicitacao(){
  fflush(stdin);
  char P[8]; 
  printf("Placa da moto para remover solicitacao: ");
  scanf(" %[^\n]",P);
  int Pos=-1; //posição da moto P no vetor
  for (int Cont=0; Cont<=Quant; Cont++) {
    if (compareStrings(VZonda[Cont].Placa,P)==0)
      Pos=Cont;
  }
  if (Pos==-1)
    printf("Moto nao cadastrada!");
  else {
    if (VZonda[Pos].Status == '1')
    {
      printf ("Servico ja foi iniciado, infelizmente nao podemos remove-lo agora!!");
    }
    else{
      VZonda[Pos].Status='2';
      printf("\n Solicitacao removida com sucesso \n");}
    }
}

/*(4) Consultar Solicitações – quando se exibe todas as solicitações ainda não feitas (não
iniciadas). */

void ConsultarSolicitacoes(){
  fflush(stdin);
  int aberto = 1;
  printf("\n\n >>> Motos Zonda <<< \n\n");
  if (Quant==-1)
    printf("Nao ha servicos cadastrados.");
  else{
    for (int Cont=0; Cont<=Quant; Cont++){
      if (VZonda[Cont].Status == '0')
      {
        aberto = 0;
        printf("\n Cliente %d: %s", Cont+1, VZonda[Cont].Nome);
        printf("\n Modelo: %s", VZonda[Cont].Modelo);
        printf("\n Placa: %s", VZonda[Cont].Placa);
        printf("\n Defeito: %s", VZonda[Cont].Defeito);
        printf("\n Status: %c",VZonda[Cont].Status);
        if (VZonda[Cont].Preco==0)
          printf("\n Preco: NAO DEFINIDO");       
        else
          printf("\n Preco: %.2f",VZonda[Cont].Preco);
        printf("\n --------------------- \n\n");}
      }
      if (aberto == 1)
      {
        printf ("Nao ha solicitacoes em aberto! \n");
      }
      
    } 

  }

/*(5) Concluir Serviço – para indicar que o mecânico concluiu o atendimento, define o preço
final e o status passa a ser três.*/

void ConcluirServico(){
  fflush(stdin);
  char P[8]; 
  printf("Placa da moto para concluir o atendimento: ");
  scanf(" %[^\n]",P);
  int Pos=-1; //posição da moto P no vetor
  for (int Cont=0; Cont<=Quant; Cont++)
    if (compareStrings(VZonda[Cont].Placa,P)==0)
      Pos=Cont;
  if (Pos==-1)
    printf("Moto nao cadastrada!");
  else {
    if (VZonda[Pos].Status == '1'){
      VZonda[Pos].Status='3';
      printf ("Qual o preco do servico? \n");  
      scanf("%f", &VZonda[Pos].Preco);
      printf ("Servico concluido!! \n");
    }
    else{
      printf("Nao foi possivel concluir o servico! \n");}
    }
}

/*(6) Encerrar Expediente – para exibição de todos os serviços efetuados,
e exibição do valor total obtido com os serviços.*/

/*1. ao encerrar o expediente, havendo motos cujos serviços não
foram concluídos (status 0 ou status 1), guardar dados em arquivo
auxiliar.*/

/*3. em outro arquivo auxiliar, contendo: data e valor recebido no dia;
ao encerrar expediente*/

void EncerrarExpediente(FILE *ArqAux, FILE *ArqFinanceiro){
  fflush(stdin);
  float valorTotal = 0;

  printf ("Qual a data de encerramento do expediente no formato dd/mm/aaaa? \n");  
  scanf(" %s", Historico.Data);

  for (int Cont=0; Cont<=Quant; Cont++){
    if (VZonda[Cont].Status == '3')
    {
      printf("\n Cliente %d: %s", Cont+1, VZonda[Cont].Nome);
      printf("\n Modelo: %s", VZonda[Cont].Modelo);
      printf("\n Placa: %s", VZonda[Cont].Placa);
      printf("\n Defeito: %s", VZonda[Cont].Defeito);
      if (VZonda[Cont].Preco==0)
        printf("\n Preco: NAO DEFINIDO");       
      else{
        printf("\n Preco: %.2f",VZonda[Cont].Preco);
        valorTotal = valorTotal + VZonda[Cont].Preco;
      }
      printf("\n --------------------- \n\n");
    }
    else {
      if (VZonda[Cont].Status != '2'){
        fseek(ArqAux, 0, SEEK_END);
        fwrite(&VZonda[Cont], sizeof(struct RegMoto), 1, ArqAux);
      }
    }
  } 
  Historico.Valor = valorTotal;
  fseek(ArqFinanceiro, 0, SEEK_END);
  fwrite(&Historico, sizeof(struct Financeiro), 1, ArqFinanceiro);
  printf ("O valor total obtido por servicos eh de: R$%.2f \n", valorTotal);
}

void HistoricoFinanceiro(FILE *ArqFinanceiro){
  float ValorTotal = 0, MaiorValor = 0;
  char stringaux[15];
  fseek(ArqFinanceiro, 0, SEEK_SET);
  while (fread(&Historico, sizeof(struct Financeiro), 1, ArqFinanceiro) == 1) {
      printf ("Na data %s foi recebido o valor total de R$%.2f \n", Historico.Data, Historico.Valor);
      ValorTotal = ValorTotal + Historico.Valor;
      if (Historico.Valor > MaiorValor){
        strcpy (stringaux,Historico.Data);
        MaiorValor = Historico.Valor;
      }
      
    }

  if(ValorTotal == 0){ // Lágica de não ter valor nenhum no histórico.
    printf ("Infelizmente nao foi arrecado nenhum valor! \n");
  }
  else{
    printf("O valor total arrecadado foi de R$%.2f \n", Historico.Valor);
    printf("E o maior valor recebido foi de R$%.2f, na data %s!! \n", MaiorValor, stringaux);
  }

}

int main(){
  FILE *ArqAux; //auxiliar para guardar dados
  FILE *ArqFinanceiro; //auxiliar para guarda data e valor arrecadado do dia
  ArqFinanceiro = fopen("financeiro.dat", "a+b");
  int Opcao;
  ArqAux = fopen("aux.dat", "a+b");
  IniciarArray(ArqAux);
  system("clear"); //limpa tela no ReplIt
  do{
    //Exibicao de menu e leitura da opcao. 	
	  printf("\n\n >>> Motos Zonda <<< \n\n");
	  printf("1 - Solicitar Servico \n");
	  printf("2 - Iniciar Servico \n");
	  printf("3 - Remover Solicitacao \n");
	  printf("4 - Consultar Solicitacoes \n");
	  printf("5 - Concluir Servico \n");
	  printf("6 - Encerrar Expediente \n");
    printf("7 - Historico Financeiro \n");
	  printf("8 - Sair \n\n");
	  printf("Digite a opcao desejada: ");
	  scanf("%d",&Opcao);	
    switch (Opcao){
      case 1: SolicitaServico(); break;
	  case 2: IniciaServico(); break;
	  case 3: RemoverSolicitacao(); break;
	  case 4: ConsultarSolicitacoes(); break;
	  case 5: ConcluirServico(); break;
	  case 6: EncerrarExpediente(ArqAux, ArqFinanceiro); break;
    case 7: HistoricoFinanceiro(ArqFinanceiro); break;
	  case 8: break;}}	  	
	
  while (Opcao!=8);
  fclose(ArqAux);
  fclose(ArqFinanceiro);

  return 0;}