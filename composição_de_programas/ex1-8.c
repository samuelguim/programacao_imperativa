/*
Escrever um programa em C para calcular a área de um retângulo. O usuário
deve fornecer o comprimento e a largura desse.
*/

#include <stdio.h>
int main() {
  float comp, larg;
  printf("Qual é o comprimento do retângulo? ");
  scanf("%f", &comp);
  printf("Qual é a largura do retângulo? ");
  scanf("%f", &larg);
  printf("O retângulo tem %.2f de área\n", comp * larg);
}
