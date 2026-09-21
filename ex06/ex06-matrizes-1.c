#include <stdio.h>

#define QTD_LINHAS 4
#define QTD_COLUNAS 4

void preencherMatriz(int m[][QTD_COLUNAS], int lins, int cols);
void imprimirMatriz(int m[][QTD_COLUNAS], int lins, int cols);
void imprimirMatrizTransp(int m[][QTD_LINHAS], int lins, int cols);
void maiorValorMatriz(int m[][QTD_COLUNAS], int lins, int cols, int *posI, int *posJ);
int buscarMatriz(int m[][QTD_COLUNAS], int lins, int cols, int x, int *posI, int *posJ);
void somatorioPorLinha(int m[][QTD_COLUNAS], int lins, int cols, int soma[]);
void somatorioPorColuna(int m[][QTD_COLUNAS], int lins, int cols, int soma[]);
void zerarAbaixoDiagonalPrincipal(int m[][QTD_COLUNAS], int lins, int cols);
void zerarAcimaDiagonalSecundaria1(int m[][QTD_COLUNAS], int lins, int cols);
void zerarAcimaDiagonalSecundaria1(int m[][QTD_COLUNAS], int lins, int cols);
void matrizTransposta(int m[QTD_LINHAS][QTD_COLUNAS], int lins, int cols, int mt[QTD_COLUNAS][QTD_LINHAS]);
void matrizTranspostaInPlace(int m[QTD_LINHAS][QTD_COLUNAS], int lins, int cols);

int main() {
    int iMaior, jMaior;
    int matriz[QTD_LINHAS][QTD_COLUNAS], matrizTransp[QTD_COLUNAS][QTD_LINHAS];
    preencherMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
    printf("\nImpressão Matriz M\n");
    imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
    maiorValorMatriz(matriz, QTD_LINHAS, QTD_COLUNAS, &iMaior, &jMaior);
    printf("O maior valor é %d e está na posição (%d, %d)\n",
        matriz[iMaior][jMaior], iMaior + 1, jMaior + 1);
    printf("\n\nMatriz Transposta\n");
    matrizTransposta(matriz, QTD_LINHAS, QTD_COLUNAS, matrizTransp);
    imprimirMatrizTransp(matrizTransp, QTD_COLUNAS, QTD_LINHAS);
    printf("\n\nMatriz Transposta In Place\n");
    matrizTranspostaInPlace(matriz, QTD_LINHAS, QTD_COLUNAS);
    imprimirMatrizTransp(matriz, QTD_COLUNAS, QTD_LINHAS);
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

void imprimirMatrizTransp(int m[][QTD_LINHAS], int lins, int cols) {
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

int buscarMatriz(
    int m[][QTD_COLUNAS], int lins, int cols, int x, int *posI, int *posJ
) {
    for (int i = 0; i < lins; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (m[i][j] == x) {
                *posI = i;
                *posJ = j;
                return 1;
            }
        }
    }
    *posI = -1;
    *posJ = -1;
    return 0;
}

void somatorioPorLinha(int m[][QTD_COLUNAS], int lins, int cols, int soma[]) {
    for (int i = 0; i < lins; i += 1) {
        soma[i] = 0;
        for (int j = 0; j < cols; j += 1) {
            soma[i] += m[i][j];
        }
    }
}

void somatorioPorColuna(int m[][QTD_COLUNAS], int lins, int cols, int soma[]) {
    for (int j = 0; j < cols; j += 1) {
        soma[j] = 0;
        for (int i = 0; i < lins; i += 1) {
            soma[j] += m[i][j];
        }
    }
}

void zerarAbaixoDiagonalPrincipal(int m[][QTD_COLUNAS], int lins, int cols) {
    if (lins != cols) {
        printf("Não é possível realizar esta operação, pois a matriz não é quadrada!\n");
        return;
    }
    for (int i = 1; i < lins; i += 1) {
        for (int j = 0; j < i; j += 1) {
            m[i][j] = 0;
        }
    }
}

// void zerarAbaixoDiagonalPrincipal(int m[][QTD_COLUNAS], int lins, int cols) {
//     if (lins != cols) {
//         printf("Não é possível realizar esta operação, pois a matriz não é quadrada!\n");
//         return;
//     }
//     for (int i = 0; i < lins; i += 1) {
//         for (int j = 0; j < cols; j += 1) {
//             if (i > j) {
//                 m[i][j] = 0;
//             }
//         }
//     }
// }

void zerarAcimaDiagonalSecundaria1(int m[][QTD_COLUNAS], int lins, int cols) {
    if (lins != cols) {
        printf("Não é possível realizar esta operação, pois a matriz não é quadrada!\n");
        return;
    }
    for (int i = 0; i < lins; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (i + j < lins - 1) {
                m[i][j] = 0;
            }
        }
    }
}

void zerarAcimaDiagonalSecundaria2(int m[][QTD_COLUNAS], int lins, int cols) {
    if (lins != cols) {
        printf("Não é possível realizar esta operação, pois a matriz não é quadrada!\n");
        return;
    }
    for (int i = 0; i < lins - 1; i += 1) {
        for (int j = 0; j < lins - 1 - i; j += 1) {
            m[i][j] = 0;
        }
    }
}

void matrizTransposta(int m[QTD_LINHAS][QTD_COLUNAS], int lins, int cols, int mt[QTD_COLUNAS][QTD_LINHAS]) {
    for (int i = 0; i < cols; i += 1) {
        for (int j = 0; j < lins; j += 1) {
            mt[i][j] = m[j][i];
        }
    }
}

void matrizTranspostaInPlace(int m[QTD_LINHAS][QTD_COLUNAS], int lins, int cols) {
    int aux;
    if (lins != cols) {
        printf("Não é possível realizar esta operação, pois a matriz não é quadrada!\n");
        return;
    }
    for (int i = 0; i < cols; i += 1) {
        for (int j = 0; j < i; j += 1) {
            aux = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }    
}

void multiplicarMatrizes(
    int a[][QTD_COLUNAS], int linsA, int colsA,
    int b[][QTD_COLUNAS], int linsB, int colsB,
    int mult[][QTD_COLUNAS]
) {
    if (colsA != linsB) {
        printf("Não é possível realizar esta operação, pois as matrizes não são compatíveis!\n");
        return;       
    }
    for (int i = 0; i < linsA; i += 1) {
        for (int j = 0; j < colsB; j += 1) {
            mult[i][j] = 0;
            for (int k = 0; k < colsA; k += 1) {
                mult[i][j] =+ a[i][k] * b[k][j];
            }
        }
    }
}