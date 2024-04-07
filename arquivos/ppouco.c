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

long int TArquivo(){
	fseek(ArqFarma,0,2);
	long int R=ftell(ArqFarma)/Tamanho;
	return R;}

void ExibirFarmaco(){
  printf("Nome: %s\n",RgFarma.Nome);
  printf("Valor: %.2f\n",RgFarma.Preco);
  printf("Estoque: %d\n",RgFarma.QEstoque);
  /*
  if (RgFarma.QEstoque >= 0){
    printf("Status: Ativo\n");}
  else{
    printf("Status: Excluído\n");}
  */
}

int ProcuraFarmaco(char Farmaco[21]){
  int Achou=0;
  fseek(ArqFarma,0,0);
    do {
	    fread(&RgFarma,sizeof(RgFarma),1,ArqFarma);
	    if (strcmp(RgFarma.Nome,Farmaco)==0){
	      Achou=1;}}
    while (!feof(ArqFarma) && (Achou==0));
  return Achou;
}

void Alterar(char Acao){
  if (TArquivo()!=0){
    fclose(ArqFarma); //modo a + b
    ArqFarma=fopen("Farmacos.dat","r+b");
    system("clear");
    if (Acao == 'a'){
      printf("*** Alterar ***\n\n");}
    if (Acao == 'e'){
      printf("*** Excluir ***\n\n");}
    if (Acao == 'r'){
      printf("*** Recuperação ***\n\n");}
    fseek(ArqFarma,0,0);
    printf("Qual farmaco? ");
    char Farmaco[21];
    scanf("%s",Farmaco);
    int Achou = ProcuraFarmaco(Farmaco);
    if (Achou==0 || (Acao != 'r' && RgFarma.QEstoque < 0)){
      printf("Registro inexistente!"); 
      printf("\n"); }
    else{
      if (Acao == 'a'){
        ExibirFarmaco();
        printf("Qual o novo preco? \n"); 
        scanf("%f",&RgFarma.Preco);
        printf("Qual a nova quantidade? \n");
        scanf("%d",&RgFarma.QEstoque);
        printf(">>> Alteracao efetuada com sucesso! <<<\n");}
      if (Acao == 'e'){
        RgFarma.QEstoque = -1;
        printf(">>> Exclusão efetuada com sucesso! <<<\n");}
      if (Acao == 'r'){
        RgFarma.QEstoque = 0;
        printf(">>> Recuperação efetuada com sucesso! <<<\n");}
      fseek(ArqFarma,-sizeof(RgFarma),1);
      fwrite(&RgFarma,sizeof(RgFarma),1,ArqFarma);}
    fclose(ArqFarma);
    ArqFarma=fopen("Farmacos.dat","a+b");}
  else{
    printf("Arquivo Vazio. Nao existem dados a alterar.");}
  system("read -p 'Pressione Enter para continuar...' var");
  return;}

void Incluir() {
  char R;
  do{
    system("clear");
    printf("*** inclusao ***\n\n");
    printf("Nome: ");
    char Farmaco[21];
    scanf("%s",Farmaco);
    int Repitido = ProcuraFarmaco(Farmaco);
    if (Repitido == 0 && RgFarma.QEstoque >= 0){
      strcpy(RgFarma.Nome, Farmaco);
      printf("Preco: ");
      scanf("%f",&RgFarma.Preco);
      printf("Estoque: ");
      scanf("%d",&RgFarma.QEstoque);
      fseek(ArqFarma,0,2);
      fwrite(&RgFarma,sizeof(RgFarma),1,ArqFarma);}
    else if (Repitido != 0 && RgFarma.QEstoque < 0){
      printf("Um fármaco com o mesmo nome foi excluído.\n");
      printf("Deseja acionar a ferramenta de recuperação? S/N ");
      char Decisao;
      scanf(" %c",&Decisao);
      Decisao=toupper(Decisao);
      if (Decisao == 'S'){
        Alterar('r');}
      else{
        printf("Operação não concluída.\n");
        printf("\n");}}
    else {
      printf("Operação não concluída pois um fármaco com o mesmo nome já está cadastrado.\n");
      printf("\n");}
    printf("\nNova inclusao? S/N ");
    scanf(" %c",&R);
    R=toupper(R);}
  while (R!='N');
  return;}

void Consultar(){
  system("clear");
  printf("*** consulta ***\n\n");  
  fseek(ArqFarma,0,0);
  printf("Qual farmaco? ");
  char Farmaco[21];
  scanf("%s",Farmaco);
  int Achou = ProcuraFarmaco(Farmaco);
  if (Achou == 0 || RgFarma.QEstoque < 0){
    printf("Registro inexistente!");
    printf("\n");}
  else {
    ExibirFarmaco();}
  system("read -p 'Pressione Enter para continuar...' var");
  return;}

void LTodos(){
  system("clear");
  printf("*** lista todos ***\n\n"); 
  fseek(ArqFarma,0,0);
  do {
	  fread(&RgFarma,sizeof(RgFarma),1,ArqFarma);
	  if (!feof(ArqFarma) && RgFarma.QEstoque >= 0){
	    ExibirFarmaco();
      printf("***\n\n");}}
  while (!feof(ArqFarma));
  system("read -p 'Pressione Enter para continuar...' var");
}

int main(){
  ArqFarma=fopen("Farmacos.dat","a+b");
  char Opcao;
  do{
	  system("clear");
    printf("\n\n> > > Pague Pouco < < < \n\n");
    printf("Que deseja fazer? \n\n");
    printf("I - Incluir \n");  
    printf("E - Excluir \n");
    printf("A - Alterar \n");
    printf("R - Recuperar \n");
    printf("C - Consultar \n");
    printf("T - Listar Todos \n");
    printf("S - Sair \n\n");
    scanf(" %c", &Opcao);
    Opcao=toupper(Opcao);
    switch (Opcao){
      case 'I': Incluir(); break; 
      case 'E': Alterar('e'); break; 
      case 'A': Alterar('a'); break; 
      case 'R': Alterar('r'); break;
      case 'C': Consultar(); break; 
      case 'T': LTodos(); break;}} 
  while (Opcao != 'S');
  fclose(ArqFarma);
  return 0;}