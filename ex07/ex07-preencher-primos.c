#include <stdio.h>

#define TAM 20

void preencherPrimos(int v[], int tam);
void imprimirVetor(int v[], int n);

int main() {
    int primos[TAM];
    preencherPrimos(primos, TAM);
    imprimirVetor(primos, TAM);
    return 0;
}

int ePrimo(int v[], int tam, int num) {
    for (int i = 0; i < tam; i += 1) {
        if (num % v[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void preencherPrimos(int v[], int tam) {
    int num = 2, qtdPrimos = 0;
    while (qtdPrimos < tam) {
        if (ePrimo(v, qtdPrimos, num)) {
            v[qtdPrimos] = num;
            qtdPrimos += 1;
        }
        num += 1;
    }
}

void imprimirVetor(int v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %3d", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %3d", v[i]);
        }
    }
    printf(" }\n");
}