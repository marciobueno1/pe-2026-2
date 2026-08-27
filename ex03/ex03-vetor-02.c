#include <stdio.h>

#define TAM 20

void preencherVetorDigitacao(int v[], int n);
void imprimirVetor(int v[], int n);
int posMaiorValor(int v[], int n);
int buscaSequencial(int v[], int n, int x);
int removerValor(int v[], int n, int x);
int inserirInicio(int v[], int n, int x);

int main() {
    int opcao, num, posA, posB, tamA = TAM, tamB = TAM;
    int va[TAM], vb[TAM];
    printf("===== Preenchimento do Vetor A =====\n");
    preencherVetorDigitacao(va, TAM);
    printf("\n===== Preenchimento do Vetor B =====\n");
    preencherVetorDigitacao(vb, TAM);
    do {
        printf("MENU\n");
        printf("1 - Imprimir os dois vetores\n");
        printf("2 - Buscar um valor nos dois vetores\n");
        printf("3 - Achar o maior elemento dos dois vetores\n");
        printf("4 - Remover um valor do vetor A\n");
        printf("5 - Remover um valor do vetor B\n");
        printf("6 - Inserir um valor no início do vetor A\n");
        printf("7 - Inserir um valor no início do vetor B\n");
        printf("Digite sua opção (0 para sair): \n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                printf("A = ");
                imprimirVetor(va, tamA);
                printf("B = ");
                imprimirVetor(vb, tamB);
                break;
            case 2:
                printf("Digite um valor a ser buscado:\n");
                scanf("%d", &num);
                posA = buscaSequencial(va, tamA, num);
                if (posA != -1) {
                    printf("O número %d está na %da posição do vetor A\n", num, posA + 1);
                } else {
                    printf("O número %d não existe no vetor A\n", num);
                }
                posB = buscaSequencial(vb, tamB, num);
                if (posB != -1) {
                    printf("O número %d está na %da posição do vetor B\n", num, posB + 1);
                } else {
                    printf("O número %d não existe no vetor B\n", num);
                }
                break;
            case 3:
                posA = posMaiorValor(va, tamA);
                printf("%d é o maior valor do vetor A e está na %da posição\n", va[posA], posA + 1);
                posB = posMaiorValor(vb, tamB);
                printf("%d é o maior valor do vetor B e está na %da posição\n", vb[posB], posB + 1);
                break;
            case 4:
                printf("Digite um valor a ser removido do vetor A:\n");
                scanf("%d", &num);
                if (removerValor(va, tamA, num)) {
                    tamA -= 1;
                    printf("O valor %d foi removido do vetor A\n", num);
                } else {
                    printf("O valor %d não se encontra no vetor A, e nada foi removido!\n", num);
                }
                break;
            case 5:
                printf("Digite um valor a ser removido do vetor B:\n");
                scanf("%d", &num);
                if (removerValor(vb, tamB, num)) {
                    tamB -= 1;
                    printf("O valor %d foi removido do vetor B\n", num);
                } else {
                    printf("O valor %d não se encontra no vetor B, e nada foi removido!\n", num);
                }
                break;
            case 6:
                printf("Digite um valor a ser inserido no início do vetor A:\n");
                scanf("%d", &num);
                if (inserirInicio(va, tamA, num)) {
                    tamA += 1;
                    printf("%d foi inserido com sucesso!\n", num);
                } else {
                    printf("%d não foi inserido, pois o vetor A está cheio!\n", num);
                }
                break;
            case 7:
                printf("Digite um valor a ser inserido no início do vetor B:\n");
                scanf("%d", &num);
                if (inserirInicio(va, tamB, num)) {
                    tamB += 1;
                    printf("%d foi inserido com sucesso!\n", num);
                } else {
                    printf("%d não foi inserido, pois o vetor B está cheio!\n", num);
                }
                break;
            default:
                break;
        }
    } while (opcao != 0);
    printf("Programa encerrado! Até logo!\n");
    return 0;
}

void preencherVetorDigitacao(int v[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("Digite o %dº valor:\n", i + 1);
        scanf("%d", &v[i]);
    }
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

int posMaiorValor(int v[], int n) {
    int maior = 0;
    for (int i = 1; i < n; i += 1) {
        if (v[i] > v[maior]) {
            maior = i;
        }
    }
    return maior;
}

int buscaSequencial(int v[], int n, int x) {
    for (int i = 0; i < n; i += 1) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

// EXEMPLO: { 4, 5, 7, 2, 3 } ==> { 4, 5, 2, 3 }
// função que remove um valor, deslocando para a esquerda todos
// os valores posteriores e retorna 1 se removeu, e 0 caso contrário
int removerValor(int v[], int n, int x) {
    int pos = buscaSequencial(v, n, x);
    if (pos == -1) {
        return 0;
    }
    for (int i = pos + 1; i < n; i += 1) {
        v[i - 1] = v[i];
    }
    return 1;
}

int inserirInicio(int v[], int n, int x) {
    if (n >= TAM) {
        return 0;
    }
    for (int i = n - 1; i >= 0; i -= 1) {
        v[i + 1] = v[i];
    }
    v[0] = x;
    return 1;
}
