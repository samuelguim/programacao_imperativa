#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Frz, Crc;

struct TpFreezer {
  char Marca[5];
  float Capacidade, Garantia, Economia, Temperatura;
};

struct TpFreezer Freezer[6] = {
        {"Deia\0", 385, 12, 35.9, -28},
        {"Sul\0", 534, 121, 72.1, -18},
        {"NSul\0", 309, 12, 46.2, -18},
        {"Frio\0", 546, 3, 74.3, -18},
        {"Fri\0", 503, 24, 78, -22},
        {"Lux\0", 477, 12, 90, -18},
};

void SelecionaFreezer(int *F){
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

void SelecionaCaracteristica(int *C){
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

void AlteraDado (){
  system("clear");
  float Alteracao;
  SelecionaFreezer(&Frz);
  SelecionaCaracteristica(&Crc);
  printf("Digite um valor para substituir: ");
  scanf("%f", &Alteracao);
  if (Crc == 0) {
    Freezer[Frz].Capacidade = Alteracao;
  }
  if (Crc == 1) {
    Freezer[Frz].Garantia = Alteracao;
  }
  if (Crc == 2) {
    Freezer[Frz].Economia = Alteracao;
  }
  if (Crc == 3) {
    Freezer[Frz].Temperatura = Alteracao;
  }
}

int main(){
  AlteraDado ();
  printf("Capacidade: %.1f\n", Freezer[Frz].Capacidade);
  printf("Garantia: %.0f\n", Freezer[Frz].Garantia);
  printf("Economia: %.1f\n", Freezer[Frz].Economia);
  printf("Temperatura: %.1f\n", Freezer[Frz].Temperatura);
  return 0;
}
