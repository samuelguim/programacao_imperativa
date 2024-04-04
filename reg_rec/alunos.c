#include <stdio.h>

int main (){

  //declara variáveis
  struct TpAluno {
    char Nome[21];
    float Nota1, Nota2, Nota3;
    int Frequencia;
    float MediaIndividual;
  };
  
  struct TpAluno Aluno[80];
  float MediaTurma = 0, Soma = 0;

  //coleta variáveis
  for (int i = 0; i < 80; i++) {
    printf ("Digite o nome do aluno(a): ");
    scanf(" %[^\n]s", Aluno[i].Nome);
    printf ("Digite a Nota 1 do aluno(a): ");
    scanf(" %f", &Aluno[i].Nota1);
    printf ("Digite a Nota 2 do aluno(a): ");
    scanf(" %f", &Aluno[i].Nota2);
    printf ("Digite a Nota 3 do aluno(a): ");
    scanf(" %f", &Aluno[i].Nota3);
    printf ("Digite a frequência do aluno(a): ");
    scanf(" %d", &Aluno[i].Frequencia);
    Aluno[i].MediaIndividual = (Aluno[i].Nota1 + Aluno[i].Nota2 + Aluno[i].Nota3)/3;
  }

  //calcula média
  for (int j = 0; j < 80; j++){
    Soma = Soma + Aluno[j].MediaIndividual;
  }
  MediaTurma = Soma/80;

  //imprime na tela
  printf ("-----------------------\n");
  printf ("Média da Turma: %.2f\n", MediaTurma);

  for (int k = 0; k < 80; k++){
    printf ("-----------------------\n");
    printf ("Aluno: %s\n", Aluno[k].Nome);
    printf ("Média: %.2f\n", Aluno[k].MediaIndividual);
    if (Aluno[k].Frequencia >= 65 && Aluno[k].MediaIndividual>=MediaTurma) {
      printf ("Situação: Aprovado(a).\n"); }
    else {
      printf ("Situação: Reprovado(a).\n"); }
  }
    printf ("-----------------------\n");
  
  return 0;
}