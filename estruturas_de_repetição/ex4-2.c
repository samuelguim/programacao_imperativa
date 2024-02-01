/*

int main (){
  float Meta, Doacao, Soma = 0;
  printf ("Meta da vaquinha: ");
  scanf ("%f", &Meta);
  do {
    printf ("Valor da doação: ");
    scanf ("%f", &Doacao);
    Soma = Soma + Doacao; }
  while (Soma < Meta);
  printf ("A meta da vaquinha foi alcançada\n");
  return 0;
}

Ajustar o código dado de forma que seja identificado também quando a
meta da vaquinha foi ultrapassada, passando a haver duas
mensagens de retorno ao usuário, e para, sempre que houver uma
doação, exibir o valor parcial alcançado.
*/

#include <stdio.h>

int main (){
  float Meta, Doacao, Soma = 0;
  printf ("Meta da vaquinha: ");
  scanf ("%f", &Meta);
  do {
    printf ("Valor da doação: ");
    scanf ("%f", &Doacao);
    Soma = Soma + Doacao;
    printf ("Valor parcial alcançado: %.2f\n\n", Soma); }
  while (Soma < Meta);
  if (Soma == Meta) {
    printf ("A meta da vaquinha foi alcançada.\n"); }
  else {
    printf ("Valor da vaquinha ultrapassado em %.2f reais.\n", Soma-Meta); }
  
  return 0;
}