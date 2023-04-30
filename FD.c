#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    float valor;
    struct no *prox;
}NO;

typedef struct fd
{
    int tamanho;
    struct NO *inicio;
    struct NO *fim;
}FD;

void Iniciar(FD *Fila){
    Fila->inicio = NULL;
    Fila->fim = NULL;
    Fila->tamanho = 0;
}

bool vazio(FD *Fila){
    if (Fila->inicio == NULL)
    {
        printf("Está vazia \n");
        return true;
    }
    return false;
}


bool InserirInicio(FD *Fila, float valor){
    NO *aux = (NO *)malloc(sizeof(NO));
    aux->valor = valor;
    aux->prox = NULL;
        if (Fila->inicio == NULL)
        {
            Fila->inicio = aux;
            Fila->tamanho++;
            return true;
        }
    Fila->fim = aux;
    Fila->tamanho++;
    return true;
}



bool Remover(FD *Fila, float *valor){
    NO *aux;
    if (Fila->inicio == NULL)
    {
        printf("Operação impossível");
        return false;
    }
    aux = Fila->inicio;
    *valor = aux->valor;
    Fila->inicio = aux->prox;
    free(aux);
    Fila->tamanho--;   
}

bool Busca(FD *Fila, float valor){
    NO *aux = Fila->inicio;
    if (Fila->inicio == NULL)
    {
        printf("Fila vazia");
    }
    while(aux != NULL)
    {
        if (aux->valor == valor)
        {
            printf("Encontrado");
            return true;
        }
        aux = aux->prox;
    }
    return false; 
}

void Imprimir(FD *Fila){
    NO *aux = Fila->inicio;
    if (Fila->inicio == NULL)
    {
        printf("Fila vazia");  
    }
    else
    {
        while (aux != NULL)
        {
            printf("%f ", aux->valor);
            aux=aux->prox;
        }
        
    }   
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
