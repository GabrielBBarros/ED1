#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    float valor;
    struct no *prox;
}NO;


typedef struct ld
{
    int tamanho;
    struct NO *inicio;
    struct NO *final;

}LD;


void Inicializar(LD *Lista){
    Lista->inicio = NULL;
    Lista->tamanho = 0;
}

bool Vazio(LD *Lista){
    if (Lista->tamanho == 0)
    {
        return true;
    }
    return false;
}

bool InserirInicio(LD *Lista, float valor){
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = novo;
    if (Lista->inicio == NULL)
    {
        novo->prox = NULL;
        Lista->inicio = novo;
        Lista->final = novo;
    }
    else{
        novo->prox = Lista->inicio;
        Lista->inicio = novo;
    }
    Lista->tamanho++;
    return true;
}

bool InserirFinal(LD *Lista, float valor){
    NO *novo = (NO *)malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = novo;
    if (Lista->inicio == NULL)
    {
        Lista->inicio = novo;
        Lista->final = novo;
    }
    else{
        Lista->final = novo;
    }
    Lista->tamanho++;
}

bool Remover(LD *Lista, float valor){
    if (Lista->inicio == NULL) {
        printf("Lista vazia\n");
        return false;
    }   
    
    NO *aux = Lista->inicio;
    NO *anterior = NULL;
    
    while (aux != NULL) {
        if (aux->valor == valor) {
            if (anterior == NULL) { // elemento a ser removido é o primeiro da lista
                Lista->inicio = aux->prox;
            } else {
                anterior->prox = aux->prox;
            }
            
            free(aux);
            Lista->tamanho--;
            return true;
        }
        anterior = aux;
        aux = aux->prox;
    }
    
    printf("Elemento nao encontrado na lista\n");
    return false;
}



void Imprimir(LD *Lista){
    if (Lista->tamanho == 0)
    {
        printf("Lista vazia");
        return;
    }
    NO *aux = Lista->inicio;
    while (aux != NULL)    
    {
        printf("%f ", aux->valor);
        aux = aux->prox;
    }
}

void Buscar(LD *Lista, float valor){
    if (Lista->tamanho == 0)
    {
        printf("Lista vazia");
        return;
    }
    NO *aux = Lista->inicio;
    while(aux != NULL)
    {
        printf("%f ", aux->valor);
        aux = aux->prox;
    }
}