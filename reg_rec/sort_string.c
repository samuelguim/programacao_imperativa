#include <stdio.h>
#include <string.h>

int bbinaria (char chave[21], int inicio, int fim, char vetor[10][21]) {

    int meio = (inicio + fim)/2;
    if (strcmp(chave, vetor[meio])==0){
      return meio; }
    else {
      if (strcmp(chave, vetor[meio]) < 0){
        return bbinaria (chave, meio+1, fim, vetor);}
      else {
        return bbinaria (chave, inicio, meio-1, vetor); }}
}


int main (){
  printf ("%d", strcmp("FELICIDADE", "DIRECAO"));
  char vetor_palavras[10][21] = {"AMOR","ATENCAO","BELEZA","BELO","DIRECAO","FELICIDADE","FELIZ","MALETA","REVOLTA","SABIO"};
  char palavra[21];
  int posicao;

  printf ("Qual palavra você deseja encontrar? ");
  scanf (" %[^\n]s", palavra);
  posicao = bbinaria (palavra,0,9,vetor_palavras);
  printf ("Posição: %d\n", posicao);
  printf ("Resultado: %s\n", vetor_palavras[posicao]);
  return 0;
}