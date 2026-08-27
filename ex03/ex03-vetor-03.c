#include <stdio.h>

#define TAM 20

void imprimirVetor(int v[], int n);
void preencherOrdenadoDigitacao(int v[], int n);
void inserirOrdenado(int v[], int n, int x);

int main() {
    int numeros[TAM];
    preencherOrdenadoDigitacao(numeros, TAM);
    imprimirVetor(numeros, TAM);
    return 0;
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

void preencherOrdenadoDigitacao(int v[], int n) {
    int num;
    for (int i = 0; i < n; i += i) {
        printf("Digite um número inteiro: ");
        scanf("%d", &num);
        inserirOrdenado(v, i, num);
    }
}

void inserirOrdenado(int v[], int n, int x) {

}
