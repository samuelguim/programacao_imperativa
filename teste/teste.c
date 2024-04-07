#include <stdio.h>
#include <stdlib.h>  //usado system
#include <ctype.h>   //usado toupper
#include <string.h>  //usado strcmp

struct TpFarma {
    char Nome[21];
    float Preco;
    int QEstoque;
    int Excluido; // Novo campo para marcar se o registro foi excluído logicamente
};

typedef struct TpFarma TpFARMA;

TpFARMA RgFarma;

FILE *ArqFarma;

long int Tamanho = 21 * sizeof(char) + sizeof(float) + sizeof(int) + sizeof(int); // Adicionamos o tamanho do novo campo "Excluido"

void Incluir() {
    char R;
    do {
        //system("cls");
        printf("*** inclusao ***\n\n");
        printf("Nome: ");
        scanf("%s", RgFarma.Nome);

        // Verificar se o fármaco já existe
        fseek(ArqFarma, 0, 0);
        while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
            if (strcmp(RgFarma.Nome, RgFarma.Nome) == 0 && !RgFarma.Excluido) {
                printf("Fármaco já existe no arquivo!\n");
                return; // Sair da função se já existe
            }
        }

        printf("Preco: ");
        scanf("%f", &RgFarma.Preco);
        printf("Estoque: ");
        scanf("%d", &RgFarma.QEstoque);
        RgFarma.Excluido = 0; // Definir que o registro não está excluído
        fseek(ArqFarma, 0, 2);
        fwrite(&RgFarma, Tamanho, 1, ArqFarma);
        printf("\nNova inclusao? S/N ");
        scanf(" %c", &R);
        R = toupper(R);
    } while (R != 'N');
    return;
}

void Excluir() {
    printf("*** exclusao ***\n\n");
    printf("Nome do fármaco a excluir: ");
    char Farmaco[21];
    scanf("%s", Farmaco);

    // Marcar o registro como excluído logicamente
    fseek(ArqFarma, 0, 0);
    int Achou = 0;
    while (fread(&RgFarma, Tamanho, 1, ArqFarma) == 1) {
        if (strcmp(RgFarma.Nome, Farmaco) == 0 && !RgFarma.Excluido) {
            RgFarma.Excluido = 1; // Marcar como excluído
            fseek(ArqFarma, -Tamanho, 1);
            fwrite(&RgFarma, Tamanho, 1, ArqFarma);
            printf("Fármaco excluído com sucesso!\n");
            Achou = 1;
            break;
        }
    }
    if (!Achou) {
        printf("Fármaco não encontrado ou já excluído.\n");
    }
}

void Consultar() {
    //system("cls");
    printf("*** consulta ***\n\n");
    fseek(ArqFarma, 0, 0);
    printf("Qual farmaco? ");
    char Farmaco[21];
    scanf("%s", Farmaco);
    int Achou = 0;
    do {
        fread(&RgFarma, Tamanho, 1, ArqFarma);
        if (strcmp(RgFarma.Nome, Farmaco) == 0 && !RgFarma.Excluido) {
            Achou = 1;
            printf("Nome: %s\n", RgFarma.Nome);
            printf("Valor: R$%.2f\n", RgFarma.Preco);
            printf("Estoque: %d\n", RgFarma.QEstoque);
        }
    } while (!feof(ArqFarma) && (Achou == 0));
    if (Achou == 0)
        printf("Registro inexistente ou excluído!\n");
    return;
}

void LTodos() {
    //system("cls");
    printf("*** lista todos ***\n\n");
    fseek(ArqFarma, 0, 0);
    do {
        fread(&RgFarma, Tamanho, 1, ArqFarma);
        if (!feof(ArqFarma) && !RgFarma.Excluido) {
            printf("Nome: %s\n", RgFarma.Nome);
            printf("Valor: R$%.2f\n", RgFarma.Preco);
            printf("Estoque: %d\n", RgFarma.QEstoque);
            printf("***\n\n");
        }
    } while (!feof(ArqFarma));
}

int main() {
    ArqFarma = fopen("Farmacos.dat", "a+b");
    char Opcao;
    do {
        //system("cls");
        printf("\n\n> > > Pague Pouco < < < \n\n");
        printf("Que deseja fazer? \n\n");
        printf("I - Incluir \n");
        printf("E - Excluir \n");
        printf("C - Consultar \n");
        printf("T - Listar Todos \n");
        printf("S - Sair \n\n");
        scanf(" %c", &Opcao);
        Opcao = toupper(Opcao);
        switch (Opcao) {
        case 'I':
            Incluir();
            break;
        case 'E':
            Excluir();
            break;
        case 'C':
            Consultar();
            break;
        case 'T':
            LTodos();
            break;
        }
    } while (Opcao != 'S');
    fclose(ArqFarma);
    return 0;
}
