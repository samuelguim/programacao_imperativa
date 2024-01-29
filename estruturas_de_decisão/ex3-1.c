/*
Os colegas do filho de Sr. Zé estão sentindo dificuldade para
alugar um ônibus para levá-los ao “Museu da Gente
Sergipana”. Então Sr. Zé resolveu disponibilizar sua Kombi,
mas a depender do número de inscritos, serão necessárias
muitas viagens, e alguns passageiros deverão ir de coletivo.
Considerando que a Kombi tem capacidade para transportar 11
pessoas (fora o motorista – Sr. Zé), escrever um programa em
C, para, dado o número de inscritos no passeio ao Museu,
exibir o número de viagens que devem ser necessárias e o
número de passagens de coletivo. Exemplos: se 22 pessoas –
2 viagens de kombi e 0 passagem em coletivo; se 37 pessoas
– 3 viagens e 4 passagens em coletivo. Vale esclarecer que se
o número de passageiros for inferior a 11, Sr. Zé os levará de
Kombi.
*/

#include <stdio.h>

int main (){
  int insc, v_kombi, v_coletivo;
  printf ("Quantas inscrições foram realizadas? ");
  scanf ("%d", &insc);
  if (insc <= 11){
    printf ("Apenas uma viagem de kombi será realizada.\n");
  }
  else {
    v_coletivo = insc % 11;
    v_kombi = (insc - v_coletivo)/11;
    printf ("%d passagem(ns) de coletivo deverá(ão) ser comprada(s).\n", v_coletivo);
    printf ("%d viagem(ns) de kombi será(ão) realizada(s).\n", v_kombi);
  }
  return 0;
}