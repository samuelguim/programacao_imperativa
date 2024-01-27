/*
Para a manutenção da saúde é indispensável que as
pessoas mantenham o peso ideal e, assim, evitem a
obesidade. Escrever programa para ler: peso atual, peso
ideal e perda mensal; e exibir em quantos dias a pessoa
alcançará o peso ideal.
*/

#include <stdio.h>
int main() {
  float peso, peso_ideal, perda_mensal;
  printf("Qual é o seu peso atual? ");
  scanf("%f", &peso);
  printf("\nQual é o seu peso ideal? ");
  scanf("%f", &peso_ideal);
  printf("\nQuantos quilos você perderá mensalmente? ");
  scanf("%f", &perda_mensal);
  printf(
      "\n☆☆☆☆☆☆☆☆☆☆☆\nVocê precisará de %.0f dias para chegar ao seu peso ideal.\n", ((peso - peso_ideal) / perda_mensal) * 30);
}

