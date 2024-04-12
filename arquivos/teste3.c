#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

FILE *ArqMotos;
FILE *ArqHistFinanceiro;


struct RegMoto{ //struct com as variáveis que serão utilizadas no programa
    char nome[20];
    char modelo[10];
    char placa[7];
    char defeito[50];
    int status;
    float preco;};

struct RegFinanceiro {
    char data[10];
    float valor;
};
typedef struct RegFinanceiro TpFinanceiro; //redefininido o nome da estrutura anteriormente declarada e colocando-a com o máximo de 50.
TpFinanceiro vfinanceiro;

typedef struct RegMoto TpRegMoto; //redefininido o nome da estrutura anteriormente declarada e colocando-a com o máximo de 50.
TpRegMoto VZonda[50], sobra;
int posicao=-1, Expediente = 1; //Controla o preenchimento do vetor

int VerificaRepeticao(char PlacaUsuario[7]){
    int PlacaObtida = -1;
    for (int i = 0; i <= posicao; i++){
        if (strcmp(VZonda[i].placa, PlacaUsuario) == 0){
            PlacaObtida = i;
        }
    }
    return PlacaObtida;
}

int BuscarPelaPlaca(){
    char BuscarPlaca[7];
    printf("Insira a placa da moto que deseja buscar: ");
    scanf(" %[^\n]s",BuscarPlaca);
    int PlacaObtida = -1;
    for (int i = 0; i <= posicao; i++){
        if (strcmp(VZonda[i].placa, BuscarPlaca) == 0){
            PlacaObtida = i;
        }
    }
    if (PlacaObtida < 0){
        printf("A moto nao esta cadastrada\n");
        return -1;
    }
    else{
        return PlacaObtida;
    }
}

void ListarServicos(int PlacaObtida){
    printf("\n==============\n");
    printf("Cliente %d: %s\n", PlacaObtida + 1, VZonda[PlacaObtida].nome);
    printf("Modelo: %s\n", VZonda[PlacaObtida].modelo);
    printf("Placa: %s\n", VZonda[PlacaObtida].placa);
    printf("Defeito: %s\n", VZonda[PlacaObtida].defeito);
    printf("Status: %d\n", VZonda[PlacaObtida].status);
    if (VZonda[PlacaObtida].preco == 0){
        printf("O preco ainda nao foi estabelecido!");
    }
    else{
        printf("Preco: R$%.2f", VZonda[PlacaObtida].preco);
    }
}
    //(1) Solicitar Serviço – quando se insere os dados supracitados, e também os campos status é inicializado com valor zero
    //sinalizando que o serviço ainda não foi feito, preço, também iniciado com zero. Este deve estar em loop.



void SolicitarServico(){
    //vc vai adicionar variáveis temporárias bbd aqui 
    char resposta = 'S', nome_temp[20], modelo_temp[10], placa_temp[7];
    do{
       
        printf("Insira as informacoes a seguir para continuar o servico\n");
        printf("\n");
        printf("nome: ");
        scanf(" %[^\n]s",nome_temp);
        printf("\nmodelo da moto: ");
        scanf(" %[^\n]s",modelo_temp);
        printf("\nplaca: ");
        scanf(" %[^\n]s",placa_temp);

        int rep = VerificaRepeticao(placa_temp);

        if (rep == -1){
            posicao++;
            strcpy(VZonda[posicao].nome, nome_temp);
            strcpy(VZonda[posicao].modelo, modelo_temp);
            strcpy(VZonda[posicao].placa, placa_temp);
            printf("\ndescricao do defeito: ");
            scanf(" %[^\n]s",VZonda[posicao].defeito);
            VZonda[posicao].status = 0;
            VZonda[posicao].preco = 0;
        }
        else {
            printf("Uma moto com essa placa já foi incluída.\n");
        }

        printf("\nDeseja solicitar outro servico? (S/N): ");
        scanf(" %c", &resposta);
        resposta = toupper(resposta);
        if (resposta != 'S'){
            if (resposta != 'N'){
                printf("Insira S para Sim, ou N para Nao!");
                continue;
            }
        }}
    while (resposta != 'N');
}

    //(2) Iniciar Serviço – quando o status de uma dada moto (placa) é iniciado pelo mecânico e o status para a ser um.
void IniciarServico(){
    int PlacaObtida = BuscarPelaPlaca();
    if (PlacaObtida >= 0){
        if (VZonda[PlacaObtida].status == 0){
            VZonda[PlacaObtida].status = 1;
            ListarServicos(PlacaObtida);
        }
        else{
            printf("O servico deu erro, por favor tente novamente!\n");
        }
    }
}
    //(3) Remover Solicitação – para o caso do proprietário desistir de esperar, 
    //o que somente é permitido se o serviço não tiver iniciado, e o status passa a ser dois, dada a placa da moto.
void RemoverSolicitacao(){
 
 int PlacaObtida = BuscarPelaPlaca();
 if (PlacaObtida >= 0){
    if (VZonda[PlacaObtida].status == 0){
        VZonda[PlacaObtida].status = 2;
        printf("\nFoi removido com sucesso!\n");
        ListarServicos(PlacaObtida);
        }
    else{
        printf("Nao foi possivel concluir a remocao, tente novamente!\n");
        }
    }
 
}
    //(4) Consultar Solicitações – quando se exibe todas as solicitações ainda não feitas (não iniciadas).
