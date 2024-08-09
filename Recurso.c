#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct recurso
{
    float valor;
    char destino[50];
}Recurso;

typedef struct NO_Fila
{
    Recurso recurso;
    NO_Fila *prox;
}NO_Fila;

typedef struct NO_Pilha
{
    Recurso recurso;
    NO_Fila *prox;
}NO_Pilha;


typedef struct Pilha
{
    struct NO_Pilha *topo;
    int tamanho_pilha;
}Pilha;


typedef struct Fila
{
    struct NO_Fila *inicio;
    struct NO_Fila *fim;
    int tamanho_fila;
}Fila;

Recurso Gerar(){
    Recurso recurso;
    recurso.valor = rand()%2000000;
    recurso.destino = 
    return recurso;
}