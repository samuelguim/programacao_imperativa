/*
1. Há pessoas que precisam fazer tratamento de saúde contínuo (em
comprimidos), a exemplo de reposição hormonal. Sabendo que uma
pessoa deve fazer uso de X comprimidos ao mês e que em cada caixa
desse há N unidades (comprimidos); escrever um programa em C
onde se lê X e N e é exibido o número de caixas a serem adquiridas.
*/

#include <stdio.h>
#include <math.h>

int caixas (int x){
  int c;
  if (30 % x == 0){
    c = 30/x;
  }
  else {
    c = (30/x)+1;
  return c;
  }
}

int main (){
  int x, n;
  printf ("Qual é o número de comprimidos por caixa? ");
  scanf ("%d", &x);
  n = caixas (x);
  if (n > 1){
    printf ("%d caixas devem ser compradas.\n", n);
  }
  else{
    printf ("%d caixa deve ser comprada.\n", n);
  }
  return 0;
}
