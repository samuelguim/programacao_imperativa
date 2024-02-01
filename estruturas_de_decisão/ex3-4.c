/*
Faça um programa para ler um número
inteiro, positivo de três dígitos, e gerar outro
número formado pelos dígitos invertidos do
número lido. (Ex: Numero Lido = 123;
Numero Gerado = 321) Em seguida informar:
NÚMERO GERADO MAIOR QUE NÚMERO LIDO ou
NÚMERO LIDO MAIOR QUE NÚMERO GERADO, ou
ainda, NÚMERO GERADO IGUAL AO NÚMERO
LIDO.
*/

#include <stdio.h>

int f_invert (int numero) {
  int u, d, c, total;
  u = numero % 10;
  d = (numero / 10) % 10;
  c = (numero / 100) % 100;
  total = (u*100)+(d*10)+(c*1);
  return total;
}

int main () {
  int numero, invertido;
  printf ("Digite um número inteiro positivo de 3 dígitos: ");
  scanf ("%d", &numero);
  if (numero >= 100 && numero <= 999) {
    invertido = f_invert (numero);
    printf ("Número gerado: %d\n", invertido);
    if (invertido == numero) {
      printf ("NÚMERO GERADO IGUAL AO NÚMERO LIDO\n");
    }
    else {
      if (numero > invertido) {
        printf ("NÚMERO LIDO MAIOR QUE NÚMERO GERADO\n");
      }
      else {
        printf ("NÚMERO GERADO MAIOR QUE NÚMERO LIDO\n");
      }
    }
  }
  else {
    printf ("O número não satisfaz os requisitos.\n");
  }
  return 0;
}