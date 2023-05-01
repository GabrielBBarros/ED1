#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct dequee
{
    int inicio;
    int fim;
    int tamanho;
    int valores[MAX];

}DequeE;

void Inicializar(DequeE *deque){
    deque->inicio = 0;
    deque->fim = -1;
    deque->tamanho = 0;
}

bool Cheio(DequeE *deque){
    if (deque->inicio == 0)
    {
        return true;
    }
    return false;
    
}

bool Vazio(DequeE *deque){
    if (deque->tamanho == MAX)
    {
        return true;
    }
    return false;
}

bool InserirInicio(DequeE *deque, int valor){
    if (deque->tamanho == MAX)
    {
        return false;
    }
    deque->inicio--;
    deque->valores[deque->inicio] = valor;
    return true;  
}

bool InserirFim(DequeE *deque, int valor){
    if (deque->tamanho == MAX)
    {
        return false;
    }
    deque->fim++;
    deque->valores[deque->fim] = valor;
    return true;  
}

bool RemoverInicio(DequeE *deque){
    if (deque->tamanho == 0)
    {
        return false;
    }
    deque->inicio++;
    return true;
}

bool RemoverFim(DequeE *deque){
    if (deque->tamanho == 0)
    {
        return false;
    }
    deque->fim--;
    return true;
}

void Imprimir(DequeE *deque){
    if (deque->tamanho == 0)
    {
        printf("Sem elementos \n");
    }
    for (int i = deque->inicio; i <= deque->fim; i++)
    {
        printf("%i \n", deque->valores[i]);
    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
