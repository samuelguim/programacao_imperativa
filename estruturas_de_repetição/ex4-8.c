/*

*/

#include <stdio.h>

int main (){
  int numero, cont_linha, cont_coluna;
  printf ("Digite um número entre 0 e 40: ");
  scanf ("%d", &numero);
  if (numero >= 0 && numero <= 40) {
    while (cont_coluna <= numero) {
      cont_coluna++;
      cont_linha = 1;
      while (cont_linha < cont_coluna) {
        printf ("%d", cont_linha);
        cont_linha++;
      }
      printf ("\n");
    }
  }
  else {
    printf ("O número escolhido é menor que 0 ou maior que 40");
  }
}