#include <stdio.h>

#define TAM 20

void preencherVetorDigitacao(int v[], int n);
void imprimirVetor(int v[], int n);

int main() {
    int va[TAM], vb[TAM];
    printf("===== Preenchimento do Vetor A =====\n");
    preencherVetorDigitacao(va, TAM);
    printf("\n===== Preenchimento do Vetor B =====\n");
    preencherVetorDigitacao(vb, TAM);
    printf("A = ");
    imprimirVetor(va, TAM);
    printf("B = ");
    imprimirVetor(vb, TAM);
    return 0;
}

void preencherVetorDigitacao(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("Digite o %dº valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
}

void imprimirVetor(int v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %2d", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %2d", v[i]);
        }
    }
    printf(" }\n");
}