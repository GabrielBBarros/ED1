#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct fe
{
    int valores[MAX];
    int inicio;
    int fim;
    int tamanho;
    int prox;
}FE;


void Inicializar(FE *F){
    F->inicio = 0;
    F->fim = -1;
    F->tamanho = 0;
}

bool Cheia(FE *F){
    if (F->tamanho == MAX)
    {
        return true;
    }
    return false;
}

bool Vazio(FE *F){
    if (F->tamanho == 0)
    {
        return true;
    }
    return false;
}

bool Inserir(FE *F, int valor){
    if (F->tamanho == MAX)
    {
     return false;
    }
    if (F->inicio == 0)
    {
        F->valores[F->inicio] = valor; 
    }
    F->valores[F->inicio] = valor;  
    F->fim++;
    F->tamanho++;
    return true;
}

bool Remover(FE *F, int *valor){
    if (F->tamanho == 0)
    {
     return false;
    }
    *valor = F->valores[F->inicio];
    F->inicio++;
    F->tamanho--;
    return true;
}

void Imprimir(FE *F){
    for (int i = 0; i <= F->tamanho; i++)
    {
        printf("%d \n", F->valores[i]);
    }
    
}

int main(int argc, char const *argv[])
{
    FE F;
    Inicializar(&F); // Inicializa a fila

    // Insere valores na fila
    Inserir(&F, 1);
    Inserir(&F, 2);
    Inserir(&F, 3);

    // Remove valores da fila
    int valor;
    Remover(&F, &valor);
    printf("Valor removido: %d\n", valor);
    Remover(&F, &valor);
    printf("Valor removido: %d\n", valor);

    // Insere mais valores na fila
    Inserir(&F, 4);
    Inserir(&F, 5);

    // Imprime a fila
    Imprimir(&F);

    return 0;
}


