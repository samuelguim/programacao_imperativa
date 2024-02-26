/*
(Adaptado do 3º Exercício Resolvido – Cap. 5 – Fund.
Da Prog. De Computadores) Faça um programa
para ler N números inteiros e positivos e de cada
um desses apresente o fatorial. O cálculo do fatorial
deve ser efetuado por meio de função elaborada
pelo programador.
*/


#include <stdio.h>

int fatorial (int numero) {
  int j, f = 1;
  for (j = 1; j <= numero; j++) {
    f = f*j;
  }
  return f;
}

int main () {
  int numero, n, fat;
  printf ("De quantos números você deseja calcular o fatorial? ");
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++) {
    printf ("Número: ");
    scanf ("%d", &numero);
    if (numero >= 0) {
      fat = fatorial (numero);
      printf ("%d! = %d\n", numero, fat);
    }
    else {
      printf ("O número não satisfaz às condições\n");
    }
  }
  return 0;
}