#include <stdio.h>

#define QTD_MAX_VALORES 5

int main() {
  int num, soma = 0, qtd = 0, qtdAcimaMedia = 0;
  int numeros[QTD_MAX_VALORES];
  double media;
  printf("Digite um valor inteiro positivo: ");
  scanf("%d", &num);
  while (num > 0) {
    numeros[qtd] = num;
    soma += num;
    qtd += 1;
    if (qtd >= QTD_MAX_VALORES) {
      printf("Quantidade máxima de valores atingida!\n");
      break;
    }
    printf("Digite um valor inteiro positivo (<= 0 para finalizar): ");
    scanf("%d", &num);
  }
  if (qtd > 0) {
    media = (double) soma / (double) qtd;
    printf("Foram digitados %d números e a média é %lf.\n", qtd, media);
    printf("\n\nTodos os números digitados\n");
    for (int i = 0; i < qtd; i += 1) {
      printf("numeros[%d] = %d\n", i + 1, numeros[i]);
    }

    printf("\n\nListagem de números digitados acima da média\n");
    for (int i = 0; i < qtd; i += 1) {
      if (numeros[i] > media) {
        printf("numeros[%d] = %d\n", i + 1, numeros[i]);
        qtdAcimaMedia += 1;
      }
    }
    if (qtdAcimaMedia >0) {
      printf("\n\nExistem %d números digitados acima da média.\n", qtdAcimaMedia);
    } else {
      printf("Não tem nenhum número digitado acima da média\n");
    }
  } else {
    printf("Nenhum número válido foi digitado!\n");
  }
  return 0;
}