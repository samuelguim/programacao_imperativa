#include <stdio.h>
#include <string.h>

int bbinaria (char chave[21], int inicio, int fim, char vetor[10][21]) {
  if (fim < inicio) {
    return -1;
  }
  else {
    int meio = (inicio + fim)/2;
    if (strcmp(vetor[meio], chave)==0){
      return meio; }
    else {
      if (strcmp(vetor[meio], chave) < 0){
        return bbinaria (chave, meio+1, fim, vetor);}
      else {
        return bbinaria (chave, inicio, meio-1, vetor); }}
  }
}

int main (){
  char vetor_palavras[10][21] = {"AMOR","ATENCAO","BELEZA","BELO","DIRECAO","FELICIDADE","FELIZ","MALETA","REVOLTA","SABIO"};
  char palavra[21];
  int posicao;

  printf ("Qual palavra você deseja encontrar? ");
  scanf (" %[^\n]s", palavra);
  posicao = bbinaria (palavra,0,9,vetor_palavras);
  if (posicao == -1) {
    printf ("Palavra não encontrada\n");
  }
  else {
    printf ("Posição: %d\n", posicao);
    printf ("Resultado: %s\n", vetor_palavras[posicao]);
  }
  return 0;
}