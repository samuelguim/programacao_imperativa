/*
Escrever programa em C para solicitar ao usuário um número e exibir a
tabuada (de multiplicação) desse número até 10.
*/

#include <stdio.h>
int main() {
  int numero;
  int tab = 0;
  printf("Digite um número: ");
  scanf("%d", &numero);
  do {
    printf("\n%dx%d=%d\n", numero, tab, numero * tab);
    tab++;
  } while (tab <= 10);
}
