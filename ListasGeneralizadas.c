#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int tipo;
    //0 = átomo
    //1 = lista
    union
    {
        int valor;
        struct no *Lista;
    }index;
    struct no *prox;   
}NO;
