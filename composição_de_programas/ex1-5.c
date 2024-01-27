/*
Escrever programa em C para solicitar ao usuário a distância que ele pretende
correr e sua velocidade média esperada. Exibir o tempo estimado de exercício
(corrida).
*/

#include <stdio.h>
int main () {
  float dist, vel;
  printf ("Qual será a distância (em km) percorrida? ");
  scanf ("%f", &dist);
  printf ("Qual será a velocidade média (em km/h) estimada? ");
  scanf ("%f", &vel);
  printf ("Você concluirá o percurso em %.2f horas \n", dist/vel);
}
