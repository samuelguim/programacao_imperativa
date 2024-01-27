/*
2. No pré-escolar “Balão Mágico” o número máximo de alunos de uma
turma é definido anualmente, após as reformas de fim de ano e
evolução curricular. Escrever programa em C onde se lê o número
total de alunos matriculados, o número máximo de alunos por
turma e exibir o número de turmas a serem formadas.
*/

#include <stdio.h>
#include <math.h>

int turmas (int a, int m){
  int t;
  if (a % m == 0){
    t = a/m;
  }
  else {
    t = (a/m)+1;
  return t;
  }
}

int main (){
  int a, m, t;
  printf ("Qual é o total de alunos matriculados? ");
  scanf ("%d", &a);
  printf ("Qual é o máximo de alunos por turma? ");
  scanf ("%d", &m);
  t = turmas (a, m);
  if (t == 1){
    printf ("Apenas %d turma será formada. \n", t);
  }
  else{
    printf ("%d turmas serão formadas. \n", t);
  }
  return 0;
}
