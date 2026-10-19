#include <stdio.h>
// #include <string.h>

#define TAM 50

int meuStrLen(char str[]);
void meuStrCpy(char strDestino[], char strOrigem[]);
void lerStr(char str[], int tamMax);

int main() {
    char frase[TAM], frase2[TAM];
    printf("Digite uma frase: ");
    lerStr(frase, TAM);
    // scanf("%49[^\n]", frase);
    printf("\nA frase digitada foi: '%s' e tem tamanho %d.\n", frase, meuStrLen(frase));
    meuStrCpy(frase2, frase);
    printf("\nA frase2 foi: '%s' e tem tamanho %d.\n", frase, meuStrLen(frase));
    return 0;
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = meuStrLen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}

int meuStrLen(char str[]) {
    int tam = 0;
    while (str[tam] != '\0') {
        tam += 1;
    }
    return tam;
}

void meuStrCpy(char strDestino[], char strOrigem[]) {
    int i = 0;
    while (strOrigem[i] != '\0') {
        strDestino[i] = strOrigem[i];
        i += 1;
    }
    strDestino[i] = '\0';
}
