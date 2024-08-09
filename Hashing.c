#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct Node {
    char name[50];
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Função hash simples para mapear a chave para um índice
int hashFunction(char* key) {
    int sum = 0;
    for (int i = 0; i < strlen(key); i++) {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

// Função para inicializar a tabela hash
void initializeHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// Função para inserir um nome na tabela hash
void insert(char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;

    int index = hashFunction(name);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Nome '%s' inserido com sucesso.\n", name);
}

// Função para buscar um nome na tabela hash
void search(char* name) {
    int index = hashFunction(name);
    Node* temp = hashTable[index];
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Nome '%s' encontrado.\n", name);
            return;
        }
        temp = temp->next;
    }
    printf("Nome '%s' não encontrado.\n", name);
}

// Função para remover um nome da tabela hash
void removeName(char* name) {
    int index = hashFunction(name);
    Node* current = hashTable[index];
    Node* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                hashTable[index] = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Nome '%s' removido com sucesso.\n", name);
            return;
        }
        previous = current;
        current = current->next;
    }

    printf("Nome '%s' não encontrado.\n", name);
}

// Função para imprimir todos os nomes na tabela hash
void printHashTable() {
    printf("Conteúdo da Tabela Hash:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Índice %d: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%s ", temp->name);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    initializeHashTable();

    insert("Alice");
    insert("Bob");
    insert("Carol");
    insert("David");

    printHashTable();

    search("Bob");
    search("Eve");

    removeName("Carol");
    removeName("Frank");

    printHashTable();

    return 0;
}




/*Exercicio 2: alternativa: O tempo gasto com pesquisas em uma tabela hashing depende do tamanho da tabela e aí reside a grande vantagem destes métodos: sempre são usadas tabelas pequenas.
A função hash de transformação deve envolver uma operação simples sobre a chave.*/

/*Exercicio 3: b) O tratamento de colisões é necessário para determinar o local da chave no momento da inserção na tabela.*/

/*Exercicio 4: B) Apenas II.*/