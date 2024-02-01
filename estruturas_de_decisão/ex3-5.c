/*
Faça um programa para verificar se
determinado número inteiro lido N é divisível
por A ou B, mas não simultaneamente pelos
dois valores dados. São A e B, bem como N,
dados pelo usuário. Atendendo a condição
estabelecida, emitir mensagem “ATENDE
CONDIÇÃO”; caso contrário, exibir: “NÃO
ATENDE CONDIÇÃO”.
*/

#include <stdio.h>
int main (){
  int a, b, n;
  printf ("Digite o número A: ");
  scanf ("%d", &a);
  printf ("Digite o número B: ");
  scanf ("%d", &b);
  printf ("Digite o número N: ");
  scanf ("%d", &n);

  if (a % n == 0 && b % n == 0){
    printf ("NÃO ATENDE CONDIÇÃO\n");
  }
  else {
    if (a % n == 0 || b % n == 0) {
      printf ("ATENDE CONDIÇÃO\n");
    }
    else {
      printf ("NÃO ATENDE CONDIÇÃO\n");
    }
  }
  return: 0;
}