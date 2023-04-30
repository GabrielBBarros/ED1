#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int valor;
    struct no *prox;
    struct no *ant;
}NO;


typedef struct ldde
{
    int tamanho;
    struct NO *inicio;
    struct NO *fim;
}LDDE;

void Inicializar(LDDE *Lista){
    Lista->inicio = NULL;
    Lista->fim = NULL;
    Lista->tamanho = 0;
}

bool Vazio(LDDE *Lista){
    if (Lista->inicio == NULL)
    {
        printf("Vazio \n");
        return true;
    }
    else
    {
        printf("Com elementos \n");
        return false;
    }
}

bool Inserir(LDDE *Lista, int valor){
    NO *aux = (NO*)malloc(sizeof(NO));
    if (aux == NULL)
    {
        printf("Erro de alocacao \n");
        return false;
    }
    aux->valor = valor;
    aux->prox = NULL;
    aux->ant = NULL;
    if (Lista->inicio == NULL)
    {
        aux->prox = NULL;
        Lista->inicio = aux;
        Lista->fim = aux;
        Lista->tamanho++;
        return true;
    }
    else
    {
        Lista->fim=aux;
        Lista->tamanho++;
        return true;
    }
    
    
    
    

}



void Imprimir(LDDE *Lista){
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

void Buscar(LDDE *Lista, int valor){
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