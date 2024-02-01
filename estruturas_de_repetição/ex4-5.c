/*

REFAZER (O programa ainda mostra acido depois do -1)

Carla é uma profissional muito dedicada! Ela é responsável por analisar
o pH de várias substâncias e determinar se elas são ácidas, básicas ou
neutras. Ela não para enquanto não tiver terminado de analisar todas 
as soluções pendentes.
Escreva um programa para ajudar a nossa querida Carla no seu trabalho. 
O programa vai receber como entrada uma sequência de números, cada um 
em uma linha, representando o pH de cada solução. A última entrada vai
ser o número -1, indicando que não há mais soluções para serem analisadas
e o programa pode encerrar sua execução
Para cada solução, o programa vai determinar a sua acidez: ACIDA (pH menor que 7), 
BASICA (pH maior que 7), ou NEUTRA (pH igual a 7).
E aí, você vai ajudar a Carla? Bom trabalho!
Formato de entrada
A entrada é composta por diferentes números, cada um em uma linha. O último número 
sempre será -1.0..
Formato de saída
A saída terá as palavras ACIDA, BASICA e/ou NEUTRA, escritas em maiúsculas e sem acentos.
Note que quando a entrada for o número -1, nada a mais deve ser impresso na tela
Exemplos de:

Entrada   Saída
1         ACIDA
1         ACIDA
1         ACIDA
2         ACIDA
1         ACIDA
3         ACIDA
-1        ACIDA

*/

#include <stdio.h>

int main (){
  int ph;
  printf ("Digite o PH de cada solução: \n");
  do {
    scanf ("%d", &ph);
    if (ph == 7) {
      printf ("NEUTRO\n");
    }
    else {
      if (ph >=7) {
        printf ("BASICO\n");
      }
      else {
        printf ("ACIDO\n");
      }
    }
  }
  while (ph != -1);
}