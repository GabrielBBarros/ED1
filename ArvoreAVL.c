#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoAVL {
    int valor;
    int altura;
    struct NoAVL* esquerda;
    struct NoAVL* direita;
} NoAVL;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int altura(NoAVL* no) {
    if (no == NULL)
        return 0;
    return no->altura;
}

int fatorBalanceamento(NoAVL* no) {
    if (no == NULL)
        return 0;
    return altura(no->esquerda) - altura(no->direita);
}

NoAVL* criarNo(int valor) {
    NoAVL* novoNo = (NoAVL*)malloc(sizeof(NoAVL));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->altura = 1;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

NoAVL* rotacaoDireita(NoAVL* y) {
    NoAVL* x = y->esquerda;
    NoAVL* T2 = x->direita;

    x->direita = y;
    y->esquerda = T2;

    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;
    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;

    return x;
}

NoAVL* rotacaoEsquerda(NoAVL* x) {
    NoAVL* y = x->direita;
    NoAVL* T2 = y->esquerda;

    y->esquerda = x;
    x->direita = T2;

    x->altura = max(altura(x->esquerda), altura(x->direita)) + 1;
    y->altura = max(altura(y->esquerda), altura(y->direita)) + 1;

    return y;
}

NoAVL* inserirNo(NoAVL* no, int valor) {
    if (no == NULL)
        return criarNo(valor);

    if (valor < no->valor)
        no->esquerda = inserirNo(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserirNo(no->direita, valor);
    else
        return no;

    no->altura = 1 + max(altura(no->esquerda), altura(no->direita));

    int balanceamento = fatorBalanceamento(no);

    if (balanceamento > 1 && valor < no->esquerda->valor)
        return rotacaoDireita(no);

    if (balanceamento < -1 && valor > no->direita->valor)
        return rotacaoEsquerda(no);

    if (balanceamento > 1 && valor > no->esquerda->valor) {
        no->esquerda = rotacaoEsquerda(no->esquerda);
        return rotacaoDireita(no);
    }

    if (balanceamento < -1 && valor < no->direita->valor) {
        no->direita = rotacaoDireita(no->direita);
        return rotacaoEsquerda(no);
    }

    return no;
}

void preOrdem(NoAVL* no) {
    if (no != NULL) {
        printf("%d ", no->valor);
        preOrdem(no->esquerda);
        preOrdem(no->direita);
    }
}

int main() {
    NoAVL* raiz = NULL; // Inicializando a árvore vazia

    // Exemplo de inserção de nós na árvore AVL
    raiz = inserirNo(raiz, 10);
    raiz = inserirNo(raiz, 20);
    raiz = inserirNo(raiz, 30);
    raiz = inserirNo(raiz, 40);
    raiz = inserirNo(raiz, 50);
    raiz = inserirNo(raiz, 25);

    // Imprimindo a árvore em pré-ordem
    printf("Árvore AVL em pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    return 0;
}
