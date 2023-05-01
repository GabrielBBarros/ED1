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

    Pilha->topo++;
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
            printf("Achou\n");
            return true;
        }
        i++;
    }
    printf("Nao achou\n");
    return false;
}

bool Impressao(PE *Pilha){
    if (Pilha->tamanho == 0)
    {
        printf("Pilha vazia");
    }
    int i = 0;
    while (i < Pilha->tamanho)
    {
       printf("%f \n", Pilha->valores[i]);
        i++;
    }
}

int main(int argc, char const *argv[])
{
    PE pilha;
    Inicializar(&pilha);

    Push(&pilha, 10);
    Push(&pilha, 20);
    Push(&pilha, 30);
    Push(&pilha, 40);
    Pop(&pilha);
    Busca(&pilha, 10);
    Impressao(&pilha);
    return 0;
}
