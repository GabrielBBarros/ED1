#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct String
{
    char c;
    struct String *prox;
    struct String *ant;
}String;

typedef struct Lista
{
    String *inicio;
    String *fim;
    int tamanho;
}Lista;


void Inicializacao(Lista *L){
    L->inicio =NULL;
    L->fim = NULL;
    L->tamanho = 0;
}

void Insercao(Lista *L, char c){
    String *aux = (String*)malloc(sizeof(String));
    aux->c = c;
    aux->prox = NULL;

    if (L->inicio == NULL)
    {
        L->inicio = aux;
        L->fim = aux;
    }
    else{
        aux->prox = L->inicio;
        L->inicio = aux;
    }
    L->tamanho++;
}

bool Comparar(Lista *L1, Lista*L2){
    if (L1->tamanho == L2->tamanho)
    {
        String *aux1 = L1->inicio;
        String *aux2 = L2->inicio;

        while (aux1=!NULL && aux2!=NULL)
        {
            if (aux1->c != aux2->c)
            {
                return false;
            }
            aux1 = aux1->prox;
            aux2 = aux2->prox;
        }
        return true;  
    }
    else{
        printf("String diferentes");
        return false;
    }
    
}