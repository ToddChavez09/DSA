#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

/* Node* insert(Node *root, int data){
    Node *aux = (Node*)malloc(sizeof(Node));

    aux->data = data;
    aux->left = NULL;
    aux->right = NULL;

    if(root == NULL){
        root = aux;
    }else{
        Node *cur = root;
        Node *parent = NULL;
        while(1){
            parent = cur;
            if(data < parent->data){
                cur = cur->left;
                if(cur == NULL){
                    parent->left = aux;
                    return root;
                }
            }else{
                cur = cur->right;
                if(cur == NULL){
                    parent->right = aux;
                    return root;
                }
            }
        }
    }
    return root;
} */

Node* insert(Node *root, long int data){
    Node *aux = (Node*)malloc(sizeof(Node));

    aux->data = data;
    aux->left = NULL;
    aux->right = NULL;

    if(root == NULL){
        root = aux;
    }else{
        if(data < root->data){
            root->left = insert(root->left, data);
        }else{
            root->right = insert(root->right, data);
        }
    }
    return root;
}

void inOrder(struct Node* root){
    if(root){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void preOrder(struct Node* root){
    if(root){
        printf("%d ", root->data);
        inOrder(root->left);
        inOrder(root->right);
    }
}

void postOrder(struct Node* root){
    if(root){
        inOrder(root->left);
        inOrder(root->right);
        printf("%d ", root->data);
    }
}

int search(Node *root, int data){
    if(root == NULL){
        return 0;
    }else{
        printf("%d ", root->data);
        if(data == root->data){
            return 1;
        } else{
            if(data > root->data){
                return search(root->right, data);
            }else{
                return search(root->left, data);
            }
        }
    }
}

int main(){
    Node *root = NULL;
    int tam;

    printf("Tamanho da arvore: ");
    scanf("%d", &tam);

    int array[tam];
    int busca;

    printf("Inserir numeros: ");
    for(int i = 0; i < tam; i++){
        scanf("%d", &array[i]);
    }
    printf("\n");

    printf("Numeros Inseridos: ");
    for(int i =0; i < tam; i++){
        root = insert(root, array[i]);
        printf("%d ", array[i]);
    }
    printf("\n");

    printf("\nVisualizacao Pre Order: ");
    preOrder(root);
    printf("\n");

    printf("\nVisualizacao In Order: ");
    inOrder(root);
    printf("\n");

    printf("\nVisualizacao Post Order: ");
    postOrder(root);
    printf("\n\n");

    int num;
    printf("Buscar Numero: ");
    scanf("%d", &num);
    printf("\n");

    printf("Elementos percorridos: ");
    busca = search(root, num);
    printf("\n");

    if(busca){
        printf("\n[%d] Encontrado.\n", num);
    } else{
        printf("\n[%d] Nao encontrado.\n", num);
    }

    return 0;
}