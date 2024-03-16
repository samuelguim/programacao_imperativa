/*
Escrever programa para ler uma palavra com até 20
caracteres e exibi-la com letras maiúsculas.
Exemplos: dado brasileiro, retorna BRASILEIRO.
Dado Nordeste, retorna NORDESTE
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char Palavra [21];
  printf ("Escreva uma palavra de até 20 caracteres: ");
  scanf ("%s", Palavra);
  for (int i = 1; i <= strlen(Palavra); i++) {
    printf ("%c", toupper(Palavra[i-1]));
  }
  printf ("\n");
  return 0;
}