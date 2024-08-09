#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct ArvoreBinaria
{
    int valor;
    struct ArvoreBinaria *esquerda;
    struct ArvoreBinaria *direita;
} ArvoreBinaria;

ArvoreBinaria* criarNo(int valor)
{
    ArvoreBinaria* novoNo = (ArvoreBinaria*)malloc(sizeof(ArvoreBinaria));
    if (novoNo == NULL)
    {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

ArvoreBinaria* inserirNo(ArvoreBinaria* raiz, int valor)
{
    if (raiz == NULL)
    {
        return criarNo(valor);
    }
    else
    {
        if (valor <= raiz->valor)
        {
            raiz->esquerda = inserirNo(raiz->esquerda, valor);
        }
        else
        {
            raiz->direita = inserirNo(raiz->direita, valor);
        }
        return raiz;
    }
}

bool buscarNo(ArvoreBinaria* raiz, int valor)
{
    if (raiz == NULL)
    {
        return false;
    }
    else if (valor == raiz->valor)
    {
        return true;
    }
    else if (valor < raiz->valor)
    {
        return buscarNo(raiz->esquerda, valor);
    }
    else
    {
        return buscarNo(raiz->direita, valor);
    }
}

void emOrdem(ArvoreBinaria* raiz)
{
    if (raiz != NULL)
    {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

void posOrdem(ArvoreBinaria* raiz)
{
    if (raiz != NULL)
    {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

void preOrdem(ArvoreBinaria* raiz)
{
    if (raiz != NULL)
    {
        printf("%d ", raiz->valor);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

int main()
{
    ArvoreBinaria* raiz = NULL; // Inicializando a árvore vazia

    // Exemplo de inserção de nós na árvore
    raiz = inserirNo(raiz, 50);
    raiz = inserirNo(raiz, 30);
    raiz = inserirNo(raiz, 20);
    raiz = inserirNo(raiz, 40);
    raiz = inserirNo(raiz, 70);
    raiz = inserirNo(raiz, 60);
    raiz = inserirNo(raiz, 80);

    // Imprimindo a árvore em ordem
    printf("Árvore binária em ordem: ");
    emOrdem(raiz);
    printf("\n");

    // Imprimindo a árvore em pós-ordem
    printf("Árvore binária em pós-ordem: ");
    posOrdem(raiz);
    printf("\n");

    // Imprimindo a árvore em pré-ordem
    printf("Árvore binária em pré-ordem: ");
    preOrdem(raiz);
    printf("\n");

    // Exemplo de busca na árvore
    int valorBuscado = 40;
    if (buscarNo(raiz, valorBuscado))
    {
        printf("%d encontrado na árvore.\n", valorBuscado);
    }
    else
    {
        printf("%d não encontrado na árvore.\n", valorBuscado);
    }

    return 0;
}
