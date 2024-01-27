/*
Criar um programa em C que converta a temperatura de Celsius para
Fahrenheit. Solicite ao usuário a temperatura em Celsius e exiba o resultado em
Fahrenheit. Pesquise e escreva, como comentário, a regra de conversão usada.
*/

#include <stdio.h>
int main() {
  float celsius;
  printf ("Digite uma temperatura em graus Celsius: \n");
  scanf ("%f", &celsius);
  printf ("A temperatura informada equivale a %.2f em Fahrenheit.", 1.8*celsius+32);
}
