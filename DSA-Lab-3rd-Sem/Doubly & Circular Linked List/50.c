#include <stdio.h>
#include <stdlib.h>

// Define the structure for a Doubly Linked List Node
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node** head, int newData) {
    // 1. Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // 2. Put in the data
    newNode->data = newData;
    
    // 3. Make next of new node as head and prev as NULL
    newNode->next = (*head);
    newNode->prev = NULL;
    
    // 4. Change prev of head node to new node (if list is not empty)
    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    
    // 5. Move the head to point to the new node
    *head = newNode;
}

// Function to insert a node after a given node
void insertAfter(struct Node* prevNode, int newData) {
    // 1. Check if the given prevNode is NULL
    if (prevNode == NULL) {
        printf("The given previous node cannot be NULL.\n");
        return;
    }
    
    // 2. Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // 3. Put in the data
    newNode->data = newData;
    
    // 4. Make next of new node as next of prevNode
    newNode->next = prevNode->next;
    
    // 5. Make the next of prevNode as newNode
    prevNode->next = newNode;
    
    // 6. Make prevNode as previous of newNode
    newNode->prev = prevNode;
    
    // 7. Change previous of newNode's next node (if it exists)
    if (newNode->next != NULL) {
        newNode->next->prev = newNode;
    }
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int newData) {
    // 1. Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    struct Node* last = *head;
    
    // 2. Put in the data
    newNode->data = newData;
    
    // 3. This new node is going to be the last node, so make next of it NULL
    newNode->next = NULL;
    
    // 4. If the Linked List is empty, then make the new node as head
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    
    // 5. Else traverse till the last node
    while (last->next != NULL) {
        last = last->next;
    }
    
    // 6. Change the next of last node
    last->next = newNode;
    
    // 7. Make last node as previous of new node
    newNode->prev = last;
}

// Function to print the doubly linked list in both directions
void printList(struct Node* node) {
    struct Node* last = NULL;
    
    printf("Traversal in forward direction:\n");
    while (node != NULL) {
        printf(" %d <->", node->data);
        last = node;
        node = node->next;
    }
    printf(" NULL\n");
    
    printf("Traversal in reverse direction:\n");
    while (last != NULL) {
        printf(" %d <->", last->data);
        last = last->prev;
    }
    printf(" NULL\n");
}

// Main function to demonstrate insertions
int main() {
    // Start with an empty list
    struct Node* head = NULL;
    
    printf("--- Inserting 10 at the end ---\n");
    insertAtEnd(&head, 10);
    
    printf("--- Inserting 20 at the beginning ---\n");
    insertAtBeginning(&head, 20);
    
    printf("--- Inserting 5 at the beginning ---\n");
    insertAtBeginning(&head, 5);
    
    printf("--- Inserting 30 at the end ---\n");
    insertAtEnd(&head, 30);
    
    printf("--- Inserting 15 after the head node (%d) ---\n", head->data);
    insertAfter(head, 15); // Inserts 15 after 5
    
    // Print the final list
    printList(head);
    
    // Free allocated memory to avoid leaks
    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    
    return 0;
}
