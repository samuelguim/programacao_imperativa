#include <stdio.h>

void trocar(int vetor[], int primeiro, int segundo){
  int terceiro = vetor[primeiro];
  vetor[primeiro] = vetor[segundo];
  vetor[segundo] = terceiro;
}

int particionamento(int vetor[], int inicio, int fim){
  int pivot = vetor[inicio];
  int i = inicio;

  for (int j = inicio + 1; j <= fim; j++){
    if (vetor[j] <= pivot) {
      i++;
      trocar(vetor, i, j);
    }
  }

  trocar(vetor, inicio, i);

  return i;
}


void qqsort(int vetor[], int inicio, int fim){
  if (inicio < fim){
    int posicao_pivot = particionamento(vetor, inicio, fim);
    qqsort(vetor, inicio, posicao_pivot - 1);
    qqsort(vetor, posicao_pivot + 1, fim);
  }
}

int main () {
  int vetor_numeros[10];

  for(int i = 0; i < 10; i++){
    printf ("Digite um número inteiro: ");
    scanf ("%d", &vetor_numeros[i]);
  }

  qqsort(vetor_numeros, 0, 9);
  
  printf ("Números ordenados: ");
  for(int i = 0; i < 10; i++){
    printf ("%d, ", vetor_numeros[i]);
  }
  printf ("\n\n");

  return 0;
}