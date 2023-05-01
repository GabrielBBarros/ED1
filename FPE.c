#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct fpe
{
    int valores[MAX];
    int inicio;
    int fim;
    int tamanho;
} FPE;

void Inicializar(FPE *Fila)
{
    Fila->inicio = 0;
    Fila->fim = 0;
    Fila->tamanho = 0;
}

bool Vazio(FPE *Fila)
{
    if (Fila->tamanho == 0)
    {
        printf("Fila vazia\n");
        return true;
    }
    else
    {
        printf("Fila não vazia\n");
        return false;
    }
}

bool Cheio(FPE *Fila)
{
    if (Fila->tamanho == MAX)
    {
        printf("Fila cheia\n");
        return true;
    }
    else
    {
        printf("Fila não cheia\n");
        return false;
    }
}

bool Inserir(FPE *Fila, int valor)
{
    if (Fila->tamanho == MAX)
    {
        printf("Operação impossível\n");
        return false;
    }

    Fila->valores[Fila->fim] = valor;
    Fila->fim = (Fila->fim + 1) % MAX;
    Fila->tamanho++;

    return true;
}

bool Inserir_Prioridade(FPE *Fila, int valor)
{
    if (Fila->fim == MAX)
    {
        printf("Operação impossível\n");
        return false;
    }
    if (Fila->inicio == -1)
    {
        Fila->valores[++Fila->fim] = valor;
        Fila->inicio++;
        Fila->tamanho++;
        return true;
    }
    else if (valor > 60)
    {
        Fila->valores[--Fila->inicio] = valor;
        Fila->tamanho++;
        return true;
    }
    else
    {
        Fila->valores[++Fila->fim] = valor;
        Fila->tamanho++;
        return true;
    }
}

int Remover(FPE *Fila)
{
    if (Fila->inicio == NULL)
    {
        printf("Fila vazia\n");
        return -1;
    }
    else
    {
        int valor = Fila->valores[Fila->inicio];
        Fila->inicio = (Fila->inicio + 1) % MAX;
        Fila->tamanho--;
        return valor;
    }
}

void Imprimir(FPE *Fila)
{
    if (Fila->tamanho > 0)
    {
        printf("Fila: ");

        for (int i = 0; i < Fila->tamanho; i++)
        {
            int posicao = (Fila->inicio + i) % MAX;
            printf("%d ", Fila->valores[posicao]);
        }

        printf("\n");
    }
}

bool Buscar(FPE *Fila, int valor){
    if (Fila->tamanho > 0) {
        for (int i = Fila->inicio; i < Fila->fim; i++) {
            if (Fila->valores[i] == valor) {
                printf("Valor %d encontrado na posicao %d da fila\n", valor, i);
                return true;
            }
        }
        printf("Valor %d nao encontrado na fila\n", valor);
        return false;
    }
    else {
        printf("Fila vazia\n");
        return false;
    }
}





int main(int argc, char const *argv[])
{

    FPE Fila;
    Inicializar(&Fila);

    Inserir(&Fila, 10);
    Inserir(&Fila, 20);
    Inserir(&Fila, 30);
    Inserir(&Fila, 40);
    Inserir(&Fila, 50);
    Inserir_Prioridade(&Fila, 70);
    Inserir_Prioridade(&Fila, 80);
    
    Imprimir(&Fila);
    
    Buscar(&Fila, 30);
    Buscar(&Fila, 60);
    return 0;
}
