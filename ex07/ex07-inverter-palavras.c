#include <stdio.h>
#include <string.h>

void inverterPalavras(char str[]);

int main() {
    char frase[] = "o rato roeu";
    printf("Frase original: %s\n", frase);
    inverterPalavras(frase);
    printf("Frase com palavras invertidas: %s\n", frase);
    return 0;
}

void inverterPalavra(char str[], int inicio, int fim) {
    char aux;
    for (int i = 0; i < (fim - inicio + 1) / 2; i += 1) {
        aux = str[inicio + i];
        str[inicio + i] = str[fim - i];
        str[fim - i] = aux;
    }
}

void inverterPalavra2(char str[], int inicio, int fim) {
    char aux;
    while (inicio < fim) {
        aux = str[inicio];
        str[inicio] = str[fim];
        str[fim] = aux;
        inicio += 1;
        fim -= 1;
    }
}

void inverterPalavras(char str[]) {
    int tam = strlen(str);
    int inicio = 0, fim;
    // inverterPalavra2(str, 0, tam); // adicionando essa linha resolve questao e da prova
    for (int i = 0; i < tam; i += 1) {
        if (str[i] == ' ') {
            fim = i - 1;
            inverterPalavra2(str, inicio, fim);
            inicio = i + 1;
        }
    }
    inverterPalavra2(str, inicio, tam - 1);
}