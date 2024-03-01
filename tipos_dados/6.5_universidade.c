/*
Na universidade “DuSabiTudu” os alunos são identificados por
matrículas compostas por 10 dígitos. Os 4 primeiros dígitos
correspondem ao ano em que o aluno entrou na instituição.
Assim, todos os alunos cujas matriculas iniciam por 2012
ingressaram no curso superior no ano de 2012. Os dígitos 5 e 6 da
matrícula correspondem ao curso; sendo: 97 para agroecologia e
99 para gerontologia. Escrever programa para ler a matricula de
100 alunos inscritos no programa “CienciasAlémDasFronteiras” e
identificar quantos alunos ingressaram num dado ano A no curso
de gerontologia. Aplicar função definida pelo programador.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int obter_ano (char matricula [11]) {
  char ano [4];
  ano [0] = matricula [0];
  ano [1] = matricula [1];
  ano [2] = matricula [2];
  ano [3] = matricula [3];
  return atoi (ano);
}

int obter_curso (char matricula [11]) {
  char curso [2];
  curso [0] = matricula [4];
  curso [1] = matricula [5];
  return atoi (curso);
}

//
int main(){
  char matricula[11];
  int anoA, alunos = 0;

  printf ("Você deseja identificar os alunos de qual ano? ");
  scanf ("%d", &anoA);
  
  for (int i = 1; i <= 100; i++) {
    printf ("Digite o número da matrícula: ");
    scanf ("%s", matricula);
    if (strlen (matricula) == 10) {
      if (obter_ano(matricula) == anoA && obter_curso(matricula) == 97) {
      alunos++;}
    }
    else {
      printf ("O número inserido não tem 10 digitos.\n");
    }
  }

  printf ("%d alunos ingressaram em gerontologia no ano de %d\n", alunos, anoA);
  return 0;
}
