#include <stdio.h>
int main () {
  float peso_atual, peso_alm;
  printf ("Qual é o seu peso atual? ");
  scanf ("%f", &peso_atual);
  printf ("Qual é o peso almejado? ");
  scanf ("%f", &peso_alm);
  if (peso_atual > peso_alm) {
    printf ("");
  }
  else {
    printf ("O peso atual é maior ou igual ao peso almejado.\n");
  }
  return 0;
}