/*Na oficina autorizada das motos “Zonda” há box para atender serviços expressos, os quais
correspondem a serviços que demandam até 60 minutos de dedicação da equipe de mecânicos para
serem solucionados. Quando um cliente precisa de um serviço expresso, ele dirige-se ao atendimento,
fornece: nome, modelo da moto, placa e descrição do defeito. Em seguida dirige-se a uma sala de
espera e aguarda o conserto de sua moto. Sabendo que o número máximo de solicitações não passa de
50, escrever programa modularizado para gerenciar os serviços expressos “Zonda”. Disponibilizar as
opções:

Ajustar código referente a MotosZonda implementanado as opções 3, 5 e 6 e 2 melhorias no código.
Corresponde à Ap 2 da Nota 3. */

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

int Quant=-1; //Controla o preenchimento do vetor


int compareStrings(char * Str1, char * Str2 ) { //strc
	int vfinal = strlen(Str1);
	for(int i=0;i<vfinal;i++){
		if (Str1[i]<Str2[i])	return (-1);
		else if (Str1[i]>Str2[i])	return 1;	
	}
	return 0;	
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
  printf("\n\n >>> Motos Zonda <<< \n\n");
  if (Quant==-1)
    printf("Nao ha servicos cadastrados.");
  else{
    for (int Cont=0; Cont<=Quant; Cont++){
      if (VZonda[Cont].Status == '0')
      {
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
      else{
        printf ("Nao ha solicitacoes em aberto! \n");
      
        }
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

void EncerrarExpediente(){
  fflush(stdin);  
  int valorTotal = 0;

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
  } 
  printf ("O valor total obtido por servicos eh de: R$%.2d \n", valorTotal); 
}

int main(){
  int Opcao;
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
	  printf("7 - Sair \n\n");
	  printf("Digite a opcao desejada: ");
	  scanf("%d",&Opcao);	
    switch (Opcao){
    case 1: SolicitaServico(); break;
	  case 2: IniciaServico(); break;
	  case 3: RemoverSolicitacao(); break;
	  case 4: ConsultarSolicitacoes(); break;
	  case 5: ConcluirServico(); break;
	  case 6: EncerrarExpediente(); break;
	  case 7: break;}}	  	
	
  while (Opcao!=7);
  
  return 0;}