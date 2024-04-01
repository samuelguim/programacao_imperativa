#include <stdio.h>

/*recebe um vetor de inteiros, duas posições e troca os valores que estão
nas posições informadas entre si*/
void trocar(int vetor[], int primeiro, int segundo){
  int terceiro = vetor[primeiro];
  vetor[primeiro] = vetor[segundo];
  vetor[segundo] = terceiro;
}

int particionamento(int vetor[], int inicio, int fim){
  /*um pivô na posição início é escolhido e uma variável usada para a iteração
  recebe o valor da variável início*/
  int pivot = vetor[inicio];
  int i = inicio;

  /*os valores que estão à direita do pivot são analisados e ficam imediatamente
  após o pivot caso sejam menores ou iguais a ele*/
  for (int j = inicio + 1; j <= fim; j++){
    if (vetor[j] <= pivot) {
      i++;
      trocar(vetor, i, j);
    }
  }

  /*o pivot é trocado para a posição onde a última alteração foi feita, ou seja,
  ele estará depois de todos os números menores ou iguais a ele, e consequentemente
  na sua posição "correta".*/
  trocar(vetor, inicio, i);

  /*local do pivot*/
  return i;
}


void qqsort(int vetor[], int inicio, int fim){
  if (inicio < fim){
    /*o local do pivot (primeiro número do vetor) é obtido*/
    int posicao_pivot = particionamento(vetor, inicio, fim);

    /*a função é chamada recursivamente para a primeira metade
    do vetor (valores menores ou iguais ao pivot) e para a segunda metade
    (valores maiores que o pivot).*/
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