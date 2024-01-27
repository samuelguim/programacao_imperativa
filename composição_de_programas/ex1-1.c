/*
Faça um programa que leia um número inteiro e imprima o seu antecessor e o seu sucessor.
*/

#include <stdio.h>
int main () {
  int numero;
  printf ("Qual é o número? ");
  scanf ("%d", &numero);
  printf ("%d %d \n", numero-1, numero+1);
}
