#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct no
{
    int valor;
    int linha;
    int coluna;
    struct no *baixo;
    struct no *direita;
}NO;


typedef struct MatrizEsparsa
{
    NO *linha[5];
    NO *coluna[5];
}MatrizEsparsa;


//Inicializar como nulo
void Inicializar(MatrizEsparsa *M){
    for (int i = 0; i < 5; i++)
    {
        M->linha[i] = NULL;
    }
    for (int j = 0; j < 5; j++)
    {
        M->coluna[j] = NULL;
    }
}

void Inserir(MatrizEsparsa* M, int valor, int linha, int coluna)
{
    // Aloca memória para um novo nó da matriz esparsa
    NO* novo_no = (NO*) malloc(sizeof(NO));
    if (novo_no == NULL) {
        printf("Erro de alocação de memória.");
        exit(1);
    }
    
    // Preenche as informações do novo nó
    novo_no->valor = valor;
    novo_no->linha = linha;
    novo_no->coluna = coluna;
    
    // Insere o novo nó na lista encadeada da linha correspondente
    novo_no->direita = M->linha[linha];
    M->linha[linha] = novo_no;
    
    // Insere o novo nó na lista encadeada da coluna correspondente
    novo_no->baixo = M->coluna[coluna];
    M->coluna[coluna] = novo_no;
}

void MatrizK(MatrizEsparsa* M, int linha, int valork){
    NO *aux = M->linha[linha];
    while (aux!=NULL)
    {
        aux->valor = aux->valor+valork;
        if (aux->valor == 0)
        {
            aux->valor = NULL;
        }
        aux =aux->direita;
    }  
}



//Imprimir linha
void ImprimirLinha(MatrizEsparsa *M, int linha){
    NO *aux = M->linha[linha];
    while (aux != NULL)
    {
        printf("Valor: %i \n", aux->valor);
        aux=aux->direita;
    } 
}

//Imprimir coluna
void ImprimirColuna(MatrizEsparsa *M, int coluna){
    NO *aux = M->coluna[coluna];
    while (aux != NULL)
    {
        printf("Valor: %i \n", aux->valor);
        aux=aux->baixo;
    } 
}


void ImprimirGeral(MatrizEsparsa *M){
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            NO *aux = M->linha[i];
            while (aux != NULL)
            {
                if(aux->coluna == j){
                    printf("%i ",aux->valor);
                    break;
                }
                aux=aux->direita;
            }
            if(aux == NULL){
                printf("0 ");
            }
        }
        printf("\n");
    }
}




int main(int argc, char const *argv[])
{
    MatrizEsparsa M;
    Inicializar(&M);
    
    Inserir(&M, 5, 0, 1);
    Inserir(&M, 8, 1, 2);
    Inserir(&M, 3, 2, 3);
    Inserir(&M, 6, 3, 4);
    Inserir(&M, 9, 4, 0);
    ImprimirLinha(&M, 0);
    ImprimirLinha(&M, 0);
    ImprimirGeral(&M);
    return 0;
}
