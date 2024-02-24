#include <stdio.h>
#include <math.h>

void saturno(float peso_atual, float peso_alm) {
  float peso_mensal;
  int mes = 1;
  //omiti o 
  for (peso_mensal = peso_atual-5, mes = 1; peso_mensal >= peso_alm; peso_mensal = peso_mensal-5.0, mes++) {
    printf ("Peso esperado ao final do %iº mês de dieta: %.2fkg\n",mes,  peso_mensal);
  }
}

void resto_saturno (float resto) {
  int dias_restantes = ceil (6*resto);
  printf ("Para perder os %.2f quilos restantes, aproximadamente\n", resto);
  printf ("%d dias realizando a dieta de Saturno serão necessários. \n", dias_restantes);
}

int main() {
  float peso_atual, peso_alm, resto;
  printf("Qual é o seu peso atual? ");
  scanf("%f", &peso_atual);
  printf("Qual é o peso almejado? ");
  scanf("%f", &peso_alm);

  if (peso_atual > peso_alm) {
    if (fmod ((peso_atual-peso_alm), 5) == 0) {
      saturno(peso_atual, peso_alm);
    }
    else {
      resto = fmod ((peso_atual-peso_alm), 5);
      saturno(peso_atual, peso_alm+resto);
      resto_saturno(resto);
    }
  }
  else {
    printf ("O peso atual é maior ou igual ao peso almejado.\n"); 
    printf ("A dieta não será necessária, já que o objetivo da mesma é perder peso.\n");
  }

  return 0;
}