/*
Na disciplina “Programação Imperativa” há 50 alunos e 12
avaliações. Para obtenção de aprovação o aluno deve ter no
mínimo 5 notas maiores ou iguais a 7. Escrever programa para
ler notas de cada um dos 50 alunos e identificar se foi
aprovado.
*/


// 5 notas > 7 /= média > 35/12


#include <stdio.h>

int main (){
  for (int i = 1; i <=50; i++) {
    float nota, pont_total = 0;
    for (int j = 1; j <=12; j++) {
      printf ("Insira a %dª nota do %dº aluno: ", j, i);
      scanf ("%f", &nota);
        if (nota >= 5) {
          pont_total++;
        }
    }
    if (pont_total >= 5) {
      printf ("O aluno %d foi aprovado\n", i);
    }
    else {
      printf ("O aluno %d foi reprovado\n", i);
    }
  }
  return 0;
}