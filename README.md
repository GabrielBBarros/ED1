# Estrutura de Dados I
 
# Parte 1
 Em Estrutura de Dados 1 aprendemos várias coisas, no primeiro termos vemos Pilha, Lista, Lista Cruzada, Matriz Esparsa e Filas. No segundo termo vemos Hashing e Árvores.

## Lista

 Há alguns tipos de listas: 
 
    -Lista Encadeada Estática (Memória limitada, definida por MAX, sem ponteiro);
    -Lista Encadeada Dinâmica (Memória alocada dinamicamente, com ponteiro);
    -Lista Duplamente Encadeada Estática (Memória limitada com indicador para proximo e anterior);
    -Lista Duplamente Encadeada Dinâmica (Memória dinamica com ponteiro para proximo e anterior).

A estrutura básica desses códigos na lista se diferencia entre dinâmica e estática, por exemplo:

 Dinâmica:
        
    typedef struct no{
    int valor;
    struct no *prox;
    }NO;
     
    typedef struct lista{
       int tamanho;
       NO *inicio;
       NO *fim;
    }Lista;
    
Estático:
 
    typedef struct lista{
       int tamanho;
       int inicio;
       int fim;
       int valores[MAX};
    }Lista;
    
    
