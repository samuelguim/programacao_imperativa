/*
screver programa para ler as três notas de
um aluno, calcular a média deste (média
ponderada: primeira nota com peso 1,
segunda nota com peso 2 e terceira nota com
peso 3) e determinar a situação do aluno:
APROVADO – se média igual ou superior a 7;
EM RECUPERAÇÃO – se não aprovado e com
média igual ou superior a 5; REPROVADO –
quando média inferior a 5.
*/

#include <stdio.h>

int main (){
  float n1, n2, n3, mf;
  printf ("Qual a 1ª nota do aluno? ");
  scanf ("%f", &n1);
  printf ("Qual a 2ª nota do aluno? ");
  scanf ("%f", &n2);
  printf ("Qual a 3ª nota do aluno? ");
  scanf ("%f", &n3);
  mf = (n1+n2+n3)/3;

  if (mf >= 7) {
    printf ("O aluno foi aprovado com média %.2f\n", mf);
  }
  else {
    if (mf < 7 && mf >= 5) {
      printf ("O aluno está em recuperação pois a sua média foi %.2f\n", mf);
    }
    else {
      printf ("O aluno foi reprovado pois a sua média foi %.2f\n", mf);
    }
  }
}