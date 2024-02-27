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

void primeiro_nome (char Nome [31]) {
  printf ("%c", toupper(Nome[0]));
  for (int k = 2; k <= strlen(Nome); k++) {
    if (Nome[k-1] != ' ') {
      printf ("%c", Nome[k-1]);
    }
    else {
      printf ("\n");
      break;
    }
  }
}

void sobrenome (char Nome [31]) {
  for (int i = 1; i <= strlen(Nome); i++) {
    if (Nome[i-1] == ' ') {
                                    //-1 para excluir \n
      for (int j = i; j < strlen(Nome)-1; j++) {
        printf  ("%c", toupper (Nome[j]));
      }
    }
  }
  printf (", ");
}

int main () {
  char Nome [31];
  printf ("Digite o seu nome: ");
  fgets (Nome, 31, stdin);

  sobrenome(Nome);
  primeiro_nome(Nome);
}

