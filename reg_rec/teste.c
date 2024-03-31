#include <stdio.h>
#include <string.h>

void trocar(char vetor[10][21], int primeiro, int segundo){
  char terceiro[21];
  strcpy(terceiro, vetor[primeiro]);
  strcpy(vetor[primeiro], vetor[segundo]);
  strcpy(vetor[segundo], terceiro);
}

int main (){
  char vetor_palavras[10][21] = {"AMOR","ATENCAO","BELEZA","BELO","DIRECAO","FELICIDADE","FELIZ","MALETA","REVOLTA","SABIO"};
  trocar (vetor_palavras, 2, 4);
  for (int i = 0; i < 10; i++){
    printf("%s\n", vetor_palavras[i]);
  }
  return 0;
}