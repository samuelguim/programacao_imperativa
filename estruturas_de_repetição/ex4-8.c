/*

*/

#include <stdio.h>

int main (){
  int numero, cont_x, cont_y;
  printf ("Digite um número entre 0 e 40: ");
  scanf ("%d", &numero);
  if (numero >= 0 && numero <= 40) {
    while (cont_y <= numero) {
      cont_y++;
      cont_x = 1;
      while (cont_x < cont_y) {
        printf ("%d", cont_x);
        cont_x++; }
      printf ("\n"); } }
  else {
    printf ("O número escolhido é menor que 0 ou maior que 40"); }
}