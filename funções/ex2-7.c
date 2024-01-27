/*
7.Escrever um programa em C sobre investimento. Deve ser efetuada a
leitura do valor inicial investido, do valor investido mensalmente e do tempo
de investimento (desconsiderar juros) e retornar o valor final (montante) e o
valor do rendimento (montante – valor inicial investido). Deve ser aplicado
um módulo(função) com dois parâmetros de saída.
*/

#include <stdio.h>

float mensal (float a, float b) {
  return a*b;
}

int main (){
  float inicial, valor_mensal, tempo , montante;
  printf ("Digite o valor incicial do seu investimento: ");
  scanf ("%f", &inicial);
  printf ("Digite o valor investido mensalmente no seu investimento: ");
  scanf ("%f", &valor_mensal);
  printf ("Digite por quantos meses você investiu: ");
  scanf ("%f", &tempo);
  montante = inicial + mensal (valor_mensal, tempo);
  printf ("Esse é o seu valor final: %.2f\n", montante);
}
