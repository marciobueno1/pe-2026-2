#include <stdio.h>

int main() {
    FILE *arq;
    int status;
    double num, numModif;
    arq = fopen("teste.bin", "r+b");
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    status = fread(&num, sizeof(double), 1, arq);
    while (!feof(arq) && status == 1) {
        if (status == 1) {
            printf("%f \t", num);
        } else {
            printf("Erro ao ler um número. status = %d\n", status);
            break;
        }
        status = fseek(arq, -1 * sizeof(double), SEEK_CUR);
        if (status != 0) {
            printf("\nNão conseguiu voltar 1 posição no arquivo!\n");
            break;
        }
        numModif = num + 1;
        status = fwrite(&numModif, sizeof(double), 1, arq);
        if (status != 1) {
            printf("\nErro ao tentar modificar o valor no arquivo!\n");
            break;
        }
        status = fread(&num, sizeof(double), 1, arq);
    }

    status = fclose(arq);
    if (status == 0) {
        printf("Arquivo fechado com sucesso!\n");
    } else {
        printf("Erro no fechamento do arquivo com código %d\n", status);
    }

    return 0;
}