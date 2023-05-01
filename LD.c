#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    float valor;
    struct no *prox;
} NO;

typedef struct ld
{
    int tamanho;
    NO *inicio;
    NO *final;
} LD;

void Inicializar(LD *Lista)
{
    Lista->inicio = NULL;
    Lista->final = NULL;
    Lista->tamanho = 0;
}

bool Vazio(LD *Lista)
{
    return Lista->tamanho == 0;
}

bool InserirInicio(LD *Lista, float valor)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return false;
    }

    novo->valor = valor;
    novo->prox = Lista->inicio;
    Lista->inicio = novo;

    if (Lista->final == NULL)
    {
        Lista->final = novo;
    }

    Lista->tamanho++;

    return true;
}

bool InsercaoOrdenada(LD *Lista, float valor){
    NO *aux = (NO*)malloc(sizeof(NO));
    aux->valor = valor;
    aux->prox = NULL;
    if (Lista->inicio == NULL || valor < Lista->inicio->valor)
    {
        aux->prox = Lista->inicio;
        Lista->inicio = aux;
        Lista->tamanho++;
        return true;
    }
    NO *anterior = Lista->inicio;
    NO *atual = anterior->prox;
    while (atual != NULL && atual->valor < valor)
    {
        anterior = atual;
        atual = atual->prox;
    }
    aux->prox = atual;
    anterior->prox = aux;
    Lista->tamanho++;
    return true;  
}


















bool InserirFinal(LD *Lista, float valor)
{
    NO *novo = (NO *)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return false;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if (Lista->final == NULL)
    {
        Lista->inicio = novo;
        Lista->final = novo;
    }
    else
    {
        Lista->final->prox = novo;
        Lista->final = novo;
    }

    Lista->tamanho++;

    return true;
}

bool Remover(LD *Lista, float valor)
{
    NO *atual = Lista->inicio;
    NO *anterior = NULL;

    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            if (anterior == NULL)
            {
                Lista->inicio = atual->prox;
            }
            else
            {
                anterior->prox = atual->prox;
            }

            if (atual == Lista->final)
            {
                Lista->final = anterior;
            }

            free(atual);
            Lista->tamanho--;

            return true;
        }

        anterior = atual;
        atual = atual->prox;
    }

    return false;
}

void Imprimir(LD *Lista)
{
    NO *atual = Lista->inicio;

    while (atual != NULL)
    {
        printf("%.2f ", atual->valor);
        atual = atual->prox;
    }

    printf("\n");
}

void Buscar(LD *Lista, float valor)
{
    NO *atual = Lista->inicio;

    while (atual != NULL)
    {
        if (atual->valor == valor)
        {
            printf("Valor encontrado: %.2f\n", valor);
            return;
        }

        atual = atual->prox;
    }

    printf("Valor nao encontrado: %.2f\n", valor);
}

int main() {
    LD lista;
    Inicializar(&lista);

    InserirFinal(&lista, 5);
    InserirFinal(&lista, 7);
    InserirFinal(&lista, 9);
    InserirFinal(&lista, 11);

    printf("Lista: ");
    Imprimir(&lista);
    printf("\n");

    Buscar(&lista, 7);
    printf("\n");

    Remover(&lista, 9);

    printf("Lista apos remover: ");
    Imprimir(&lista);
    printf("\n");

    return 0;
}