void ConsultarSolicitacoes(){
    if (posicao == -1){
        printf("Nao ha solicitacoes a serem exibidas\n");
    }
    else{
        printf("A seguir serao exibidos os servicos a serem finalizados em ordem de chegada:\n");
        for (int i = 0; i <= posicao; i++){
            if (VZonda[i].status == 0){
                ListarServicos(i);
            }
        }
    }
}
    //(5) Concluir Serviço – para indicar que o mecânico concluiu o atendimento, define o preço final e o status passa a ser três.
void ConcluirServico(){
    int PlacaObtida = BuscarPelaPlaca();
    if (PlacaObtida >= 0 && VZonda[PlacaObtida].status == 1){
        printf("Preco do servico: ");
        scanf("%f", &VZonda[PlacaObtida].preco);
        VZonda[PlacaObtida].status = 3;
        ListarServicos(PlacaObtida);
    }
    else{
        printf("O servico nao foi iniciado ainda\n");
    }
}
    //(6) Encerrar Expediente – para exibição de todos os serviços efetuados, e exibição do valor total obtido, no dia, com os serviços.
void EncerrarExpediente(){
    if (Expediente == 1) {
        float LucroObtido = 0;
        Expediente = 0;
        printf("qual eh a data ");
        char data[10];
        scanf(" %[^\n]s", vfinanceiro.data);
        printf("Servicos realizados no dia: \n");
        for (int i = 0; i <= posicao; i++){
            if (VZonda[i].status == 3){
                ListarServicos(i);
                LucroObtido = LucroObtido + VZonda[i].preco;
            }
            if(VZonda[i].status == 0 || VZonda[i].status == 1){ 
                sobra = VZonda[i];
                fseek(ArqMotos,0,2);
                fwrite(&sobra,sizeof(sobra),1,ArqMotos);
            }
    }
    printf("\nLucro obtido no dia: R$%.2f", LucroObtido);
    vfinanceiro.valor = LucroObtido;
    fseek(ArqHistFinanceiro,0,2);
    fwrite(&vfinanceiro,sizeof(vfinanceiro),1,ArqHistFinanceiro);
    }
    else {
        printf("O expediente já foi encerrado.");
    }
}
void HistoricoFinanceiro (){ 
    char maiorData[10] ; int maiorValor = 0;
    printf("*** historico financeiro***\n\n"); 
    fseek(ArqHistFinanceiro,0,0);
  do { 
	fread(&vfinanceiro,sizeof(vfinanceiro),1,ArqHistFinanceiro);
	if (!feof(ArqHistFinanceiro)){
      printf("data: %s\n",vfinanceiro.data);
      printf("valor: R$%.2f\n",vfinanceiro.valor);
      if(vfinanceiro.valor>maiorValor){
        maiorValor = vfinanceiro.valor;
        strcpy(maiorData,vfinanceiro.data);
      }
    
      printf("***\n\n");}}
  while (!feof(ArqHistFinanceiro));
  printf(" a data com o maior valor de venda foi: %s" ,maiorData);
  //system("pause");
  }

    //(7) Sair – para encerrar a execução do programa.
        //(Um simples break pro loop finalizar)
int main(){ 
    ArqMotos= fopen ("motos.dat","a+b");
    ArqHistFinanceiro= fopen ("financeiro.dat","a+b");

    fclose(ArqMotos); //modo a + b
    ArqMotos=fopen("motos.dat","r+b");
    fseek(ArqMotos,0,0);
    int i = 0;

    if (!feof(ArqMotos)); {
            do { 
	        fread(&sobra,sizeof(sobra),1,ArqMotos);
            if (sobra.status == 0 || sobra.status == 1){
            VZonda[i]= sobra;
            sobra.status = 4;
            fseek(ArqMotos,-sizeof(sobra),1);
            fwrite(&sobra,sizeof(sobra),1,ArqMotos);
            i++; 
            posicao++;
            }
        }
    while (!feof(ArqMotos));}
    fclose(ArqMotos); //
    ArqMotos=fopen("motos.dat","a+b");
  
    while(true){
        fflush(stdin);
        int escolha = 0;
        printf("\n======== Moto Zonda ========\n\nEscolha uma das opcoes a seguir:\n1 - Solicitar Servico\n2 - Iniciar Servico\n3 - Remover Solicitacao\n4 - Consultar Solicitacoes\n5 - Concluir Servico\n6 - Encerrar expediente\n7 - Consultar Historico\n8 - Sair do programa\nSua Escolha: ");
        scanf("%d",&escolha);
        if (escolha == 1){
            SolicitarServico();
            continue; }
        if (escolha == 2){
            IniciarServico();
            continue;}
        if (escolha == 3){
            RemoverSolicitacao();
            continue; }
        if (escolha == 4){
            ConsultarSolicitacoes();
            continue;}
        if (escolha == 5){
            ConcluirServico();
            continue; }
        if (escolha == 6){
            EncerrarExpediente();
            continue;  }
        if (escolha == 7){
            HistoricoFinanceiro();
            continue;  }
        if(escolha==8){
            if (Expediente == 0){
               system("cls");
               printf("O programa foi encerrado!"); 
            }
            else{
                printf("Feche o expediente antes de sair do programa\n");
                continue;
            }
        }
        else{
            printf("Insira uma opcao correta!\n");
            continue; }
        fclose(ArqMotos);
        fclose (ArqHistFinanceiro);
    return 0;
}
}