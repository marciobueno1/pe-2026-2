#include <stdio.h>
#include <string.h>

#define TAM 255

int lerStr(char str[], int tamMax, FILE *arq);

int main() {
    char frase[255];
    int status, numLinha = 1;
    FILE *arq = fopen("teste.txt", "rt");
    if (!arq) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    status = lerStr(frase, TAM, arq);
    while (!feof(arq) && status == 0) {
        printf("%2d: %s\n", numLinha, frase);
        numLinha += 1;
        status = lerStr(frase, TAM, arq);
    }
    if (!feof(arq)) {
        printf("\nErro ao ler linha do arquivo. erro = %d\n", status);
    }
    status = fclose(arq);
    if (status != 0) {
        printf("Erro ao fechar o arquivo!\n");
        return 2;
    }
    return 0;
}

int lerStr(char str[], int tamMax, FILE *arq) {
    char *status = fgets(str, tamMax, arq);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
    return status != str;
}
