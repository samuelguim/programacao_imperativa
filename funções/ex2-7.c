/*
7.Escrever um programa em C sobre investimento. Deve ser efetuada a
leitura do valor inicial investido, do valor investido mensalmente e do tempo
de investimento (desconsiderar juros) e retornar o valor final (montante) e o
valor do rendimento (montante – valor inicial investido). Deve ser aplicado
um módulo(função) com dois parâmetros de saída.
*/

#include <stdio.h>

float mensal (float a, float b, float c, float *v_final, float *rendimento) {
  *v_final = a+(b*c);
  *rendimento = *v_final - a ;
}

int main (){
  float v_inicial, v_mensal, temp, v_final, rendimento;
  printf ("Digite o valor incicial do seu investimento: ");
  scanf ("%f", &v_inicial);
  printf ("Digite o valor investido mensalmente: ");
  scanf ("%f", &v_mensal);
  printf ("Digite por quantos meses você investiu: ");
  scanf ("%f", &temp);

  mensal (v_inicial, v_mensal, temp, &v_final, &rendimento);

  printf ("Esse é o seu valor final: %.2f\n", v_final);
  printf ("Esse foi o seu rendimento: %.2f\n", rendimento);
}
