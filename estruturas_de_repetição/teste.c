#include <stdio.h>

char menu (){
  char decis;
  printf ("Deseja continuar? (S - N)");
  scanf (" %c", &decis);
  switch (decis) {
    case 'S':
    case 's': return 'S'; break;
    case 'N':
    case 'n': return 'N'; break;
    default: printf ("Não existe\n"); break;
  }
}

int main (){
  int ph;
  char decisao;
  printf ("Digite o PH de cada solução: \n");
  do {
    scanf ("%d", &ph);
    if (ph == 7) {
      printf ("NEUTRO\n"); }
    else {
      if (ph >7) {
        printf ("BASICO\n"); }
      else {
        if (ph >= 0) {
          printf ("ACIDO\n"); }
        else {
          break; }
      }
    }
    decisao = menu ();
  }
  while (decisao == 'S');
}