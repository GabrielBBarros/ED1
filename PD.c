#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    float valor;
    struct no *prox;

}NO;


typedef struct pd
{
    NO *topo;
    int tamanho;
}PD;


void Inicializar(PD *Lista){
    Lista->topo = NULL;
    Lista->tamanho = 0;
}

bool Vazio(PD*Lista){
    if (Lista->tamanho == 0)
    {
        printf("Está vazio");
        return true;
    }
    return false;
}


bool Inserir(PD*Lista, float valor){
    
    NO *novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL)
    {
        return false;
    }
    
    novo->valor = valor;
    //Vc so tem dificuldade aqui
    novo->prox = Lista->topo;
    //
    Lista->topo = novo;
    Lista->tamanho++;
}

bool Busca(PD*Lista, float valor){
    int posicao = 0;
    NO *aux = Lista->topo;
    while (aux != NULL)
    {
        if (aux->valor == valor)
        {
            printf("Achou\n");
            return true;
        }
        aux = aux->prox;
        posicao++;
        
    }
    printf("Não achou\n");
    return false;
    
}

void Imprimir(PD*Lista){
    NO *aux = Lista->topo;
    if (Lista->topo == NULL)
    {
        printf("Não tem nada man");
    }
    
    while (aux != NULL)
    {
        printf("%f \n", aux->valor);
        aux = aux->prox;
    }
    

}


bool Remover(PD*Lista){
    if (Lista->topo == NULL)
    {
        printf("Operação impossivel até para o 007");
        return false;
    }
    NO *aux = Lista->topo;
    Lista->topo = aux->prox;
    free(aux);
    return true;
}


int main(){

    PD pilha;
    Inicializar(&pilha);

    Inserir(&pilha, 10);
    Inserir(&pilha, 20);
    Inserir(&pilha, 30);
    Inserir(&pilha, 40);
    Busca(&pilha, 20);
    Remover(&pilha);

    printf("Pilha:\n");
    Imprimir(&pilha);

    return 0;
}