//quantidade mínima de passageiros errada

/*
a)//Ônibus UFS Atalaia - Qual melhor horário?
b)
c)#include <stdio.h>
d)int main()
e){
f) int Horas, NumPassageiros, MaisPassageiros, MelhorHorario;
g) MaisPassageiros = 0;
h) for (Horas=8; Horas<=18; Horas++)
i) {
j) printf("Numero de passageiras do %d horas: ",Horas);
k) scanf("%d",&NumPassageiros);
l) if (NumPassageiros > MaisPassageiros){
m) MelhorHorario = Horas;
n) MaisPassageiros = NumPassageiros;}
o) }
p) printf("Horario de maior procura: %d.",MelhorHorario);
q) return 0;
r)}

D. Maria tem um ônibus que faz diariamente, das 8 as 18
horas, o trajeto Rosa Elze – Atalaia. É feita 1 viagem por
hora e D. Maria registra o número de passageiros de cada
uma para identificar o horário com maior número de
passageiros. Para tanto foi implementado e discutido em
sala um programa em C. Efetuar ajustes nesse de forma
que seja identificado o horário com menor número de
passageiros, exibir o número médio de passageiros, a soma
de passageiros do dia e o montante recebido por D. Maria,
considerando que a passagem custa R$22,00. Aplicar for e
pelo menos 1 função.
*/

#include <stdio.h>

//máximo
void Maximo(int *NumPassageiros, int *MaisPassageiros, int *MelhorHorario, int *Horas) {
  if (*NumPassageiros > *MaisPassageiros){
      *MelhorHorario = *Horas;
      *MaisPassageiros = *NumPassageiros;}
}

//mínimo
void Mínimo(int *NumPassageiros, int *MaisPassageiros, int *PiorHorario, int *Horas) {
  
  if (*NumPassageiros < *MaisPassageiros){
      *PiorHorario = *Horas;
      *MaisPassageiros = *NumPassageiros;}
} 

//soma
void Soma (int NumPassageiros, int *SomaPas) {
*SomaPas = NumPassageiros + *SomaPas;
}
  

int main() {
  int Horas, NumPassageiros, MaisPassageiros, MelhorHorario, PiorHorario, SomaPas;
  MaisPassageiros = 0;
  for (Horas=8; Horas<=18; Horas++) {
    printf("Numero de passageiras do %d horas: ",Horas);
    scanf("%d",&NumPassageiros);
    Maximo(&NumPassageiros, &MaisPassageiros, &MelhorHorario, &Horas);
    Mínimo(&NumPassageiros, &MaisPassageiros, &PiorHorario, &Horas);
    Soma(NumPassageiros, &SomaPas);
  }
  
  printf("\nHorario de maior procura: %d.\n",MelhorHorario);
  printf("Horario de menor procura: %d.\n",PiorHorario);
  printf("Média de passageiros: %.2f.\n",SomaPas/11.0);
  printf("Soma de passageiros: %d.\n",SomaPas);
  printf("Montante recebido: R$%d,00.\n",SomaPas*22);

  return 0;
}
