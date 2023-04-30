#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    float valor;
    struct no *prox;
}NO;

typedef struct pmd
{
    struct NO *topo;
    int tamanho;
}PMD;

void Inicializar(PMD * Pilha){
    Pilha->topo = NULL;
    Pilha->tamanho = 0;
}

bool vazio(PMD * Pilha){
    if (Pilha->topo == NULL)
    {
        printf("Piilha vazia");
        return true;
    }
    return false;
}

