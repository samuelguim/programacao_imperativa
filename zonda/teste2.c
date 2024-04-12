#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

struct RegMoto{ //struct com as variáveis que serão utilizadas no programa
    char nome[20];
    char modelo[10];
    char placa[7];
    char defeito[50];
    int status;
    float preco;};

typedef struct RegMoto TpRegMoto; //redefininido o nome da estrutura anteriormente declarada e colocando-a com o máximo de 50.
TpRegMoto VZonda[50];

int posicao=-1; //Controla o preenchimento do vetor

int BuscarPelaPlaca(){
    char BuscarPlaca[7];
    printf("Insira a placa da moto que deseja buscar: ");
    scanf(" %[^\n]s",BuscarPlaca);
    int PlacaObtida = -1;
    for (int i = 0; i <= posicao; i++){
        if (strcmp(VZonda[i].placa, BuscarPlaca) == 0){
            PlacaObtida = i;
        }
    return PlacaObtida;
    }
}

int VerificarCadastramento(){
    int PlacaObtida = BuscarPelaPlaca();
    if (PlacaObtida < 0){
        printf("A moto nao esta cadastrada\n");
        return -1;
    }
    else{
        return 1;
    }
}

void ListarServicos(int PlacaObtida){
    printf("Cliente %d: %s\n", PlacaObtida + 1, VZonda[PlacaObtida].nome);
    printf("Modelo: %s\n", VZonda[PlacaObtida].modelo);
    printf("Placa: %s\n", VZonda[PlacaObtida].placa);
    printf("Defeito: %s\n", VZonda[PlacaObtida].defeito);
    printf("Status: %d\n", VZonda[PlacaObtida].status);
    if (VZonda[PlacaObtida].preco == 0){
        printf("O preco ainda nao foi estabelecido!");
    }
    else{
        printf("Preco: R$%.2f", VZonda[posicao].preco);
    }
}
    //(1) Solicitar Serviço – quando se insere os dados supracitados, e também os campos status é inicializado com valor zero
    //sinalizando que o serviço ainda não foi feito, preço, também iniciado com zero. Este deve estar em loop.
void SolicitarServico(){
    char resposta = 'S';
    do{
        posicao = posicao + 1;
        if (posicao > 50){
            printf("\nSolicitacoes diarias excedidas\n");
            break;
        }
        printf("Eh necessario inserir os dados supracitados para o inicio do servico\n");
        printf("Insira as informacoes a seguir para continuar o servico\n");
        printf("\n");
        printf("nome: ");
        scanf(" %[^\n]s",VZonda[posicao].nome);
        printf("\nmodelo da moto: ");
        scanf(" %[^\n]s",VZonda[posicao].modelo);
        printf("\nplaca: ");
        scanf(" %[^\n]s",VZonda[posicao].placa);
        printf("\ndescricao do defeito: ");
        scanf(" %[^\n]s",VZonda[posicao].defeito);
        VZonda[posicao].status = 0;
        VZonda[posicao].preco = 0;
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
    if (VerificarCadastramento() == 1){
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
    if (VerificarCadastramento() == 1){
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
    if (VerificarCadastramento() == 1 && VZonda[PlacaObtida].status == 1){
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
    float LucroObtido = 0;
    printf("Servicos realizados no dia: \n");
    for (int i = 0; i <= posicao; i++){
        if (VZonda[i].status == 3){
            ListarServicos(i);
            LucroObtido = LucroObtido + VZonda[i].preco;
        }
    }
    printf("\nLucro obtido no dia: R$%.2f", LucroObtido);
}
    //(7) Sair – para encerrar a execução do programa.
        //(Um simples break pro loop finalizar)
int main(){
    while(true){
        fflush(stdin);
        int escolha = 0;
        printf("\n======== Moto Zonda ========\n\nEscolha uma das opcoes a seguir:\n1 - Solicitar Servico\n2 - Iniciar Servico\n3 - Remover Solicitacao\n4 - Consultar Solicitacoes\n5 - Concluir Servico\n6 - Encerrar expediente\n7 - Sair do programa\nSua Escolha: ");
        scanf("%d",&escolha);
        if (escolha == 1){
            SolicitarServico();
            continue;
        }
        if (escolha == 2){
            IniciarServico();
            continue;
        }
        if (escolha == 3){
            RemoverSolicitacao();
            continue;
        }
        if (escolha == 4){
            ConsultarSolicitacoes();
            continue;
        }
        if (escolha == 5){
            ConcluirServico();
            continue;
        }
        if (escolha == 6){
            EncerrarExpediente();
            continue;
        }
        if (escolha == 7){
            system("cls");
            printf("O programa foi encerrado!");
            break;
        }
        else{
            printf("Insira uma opcao correta!\n");
            continue;
        }
    return 0;
}
}