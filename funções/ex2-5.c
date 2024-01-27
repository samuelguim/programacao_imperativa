/*
5. Escrever um programa em C para ler o raio de um círculo e exibir em
tela a área desse (círculo) usando a fórmula: Área = π . raio2. Usar um
módulo/função para cálculo da área, outro módulo/função para cálculo do
quadrado. E usar uma constante para definição de π. Recomenda-se o
uso de função e/ou constante nativa, se houver.
*/

#include <stdio.h>
#include <math.h>

float area (float c) {
return (M_PI*(c*c));
}

int main () {
  float raio;
  printf ("Digite a área do círculo: ");
  scanf ("%f", &raio);
  raio = area (raio);
  printf ("A área do círculo é de %.2f\n", raio);
  return 0;
}