/*
corrigir (número de aprovados nao ta aparecendo)
*/

#include <stdio.h>

int main () {
  int port, mat, aprovados;
  float red;
  printf ("Digite os resultados dos inscritos: \n");
  do {
    scanf ("%d", &port);
    if (port >= 0) {
      scanf ("%d", &mat);
      scanf ("%f", &red);
    }
    else {
      break;
    }
    if (port >= 40 && mat >= 21 && red >= 7){
      aprovados++;
    }
    else {
      aprovados = aprovados;
    }
  }
  while (port >=0);
  printf ("\n%d\n", aprovados);
}