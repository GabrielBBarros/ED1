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
    int valor;
    char operacao;
    printf("Digite uma operacao: ");
    scanf("%c", operacao);
    while (true)
    {
        if (operacao == '+')
        {
            printf("Digite um valor (ou 0 para sair): ");
        scanf("%i", &valor);

        if (valor == 0)
        {
            break;
        }

        Push(&pilha, valor);

        int soma = 0;
        NO *aux = pilha.topo;
        while (aux != NULL)
        {
            soma += aux->valor;
            aux = aux->prox;
        }

        printf("Soma: %i\n", soma);
        }



        if (operacao == '-')
        {
        printf("Digite um valor (ou 0 para sair): ");
        scanf("%i", &valor);

        if (valor == 0)
        {
            break;
        }

        Push(&pilha, valor);

        int subtracao = 0;
        NO *aux = pilha.topo;
        while (aux != NULL)
        {
            subtracao -= aux->valor;
            aux = aux->prox;
        }

        printf("Soma: %i\n", subtracao);
        }
        
        
    }

    return 0;
}
