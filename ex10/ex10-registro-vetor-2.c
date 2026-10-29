#include <stdio.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_PESSOAS 5

struct Pessoa {
    char nome[TAM_NOME];
    int idade;
    double peso;
    double altura;
};

void lerStr(char str[], int tamMax);
double calcularIMC(struct Pessoa p);
void imprimirPessoas(struct Pessoa v[], int n);
void imprimirPessoa(struct Pessoa p);
void preencherDigitacaoPessoa(struct Pessoa *p);
void preencherDigitacaoPessoas(struct Pessoa v[], int n);
int posPessoaMaisVelha(struct Pessoa v[], int n);
int buscaSequencialPorIdade(struct Pessoa v[], int n, int idade);
int buscaSequencialPorNome(struct Pessoa v[], int n, char nome[]);
void bubblesortPorIdade (struct Pessoa v[], int n);

int main() {
    int posMaisVelha;
    struct Pessoa pessoas[TAM_PESSOAS];
    printf("Digitação do vetor de pessoas:\n");
    preencherDigitacaoPessoas(pessoas, TAM_PESSOAS);
    printf("\nImpressão do Vetor de Pessoas\n");
    imprimirPessoas(pessoas, TAM_PESSOAS);
    posMaisVelha = posPessoaMaisVelha(pessoas, TAM_PESSOAS);
    printf("\nA pessoa mais velha está na posição %d e é ", posMaisVelha + 1);
    imprimirPessoa(pessoas[posMaisVelha]);
    printf("\nOREDENAÇÃO...\n");
    bubblesortPorIdade(pessoas, TAM_PESSOAS);
    imprimirPessoas(pessoas, TAM_PESSOAS);
    return 0;
}

void imprimirPessoas(struct Pessoa v[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("[%d]: ", i + 1);
        imprimirPessoa(v[i]);
    }
}

void imprimirPessoa(struct Pessoa p) {
    double imc = calcularIMC(p);
    printf("%s, %d anos, %.1f kg, %.1f m, imc = %.2f\n", p.nome, p.idade, p.peso, p.altura, imc);
}

void preencherDigitacaoPessoas(struct Pessoa v[], int n) {
    for (int i = 0; i < n; i += 1) {
        printf("\nDados da Pessoa %d\n", i + 1);
        preencherDigitacaoPessoa(&v[i]);
    }
}

void preencherDigitacaoPessoa(struct Pessoa *p) {
    char tmp[TAM_NOME];
    printf("Digite o seu nome:\n");
    lerStr(p->nome, TAM_NOME);
    printf("Digite a sua idade:\n");
    scanf("%d", &p->idade);
    printf("Digite o seu peso:\n");
    scanf("%lf", &p->peso);
    printf("Digite a sua altura:\n");
    scanf("%lf", &p->altura);
    lerStr(tmp, TAM_NOME); // Limpar o ENTER que sobrou do scanf anterior
}

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

int posPessoaMaisVelha(struct Pessoa v[], int n) {
    int pos = 0;
    for (int i = 1; i < n; i += 1) {
        if (v[i].idade > v[pos].idade) {
            pos = i;
        }
    }
    return pos;
}

int buscaSequencialPorIdade(struct Pessoa v[], int n, int idade) {
    for (int i = 0; i < n; i += 1) {
        if (v[i].idade == idade) {
            return i;
        }
    }
    return -1;
}

int buscaSequencialPorNome(struct Pessoa v[], int n, char nome[]) {
    for (int i = 0; i < n; i += 1) {
        if (strcmp(v[i].nome, nome) == 0) {
            return i;
        }
    }
    return -1;
}

void bubblesortPorIdade (struct Pessoa v[], int n) {
    int i, pos = 0, trocou = 1, fim = n - 2;
    struct Pessoa chave;
    while (trocou) {
        trocou = 0;
        for (i = 0; i <= fim; i++) {
            if (v[i].idade > v[i+1].idade) {
                chave = v[i];
                v[i] = v[i+1];
                v[i+1] = chave;
                pos = i; 
                trocou = 1;
            }
        }
        fim = pos - 1;
    }
}
