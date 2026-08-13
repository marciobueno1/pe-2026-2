#include <stdio.h>

#define VALOR_INICIAL 1
#define VALOR_MAXIMO 50
#define VALOR_INCREMENTO 1

int main() {
  for (int i = VALOR_INICIAL; i <= VALOR_MAXIMO; i += VALOR_INCREMENTO) {
    if (i % 3 == 0 || i % 10 == 3) {
      printf("PI");
    } else {
      printf("%d", i);
    }
    if (i < VALOR_MAXIMO) {
      printf(", ");
    }
  }
  printf("\n");
  return 0;
}
