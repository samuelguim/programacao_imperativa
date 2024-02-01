/*
Escrever programa para exibir menu: U – unidade, D –
dezena, C – centena, M – unidade de milhar e Z –
dezena de milhar; ler um número de 0 a 99.999 e deste
identificar a unidade, ou a dezena, ou a centena, ou a
unidade de milhar, ou a centena de milhar; conforme a
opção selecionada.
Deve funcionar para o caso do usuário pressionar letras
maiúsculas ou minúsculas.
Deve ser aplicado switch-case.
Deve haver mensagem de erro para o caso do usuário
selecionar opção não existente.
Deve ser modularizado.
*/

#include <stdio.h>
#include <ctype.h>

char menu (){
  char operacao;
  printf ("U – unidade\n");
  printf ("D – dezena\n");
  printf ("C – cenena\n");
  printf ("M – unidade de milhar\n");
  printf ("Z – dezena de milhar\n");
  printf ("Escolha uma opção: ");
  scanf ("%c", &operacao);
  return operacao;
}

void unidade (int numero){
  numero = numero % 10;
  printf ("Unidade do número escolhido: %d\n", numero);
}

void dezena (int numero){
  numero = (numero/10) % 10;
  printf ("Dezena do número escolhido: %d\n", numero);
}

void centena (int numero){
  numero = (numero/100) % 10;
  printf ("Centena do número escolhido: %d\n", numero);
}

void milhar (int numero){
  numero = (numero/1000) % 10;
  printf ("Milhar do número escolhido: %d\n", numero);
}

void d_milhar (int numero){
  numero = (numero/10000) % 10;
  printf ("Dezena de milhar do número escolhido: %d\n", numero);
}

int main (){
  char operacao;
  int numero;
  operacao = menu ();
  printf ("Digite um número de 0 a 99.000: ");
  scanf ("%d", &numero);
  if (numero >= 0 && numero <= 99999){
    operacao = toupper(operacao);
    switch (operacao) {
      case 'U' : unidade (numero); break;
      case 'D' : dezena (numero); break;
      case 'C' : centena (numero); break;
      case 'M' : milhar (numero); break;
      case 'Z' : d_milhar (numero); break;
      default : printf ("OPÇÃO NÃO EXISTE\n");
    }
  }
  else {
    printf ("O número escolhido é menor que 0 ou maior que 99.000.\n");
  }
  return 0;
}