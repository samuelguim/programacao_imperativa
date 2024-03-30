#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float M[4][6]={{385,534,309,546,503,477},
        {12, 121, 12, 3, 24, 12},
        {35.9, 72.1, 46.2,74.3,78,90},
        {-28, -18, -18, -18, -22, -18}};

int Frz, Crc;

void ExibeMatriz(float Matriz[][6],int L,int C){
  system ("clear");
  printf("                      Deia   Sul  NSul  Frio   Fri   Lux \n");
  for(int i=0;i<L;i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) "); 
    for (int j=0; j<C; j++)
      printf("%6.1f",Matriz[i][j]);
    printf("\n");}};

void ExibeColuna(float Matriz[][6],int L,int C){
  for(int i=0;i<L;i++){
    if (i==0) printf("Capacidade (litros) ");
    if (i==1) printf("Garantia (meses)    ");
    if (i==2) printf("Economia (KWh/mes)  ");
    if (i==3) printf("Temperatura Min (C) ");
    printf("%6.1f\n",Matriz[i][C]);}}

void ExibeLinha(float Matriz[][6],int L,int C){
  printf("Deia   Sul  NSul  Frio   Fri   Lux \n");
  for(int i=0;i<C;i++)
    printf("%.1f ",Matriz[L][i]);
  printf("\n");}

void SelecionaFreezer(float Matriz[][6],int *F){
  printf("Selecione o freezer desejado:\n");
  printf("1 - Deia\n");
  printf("2 - Sul\n");
  printf("3 - NSul\n");
  printf("4 - Frio\n");
  printf("5 - Fri\n");
  printf("6 - Lux\n\n");
  printf("Opcao: ");
  int Op;
  scanf("%d",&Op);
  *F=Op-1;};

void SelecionaCaracteristica(float Matriz[][6],int *C){
  system("clear");
  printf("Caracteristica desejado\n");
  printf("1 - Capacidade (litros)\n");
  printf("2 - Garantia (meses)\n");
  printf("3 - Economia(kWh/mes)\n");
  printf("4 - Temperatura Minima (Celsius)\n");
  printf("Opcao: ");
  int Op;
  scanf("%d",&Op);
  *C=Op-1;};

void AlteraDado (float Matriz [][6]){
  float Alteracao;
  SelecionaFreezer(M,&Frz);
  SelecionaCaracteristica(M,&Crc);
  printf("Digite um valor para substituir: ");
  scanf("%f", &Alteracao);
  M[Crc][Frz] = Alteracao;
}

void MelhorCaracteristica (float Matriz [][6], int Caracteristica){
  system("clear");
  float MelhorCar = 0;
  int i;
  char MelhorFrz [5];
  for (i=0; i<6; i++){
    if (Matriz [Caracteristica][i] > MelhorCar) {
      MelhorCar = Matriz[0][i];
      if (i==0) strcpy(MelhorFrz,"Deia");
      if (i==1) strcpy(MelhorFrz,"Sul");
      if (i==2) strcpy(MelhorFrz,"Nsul");
      if (i==3) strcpy(MelhorFrz,"Frio");
      if (i==4) strcpy(MelhorFrz,"Fri");
      if (i==5) strcpy(MelhorFrz,"Lux");
    }
  }
  printf ("O melhor freezer em capacidade é o %s e tem %.1f de capacidade.\n", MelhorFrz, MelhorCar);
}

int main(){
  do{
    system("clear");
    printf(">>> Pesquisa Freezer <<<\n\n");
    printf("Selecione a opcao desejada:\n");
    printf("1 - Exibir Levantamento\n");
    printf("2 - Dados de um Freezer\n");
    printf("3 - Dados de uma Caracteristica\n");
    printf("4 - Alterar Dado\n");
    printf("5 - Melhor Freezer em Capacidade\n");
    printf("6 - Melhor Freezer em Garantia\n");
    printf("7 - Melhor Freezer em Economia\n");
    printf("8 - Melhor Freezer em Temperatura\n");
    printf("9 - Sair\n");
    int Op;
    scanf("%d",&Op);
    switch (Op){
      case 1: ExibeMatriz(M,4,6);
              system("read -p 'Pressione Enter para continuar...' var");
              break;
      case 2: SelecionaFreezer(M,&Frz);
              ExibeColuna(M,4,Frz);
              system("read -p 'Pressione Enter para continuar...' var");
              break;
      case 3: SelecionaCaracteristica(M,&Crc);
              ExibeLinha(M,Crc,6);
              system("read -p 'Pressione Enter para continuar...' var");
              break;
      case 4: AlteraDado(M);
              system("read -p 'Pressione Enter para continuar...' var");
              break; 
      case 5: MelhorCaracteristica (M, 0);
              system("read -p 'Pressione Enter para continuar...' var");
              break;
      case 6: MelhorCaracteristica (M, 1);
              system("read -p 'Pressione Enter para continuar...' var");
              break;
      case 7: MelhorCaracteristica (M, 2);
              system("read -p 'Pressione Enter para continuar...' var");
              break;
      case 8: MelhorCaracteristica (M, 3);
              system("read -p 'Pressione Enter para continuar...' var");
              break;
      case 9: break;}
      if (Op==9)
        break;}
  while (1);
  return 0;
}
