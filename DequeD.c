#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int valor;
    struct no *prox;
    struct no*ant;
}NO;


typedef struct DequeD
{
    NO *inicio;
    NO*fim;
    int tamanho;
}DequeD;

void Iniciar(DequeD *deque){
    deque->inicio = NULL;
    deque->fim = NULL;
    deque->tamanho = 0;
}

bool Vazio(DequeD *deque){
    if (deque->inicio == NULL)
    {
        printf("Deque vazio \n");
        return true;
    }
    else
    {
        printf("Deque não vazio \n");
        return false;
    }
}

bool InserirInicio(DequeD *deque, int valor){
    NO *aux = (NO*)malloc(sizeof(NO));
    aux->valor = valor;
    aux->ant = NULL;
    aux->prox = deque->inicio;

    if (deque->inicio == NULL)
    {
        deque->fim = aux;
    }
    else{
        deque->inicio->ant = aux;
    }
    deque->inicio = aux;
    deque->tamanho++;
    return true;
}

bool InserirFim(DequeD *deque, int valor){
    NO *aux = (NO*)malloc(sizeof(NO));
    aux->valor = valor;
    aux->ant = NULL;
    aux->prox = NULL;

    if (deque->fim == NULL)
    {
        deque->inicio = aux;
    }
    else{
        deque->fim->ant = aux;
        deque->fim->prox = aux;
    }
    deque->fim = aux;
    deque->tamanho++;
    return true;
}

bool RemoverInicio(DequeD *deque){
    if (deque->inicio == NULL)
    {
        printf("Nada disponivel\n");
        return false;
    }
    NO *aux = deque->inicio;

    deque->inicio=aux->prox;
    if (deque->inicio == NULL)
    {
        deque->fim = NULL;
    }
    else
    {
        deque->inicio->ant = NULL;
    }
    free(aux);
    deque->tamanho--;
    return true;  
}


bool RemoverFim(DequeD *deque){
    if (deque->inicio == NULL)
    {
        printf("Nada disponivel\n");
        return false;
    }
    NO *aux = deque->fim;

    deque->fim=aux->ant;
    if (deque->fim == NULL)
    {
        deque->inicio = NULL;
    }
    else
    {
        deque->fim->prox = NULL;
    }
    free(aux);
    deque->tamanho--;
    return true;  
}

void Imprimir(DequeD*deque){
    NO *aux = deque->inicio;
    while (aux != NULL)
    {
        printf("%i \n", aux->valor);
        aux = aux->prox;
    }
}

int main(int argc, char const *argv[])
{
    DequeD d;
    Iniciar(&d);
    
    InserirFim(&d, 1);
    InserirFim(&d, 2);
    InserirInicio(&d, 3);
    InserirInicio(&d, 4);
    
    Imprimir(&d);
    return 0;
}