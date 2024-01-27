/*
Escrever programa em C para solicitar um valor monetário em reais, o câmbio
real - dólar, e exiba o valor em dólar.
*/

#include <stdio.h>
int main() {
  float real, cambio;
  printf ("Quantos reais você tem? ");
  scanf ("%f", &real);
  printf ("Qual é o câmbio (real-dólar) de hoje? ");
  scanf ("%f", &cambio);
  printf ("Você tem %.2f dólares \n", real/cambio);
}
