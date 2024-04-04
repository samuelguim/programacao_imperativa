#include <stdio.h>
#include <string.h>

void trocar(char vetor[10][21], int primeiro, int segundo){
  char terceiro[21];
  strcpy(terceiro, vetor[primeiro]);
  strcpy(vetor[primeiro], vetor[segundo]);
  strcpy(vetor[segundo], terceiro);
}

int particionamento(char vetor[10][21], int inicio, int fim){
  char pivot[21];
  strcpy(pivot, vetor[inicio]);
  int i = inicio;

  for (int j = inicio + 1; j <= fim; j++){
    if (strcmp(vetor[j], pivot) <= 0){
      i++;
      trocar(vetor, i, j);
    }
  }

  trocar(vetor, inicio, i);

  return i;
}


void qqsort(char vetor[25][21], int inicio, int fim){
  if (inicio < fim){
    int posicao_pivot = particionamento(vetor, inicio, fim);
    qqsort(vetor, inicio, posicao_pivot - 1);
    qqsort(vetor, posicao_pivot + 1, fim);
  }
}

int main () {
  char vetor_palavras[25][21] = {"DIRECAO","FELIZ","BELEZA","MALETA","AMOR","FELICIDADE","FELIZ","BELO","REVOLTA","ATENCAO",
                                "REVOLTA","CARINHO","AZUL","VERMELHO","AMARELO","CINZA","MARROM","ROSA","MAGENTA","AR",
                                "OBJETO","CALCULADORA","FIO","ELETRICIDADE","AULA"};
  
  /*
  for(int i = 0; i < 25; i++){
    printf ("Digite uma palavra: ");
    scanf (" %[^\n]s", vetor_palavras[i]);
  }
  */

  qqsort(vetor_palavras, 0, 24);
  
  printf ("Palavras alfabeticamente ordenadas: \n");
  for(int i = 0; i < 25; i++){
    printf ("%s\n", vetor_palavras[i]);
  }

  return 0;
}