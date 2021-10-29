# Linked List

## Contents

- [Linked List](#linked-list)
- [Singly Linked List](#singly-linked-list)
    - [Insertion of Node](#insertion-of-node)
    - [Deletion of Node](#deletion-of-node)

---
## Linked List

Linked List is a linear data structure, it's element are not stored at a contiguous location they are linked using pointers.

- Advantages
    - Dynamic Size
    - Ease of insertion/deletion

- Drawbacks
    - Random access is not allowed
    - Extra memory space for pointer with each element of the list

---
## Singly Linked List

All programs discussed in this section consider the following representations of linked list. 
```cpp
// A linked list node
class Node
{
    public:
    int data;
    Node *next;
};
```

### Insertion of node

<details>
    <summary> At Front </summary>

```cpp
/* Given a reference (pointer to pointer)
to the head of a list and an int,
inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
    /* 1. allocate node */
    Node* new_node = new Node();
 
    /* 2. put in the data */
    new_node->data = new_data;
 
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
 
    /* 4. move the head to point to the new node */
    (*head_ref) = new_node;
}
```
</details>

<details>
    <summary> After a given node </summary>

```cpp
// Given a node prev_node, insert a
// new node after the given 
// prev_node
void insertAfter(Node* prev_node, int new_data) 
{
   
    // 1. Check if the given prev_node is NULL
    if (prev_node == NULL) 
    { 
        cout << "The given previous node cannot be NULL"; 
        return; 
    }
   
    // 2. Allocate new node
    Node* new_node = new Node();
   
    // 3. Put in the data
    new_node->data = new_data; 
   
    // 4. Make next of new node as
    // next of prev_node
    new_node->next = prev_node->next; 
   
    // 5. move the next of prev_node
    // as new_node
    prev_node->next = new_node; 
}
```
</details>

<details>
    <summary> At the end </summary>

```cpp
// Given a reference (pointer to pointer) to the head 
// of a list and an int, appends a new node at the end
void append(Node** head_ref, int new_data) 
{ 
   
    // 1. allocate node
    Node* new_node = new Node();
   
    // Used in step 5
    Node *last = *head_ref;
   
    // 2. Put in the data
    new_node->data = new_data; 
   
    // 3. This new node is going to be 
    // the last node, so make next of 
    // it as NULL
    new_node->next = NULL; 
   
    // 4. If the Linked List is empty,
    // then make the new node as head
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 
   
    // 5. Else traverse till the last node
    while (last->next != NULL)
    {
        last = last->next; 
    }
   
    // 6. Change the next of last node
    last->next = new_node; 
    return; 
}
```
</details>  
<br/>

### Deletion of Node

<details>
    <summary> First occurrence using Iterative Method </summary>

```cpp
// Given a reference (pointer to pointer)
// to the head of a list and a key, deletes
// the first occurrence of key in linked list
void deleteNode(Node** head_ref, int key)
{
     
    // Store head node
    Node* temp = *head_ref;
    Node* prev = NULL;
     
    // If head node itself holds
    // the key to be deleted
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // free old head
        return;
    }
 
    // Else Search for the key to be deleted,
    // keep track of the previous node as we
    // need to change 'prev->next' */
      else
    {
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
 
    // If key was not present in linked list
    if (temp == NULL)
        return;
 
    // Unlink the node from linked list
    prev->next = temp->next;
 
    // Free memory
    delete temp;
    }
}
```
</details>

<details>
    <summary> At given possition</summary>

```cpp
// Given a reference (pointer to pointer) to
// the head of a list and a position, deletes
// the node at the given position 
void deleteNode(Node **head_ref, int position)
{
      
    // If linked list is empty
    if (*head_ref == NULL)
        return;
      
    // Store head node
    Node* temp = *head_ref;
  
    // If head needs to be removed
    if (position == 0)
    {
          
        // Change head
        *head_ref = temp->next; 
          
        // Free old head
        free(temp);             
        return;
    }
  
    // Find previous node of the node to be deleted
    for(int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;
  
    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;
  
    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
     Node *next = temp->next->next;
  
    // Unlink the node from linked list
    free(temp->next); // Free memory
      
    // Unlink the deleted node from list
    temp->next = next; 
}
```
</details>  
<br/>

---
