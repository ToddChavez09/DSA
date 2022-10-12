#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node;

Node *head;

void push(int x){
    Node *new = malloc(sizeof(Node));
    new->data = x;
    new->next = head;
    head = new;
}

void pop(){
    Node *p = head;
    head = head->next;
    printf("Popped element: %d\n", p->data);
    free(p);
}


void display(){
    Node *p = head;
    while(p->next!=NULL){
        printf("%d -> ",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}

int main(){
    int x, a, b, c;
    printf("Input 1: ");
    scanf("%d", &x);
    printf("Input 2: ");
    scanf("%d", &a);
    printf("Input 3: ");
    scanf("%d", &b);
    printf("Input 4: ");
    scanf("%d", &c);

    push(x);
    push(a);
    push(b);
    push(c);
    pop();
    pop();
    display();

    return 0;
}