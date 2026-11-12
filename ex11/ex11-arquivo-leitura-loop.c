#include <stdio.h>

int main() {
    FILE *arq;
    int status;
    double num;
    arq = fopen("teste.bin", "rb");
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    status = fread(&num, sizeof(double), 1, arq);
    while (!feof(arq)) {
        if (status == 1) {
            printf("%f \t", num);
        } else {
            printf("Erro ao ler um número. status = %d\n", status);
            break;
        }
        status = fread(&num, sizeof(double), 1, arq);
    }

    status = fclose(arq);
    if (status == 0) {
        printf("\nArquivo fechado com sucesso!\n");
    } else {
        printf("\nErro no fechamento do arquivo com código %d\n", status);
    }

    return 0;
}