/*
5. Escrever um programa em C para ler o raio de um círculo e exibir em
tela a área desse (círculo) usando a fórmula: Área = π . raio2. Usar um
módulo/função para cálculo da área, outro módulo/função para cálculo do
quadrado. E usar uma constante para definição de π. Recomenda-se o
uso de função e/ou constante nativa, se houver.
*/

#include <stdio.h>
#include <math.h>

float quad (float n) {
  return (n*n);
}

float area (float c) {
return (M_PI*(quad (c)));
}

int main () {
  float raio;
  printf ("Digite o raio do círculo: ");
  scanf ("%f", &raio);
  raio = area (raio);
  printf ("A área do círculo é de %.2f\n", raio);
  return 0;
}