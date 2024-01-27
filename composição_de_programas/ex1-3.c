/*
vacinas periódicas
*/

#include <stdio.h>
int main () {
  int ano, period;
  printf ("Em qual ano a 1ª dose da vacina foi aplicada? ");
  scanf ("%d", &ano);
  printf ("\nQual é a periodicidade da vacina? ");
  scanf ("%d", &period);
  printf ("\nAs próximas doses serão tomadas em: \n%d\n%d\n%d \n", ano+period, ano+period*2, ano+period*3);
}
