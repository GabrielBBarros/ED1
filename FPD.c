#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct no
{
    float valor;
    struct no *prox;
}NO;


typedef struct fpd
{
    int tamanho;
    NO *inicio;
    NO *fim;
}FPD;


void Inicializar(FPD *Fila){
    Fila->inicio = NULL;
    Fila->fim = NULL;
    Fila->tamanho = 0;
}

bool Vazio(FPD *Fila){
    if (Fila->tamanho == 0)
    {
        return true;
    }
    return false;
}

bool InserirGeral(FPD *Fila, float valor){
    NO *aux = (NO *)malloc(sizeof(NO));
    if (aux == NULL)
    {
        printf("Erro de alocação \n");
        return false;
    }
    aux->valor = valor;
    aux->prox = NULL;

    if (Fila->inicio == NULL) // Se a fila estiver vazia
    {
        Fila->inicio = aux;
        Fila->fim = aux;
        Fila->tamanho++;
        return true;
    }

    if (valor > 60) // Inserção com prioridade
    {
        aux->prox = Fila->inicio;
        Fila->inicio = aux;
        Fila->tamanho++;
        return true;
    }

    // Inserção no final da fila
    Fila->fim->prox = aux;
    Fila->fim = aux;
    Fila->tamanho++;
    return true;
}



bool Remover(FPD *Fila, float *valor){
    NO *aux = Fila->inicio;
    if (Fila->inicio == NULL)
    {
        printf("Operacao impossivel \n");
        return false;
    }
    *valor = aux->valor;
    Fila->inicio = aux->prox;
    free(aux);
    Fila->tamanho--;   
    return true;
}

void Imprimir(FPD *Fila){
    NO *aux = Fila->inicio;
    if (Fila->inicio == NULL)
    {
        printf("Vazio \n");
    }
    while (aux != NULL)
    {
        printf("%f \n", aux->valor);
        aux =aux->prox;
    }   
}

bool Buscar(FPD *Fila, float valor){
    NO *aux = Fila->inicio;
    if (Fila->inicio == NULL)
    {
        printf("Vazio \n");
        return false;
    }
    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            printf("Achou : %f", aux->valor);
            return true;
        }
        aux =aux->prox;
    }   
    return false;
}

int main()
{
    FPD fila;
    Inicializar(&fila);
    InserirGeral(&fila, 20);
    InserirGeral(&fila, 30);
    InserirGeral(&fila, 40);
    InserirGeral(&fila, 50);
    InserirGeral(&fila, 70);
    Imprimir(&fila);
    Buscar(&fila, 30);
    return 0;
}

