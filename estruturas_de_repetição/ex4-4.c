/*
Escrever programa , sem aplicar resto de divisão (%)
e valor do quociente (/), para calcular a quantidade
de meses contidos numa dada quantidade de dias.
Considerar que todos os meses são compostos por 30 dias
e desprezar o montante de dias que não formam pelo menos
um mês completo (resto).
*/

#include <stdio.h>

int main (){
  int dias, meses, cont;
  printf ("Digite a quantidade de dias: ");
  scanf ("%d", &dias);
  while (dias >= 30) {
    while (cont <=30) {
      dias = dias - 1;
      cont++;
    }
    cont = 0;
    meses++;
  }
  printf ("Meses: %d\n", meses);
  return 0;
}