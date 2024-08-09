#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct aviao {
    int ID;
    int tempo;
    int tipo; //0 decolagem, 1 aterrissagem
} Aviao;

typedef struct no {
    Aviao aviao;
    struct no *prox;
} No;

typedef struct fila {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

void inicializarFila(Fila *F) {
    F->inicio = NULL;
    F->fim = NULL;
    F->tamanho = 0;
    srand(time(NULL));
}

Aviao aviaoAleatorio() {
    Aviao aviao;
    aviao.ID = rand() % 100 + 1;
    aviao.tempo = rand() % 5 + 1;
    aviao.tipo = rand() % 2;
    return aviao;
}

int tempo_total = 0;
int tempo_aux = 0;

void usarPista(Fila *F, Aviao aviao) {
    No *aux = (No *) malloc(sizeof(No));
    aux->aviao = aviao;
    aux->prox = NULL;

    if (F->inicio == NULL) {
        F->inicio = aux;
        F->fim = aux;
    } 
    
    
    
    else if (aviao.tipo == 0) { // Decolagem
        No *aux2 = F->inicio;
        No *auxAnterior = NULL;
        while (aux2 != NULL && aux2->aviao.tipo == 1) {
            auxAnterior = aux2;
            aux2 = aux2->prox;
        }
        if (auxAnterior == NULL) { // Insere no início da fila
            aux->prox = F->inicio;
            F->inicio = aux;
        } else if (aux2 == NULL) { // Insere no fim da fila
            F->fim->prox = aux;
            F->fim = aux;
        } else { // Insere no meio da fila
            aux->prox = aux2;
            auxAnterior->prox = aux;
        }
    printf("", aviao);
        F->tamanho++;
    } 
    
    
    
    else { // Aterrissagem
        No *aux2 = F->inicio;
        No *auxAnterior = NULL;
        while (aux2 != NULL && aux2->aviao.tipo == 1) {
            auxAnterior = aux2;
            aux2 = aux2->prox;
        }
        if (auxAnterior == NULL) { // Insere no início da fila
            aux->prox = F->inicio;
            F->inicio = aux;
        } else { // Insere no meio ou fim da fila
            aux->prox = aux2;
            if (aux2 == NULL) {
                F->fim = aux;
            }
            auxAnterior->prox = aux;
        }
    }
    printf("Sucesso \n");
    F->tamanho++;

    ///Função para calcular tempo total
    if (true)
    {
        tempo_aux = tempo_aux + aviao.tempo; // soma o tempo do avião atual com o tempo acumulado anteriormente
        int tempo_decolagem = 5;
        int tempo_aterrisagem = 10;
        if (aviao.tipo == 0) // se for decolagem
        {
            tempo_total = tempo_aux + tempo_decolagem; // soma o tempo acumulado com o tempo de decolagem
        }
        else // se for aterrissagem
        {
            tempo_total = tempo_aux + tempo_aterrisagem; // soma o tempo acumulado com o tempo de aterrissagem
        }
        printf("Tempo total: %d\n", tempo_total); // imprime o tempo total
    }

}

int main(int argc, char const *argv[]) {
    Fila F;
    inicializarFila(&F);

    Aviao aviao1 = aviaoAleatorio();
    printf("\nId: %d\n", aviao1.ID);
    printf("Tempo: %d\n", aviao1.tempo);
    printf("Tipo: %d\n", aviao1.tipo);
    usarPista(&F, aviao1);

    Aviao aviao2 = aviaoAleatorio();
    printf("\nId: %d\n", aviao2.ID);
    printf("Tempo: %d\n", aviao2.tempo);
    printf("Tipo: %d\n", aviao2.tipo);
    usarPista(&F, aviao2);

    Aviao aviao3 = aviaoAleatorio();
    printf("\nId: %d\n", aviao3.ID);
    printf("Tempo: %d\n", aviao3.tempo);
    printf("Tipo: %d\n", aviao3.tipo);
    usarPista(&F, aviao3);

    return 0;
}