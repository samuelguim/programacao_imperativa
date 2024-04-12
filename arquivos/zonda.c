#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct RegFinanceiro{
	char Data[10];
	float Valor;};
typedef struct RegFinanceiro TpRegFinanceiro;
TpRegFinanceiro VFinanceiro;

struct RegMoto{
	char Nome[20];
	char Modelo[10];
	char Placa[7];
	char Defeito[50];
	char Status;
	float Preco;};
typedef struct RegMoto TpRegMoto;
TpRegMoto VZonda[50], SobraVZonda;

FILE *ArqZonda;
FILE *ArqFinanceiro;

long int Tamanho=88*50*sizeof(char)+50*sizeof(float);
long int TamanhoF=10*sizeof(char)+sizeof(float);

long int TArquivo(){
	fseek(ArqZonda,0,2);
	long int R=ftell(ArqZonda)/Tamanho;
	return R;}
long int TArquivoF(){
	fseek(ArqFinanceiro,0,2);
	long int RF=ftell(ArqFinanceiro)/TamanhoF;
	return RF;}

int Quant=-1;//Controla o preenchimento do vetor

void ExportaServicos(){
  for (int Cont=0; Cont<=Quant; Cont++){
    if (VZonda[Cont].Status=='0' || VZonda[Cont].Status=='1'){
      SobraVZonda = VZonda[Cont];
      fseek(ArqZonda,0,2);
      fwrite(&SobraVZonda,sizeof(SobraVZonda),1,ArqZonda);}}
}

void ImportaServicos(){
  fclose(ArqZonda); //modo a + b
  ArqZonda=fopen("Motos.dat","r+b");
  fseek(ArqZonda,0,0);
  int i = 0;
  do {
    fread(&SobraVZonda,sizeof(SobraVZonda),1,ArqZonda);
    if (SobraVZonda.Status == '0' || SobraVZonda.Status == '1'){
      VZonda[i] = SobraVZonda;
      Quant++;
      i++;
      SobraVZonda.Status = '4';
      fseek(ArqZonda,-sizeof(SobraVZonda),1);
      fwrite(&SobraVZonda,sizeof(SobraVZonda),1,ArqZonda);
    }
  } while (!feof(ArqZonda));
  fclose(ArqZonda); //modo a + b
  ArqZonda=fopen("Motos.dat","a+b");
}

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
    char NomeTemp[20];
    scanf(" %[^\n]s",NomeTemp);
    printf("Qual o modelo da moto? ");
    char ModeloTemp[10];
    scanf(" %[^\n]s",ModeloTemp);
    printf("Qual a placa da moto? ");
    char PlacaTemp[7];
    scanf(" %[^\n]s",PlacaTemp);

    int Repetido=-1;
    for (int Cont=0; Cont<=Quant; Cont++){
     if (strcmp(VZonda[Cont].Placa,PlacaTemp)==0){
        Repetido=Cont;}}

    if (Repetido == -1){
      strcpy(VZonda[Quant].Nome, NomeTemp);
      strcpy(VZonda[Quant].Modelo, ModeloTemp);
      strcpy(VZonda[Quant].Placa, PlacaTemp);
      printf("Qual o defeito da moto? ");
      scanf(" %[^\n]s",VZonda[Quant].Defeito);
      VZonda[Quant].Status='0';
      VZonda[Quant].Preco=0;}
    else{
      printf("Essa mesma placa já foi registrada.\n");}

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
  printf("Qual é a data de hoje? ");
  scanf(" %[^\n]s",VFinanceiro.Data);
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
  
  VFinanceiro.Valor = Lucro;
  fseek(ArqFinanceiro,0,2);
  fwrite(&VFinanceiro,sizeof(VFinanceiro),1,ArqFinanceiro);

  ExportaServicos();
}

void HistoricoFinanceiro(){
  system("clear");
  float MaiorValor = 0;
  float TotalHistorico = 0;
  char MelhorData[10];
  printf(">>> Histórico Financeiro <<<\n\n"); 
  fseek(ArqFinanceiro,0,0);
  do {
	  fread(&VFinanceiro,sizeof(VFinanceiro),1,ArqFinanceiro);
	  if (!feof(ArqFinanceiro)){
	      printf("Data: %s\n",VFinanceiro.Data);
        printf("Valor: R$%.2f\n",VFinanceiro.Valor);
        printf("--------------------\n\n");
        TotalHistorico = TotalHistorico + VFinanceiro.Valor;
        if (VFinanceiro.Valor > MaiorValor){
          MaiorValor = VFinanceiro.Valor;
          strcpy(MelhorData, VFinanceiro.Data);}}}
  while (!feof(ArqFinanceiro));
  printf("Melhor Data: %s\n--------------------\n", MelhorData);
  printf("Total: R$%.2f\n", TotalHistorico);
}

int main(){
  ArqZonda=fopen("Motos.dat","a+b");
  ArqFinanceiro=fopen("Financeiro.dat","a+b");
  ImportaServicos();

  int Opcao, Expediente = 1;
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
	  printf("7 - Histórico Financeiro \n");
    printf("8 - Sair \n\n");
	  printf("Digite a opcao desejada: ");
	  scanf("%d",&Opcao);	
    switch (Opcao){
      case 1: SolicitaServico(); 
              system("read -p '--------------------\nPressione Enter para continuar...' var");break;
	    case 2: IniciaServico();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 3: RemoverSolicitacao();
              system("read -p '--------------------\nPrdessione Enter para continuar...' var"); break;
	    case 4: ConsultarSolicitacoes();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 5: ConcluirServico();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 6: EncerrarExpediente();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
	    case 7: HistoricoFinanceiro();
              system("read -p '--------------------\nPressione Enter para continuar...' var"); break;
      case 8: break;}}	  	
	while (Opcao!=8);
  fclose(ArqZonda);
  fclose(ArqFinanceiro);
  return 0;}