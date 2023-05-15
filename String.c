#include <stdio.h>

typedef struct strdim {
    char c;
    struct strdim *prox;
} STR;

//1) Cria uma string vazia, deve ser usada antes de qualquer outra operação
STR *criarString(){
    STR *aux = (STR*)malloc(sizeof(STR));
    if (aux == NULL)
    {
        printf("Erro \n");
        exit (1);
    }
    aux->c = '\0';
    aux->prox = NULL;
    return aux;
}

//2) Reinicializa uma string existente, através da remoção de todos os elementos contidos nela
void reinicializar(STR *str){
    STR *aux = str;
    while (aux != NULL)
    {
        STR *prox = aux->prox;
        free(aux);
        aux = aux->prox;
    }   
}

//3) Imprime uma string dinâmica
void imprimir(STR *str){
    STR *aux = str;
    while (aux != NULL)
    {
        printf("%c", aux->c);
        aux = aux->prox;
    }
}

//4) Função que retorna o tamanho de uma string dinâmica
size_t tamanho (STR *str){
    size_t tamanho = 0;
    STR *aux = str;
    while (aux != NULL)
    {
        tamanho++;
        aux = aux->prox;
    }
    return tamanho-1;
}

//5) Insere um determinado caracter (c) na string (str1)
void insereCaractere(STR *str1, char c, int pos) {
    STR *novo = (STR*) malloc(sizeof(STR)); // aloca memória para o novo nó
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->c = c; // define o caractere do novo nó

    STR *anterior = str1;
    STR *atual = str1->prox;

    // percorre a lista até a posição indicada
    for (int i = 0; i < pos; i++) {
        if (atual == NULL) {
            printf("Posição inválida.\n");
            exit(1);
        }
        anterior = atual;
        atual = atual->prox;
    }

    // insere o novo nó na lista
    anterior->prox = novo;
    novo->prox = atual;
}



//6 Copia o conteúdo da string (str1) para a string (str2) utilizando o função insere
void copiaString(STR *str1, STR *str2) {
    STR *atual = str1->prox;
    int pos = 0;

    while (atual != NULL) {
        insereCaractere(str2, atual->c, pos);
        atual = atual->prox;
        pos++;
    }
}


//7) Concatena a string (str1) com a string (str2) armazenando o resultado na string (str3)
//utilizando a função copia

void concatenaString(STR *str1, STR *str2, STR *str3) {
    copiaString(str1, str3);
    copiaString(str2, str3);
}

//8) Remove da string (str1), a quantidade de caracteres especificado por (nro) a partir da posição
//(start)
void remove_chars(STR **str1, int start, int nro) {
    STR *aux = *str1;
    STR *prev = NULL;
    int count = 0;

    while (aux != NULL && count < start) {
        prev = aux;
        aux = aux->prox;
        count++;
    }

    if (aux == NULL) {
        printf("Posicao inicial invalida.\n");
        return;
    }

    while (nro > 0 && aux != NULL) {
        STR *tmp = aux->prox;
        free(aux);
        aux = tmp;
        nro--;
    }

    if (prev == NULL) {
        *str1 = aux;
    } else {
        prev->prox = aux;
    }
}


//9) Insere na string (str1) uma substring (subs) a partir da posição (start). A inserção não deve
//ser feita no fim da string. Inserção no fim deve usar a concatenação de strings
void insert_substring(STR **str1, int start, STR *subs) {
    STR *aux = *str1;
    STR *prev = NULL;
    int count = 0;

    while (aux != NULL && count < start) {
        prev = aux;
        aux = aux->prox;
        count++;
    }

    if (aux == NULL) {
        printf("Posicao inicial invalida.\n");
        return;
    }

    while (subs != NULL) {
        STR *new_char = (STR*) malloc(sizeof(STR));
        new_char->c = subs->c;
        new_char->prox = aux;

        if (prev == NULL) {
            *str1 = new_char;
        } else {
            prev->prox = new_char;
        }

        prev = new_char;
        subs = subs->prox;
    }
}



//10) Função que verifica se uma string (str1) é menor que outra (str2), caso verdade a função
//retorna True, senão False

int str_less_than(STR *str1, STR *str2) {
    while (str1 != NULL && str2 != NULL) {
        if (str1->c < str2->c) {
            return 1;
        } else if (str1->c > str2->c) {
            return 0;
        }
        str1 = str1->prox;
        str2 = str2->prox;
    }

    if (str1 == NULL && str2 != NULL) {
        return 1;
    }

    return 0;
}

//11) Função que verifica se uma string (str1) é igual a outra (str2), caso verdade a função retorna
//True, senão False

int str_equal(STR *str1, STR *str2) {
    while (str1 != NULL && str2 != NULL) {
        if (str1->c != str2->c) {
            return 0;
        }
        str1 = str1->prox;
        str2 = str2->prox;
    }

    if (str1 == NULL && str2 == NULL) {
        return 1;
    }

    return 0;
}


//12) Busca a posição (local) na string (str1) em que a string (padrão) se inicia. Se (local) = 0
//então (padrão) não esta contida em str1, caso contrário (local) e a posição de início da string
//(padrão) dentro da string (str1)

int buscaPadrao(STR *str1, STR *padrao, int local) {
    int i = 1, j;
    STR *p = str1, *q;

    while (i < local && p != NULL) {
        p = p->prox;
        i++;
    }

    while (p != NULL) {
        j = 0;
        q = p;

        while (q != NULL && padrao != NULL && q->c == padrao->c) {
            q = q->prox;
            padrao = padrao->prox;
            j++;
        }

        if (padrao == NULL) {
            return i;
        }

        p = p->prox;
        i++;
        padrao = padrao->prox;
        padrao = padrao->prox != NULL ? padrao : NULL;
    }

    return 0;
}

