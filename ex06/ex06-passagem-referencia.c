#include <stdio.h>

void troca(int *a, int *b);

int main() {
    int numero1 = 10, numero2 = 20;
    printf("&numero1 = %p, numero1 = %d e &numero2 = %p, numero2 = %d\n", &numero1, numero1, &numero2, numero2);
    troca(&numero1, &numero2);
    printf("&numero1 = %p, numero1 = %d e &numero2 = %p, numero2 = %d\n", &numero1, numero1, &numero2, numero2);
    return 0;
}

void troca(int *a, int *b) {
    printf("a = %p, *a = %d e b = %p, *b = %d\n", a, *a, b, *b);
    int aux = *a;
    *a = *b;
    *b = aux;
    printf("a = %p, *a = %d e b = %p, *b = %d\n", a, *a, b, *b);
}