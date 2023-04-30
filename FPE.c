#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct fpe
{
    int valores[MAX];
    int inicio;
    int fim;
    int tamanho
}FPE;

void Inicializar(FPE *Fila){
    Fila->inicio = -1;
    Fila->fim = -1;
    Fila->tamanho = 0;
}

bool Vazio(FPE *Fila){
    if (Fila->inicio == Fila->fim)
    {
        printf("Fila vazia \n");
        return false;
    }
    else
    {
        printf("Não vazia \n");
        return true;
    }
}

bool Cheio(FPE *Fila){
    if (Fila->fim == MAX)
    {
        printf("Fila cheia \n");
        return false;
    }
    else
    {
        printf("Não cheia \n");
        return true;
    }
}

bool Inserir(FPE *Fila, float valor){
    if (Fila->fim == MAX)
    {
        printf("Operacao impossivel \n");
        return false;
    }
    if (Fila->inicio == -1)
    {
        Fila->valores[Fila->inicio] = valor;
        Fila->tamanho++;
        return true;
    }
    else
    {
        Fila->valores[Fila->fim] = valor;
        Fila->tamanho++;
        return true;
    }   
}

bool Inserir_Prioridade(FPE *Fila, float valor){
    if (Fila->fim == MAX)
    {
        printf("Operacao impossivel \n");
        return false;
    }
    if (Fila->inicio == -1)
    {
        Fila->valores[Fila->inicio] = valor;
        Fila->tamanho++;
        return true;
    }
    if (valor>60)
    {
        Fila->valores[Fila->inicio] = valor;
        Fila->tamanho++;
        return true;
    }
    
    else
    {
        Fila->valores[Fila->fim] = valor;
        Fila->tamanho++;
        return true;
    }   
}



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
