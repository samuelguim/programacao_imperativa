#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char Estaciona[30][14];
/*30 vagas, mantem placa com 7 caracteres, sinal
+ e 5 caracteres para hora */
int Frequencia[30];
float Valor, Lucro[30];
char Responsavel[21], Iniciou = 0;

void AbrirCaixa(){
    system("clear");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n ABRINDO CAIXA \n");

    for (int i=0; i<30; i++){
        Frequencia[i] = 0;}

    for (int j=0; j<30; j++){
        Lucro[j] = 0;}

    for (int k=0; k<30; k++){
        strcpy(Estaciona[k],"LIVRE");}

    printf("\nQual o valor do estacionamento? ");
    scanf("%f",&Valor);
    fflush(stdin);
    printf("Qual o nome do responsavel? ");
    scanf(" %[^\n]s", Responsavel);
    Iniciou=1;
}

void ClienteChega(){
    int Vaga;
    char Placa[8], Hora[5], Entrada[14], HoraConversao[2], H1, Frequencia[30];
    system("clear");
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

        HoraConversao[0] = Hora[0];
        HoraConversao[1] = Hora[1];
        HoraConversao[2] = '\0';
        H1 = atoi(HoraConversao); // convete string em inteiro

        Frequencia[Vaga] = H1;

        printf("Chegada registrada com sucesso!\n");}
    else{
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");}

    system("read -p 'Pressione Enter para continuar...' var");
}

void ClienteSai(){
    int Vaga;
    char Placa[8], Entrada[14], Hora[3], Min[3], HorarioSaida[5], HoraSaida[3], MinSaida[3];
    int H, M, Hsaida, Msaida; //hora, minuto e segundo
    float ValorAPagar, ValorPago;
    system("clear");
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
        for (int i=0; i<7; i++){
            Placa[i] = toupper(Entrada[i]);}
        Placa[8]='\0';
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
        printf("\n>>>>>>>Minutos: %d\n",M);
        

        printf("\n\nQual a hora de saída [formato nn:nn]? ");
        scanf(" %[^\n]s", HorarioSaida);
        HoraSaida[0] = HorarioSaida[0];
        HoraSaida[1] = HorarioSaida[1];
        HoraSaida[2] = '\0';
        Hsaida = atoi(HoraSaida); // convete string em inteiro
        MinSaida[0] = HorarioSaida[3];
        MinSaida[1] = HorarioSaida[4];
        MinSaida[2] = '\0';
        Msaida = atoi(MinSaida); // convete string em inteiro

        ValorAPagar = ((Hsaida-H)*Valor) + (Msaida-M * (Valor/60));
        printf("\nValor a pagar: R$%.2f", ValorAPagar);
        printf("\nQual foi o valor pago? R$");
        scanf("%f", &ValorPago);
        printf ("\nTroco: R$%.2f", ValorAPagar-ValorPago);
        Lucro[Vaga] = ValorAPagar;
        strcpy(Estaciona[Vaga],"LIVRE");} //if (Iniciou)
    
    else{
    printf("\nERRO: Antes eh preciso abrir o caixa!\n");}
    system("read -p 'Pressione Enter para continuar...' var");
}

void FecharCaixa(){
    int Total=0, Frequencia[30];
    float Soma, Lucro[30];
    system("clear");
    system("color 80"); // 8 - cinza 0 - preto
    printf("\n >>> Estacionamento <<< \n");
    printf(" >>> Largas Vagas <<< \n");
    printf("\n FECHANDO CAIXA \n");
    if (Iniciou){
        printf("\n Responsavel: %s\n\n", Responsavel);

        printf(">>>>>>> Frequência de entrada em cada horário: ");
        for (int i = 6; i < 20; i++) {
            for (int j = 0 ; j < 30; j++) {
                if (Frequencia[j] == i) {
                    Total++;} }
            printf ("\n%d Horas: %d entrada(s).", i, Total);
            Total = 0;
        }
        
        for (int k = 0; k < 30; k++){
            Soma = Soma + Lucro[k];
        }
        printf("\n>>>>>>>Soma dos valores recebidos ao longo do dia: R$%.2f.\n", Soma);

    }
    else{
        printf("\nERRO: Antes eh preciso abrir o caixa!\n");}
}


int main(){
    int Op;
    do{
        system("clear");
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