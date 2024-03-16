#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Estaciona[30][14];
/*30 vagas, mantem placa com 7 caracteres, sinal
+ e 5 caracteres para hora */

float Valor;
char Responsavel[21], Iniciou = 0;

void AbrirCaixa(){
    system("cls");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n ABRINDO CAIXA \n");
    for (int i=0; i<30; i++){
        strcpy(Estaciona[i],"LIVRE");}
    printf("\nQual o valor do estacionamento? ");
    scanf("%f",&Valor);
    fflush(stdin);
    printf("Qual o nome do responsavel? ");
    scanf(" %[^\n]s", Responsavel);
    Iniciou=1;
}

void ClienteChega(){
    int Vaga;
    char Placa[8], Hora[5], Entrada[14];
    system("cls");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n CHEGADA DE CLIENTE \n");
    if (Iniciou){
        printf("\n CAIXA ABERTO Valor/h: %.2f", Valor);
        printf("\n Responsavel: %s\n\n", Responsavel);
        printf("Qual a vaga ocupada? ");
        scanf("%d",&Vaga);
        fflush(stdin);
        printf("Qual a placa do veiculo [7 digitos]? ");
        scanf(" %[^\n]s", Placa);
        strcpy(Entrada,Placa);
        fflush(stdin);
        printf("Qual a hora de entrada [formato nn:nn]? ");
        scanf(" %[^\n]s", Hora);
        strcat(Entrada,"+");
        strcat(Entrada,Hora);
        strcpy(Estaciona[Vaga-1],Entrada);
        printf("Chegada registrada com sucesso!\n");}
    else{
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");}
    system("pause");
}

void ClienteSai(){
    int Vaga;
    char Placa[8], Entrada[14], Hora[3], Min[3];
    int H, M; //hora, minuto e segundo
    system("cls");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n SAIDA DE CLIENTE \n");
    if (Iniciou){
    printf("\n CAIXA ABERTO Valor/h: %.2f", Valor);
    printf("\n Responsavel: %s\n\n", Responsavel);
    printf("Qual a vaga ocupada? ");
    scanf("%d",&Vaga);
    //se vaga LIVRE, houve erro
    strcpy(Entrada,Estaciona[Vaga-1]);
    //Teste
    printf("\n>>>>>>>%s",Entrada);
    for (int i=0; i<7; i++)
    Placa[i] = toupper(Entrada[i]);
    //Teste
    printf("\n>>>>>>>Placa: %s",Placa);
    Hora[0] = Entrada[8];
    Hora[1] = Entrada[9];
    Hora[2] = '\0';
    H = atoi(Hora); // convete string em inteiro
    Min[0] = Entrada[11];
    Min[1] = Entrada[12];
    Min[2] = '\0';
    M = atoi(Min); // convete string em inteiro
    //Teste
    printf("\n>>>>>>>Hora: %d",H);
    printf("\n>>>>>>>Minutos: %d\n",M);} //if (Iniciou)
else{
    printf("\nERRO: Antes eh preciso abrir o caixa!\n");}
system("pause");
}

void FecharCaixa(){

}


int main(){
    int Op;
    do{
        system("cls");
        system("color 80"); // 8 - cinza 0 - preto
        printf("\n >>> Estacionamento <<< \n");
        printf(" >>> Largas Vagas <<< \n");
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
        }while (1);
        switch (Op) {
            case 1: AbrirCaixa(); break;
            case 2: ClienteChega(); break;
            case 3: ClienteSai(); break;
            case 4: FecharCaixa(); break;}
    } while (Op != 4);
    return 0;}