#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 3

void preencherMatriz(int m[][QTD_COLUNAS], int lins, int cols);
void imprimirMatriz(int m[][QTD_COLUNAS], int lins, int cols);
void maiorValorMatriz(int m[][QTD_COLUNAS], int lins, int cols, int *posI, int *posJ);
void buscarMatriz(int m[][QTD_COLUNAS], int lins, int cols, int x);

int main() {
    int iMaior, jMaior;
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    preencherMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
    printf("\nImpressão Matriz M\n");
    imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
    maiorValorMatriz(matriz, QTD_LINHAS, QTD_COLUNAS, &iMaior, &jMaior);
    printf("O maior valor é %d e está na posição (%d, %d)\n",
        matriz[iMaior][jMaior], iMaior + 1, jMaior + 1);
    return 0;
}

void preencherMatriz(int m[][QTD_COLUNAS], int lins, int cols) {
    for (int i = 0; i < lins; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            printf("Digite o valor de m[%d][%d]:\n", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprimirMatriz(int m[][QTD_COLUNAS], int lins, int cols) {
    for (int i = 0; i < lins; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
}

void maiorValorMatriz(
    int m[][QTD_COLUNAS], int lins, int cols, int *posI, int *posJ
) {
    int iMaior = 0, jMaior = 0;
    for (int i = 0; i < lins; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (m[i][j] > m[iMaior][jMaior]) {
                iMaior = i;
                jMaior = j;
            }
        }
    }
    *posI = iMaior;
    *posJ = jMaior;
}

void buscarMatriz(int m[][QTD_COLUNAS], int lins, int cols, int x) {

}