#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct fe
{
    int valores[MAX];
    int fim;
    int inicio;
    int tamanho;
}FE;

void Inicializar(FE *Fila){
    Fila->tamanho = 0;
    Fila->inicio = -1;
    Fila->fim = -1;
}

bool Vazio(FE *Fila){
    if (Fila->inicio == -1)
    {
        printf("Vazio \n");
        return true;
    }
    else
    {
        printf("Com elementos \n");
        return false;
    }
}

bool Cheio(FE *Fila){
    if (Fila->fim == MAX)
    {
        printf("Cheio \n");
        return true;
    }
    else
    {
        printf("Não esta cheio \n");
        return false;
    }
}

bool Inserir(FE *Fila, float valor){
    //Fila cheia
    if (Fila->fim == MAX)
    {
        printf("Fila cheia \n");
        return false;
    }
    //Inserir no ínicio
    if (Fila->inicio == -1)
    {
        Fila->valores[Fila->inicio] = valor;
        Fila->tamanho++;
        return true;
    }
    //Inserir no fim
    Fila->valores[Fila->fim] = valor;
    Fila->tamanho++;
    return true;
}

bool Remover(FE *Fila, float *valor){
    if (Fila->inicio == -1)
    {
        printf("Fila vazia \n");
        return false;
    }
    
    *valor = Fila->valores[Fila->inicio];
    Fila->inicio++;
    Fila->tamanho--;
    return true;
}

bool Buscar(FE *Fila, float valor){
    if (Fila->inicio == Fila->fim)
    {
        printf("Fila vazia \n");
        return false;
    }
    for (int i = 0; i <= Fila->fim; i++)
    {
        if (Fila->valores[i] == valor)
        {
            printf("Encontrou");
            return true;
        }
        
    } 
}

bool Imprimir(FE *Fila){
    if (Fila->inicio == Fila->fim)
    {
        printf("Fila vazia \n");
        return false;
    }
    for (int i = 0; i <= Fila->fim; i++)
    {
            printf("%f \n", Fila->valores[i]);
    } 
    return true;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
