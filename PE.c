#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10



typedef struct pe
{
    int tamanho;
    float valores[MAX];
    int topo;
}PE;



void Inicializar(PE *Pilha){
    Pilha->topo = -1;
    Pilha->tamanho = 0;
}

bool Vazio(PE *Pilha){
    if (Pilha->tamanho == 0)
    {
        return true;
    }
    return false;
    
}

bool Cheio(PE *Pilha){
    if (Pilha->tamanho == MAX)
    {
        return true;
    }
    return false;
    
}

bool Push(PE *Pilha, float valor){
    if (Pilha->tamanho == MAX)
    {
        printf("Operação impossivel");
        return false;
    }

    Pilha->valores[Pilha->topo] = valor;
    Pilha->tamanho++;
    return true;
    
}

bool Pop(PE *Pilha){
    if (Pilha->tamanho == 0)
    {
        printf("Operação impossivel");
        return false;
    }
    Pilha->topo--;
    Pilha->tamanho--;
    return true;
    
}

bool Busca(PE *Pilha, float valor){
    if (Pilha->tamanho == 0)
    {
        printf("Pilha vazia");
    }
    int i = 0;
    while (i<Pilha->tamanho)
    {
        if (Pilha->valores[i] == valor)
        {
            printf("Achou");
            return true;
        }
        i++;
    }

    return false;
}

bool Impressao(PE *Pilha){
    if (Pilha->tamanho == 0)
    {
        printf("Pilha vazia");
    }
    int i = 0;
    while (i >= 0)
    {
       printf("%f", Pilha->valores[i]);
        i++;
    }

    return false;
}