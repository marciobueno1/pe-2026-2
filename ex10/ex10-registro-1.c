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
double calcularIMC(struct Pessoa p);
void imprimirPessoa(struct Pessoa p);
void preencherDigitacaoPessoa(struct Pessoa *p);

int main() {
    struct Pessoa pessoa;
    preencherDigitacaoPessoa(&pessoa);
    imprimirPessoa(pessoa);
    double imc = calcularIMC(pessoa);
    printf("O IMC desta pessoa é %.2f\n", imc);
    return 0;
}

void imprimirPessoa(struct Pessoa p) {
    printf("%s, %d anos, %.1f kg, %.1f m\n", p.nome, p.idade, p.peso, p.altura);
}

void preencherDigitacaoPessoa(struct Pessoa *p) {
    printf("Digite o seu nome:\n");
    lerStr(p->nome, TAM_NOME);
    printf("Digite a sua idade:\n");
    scanf("%d", &p->idade);
    printf("Digite o seu peso:\n");
    scanf("%lf", &p->peso);
    printf("Digite a sua altura:\n");
    scanf("%lf", &p->altura);
}

// void preencherDigitacaoPessoa(struct Pessoa *p) {
//     printf("Digite o seu nome:\n");
//     lerStr((*p).nome, TAM_NOME);
//     printf("Digite a sua idade:\n");
//     scanf("%d", &(*p).idade);
//     printf("Digite o seu peso:\n");
//     scanf("%lf", &(*p).peso);
//     printf("Digite a sua altura:\n");
//     scanf("%lf", &(*p).altura);
// }

double calcularIMC(struct Pessoa p) {
    return p.peso / (p.altura * p.altura);
}

void lerStr(char str[], int tamMax) {
    fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
}
