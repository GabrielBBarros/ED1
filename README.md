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
    //struct no *ant;
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
    
 Além disso uma das coisas importantes é que na lista podemos inserir no início e no fim. Podemos também fazer outras operações como Inicialização, Cheia, Vazia, Remoção, Busca e Impressão.
 
 ## Fila
 
 Numa fila as caracteristicas são muito parecidos com as listas, a diferença é que na lista apenas inserimos no final, a não ser que ele seja preferencial. As operações são as mesmas.
 
 Dinâmica:
    
    Dinâmico:
    
    typedef struct no{
    int valor;
    //struct no *ant;
    struct no *prox;
    }NO;
     
    typedef struct lista{
       int tamanho;
       NO *inicio;
       NO *fim;
    }Lista;
    
    
    Estático:
    
    typedef struct fila{
       int tamanho;
       int inicio;
       int fim;
       int valores[MAX};
    }Fila;
 
 ## Pilha
 
 Em uma pilha diferente das demais segua a estrutra FILO (First in Last out), dessa forma a remoção só pode ser feita no topo da pilha, não em outro lugar, de mais as pilhas seguem o mesmo padrão em termos de função, logo abaixo um exemplo de estrutura de pilha estática e dinamica.
 
     Dinâmica:
     
     typedef struct no
     {
         float valor;
         struct no *prox;
     }NO;

     typedef struct fila
     {
         int tamanho;
         struct NO *inicio;
         struct NO *fim;
     }Fila;
     
     
     Estática:
     
     typedef struct fila_estatica
     {
         int valores[MAX];
         int inicio;
         int fim;
         int tamanho;
     } FilaEstatica;

## Matriz Esparsa

 Uma matriz esparsa é como se fosse uma tabela da ordem (x,y). É colocado os valores o o restante é preenchido com elementos nulos.
 
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
