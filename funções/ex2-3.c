/*
3. Escrever programa em C para ler um
número N e retornar N3 (N ao cubo),
aplicando função (que calcula cubo).
*/

#include <stdio.h>

int cubo (int c) {
return (c*c*c);
}

int main () {
  int n;
  printf ("Digite um número para obter o seu cubo: ");
  scanf ("%d", &n);
  n = cubo (n);
  printf ("%d\n", n);
  return 0;
}
