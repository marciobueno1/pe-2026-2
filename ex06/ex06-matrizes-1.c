#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 3

void preencherMatriz(int m[][QTD_COLUNAS], int lins, int cols);
void imprimirMatriz(int m[][QTD_COLUNAS], int lins, int cols);
void imprimirMaiorValorMatriz(int m[][QTD_COLUNAS], int lins, int cols);

int main() {
    int matriz[QTD_LINHAS][QTD_COLUNAS];
    preencherMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
    printf("\nImpressão Matriz M\n");
    imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
    imprimirMaiorValorMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
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

void imprimirMaiorValorMatriz(int m[][QTD_COLUNAS], int lins, int cols) {
    int iMaior = 0, jMaior = 0;
    for (int i = 0; i < lins; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (m[i][j] > m[iMaior][jMaior]) {
                iMaior = i;
                jMaior = j;
            }
        }
    }
    printf("O maior valor é %d e está na posição (%d, %d)\n",
        m[iMaior][jMaior], iMaior + 1, jMaior + 1);
}
