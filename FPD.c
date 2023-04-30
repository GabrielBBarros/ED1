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
    struct NO *inicio;
    struct NO *fim;
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
    if (Fila->inicio == NULL)
    {
        Fila->inicio = aux;
        Fila->tamanho++;
        return true;
    }
    if (valor>60)
    {
        Fila->inicio = aux;
        Fila->tamanho++;
        return true;
    }
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

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
