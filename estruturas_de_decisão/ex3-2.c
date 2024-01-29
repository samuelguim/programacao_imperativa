/*
Para conter o crescimento da quantidade de gatos
abandonados na UFS, e seus consequentes prejuízos, surgiu o
projeto "CastraçãoSolidária", a partir do qual 4 veterinários
experientes e 1 recém formado decidiram efetuar capturas e
castrações todos os dias úteis, sendo os animais capturados
divididos igualitariamente entre os veterinários experientes, e
havendo sobras (não sendo possível uma divisão exata), o
restante fica sob a responsabilidade do 5o veterinário – recém
formado. Por exemplo, se capturados 22 gatos, cada
veterinário experiente fica com 5 castrações, e o recém
formado fica com 2. Se capturados 19, os experientes ficam
com 4 e o formado recentemente fica com 3. Escrever
programa em C para ler número de gatos capturados e exibir a
distribuição das castrações entre os veterinários. Vale
esclarecer que se capturados 4 ou menos gatos, as castrações
ficam sob a responsabilidade de todos os veterinários, em
conjunto. 
*/

#include <stdio.h>

int main (){
  int gatos, vet_exp, vet_rec;
  printf ("Quantos gatos serão castrados? ");
  scanf ("%d", &gatos);
  if (gatos <= 4){
    printf ("Os gatos ficarão sob responsabilidade de todos os veterinários em conjunto.\n");
  }
  else {
    vet_rec = gatos % 4;
    vet_exp = (gatos - vet_rec)/4;
    printf ("%d gatos será(ão) castrado(s) pelo veterinário recém formado.\n", vet_rec);
    printf ("%d gato(s) será(ão) castrado(s) por cada veterinário experiente.\n", vet_exp);
  }
  return 0;
}