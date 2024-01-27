/*
8.Escrever um programa em C para ler um valor V em reais, taxa de
câmbio fixa de dólar e taxa de câmbio fixa de euro e exibir em tela os
correspondentes a V em dólar e em euro. Para tanto, criar função F em que
dados valor e taxa de câmbio, retorna o valor convertido. Criar módulo com
aplicação de F, parâmetros de entrada e dois parâmetros de saída: valor em
dólar e valor em euro.
*/

#include <stdio.h>

float mensal (float a, float b, float c, float *v_dolar, float *v_euro) {
  *v_dolar = a/b;
  *v_euro = a/c;
}

int main (){
  float v_real, cambio_d, cambio_e, v_dolar, v_euro;
  printf ("Digite o valor a ser convertido: ");
  scanf ("%f", &v_real);
  printf ("Digite a taxa de câmbio fixa de dólar: ");
  scanf ("%f", &cambio_d);
  printf ("Digite a taxa de câmbio fixa de euro: ");
  scanf ("%f", &cambio_e);

  mensal (v_real, cambio_d, cambio_e, &v_dolar, &v_euro);

  printf ("Esse é o valor em dólar: %.2f\n", v_dolar);
  printf ("Esse é o valor em euro: %.2f\n", v_euro);
}