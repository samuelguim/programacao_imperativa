/*
Escrever programa para: (a) exibir menu: 1 –
area, 2 – perímetro e 3 – diagonal; (d) ler
medida de lado de um quadrado; (c) exibir
a informação solicitada pelo usuário
conforme opção de menu selecionada.
Deve haver mensagem de erro para o caso do
usuário selecionar opção não existente.
Deve ser modularizado.
*/


#include <stdio.h>
#include <math.h>

int menu (){
  int operacao;
  printf ("1 – area\n");
  printf ("2 – perímetro\n");
  printf ("3 – diagonal\n");
  printf ("Escolha uma opção: ");
  scanf ("%d", &operacao);
  return operacao;
}

void area (float lado){
  printf ("Área do quadrado: %.2f\n", lado*lado);
}

void perimetro (float lado){
  printf ("Perímetro do quadrado: %.2f\n", lado*4);
}

void diagonal (float lado){
  printf ("Diagonal do quadrado: %.2f\n", lado * (sqrt (2)));
}

int main (){
  int operacao;
  float lado;
  operacao = menu ();
  printf ("Digite o lado do quadrado: ");
  scanf ("%f", &lado);
  switch (operacao) {
    case 1 : area (lado); break;
    case 2 : perimetro (lado); break;
    case 3 : diagonal (lado); break;
    default : printf ("OPÇÃO NÃO EXISTE\n");
  }
  return 0;
}