#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct fila_estatica
{
    int valores[MAX];
    int inicio;
    int fim;
    int tamanho;
} FilaEstatica;

void inicializar(FilaEstatica *fila)
{
    fila->tamanho = 0;
    fila->inicio = 0;
    fila->fim = -1;
}

bool vazia(FilaEstatica *fila)
{
    if (fila->tamanho == 0)
    {
        printf("Fila vazia.\n");
        return true;
    }
    else
    {
        printf("Fila com elementos.\n");
        return false;
    }
}

bool cheia(FilaEstatica *fila)
{
    if (fila->tamanho == MAX)
    {
        printf("Fila cheia.\n");
        return true;
    }
    else
    {
        printf("Fila nao esta cheia.\n");
        return false;
    }
}

bool inserir(FilaEstatica *fila, int valor)
{
    if (fila->tamanho == MAX)
    {
        printf("Erro: Fila cheia.\n");
        return false;
    }
    else
    {
        fila->fim++;
        fila->valores[fila->fim] = valor;
        fila->tamanho++;
        return true;
    }
}

bool remover(FilaEstatica *fila, int *valor)
{
    if (fila->tamanho == MAX)
    {
        printf("Erro: Fila vazia.\n");
        return false;
    }
    else
    {
        *valor = fila->valores[fila->inicio];
        fila->inicio++;
        fila->tamanho--;
        return true;
    }
}

bool buscar(FilaEstatica *fila, int valor)
{
    if (fila->tamanho == 0)
    {
        printf("Erro: Fila vazia.\n");
        return false;
    }

    for (int i = fila->inicio; i <= fila->fim; i++)
    {
        if (fila->valores[i] == valor)
        {
            printf("Valor encontrado.\n");
            return true;
        }
    }
    printf("Valor nao encontrado.\n");
    return false;
}

void imprimir(FilaEstatica *fila)
{
    if (fila->tamanho == 0)
    {
        printf("Erro: Fila vazia.\n");
        return;
    }

    printf("Conteudo da fila:\n");

    for (int i = fila->inicio; i <= fila->fim; i++)
    {
        printf("%d ", fila->valores[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    FilaEstatica fila;
    int valor;

    inicializar(&fila);

    vazia(&fila);
    cheia(&fila);

    inserir(&fila, 10);
    inserir(&fila, 20);
    inserir(&fila, 30);
    imprimir(&fila);


}
