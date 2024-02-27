/*
Escrever programa para ler o nome de uma pessoa,
composto por nome e sobrenome (entre nome e
sobrenome há um espaço em branco). E exibir,
sobrenome em maiúsculo, seguido de vírgula e do nome
da pessoa. Efetuar essa operação para tantas entradas quantas
o usuário desejar.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
  char Completo [31], Nome [16], Sobrenome [16];
  int espaco;
  printf ("Digite o seu nome e sobrenome: ");
  fgets (Completo, 31, stdin);
  
  for (int i = 1; i <= strlen(Completo); i++) {
    if (Completo[i-1] != ' ') {
      Nome[i-1] = Completo [i-1];
    } 
    else {
      espaco = i-1;
      break;
    }
  printf ("%s", Nome);
  }
  return 0;
}