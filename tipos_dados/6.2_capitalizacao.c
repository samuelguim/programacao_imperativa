/*
Escrever programa para ler um nome e, independente
de como este foi escrito, exibir a inicial maiúscula e o
restante minúscula.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char Palavra [21];
  printf ("Escreva uma palavra: ");
  scanf ("%s", Palavra);
  printf ("%c", toupper (Palavra[0]));
  for (int i = 2; i <= strlen(Palavra); i++) {
    printf ("%c", tolower(Palavra[i-1]));
  }
  return 0;
}