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

long int Tamanho=21*sizeof(char)+sizeof(float)+sizeof(int);

void Incluir() {
  char R;
  do{
    //system("cls");
    printf("*** inclusao ***\n\n");
    printf("Nome: ");
    scanf("%s",RgFarma.Nome);
    printf("Preco: ");
    scanf("%f",&RgFarma.Preco);
    printf("Estoque: ");
    scanf("%d",&RgFarma.QEstoque);
    fseek(ArqFarma,0,2);
    fwrite(&RgFarma,Tamanho,1,ArqFarma);
    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);}
  while (R!='N');
  return;}

void Excluir(){
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
    printf("Que deseja fazer? \n\n");
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