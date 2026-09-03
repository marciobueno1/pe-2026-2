#include <stdio.h>

#define TAM 7

void imprimirVetor(double v[], int n);
void preencherOrdenadoDigitacao(double v[], int n);
void inserirOrdenado(double v[], int n, double x);
int buscaBinaria (double v[], int n, double chave);
void pesquisarNoVetor(double v[], int n);

int main() {
    double numeros[TAM + 1];
    preencherOrdenadoDigitacao(numeros, TAM);
    printf("Vetor Ordenado: ");
    imprimirVetor(numeros, TAM);
    pesquisarNoVetor(numeros, TAM);
    return 0;
}

void pesquisarNoVetor(double v[], int n) {
    int opcao, pos;
    double num;
    do {
        printf("V = ");
        imprimirVetor(v, n);
        printf("Digite um número para ser pesquisado:\n");
        scanf("%lf", &num);
        pos = buscaBinaria(v, n, num);
        if (pos != -1) {
            printf("%6.2f foi econtrado na posição %d\n", num, pos + 1);
        } else {
            printf("%6.2f não foi econtrado no vetor\n", num);
        }
        printf("Quer fazer outra pesquisa (1 - p/ sim e 2 - p/ não):\n");
        scanf("%d", &opcao);
    } while (opcao == 1);
}


void imprimirVetor(double v[], int n) {
    printf("{");
    if (n > 0) {
        printf(" %6.2f", v[0]);
        for (int i = 1; i < n; i += 1) {
            printf(", %6.2f", v[i]);
        }
    }
    printf(" }\n");
}

void preencherOrdenadoDigitacao(double v[], int n) {
    double num;
    for (int i = 0; i < n; i += 1) {
        printf("Digite o %dº número real:\n", i + 1);
        scanf("%lf", &num);
        inserirOrdenado(v, i, num);
    }
}

void inserirOrdenado(double v[], int n, double x) {
    int i = n - 1;
    while (i >= 0 && v[i] > x) {
        v[i + 1] = v[i];
        i -=  1;
    }
    v[i + 1] = x;
}

int buscaSequencial(double v[], int n, double x) {
    for (int i = 0; i < n; i += 1) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int buscaSequencialMelhorada(double v[], int n, double x) {
    int i;
    for (i = 0; i < n; i += 1) {
        if (v[i] >= x) {
            break;
        }
    }
    if (i < n && v[i] == x) {
        return i;
    }
    return -1;
}

int buscaSequencialSentinela(double v[], int n, double x) {
    int i = 0;
    v[n] = x; // vetor precisa ter capacidade de pelo menos 1 a mais que o tamanho
    while (v[i] != x) {
        i += 1;
    }
    if (i < n) {
        return i;
    }
    return -1;
}

int buscaBinaria (double v[], int n, double chave) {
    int inicio = 0, meio, fim = n - 1;
    do {
        meio = (inicio + fim) / 2;
        if (v[meio] > chave) {
            fim = meio - 1;
        } else {
            inicio = meio + 1;
        }
    } while (chave != v[meio] && inicio <= fim);
    if (chave == v[meio]) {
        return meio; // retorna a posição
    }
    return -1; // não achou
}