#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 3

int main() {
    int m[QTD_LINHAS][QTD_COLUNAS];
    for (int i = 0; i < QTD_LINHAS; i += 1) {
        for (int j = 0; j < QTD_COLUNAS; j += 1) {
            printf("Digite o valor de m[%d][%d]:\n", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
    printf("\nImpressão Matriz M\n");
    for (int i = 0; i < QTD_LINHAS; i += 1) {
        for (int j = 0; j < QTD_COLUNAS; j += 1) {
            printf("%2d ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}
