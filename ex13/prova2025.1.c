#include <stdio.h>
#include <string.h>

#define TAM 100
#define TAM_NOME 50

struct Categoria {
    int codigo;
    char nome[50];
};
struct Produto {
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria; // código da categoria que está no vetor categorias
    int preco; // representa um valor numérico com 2 casas decimais
};

int lerStr(char str[], int tamMax);
void cadastrarCategoria(struct Categoria v[], int *qtd);
void imprimirCategorias(struct Categoria v[], int qtd);
int buscaSequencialCategoriaPorCodigo(struct Categoria v[], int qtd, int codigo);
void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);

int main() {
    int qtdCateg = 0, qtdProd = 0;
    struct Categoria categorias[TAM];
    struct Produto produtos[TAM];
    cadastrarCategoria(categorias, &qtdCateg);
    cadastrarCategoria(categorias, &qtdCateg);
    printf("Listagem de Categorias\n");
    imprimirCategorias(categorias, qtdCateg);
    return 0;
}

int buscaSequencialCategoriaPorCodigo(struct Categoria v[], int qtd, int codigo) {
    for (int i = 0; i < qtd; i += 1) {
        if (v[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}

void cadastrarCategoria(struct Categoria v[], int *qtd) {
    struct Categoria categoria;
    if (*qtd >= TAM) {
        printf("Vetor de categoria cheio, não é possível mais cadastrar!\n");
        return;
    }
    printf("Digite o código da categoria:\n");
    scanf("%d", &categoria.codigo);
    while (buscaSequencialCategoriaPorCodigo(v, *qtd, categoria.codigo) != -1) {
        printf("Código já existente! Digite outro código:\n");
        scanf("%d", &categoria.codigo);
    }
    printf("Digite o nome da categoria:\n");
    lerStr(categoria.nome, TAM_NOME); // para jogar fora o ENTER
    lerStr(categoria.nome, TAM_NOME); // para ler o nome

    v[*qtd] = categoria;
    *qtd += 1;
}

void imprimirCategorias(struct Categoria v[], int qtd) {
    for (int i = 0; i < qtd; i += 1) {
        printf("[%2d]: %2d %s\n", i + 1, v[i].codigo, v[i].nome);
    }
}

void imprimirProdutos(struct Produto vp[], int qtdProdutos, struct Categoria vc[], int qtdCategorias) {
    int pos;
    char *nomeCateg;
    for (int i = 0; i < qtdProdutos; i += 1) {
        pos = buscaSequencialCategoriaPorCodigo(vc, qtdCategorias, vp[i].categoria);
        if (pos != -1) {
            nomeCateg = vc[pos].nome;
        } else {
            nomeCateg = "categoria inexistente";
        }
        printf("%3d %s (%s) [%s] R$ %.2f", 
            vp[i].codigo, vp[i].titulo, vp[i].descricao, nomeCateg, (double) vp[i].preco / 100.0
        );
    }
}

void selectionSortPorDescricao(struct Produto v[], int qtd) {
    int i, j, menor;
    struct Produto aux;
    for (i = 0; i < qtd - 1; i++) {
        menor = i;
        for (j = i + 1; j <= qtd - 1 ; j++) {
            if (strcmp(v[j].descricao, v[menor].descricao) < 0) {
                menor = j;
            }
        }
        aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
    }
}

void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) { // char *x <=> char x[]
    int inicio = 0, fim = qtd - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (strcmp(v[meio].descricao, x) == 0) {
            return meio;
        } else if (strcmp(v[meio].descricao, x) < 0) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
 }

int lerStr(char str[], int tamMax) {
    char *status = fgets(str, tamMax, stdin);
    int tam = strlen(str);
    if (tam > 0 && str[tam - 1] == '\n') {
        str[tam - 1] = '\0';
    }
    return status != str;
}