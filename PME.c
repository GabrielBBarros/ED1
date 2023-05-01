#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10
#define NUM_PILHAS 3

typedef struct PME
{
int valores[MAX * NUM_PILHAS];
int topo[NUM_PILHAS];
int base[NUM_PILHAS];
int tamanho[NUM_PILHAS];
} PME;

void Inicializar(PME *Pilha)
{
for (int i = 0; i < NUM_PILHAS; i++)
{
Pilha->base[i] = i * MAX;
Pilha->topo[i] = (i * MAX) - 1;
Pilha->tamanho[i] = 0;
}
}

bool Vazia(PME *Pilha, int numPilha)
{
if (Pilha->topo[numPilha] < Pilha->base[numPilha])
{
return true;
}
else
{
return false;
}
}

bool Cheia(PME *Pilha, int numPilha)
{
if (Pilha->topo[numPilha] >= (numPilha + 1) * MAX)
{
return true;
}
else
{
return false;
}
}

bool Push(PME *Pilha, int numPilha, int valor)
{
if (Cheia(Pilha, numPilha))
{
printf("Pilha %d cheia!\n", numPilha);
return false;
}
else
{
Pilha->topo[numPilha]++;
Pilha->valores[Pilha->topo[numPilha]] = valor;
Pilha->tamanho[numPilha]++;
return true;
}
}

int main()
{
    printf("OI");
PME Pilha;
Inicializar(&Pilha);
Push(&Pilha, 0, 1);
Push(&Pilha, 0, 2);
Push(&Pilha, 1, 3);
Push(&Pilha, 1, 4);
Push(&Pilha, 1, 5);
Push(&Pilha, 2, 6);
Push(&Pilha, 2, 7);
Push(&Pilha, 2, 8);
Push(&Pilha, 2, 9);
Push(&Pilha, 2, 10);
Push(&Pilha, 2, 11);
Push(&Pilha, 2, 12);
return 0;
}