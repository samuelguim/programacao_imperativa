/*
7.Escrever um programa em C sobre investimento. Deve ser efetuada a
leitura do valor inicial investido, do valor investido mensalmente e do tempo
de investimento (desconsiderar juros) e retornar o valor final (montante) e o
valor do rendimento (montante – valor inicial investido). Deve ser aplicado
um módulo(função) com dois parâmetros de saída.
*/

#include <stdio.h>

void calcularInvestimento(float valorInicial, float investimentoMensal, int tempoInvestimento, float *montante, float *rendimento) {
    *montante = valorInicial;
    for (int i = 0; i < tempoInvestimento; ++i) {
        *montante += investimentoMensal;
    }

    *rendimento = *montante - valorInicial;
}

int main() {
    float valorInicial, investimentoMensal, montante, rendimento;
    int tempoInvestimento;
    printf("Informe o valor inicial investido: ");
    scanf("%f", &valorInicial);
    printf("Informe o valor investido mensalmente: ");
    scanf("%f", &investimentoMensal);
    printf("Informe o tempo de investimento em meses: ");
    scanf("%d", &tempoInvestimento);

    calcularInvestimento(valorInicial, investimentoMensal, tempoInvestimento, &montante, &rendimento);

    printf("\nResultados:\n");
    printf("Montante final: %.2f\n", montante);
    printf("Rendimento: %.2f\n", rendimento);

    return 0;
}
