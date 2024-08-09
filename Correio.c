#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define PESO 10

typedef struct encomenda
{
    int valor;
    int tipo_cliente;   //0 e 1
    int peso;
}Encomenda;

typedef struct NO_Pilha{
    Encomenda encomenda;
    struct NO_Pilha *prox;
}NO_Pilha;

typedef struct NO_Fila
{
    Encomenda encomenda;
    struct NO_Fila *prox;
}NO_Fila;

typedef struct Pilha
{
    NO_Pilha *topo;
    int tamanho_pilha;
}Pilha;

typedef struct Fila
{
    NO_Fila *inicio;
    NO_Fila *fim;
    int tamanho_fila;
}Fila;

Encomenda GerarEncomenda(){
    Encomenda encomenda;
    encomenda.valor = rand()%100+1;
    encomenda.tipo_cliente = rand()%2;
    encomenda.peso = rand()%25+1;
    return encomenda;
}

bool VerificarPeso(Encomenda encomenda){
    int peso_aux = encomenda.peso;
    if (peso_aux>PESO)
    {
        printf("Encomenda não entra nos parametros\n");
        return false;
    }
    else
    {
        printf("Tudo certo\n");
        return true;
    }
}

void FilaENtrada(Fila *F, Encomenda encomenda){
    if (VerificarPeso(encomenda))
    {
        NO_Fila *aux = (NO_Fila*)malloc(sizeof(NO_Fila));
        aux->encomenda = encomenda;
        aux->prox = NULL;
        if (F->inicio == NULL)
        {
            F->inicio = aux;
            F->fim = aux;
        }
        else
        {
            F->fim->prox = aux;
            F->fim = aux;
        }
        F->tamanho_fila++;
        printf("Enfileirado \n");    
    }
    else{
        printf("Erro na encomenda\n");
    }  
}

Encomenda PilhaEspera(Pilha *P, Fila *F){
    Encomenda encomenda = F->inicio->encomenda;
    NO_Pilha *aux = (NO_Pilha*)malloc(sizeof(NO_Pilha));
    aux->encomenda = encomenda;
    aux->prox = P->topo;
    P->topo =aux;
    P->tamanho_pilha++;

    NO_Fila *temp = F->inicio;
    F->inicio = F->inicio->prox;
    free(temp);
    F->tamanho_fila--;
    return encomenda;

}

int main()
{
    srand(time(NULL)); // Seed the random number generator


    printf("OI");

  
    return 0;
}
