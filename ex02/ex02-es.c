#include <stdio.h>

#define IDADE_MINIMA 0
#define IDADE_MAXIMA 130
#define ANO_ATUAL 2026

int main() {
  int idade;
  do {
    printf("Digite a sua idade: ");
    scanf("%d", &idade);
  } while (idade < IDADE_MINIMA || idade > IDADE_MAXIMA);
  printf("Você tem %d anos e nasceu em %d\n", idade, ANO_ATUAL - idade);
  return 0;
}