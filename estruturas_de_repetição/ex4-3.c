/*
Ler notas de alunos e identificar se cada foi aprovado.
Considerar como sistema de avaliação: em princípio, 3
notas; são aprovados os alunos com média 7; para os
alunos com média acima de 3, é possibilitado fazer 4ª
avaliação, então a média passa a ser 5 para obtenção da
aprovação. Após a identificação de que um aluno foi
aprovado, ou não; deve ser questionado se o usuário (do
programa) deseja verificar a situação de outro aluno.
*/

#include <stdio.h>


int calc_media () {
  double n1, n2, n3, n4, media;
  int sit_aluno;
  printf ("Digite a 1ª nota do aluno: ");
  scanf ("%lf", &n1);
  printf ("Digite a 2ª nota do aluno: ");
  scanf ("%lf", &n2);
  printf ("Digite a 3ª nota do aluno: ");
  scanf ("%lf", &n3);
  media = (n1+n2+n3)/3;
  if (media >= 7) {
    printf ("O aluno foi aprovado com media %.2f.\n", media);
  }
  else {
    if (media >= 3 && media < 7){
      printf ("O aluno obteve média %.2f e poderá fazer mais uma avaliação\n", media);
      printf ("Digite a 4ª nota do aluno: ");
      scanf ("%lf", &n4);
      media = (n1+n2+n3+n4)/4;
      if (media >=5) {
        printf ("O aluno foi aprovado com media %.2f.\n", media);
      }
      else {
        printf ("O aluno foi reprovado com media %.2f.\n", media);
      }
    }
    else {
      printf ("O aluno foi reprovado com media %.2f.\n", media);
    }
  }
  printf ("Deseja verificar a situação de outro aluno?\n");
  printf ("1 - SIM\n");
  printf ("2 - NÃO\n");
  scanf ("%d", &sit_aluno);
  switch (sit_aluno) {
    case 1 : return 1;
    case 2 : return 2;
    default : printf ("OPÇÃO NÃO EXISTE\n");
  }
}

int main () {
  int sit_aluno;
  do {
    sit_aluno = calc_media ();
  }
  while (sit_aluno == 1);
  return 0;
}