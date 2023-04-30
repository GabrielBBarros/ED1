#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct le
{
    int valores[MAX];
    int inicio;
    int final;
    int tamanho;
}LE;

void Inicializar(LE *Lista){
    Lista->tamanho = 0;
    Lista->inicio = -1;
    Lista->final = -1;
}

bool Vazia(LE *Lista){
    if (Lista->inicio == -1)
    {
        printf("Vazia \n");
        return true;
    }
    else{
        printf("Contem elementos \n");
        return false;
    }
    
}

bool Cheia(LE *Lista){
    if (Lista->inicio == MAX)
    {
        printf("Cheia \n");
        return true;
    }
    else{
        printf("Nao cheia \n");
        return false;
    }
    
}

bool InserirInicio(LE *Lista, int valor){
    if (Lista->tamanho == MAX)
    {
        printf("Impossivel \n");
        return false;
    }
    Lista->valores[Lista->inicio] = valor;
    Lista->tamanho++;
    return true;
}

bool InserirFinal(LE *Lista, int valor){
    if (Lista->tamanho == MAX)
    {
        printf("Impossivel \n");
        return false;
    }
    Lista->valores[Lista->final] = valor;
    Lista->tamanho++;
    return true;
}


bool Remover(LE *Lista, int valor){
    int posicao = -1;
    for (int i = 0; i < Lista->tamanho; i++)
    {
        if (Lista->valores[i] == valor)
        {
            posicao = i;
            break;
        }
    }

    if (posicao == -1)
    {
        printf("Valor nao encontrado \n");
        return false;
    }

    for (int i = posicao; i < Lista->tamanho - 1; i++)
    {
        Lista->valores[i] = Lista->valores[i+1];
    }

    Lista->tamanho--;
    printf("Valor removido \n");
    return true;
}

void Imprimir(LE *Lista){
    if (Lista->tamanho == 0)
    {
        printf("Lista vazia \n");
    }
    for (int i = Lista->inicio; i < Lista->final; i++)
    {
        printf("%d \n", Lista->valores[i]);
    }
}


bool Busca(LE *Lista, int valor){
    if (Lista->tamanho == 0)
    {
        printf("Lista vazia \n");
        return false;
    }
    for (int i = 0; i < Lista->tamanho; i++)
    {
        if (Lista->valores[i] == valor)
        {
            printf("Achou \n");
            return true;
        }
        
    }
    printf("Valor nao encontrado \n");
    return false;
}