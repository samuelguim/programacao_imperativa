#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct RegMoto{
	char Nome[20];
	char Modelo[10];
	char Placa[7];
	char Defeito[50];
	char Status;
	float Preco;};
typedef struct RegMoto TpRegMoto;
TpRegMoto VZonda[50];

int Quant=-1;//Controla o preenchimento do vetor

int PesquisaMoto(){
  char P[7];
  printf("Placa da moto: ");
  scanf(" %[^\n]s",P);
  int Pos=-1; //posição da moto P no vetor
  //busca da moto para iniciar serviço
  for (int Cont=0; Cont<=Quant; Cont++){
    if (strcmp(VZonda[Cont].Placa,P)==0){
      Pos=Cont;}}
  return Pos;
}

void ExibeInformacoes(int Pos){
  printf("--------------------");
  printf("\n Cliente %d: %s", Pos+1, VZonda[Pos].Nome);
  printf("\n Modelo: %s", VZonda[Pos].Modelo);
  printf("\n Placa: %s", VZonda[Pos].Placa);
  printf("\n Defeito: %s", VZonda[Pos].Defeito);
  printf("\n Status: %c",VZonda[Pos].Status);
  if (VZonda[Pos].Preco==0){
    printf("\n Preco: NAO DEFINIDO\n");} 
  else{
    printf("\n Preco: R$%.2f\n",VZonda[Pos].Preco);}
}

void SolicitaServico(){
  /* (1) Solicitar Serviço – quando se insere os dados supracitados, e também 
  os campos status com valor zero sinalizando que o serviço ainda não foi 
  feito, preço, também iniciado com zero.  Este deve estar em loop. */
  char Sair='S';
  do{
    system("clear");
    printf("\n\n >>> Motos Zonda <<< \n\n");
    Quant=Quant+1;
    printf("Qual o nome do cliente? ");
    scanf(" %[^\n]s",VZonda[Quant].Nome);
    printf("Qual o modelo da moto? ");
    scanf(" %[^\n]s",VZonda[Quant].Modelo);
    printf("Qual a placa da moto? ");
    scanf(" %[^\n]s",VZonda[Quant].Placa);
    printf("Qual o defeito da moto? ");
    scanf(" %[^\n]s",VZonda[Quant].Defeito);
    VZonda[Quant].Status='0';
    VZonda[Quant].Preco=0;
    printf("\nDeseja inserir novo servico? S|N ");
    scanf(" %c",&Sair);
    Sair=toupper(Sair);}
  while (Sair!='N');
}

void IniciaServico(){
  /*(2) Iniciar Serviço – quando o status de uma dada moto (placa) é 
  iniciado pelo mecânico e o status para a ser um.*/
  system("clear");
  int Pos = PesquisaMoto();
  if (Pos==-1){
    printf("Moto não cadastrada!\n");}
  else{
    if (VZonda[Pos].Status='0'){
      VZonda[Pos].Status='1';
      ExibeInformacoes(Pos);}
    else{
      printf("O serviço não pode ser iniciado.");}} 
}

void RemoverSolicitacao(){
  system("clear");
  int Pos = PesquisaMoto();
  if (Pos==-1){
    printf("Moto não cadastrada!");}
  else{
    if (VZonda[Pos].Status=='0'){
      VZonda[Pos].Status='2';
      ExibeInformacoes(Pos);}
    else{
      printf ("A solicitação não pode ser removida.\n");}}
}

void ConsultarSolicitacoes(){
  system("clear");
  printf("\n\n >>> Motos Zonda <<< \n\n");
  if (Quant==-1)
    printf("Não há serviços cadastrados.");
  else{
    printf("Serviços pendentes:\n");
    for (int Cont=0; Cont<=Quant; Cont++){
      if (VZonda[Cont].Status=='0'){
        ExibeInformacoes(Cont);}}}} 
  
void ConcluirServico(){
  system("clear");
  int Pos = PesquisaMoto();
  if (Pos==-1){
    printf("Moto não cadastrada!\n");}
  else{
    if (VZonda[Pos].Status=='1'){
      printf("Qual foi o preço do serviço? ");
      scanf("%f", &VZonda[Pos].Preco);
      VZonda[Pos].Status='3';
      ExibeInformacoes(Pos);}
    else {
      printf("O serviço não pode ser concluído pois não foi iniciado.\n");}}
}

void EncerrarExpediente(){
  system("clear");
  printf("Serviços Realizados:\n");
  for (int Cont=0; Cont<=Quant; Cont++){
    if (VZonda[Cont].Status=='3'){
      ExibeInformacoes(Cont);}}
  
  float Lucro = 0;
  for (int Cont=0; Cont<=Quant; Cont++){
    if (VZonda[Cont].Status=='3'){
      Lucro = Lucro + VZonda[Cont].Preco;}}
  printf("\n--------------------");
  printf("\nValor total: R$%.2f\n", Lucro);
}

int main(){
  int Opcao;
   //limpa tela no ReplIt
  do{
    system("clear");
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
      case 1: SolicitaServico(); 
              system("read -p '--------------------\nPressione Enter para continuar...' var");break;
	    case 2: IniciaServico();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 3: RemoverSolicitacao();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 4: ConsultarSolicitacoes();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 5: ConcluirServico();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 6: EncerrarExpediente();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 7: break;}}	  	
	while (Opcao!=7);
  return 0;}