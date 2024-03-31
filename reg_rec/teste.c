#include <stdio.h>

// Função que recebe um vetor de strings como parâmetro
void imprimirStrings(char **vetorStrings, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s\n", vetorStrings[i]);
    }
}

int main() {
    // Definindo um vetor de strings
    char *strings[] = {"Primeira", "Segunda", "Terceira"};

    // Obtendo o tamanho do vetor de strings
    int tamanho = sizeof(strings) / sizeof(strings[0]);

    // Chamando a função e passando o vetor de strings como parâmetro
    imprimirStrings(strings, tamanho);

    return 0;
}