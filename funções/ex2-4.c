/*
4. Escrever um programa em C para ler uma temperatura em Celsius C e
a retornar em Fahrenheit e em Kelvin. Fórmulas de conversão para
Fahrenheit: F = (C * 9/5) + 32; para Kelvin: K = C + 273,5.
Criar uma função para cada conversão.
*/

#include <stdio.h>

float fah (float temp){
return temp * 9/5 + 32;
}

float kel (float temp){
return temp + 273.5;
}

int main () {
  float celsius, fahrenheit, kelvin;
  printf ("Digite uma temperatura em Celsius: ");
  scanf ("%f", &celsius);
  fahrenheit = fah (celsius);
  kelvin = kel (celsius);
  printf ("Temperatura em Fahrenheit: %.2f\n", fahrenheit);
  printf ("Temperatura em Kelvin: %.2f\n", kelvin);
  return 0;
}