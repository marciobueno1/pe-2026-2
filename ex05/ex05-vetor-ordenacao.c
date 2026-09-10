#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

void insercaoDireta(double v[], int n);
void selecaoDireta(double v[], int n);
void bubblesort (double v[], int n);
void preencherVetorAleatorio(double v[], int n);
void imprimirVetor(double v[], int n);

int main() {
    double a[TAM];
    srand(time(NULL));
    printf("RAND_MAX = %d\n", RAND_MAX);
    preencherVetorAleatorio(a, TAM);
    imprimirVetor(a, TAM);
    printf("\n\n--------------------------------------------------\n");
    printf("           INICIANDO ORDENAÇÃO\n");
    printf("--------------------------------------------------\n");
    selecaoDireta(a, TAM);
    imprimirVetor(a, TAM);
    printf("\n\n--------------------------------------------------\n");
    printf("           INICIANDO ORDENAÇÃO\n");
    printf("--------------------------------------------------\n");
    selecaoDireta(a, TAM);
    imprimirVetor(a, TAM);
    return 0;
}

void preencherVetorAleatorio(double v[], int n) {
    for (int i = 0; i < n; i += 1) {
        v[i] = rand() / 1000000.0;
    }
}

void imprimirVetor(double v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %7.2f", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %7.2f", v[i]);
        }
    }
    printf(" }\n");
}

void insercaoDireta(double v[], int n) {
    int i, j;
    double chave;
    for (i = 1; i <= n - 1; i++) {
        chave = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > chave) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = chave;
    }
}

void selecaoDireta(double v[], int n) {
    int i, j, menor;
    double aux;
    for (i = 0; i < n - 1; i++) {
        menor = i;
        for (j = i + 1; j <= n - 1 ; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void bubblesort (double v[], int n) {
    int i, pos = 0, trocou = 1, fim = n - 2;
    double chave;
    while (trocou) {
        trocou = 0;
        for (i = 0; i <= fim; i++) {
            if (v[i] > v[i+1]) {
                chave = v[i];
                v[i] = v[i+1];
                v[i+1] = chave;
                pos = i; 
                trocou = 1;
            }
        }
        fim = pos - 1;
    }
}
