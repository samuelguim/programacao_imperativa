/*

*/

#include <stdio.h>

int menu () {
  char selecao;
  printf ("Deseja continuar? (S - SIM | N - NÃO)\n");
  scanf ("%c", &selecao);
  switch (selecao) {
    case 'A':
    case 'a': return 1; break;
    case 'B':
    case 'b': return 0; break;
    default : printf ("Opção não existe"); return 0; break;
  }
}

int main () {
  int port, mat, aprovados, continuar;
  float red;
  printf ("Digite os resultados dos inscritos: \n");
  do {
    scanf ("%d", &port);
    scanf ("%d", &mat);
    scanf ("%f", &red);
    if (port >= 40 && mat >= 21 && red >= 7){
      aprovados++; }
    else {
      aprovados = aprovados; }
    continuar = menu();
  }
  while (continuar = 1);
  printf ("\n%d\n", aprovados);
}