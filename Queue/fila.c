#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int value;
    struct Node* next;
} Node;

typedef struct Fila{
    struct Node *head, *tail;
} Fila;

Fila* enqueue(Fila *fila, int val){
    Node* new = (Node*)malloc(sizeof(Node));
    new->next = NULL;
    new->value = val;
    if(fila->head == NULL){
        fila->head = new;
        fila->tail = new;
    }else{
        fila->tail->next = new;
        fila->tail = new;
    }
    return fila;
}

Fila* dequeue(Fila *fila, int* val){
    Node *aux = NULL;
    if(fila->head == NULL){
        printf("fila vazia\n");
    }else{
        aux = fila->head->next;
        fila->head->next = aux->next;
        (*val) = aux->value;
        free(aux);
    }
    return fila;
}

Fila* listPosition(Fila *fila, int position){
    Fila *filinha = fila;
    Node *aux = fila->head;
    if(filinha->head == NULL){
        printf("fila vazia\n");
    }else{
        int i = 0;
        while(i < position && aux->next != NULL){
        aux = aux->next;
        i++;
        }
    }
    filinha->head = aux;
    return filinha;
}

Node* listFind(Fila* fila, int val){
    Node* aux = NULL;
    if(fila->head == NULL){
        printf("fila vazia\n");
    }else{
        aux = fila->head;
        while(aux->next != NULL && aux->next->value != val){
            aux = aux->next;
        }  
    }
    return aux;
}

void listPrint(Node* fila){
    Node* aux = fila;
    while(aux != NULL){
        printf("%d ", aux->value);
        aux = aux->next;
    }
    printf("\n");
}

int main(){
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->head = NULL;
    fila->tail = NULL;
    
    int valor, value;

    char evento[4];

    do
    {
        scanf(" %3[^ ]", evento);
        if (strcmp(evento, "INS") == 0)
        {
            printf("Valor a inserir: ");
            scanf("%d", &valor);
            enqueue(fila, valor);
        }
        else if (strcmp(evento, "DPO") == 0)
        {
            Fila* aux = NULL;
            printf("Posicao a deletar: ");
            scanf("%d", &valor);
            aux = listPosition(fila, valor);
            dequeue(aux, &value);
            printf("%d\n", value);
        }
        else if (strcmp(evento, "DVA") == 0)
        {
            Node* aux = NULL;
            printf("Valor a deletar: ");
            scanf("%d", &valor);
            aux = listFind(fila->head, valor);
            fila = dequeue(aux, &value);
            printf("%d\n", value);
        }
        else if (strcmp(evento, "PRI") == 0)
        {
            listPrint(fila->head);
        }
    } while (strcmp(evento, "END") != 0);

    return 0;
}