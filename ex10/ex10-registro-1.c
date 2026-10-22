#include <stdio.h>
#include <string.h>

#define TAM_NOME 50

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso;
    double altura;
};

void lerStr(char str[], int tamMax);

int main() {
    struct Pessoa pessoa;
    // Preenchimento de uma variável do tipo Pessoa
    printf("Digite o seu nome:\n");
    lerStr(pessoa.nome, TAM_NOME);
    printf("Digite a sua idade:\n");
    scanf("%d", &pessoa.idade);
    printf("Digite o seu peso:\n");
    scanf("%lf", &pessoa.peso);
    printf("Digite a sua altura:\n");
    scanf("%lf", &pessoa.altura);
    // Impressão de uma variável do tipo Pessoa
    printf("%s, %d anos, %.1f kg, %.1f m\n", pessoa.nome, pessoa.idade, pessoa.peso, pessoa.altura);
    // Cálculo do IMC
    double imc = pessoa.peso / (pessoa.altura * pessoa.altura);
    // Impressão do IMC
    printf("O IMC desta pessoa é %.2f\n", imc);
    return 0;
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}
