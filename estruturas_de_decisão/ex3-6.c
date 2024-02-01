/*
Escrever um programa para ler peso (massa)
e altura de uma pessoa, calcular o índice
de massa corporal: (IMC = massa/altura²
e determinar o tipo de obesidade da pessoa
conforme tabela dada:
<18,5       - Magreza
18,5 - 24,9 - Saudável
25,0 - 29,9 - Sobrepeso
30,0 - 34,9 - Obesidade Grau I
35,0 - 39,9 - Obesidade Grau II (severa)
>= 40       - Obesidade Grau III (mórbida)
*/

#include <stdio.h>
int main (){
  float peso, altura, imc;
  printf ("Qual é o seu peso em quilogramas? ");
  scanf ("%f", &peso);
  printf ("Qual é a sua altura em metros? ");
  scanf ("%f", &altura);
  imc = peso / (altura*altura);
  printf ("Esse é o seu IMC: %.1f\n", imc);
  if (imc < 18.5){
    printf ("De acordo com a tabela do IMC, você tem magreza\n");
  }
  else {
    if (imc >= 18.5 && imc <= 24.9){
      printf ("De acordo com a tabela do IMC, você tem um peso saudável\n");
    }
    else {
      if (imc >= 25 && imc <= 29.9){
        printf ("De acordo com a tabela do IMC, você tem sobrepeso\n");
      }
      else {
        if (imc >= 30 && imc <= 34.9){
          printf ("De acordo com a tabela do IMC, você tem Obesidade Grau I\n");
        }
        else {
          if (imc >= 40 && imc <= 39.9) {
            printf ("De acordo com a tabela do IMC, você tem Obesidade Grau II (severa)\n");
          }
          else{
            printf ("De acordo com a tabela do IMC, você tem Obesidade Grau III (mórbida)\n");
          }
        }
      }
    }
  }
  return 0;
}