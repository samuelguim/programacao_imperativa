/*
Escrever programa para ler uma palavra P qualquer
com até 20 caracteres e identificar quantas vogais P
apresenta. Aplicar função definida pelo programador
Efetuar essa operação para tantas strings quantas o usuário
desejar.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int menu () {
  int opc;
  printf ("Deseja continuar? (1 - Sim | 0 - Não) ");
  scanf ("%d", &opc);
  if (opc == 1 || opc == 0) {
    return opc;
  }
  else {
    printf ("Opção não encontrada.\n");
    return 0;
  }
}

int cont_vogais (char P [21]) {
  int vog = 0, i;
  for (i = 1; i <= strlen(P); i++) {
    if (P[i-1] == 'a' || P[i-1] == 'e' || P[i-1] == 'i' || P[i-1] == 'o' || P[i-1] == 'u') {
      vog++;
    }
    else {
      vog = vog;
    }
  }
  return vog;
} 

int main() {
  char Palavra [21];
  int vogais, continuar = 1;
  
  while (continuar == 1)
  {
    printf ("Digite uma palavra de até 20 caracteres: ");
    scanf ("%s", Palavra);
    printf ("A palavra digitada tem %d vogais.\n", cont_vogais(Palavra));
    continuar = menu();
  }
  
  return 0;
}