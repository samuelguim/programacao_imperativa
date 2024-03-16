/*
Na loja de Sr. Zé compras acima de R$300,00 podem ser parceladas em
até 10 vezes, para tanto são aplicados juros simples de 10% ao mês,
conforme o número de meses. Dado valor da compra, exibir o valor total
e o valor das parcelas. Aplicar for e função.
Exemplo:
Compra R$1.000,00
Pagamento em 1 mês – Juros: R$100,00 – Total: R$1.100 – Parcela1 x R$ 1.100,00
Pagamento em 2 meses – Juros: R$100,00 – Total – R$1.200 – Parcela 2 x R$600,00
Pagamento em 3 meses – Juros: R$100,00 – Total – R$1.300 – Parcela 3 x R$433,33
Pagamento em 4 meses – Juros: R$100,00 –Total – R$1.400 – Parcela 4 x R$350,33
…
Pagamento em 10 meses – Juros: R$100,00 –Total – R$2.000 – Parcela 10 x R$200,00
*/
#include <stdio.h>

void calc_juros (float valor) {
  printf ("Pagamento em 1 mês   – Juros: R$%.2f – Total – R$%.2f – Parcela 1 x R$%.2f\n", valor*0.1, valor+(valor*0.1), valor+(valor*0.1));
  for (int v = 2; v <= 10; v++) {
    float juros, parcelas, total;
    juros = valor * 0.1;
    total = valor + (juros * v);
    parcelas = total / v;
    printf ("Pagamento em %d meses – Juros: R$%.2f – Total – R$%.2f – Parcela %d x R$%.2f\n", v, juros, total, v, parcelas);
  }
}

int main() {
  float valor;
  printf ("Qual é o valor da compra? ");
  scanf ("%f", &valor);
  if (valor >= 300){
    calc_juros (valor);
  }
  else {
    printf ("O valor da compra não atende às condições necessárias\n");
    printf ("para o parcelamento em até 10 vezes sem juros.\n");
  }
  return 0;
}

//teste