#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct NO
{
    int valor;
    struct NO* prox;
}NO;

typedef struct Pilha
{
    struct NO *topo;
}Pilha;

void Push(Pilha *P, int valor){
    NO *aux = (NO*)malloc(sizeof(NO));
    aux->valor = valor;
    aux->prox = P->topo;
    P->topo = aux;   
}

int main(int argc, char const *argv[])
{
    Pilha pilha = {NULL};
    char operacao;
    int valor;
    while (true)
    {
        printf("Digite um valor ou uma operacao (+): ");
        scanf(" %c", &operacao);

        if (operacao == '+')
        {
            if (pilha.topo == NULL || pilha.topo->prox == NULL)
            {
                printf("Erro: pilha vazia.\n");
                exit(EXIT_FAILURE);
            }

            int valor1 = pilha.topo->valor;
            pilha.topo = pilha.topo->prox;

            int valor2 = pilha.topo->valor;
            pilha.topo = pilha.topo->prox;

            Push(&pilha, valor2 + valor1);
            printf("%i \n", pilha.topo->valor);
        }
        else
        {
            scanf("%i", &valor);
            Push(&pilha, valor);
        }
    }

    return 0;
}
