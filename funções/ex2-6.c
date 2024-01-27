/*
6.Escrever um programa em C para ler peso em kg e altura em m. Calcular
e exibir o IMC da pessoa considerando IMC = peso / altura2. Para cálculo
de IMC usar função, e nessa aplicar função de cálculo da potência (seja
definida pelo programação ou nativa).
*/

#include <stdio.h>

float quad (float n){
  return n*n;
}

float calc (float p, float a){
  return p/quad (a);
}

int main (){
  float peso, altura, imc;
  printf ("Digite o seu peso (em quilogramas): ");
  scanf ("%f", &peso);
  printf ("Digite a sua altura (em metros): ");
  scanf ("%f", &altura);
  imc = calc (peso, altura);
  printf ("O seu IMC é: %.2f\n", imc);
  return 0;
}