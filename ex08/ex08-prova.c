#include <stdio.h>

#define QTD_COLUNAS 5

int main() {
    return 0;
}

int buscaSequencial(int v[], int tam, int x) {
    for (int i = 0; i < tam; i += 1) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int buscaIntervalo(int v[], int tam, int a, int b) {
    for (int i = 0; i < tam; i += 1) {
        if (v[i] >= a && v[i] <= b) {
            return i;
        }
    }
    return -1;
}

void deslocarEsquerda(int v[], int tam, int inicio) {
    for (int i = inicio; i < tam; i += 1) {
        v[i - 1] = v[i]; 
    }
}

int removerOcorrencias(int v[], int tam, int x) {
    int pos = buscaSequencial(v, tam, x);
    while (pos != -1) {
        deslocarEsquerda(v, tam, pos + 1);
        tam -= 1;
        pos = buscaSequencial(v, tam, x);
    }
}


int removerIntervalo(int v[], int tam, int a, int b) {
    int pos = buscaIntervalo(v, tam, a, b);
    while (pos != -1) {
        deslocarEsquerda(v, tam, pos + 1);
        tam -= 1;
        pos = buscaIntervalo(v, tam, a, b);
    }
}

void uniaoOrdenada(int v1[], int tam1, int v2[], int tam2, int v3[]) {
    int i = 0, j = 0, k = 0;
    while (i < tam1 && j < tam2) {
        if (v1[i] <= v2[j]) {
            v3[k] = v1[i];
            i += 1;
            k += 1;
        } else {
            if (k == 0 || v3[k - 1] != v2[j]) {
                v3[k] = v2[j];
                k += 1;
            }
            j += 1;
        }
    }
    if (i == tam1) {
        if (k != 0 && v3[k - 1] == v2[j]) {
            j += 1;
        }
        for (; j < tam2; j += 1) {
            v3[k] = v2[j];
            k += 1;
        }
    } else {
        for (; i < tam1; i += 1) {
            v3[k] = v1[i];
            k += 1;
        }        
    }
}

int colunaMenorSoma(int m[][QTD_COLUNAS], int lin, int col) {
    int soma, menorSoma, posMenorSoma = -1;
    for (int j = 0; j < col; j += 1) {
        soma = 0;
        for (int i = 0; i < lin; i +=1 ) {
            soma += m[i][j];
        }
        if (posMenorSoma == -1 || soma < menorSoma) {
            menorSoma = soma;
            posMenorSoma = j;
        }
    }
    return posMenorSoma;
}