#include <stdio.h>

int main() {
    FILE *arq;
    int status;
    double numeros[3];
    arq = fopen("teste.bin", "rb");
    if (arq == NULL) {
        printf("Não foi possível abrir o arquivo!\n");
        return 1;
    } else {
        printf("Arquivo aberto com sucesso!\n");
    }

    status = fread(numeros, sizeof(double), 3, arq);
    if (status == 3) {
        printf("Os números lidos foram: %f - %f - %f\n",
            numeros[0], numeros[1], numeros[2]);
    } else {
        printf("Erro ao ler os números. status = %d\n", status);
    }

    status = fclose(arq);
    if (status == 0) {
        printf("Arquivo fechado com sucesso!\n");
    } else {
        printf("Erro no fechamento do arquivo com código %d\n", status);
    }

    return 0;
}