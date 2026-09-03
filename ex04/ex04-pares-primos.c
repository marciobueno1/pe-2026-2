/*
Crie um programa em C que crie 3 vetores (defina TAM como 15):
    1º vetor: preencha com números pares em sequência maiores que 100

    2º vetor: preencha com números primos (para verificar se um número é primo ou não teste a divisão com apenas os números anteriores que já estão no vetor)

    3º vetor: é o vetor somatório, onde o 1º elemento é igual a soma do 1º elemento do vetor 1 e o último elemento do vetor 2, o 2º elemento é igual a soma do 2º elemento do vetor 1 e o penúltimo elemento do vetor 2, e assim por diante.
*/

#include <stdio.h>

#define TAM 15

void imprimirVetor(int v[], int n);
void preencherPares(int v[], int n);
void preencherPrimos(int v[], int n);
void somatorio(int s[], int a[], int b[], int n);

int main() {
    int pares[TAM], primos[TAM], soma[TAM];
    preencherPares(pares, TAM);
    imprimirVetor(pares, TAM);
    preencherPrimos(primos, TAM);
    imprimirVetor(primos, TAM);
    somatorio(soma, pares, primos, TAM);
    imprimirVetor(soma, TAM);
    return 0;
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

void preencherPares(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        v[i] = 102 + 2 * i;
    }
}

int ePrimo(int v[], int n, int x) {
    for (int i = 0; i < n; i += 1) {
        if (x % v[i] == 0) {
            return 0;
        }
    }
    return 1;
}

void preencherPrimos(int v[], int n) {
    int i = 0, num = 2;
    while (i < n) {
        if (ePrimo(v, i, num)) {
            v[i] = num;
            i += 1;
        }
        num += 1;
    }
}

void somatorio(int s[], int a[], int b[], int n) {
    int ib = n - 1;
    for (int i = 0; i < n; i += 1) {
        // s[i] = a[i] + b[n - 1 - i]; // opção com fórmula, sem criar variável extra
        s[i] = a[i] + b[ib];
        ib -= 1;
    }
}
