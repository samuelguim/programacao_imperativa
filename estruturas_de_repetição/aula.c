#include <stdio.h>
int main (){
  int numero, cont = 0;
  printf ("Número: ");
  scanf ("%d", &numero);
  while (cont <= 10) {
    printf ("%d x %d = %d\n", numero, cont, numero*cont);
    cont+=2;
  }
  
  return 0;
}
