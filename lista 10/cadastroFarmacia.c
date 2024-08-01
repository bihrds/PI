/* Implementar ajustando o projeto “Cadastro Farmácia”
(PaguePouco.c) as operações a seguir:

(1) exclusão lógica de fármaco dado pelo usuário. -ok

(2) ajuste da inclusão de forma a impossibilitar fármacos repetidos. -ok

(3) ajustar a consulta total de forma a não exibir os registros excluídos (logicamente). -ok

(4) identificar e implementar melhoria 1 no código. BUSCA NOME - ok

(5) identificar e implementar melhoria 2 no código. REESCREVER ARQUIVO - ok*/ 

#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

struct TpFarma{
	char Nome[21];
	float Preco;
	int QEstoque;
  };

typedef struct TpFarma TpFARMA;

TpFARMA RgFarma;

FILE *ArqFarma;

long int Tamanho=21*sizeof(char)+sizeof(float)+sizeof(int); //locação dinâmica

int BuscaNome(char *string) { /* Melhoria 1 - Criada para modularizar a busca de um nome no arquivo, retorna 1 se for 
encontrado e 0 caso contrario. */
    TpFARMA rgaux;
    fseek(ArqFarma, 0, SEEK_SET);
    while (fread(&rgaux, sizeof(TpFARMA), 1, ArqFarma) == 1) {
        printf(" Busca %s \n", rgaux.Nome);
        if (strcmp(rgaux.Nome, string) == 0) {
            return 1;
        }
    }
    return 0;
}

//*(2) ajuste da inclusão de forma a impossibilitar fármacos repetidos.

void Incluir() {
    char R;
    do {
        printf(" inclusao \n\n");
        printf("Nome: ");
        scanf(" %s", RgFarma.Nome);
        if (BuscaNome(RgFarma.Nome)) {
            printf("Inclusao nao feita, pois o farmaco eh repetido \n");
        } else {
            printf("Preco: ");
            scanf("%f", &RgFarma.Preco);
            printf("Estoque: ");
            scanf("%d", &RgFarma.QEstoque);
            fseek(ArqFarma, 0, SEEK_END); // Move para o final do arquivo para adicionar novos dados
            fwrite(&RgFarma, sizeof(TpFARMA), 1, ArqFarma);
            printf("Registro salvo com sucesso \n");
        }
        printf("\n Nova inclusao? S/N \n");
        scanf(" %c", &R);
        R = toupper(R);
    } while (R != 'N');
}

void ReescreverArq(char *string){ /*Melhoria 2 - Metodo para apagar o struct de um arquivo, onde é criado um arquivo 
temporario, todos os dados do arquivo original, exceto o excludente são copiados para o temporario, o original é removido 
e o temporario passa a ser o novo arquivo original.*/

  FILE *ArquivoTemp = fopen("temp.dat", "wb"); // fopen - abre o arquivo, wb- escrever binario
  TpFARMA rgaux;
  fseek(ArqFarma, 0, SEEK_SET); //
  while (fread(&rgaux, sizeof(TpFARMA), 1, ArqFarma) == 1)
  {
    if (strcmp(rgaux.Nome, string) != 0)
    {
      fwrite(&rgaux, sizeof(TpFARMA), 1, ArquivoTemp);
    }
    
  }
  fclose(ArquivoTemp); // fecha o arquivo, pois é um ponteiro e se não fecharmos pode ficar aberto na memoria
  fclose(ArqFarma);
  remove("Farmacos.dat");
  rename("temp.dat","Farmacos.dat");
  ArqFarma=fopen("Farmacos.dat","r+b");
}


/*(1) exclusão lógica de fármaco dado pelo usuário.*/

void Excluir(){
  printf("*** exclusao ***\n\n");
  printf("Nome: ");
  scanf("%s",RgFarma.Nome);

  if (BuscaNome(RgFarma.Nome)){
      ReescreverArq(RgFarma.Nome);
      printf ("Exclusao concluida com sucesso!! n");
    }
    else {
      printf ("Exclusao nao feita, pois o farmaco nao foi encontrado! \n");
    }
}

long int TArquivo(){
	fseek(ArqFarma,0,2);
	long int R=ftell(ArqFarma)/Tamanho;
	return R;}
	
void Alterar(){
  if (TArquivo()!=0){
    fclose(ArqFarma); //modo a + b
    ArqFarma=fopen("Farmacos.dat","r+b");
    //system("cls");
    printf("*** alterar ***\n\n");  
    fseek(ArqFarma,0,0);
    printf("Qual farmaco? ");
    char Farmaco[21];
    scanf("%s",Farmaco);
    int Achou=0;
    do {
	    fread(&RgFarma,Tamanho,1,ArqFarma);
	    if (strcmp(RgFarma.Nome,Farmaco)==0){
	      Achou=1;	
	      printf("Nome: %s\n",RgFarma.Nome);
        printf("Valor: %f\n",RgFarma.Preco);
        printf("Estoque: %d\n",RgFarma.QEstoque);}}
    while (!feof(ArqFarma) && (Achou==0));
    if (Achou==0)
      printf("Registro inexistente!"); 
    else{
      printf("Qual o novo preco? \n"); 
      scanf("%f",&RgFarma.Preco);
      printf("Qual a nova quantidade? \n");
      scanf("%d",&RgFarma.QEstoque);
      fseek(ArqFarma,-Tamanho,1);
      fwrite(&RgFarma,Tamanho,1,ArqFarma);
      printf(">>> Alteracao efetuada com sucesso! <<<\n");}
      //system("pause");
    fclose(ArqFarma);
    ArqFarma=fopen("Farmacos.dat","a+b");}
  else{
    printf("Arquivo Vazio.  Nao existem dados a alterar.");}
    //system("pause");
  return;}

void Consultar(){
  //system("cls");
  printf("*** consulta ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? ");
  char Farmaco[21];
  scanf("%s",Farmaco);
  int Achou=0;
  do{
	  fread(&RgFarma,Tamanho,1,ArqFarma);
	  if (strcmp(RgFarma.Nome,Farmaco)==0){
	    Achou=1;	
	    printf("Nome: %s\n",RgFarma.Nome);
      printf("Valor: R$%.2f\n",RgFarma.Preco);
      printf("Estoque: %d\n",RgFarma.QEstoque);}}
  while (!feof(ArqFarma) && (Achou==0));
  if (Achou==0)
    printf("Registro inexistente!");  
  //system("pause");
  return;}

//(3) ajustar a consulta total de forma a não exibir os registros excluídos (logicamente).

void LTodos(){
  //system("cls");
  printf("*** lista todos ***\n\n"); 
  fseek(ArqFarma,0,0);
  do {
	fread(&RgFarma,Tamanho,1,ArqFarma);
	if (!feof(ArqFarma)){
	    printf("Nome: %s\n",RgFarma.Nome);
      printf("Valor: R$%.2f\n",RgFarma.Preco);
      printf("Estoque: %d\n",RgFarma.QEstoque);
      printf("***\n\n");}}
  while (!feof(ArqFarma));
  //system("pause");
  }

int main(){
  ArqFarma=fopen("Farmacos.dat","a+b");
  char Opcao;
  do{
	  //system("cls");
    printf("\n\n> > > Pague Pouco < < < \n\n");
    printf("O que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Excluir \n");
    printf("A - Alterar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break; 
      case 'E': Excluir(); break; 
      case 'A': Alterar(); break; 
      case 'C': Consultar(); break; 
      case 'T': LTodos(); break;}} 
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;}