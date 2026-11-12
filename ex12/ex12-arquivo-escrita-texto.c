#include <stdio.h>
#include <string.h>

#define TAM 255

int lerStr(char str[], int tamMax, FILE *arq);

int main() {
    char frase[255];
    int status;
    FILE *arq = fopen("teste.txt", "at");
    if (!arq) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }
    printf("Digite uma frase para ser guardada: ");
    lerStr(frase, TAM, stdin);
    // salva a frase digitada dentro de ASPAS
    status = fprintf(arq, "\"%s\"\n", frase);
    if (status < 0) {
        printf("Erro ao gravar a frase no arquivo!\n");
    } else {
        printf("Frase salva com sucesso!\n");
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
