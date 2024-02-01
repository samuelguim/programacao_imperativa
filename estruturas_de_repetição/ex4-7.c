/*

*/

#include <stdio.h>

int menu () {
  char selecao;
  printf ("Deseja sair? (S - SIM | N - NÃO)\n");
  scanf (" %c", &selecao);
  switch (selecao) {
    case 's':
    case 'S': return 0; break;
    case 'n':
    case 'N': return 1; break;
    default : printf ("Opção não existe"); return 0; break;
  }
}

int main () {
  int port, mat, aprovados, continuar;
  float red;
  printf ("Digite os resultados dos inscritos: \n");
  continuar = 1;
  while (continuar == 1) {
    scanf ("%d", &port);
    scanf ("%d", &mat);
    scanf ("%f", &red);
    if (port >= 40 && mat >= 21 && red >= 7){
      aprovados++; }
    else {
      aprovados = aprovados; }
    continuar = menu();
  }
  printf ("\n%d\n", aprovados);
}