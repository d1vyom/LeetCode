#include <stdio.h>
#include <stdlib.h>

// Define the Doubly Linked List Node structure
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to print the list from beginning to end
void printList(struct Node* head) {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Helper function to insert a node at the front (for setup)
void insertFront(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->prev = NULL;
    newNode->next = (*head);

    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }
    (*head) = newNode;
}

// 1. Delete the first node (Head)
void deleteHead(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next; // Move head to the next node

    if (*head != NULL) {
        (*head)->prev = NULL; // Disconnect the old head link
    }

    free(temp); // Free the memory
}

// 2. Delete the last node (Tail)
void deleteTail(struct Node** head) {
    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    struct Node* temp = *head;

    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // If there is only one node in the list
    if (temp->prev == NULL) {
        *head = NULL;
    } else {
        temp->prev->next = NULL; // Disconnect the tail from the second-to-last node
    }

    free(temp);
}

// 3. Delete a node at a given position (1-indexed)
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or empty list.\n");
        return;
    }

    struct Node* current = *head;

    // If the node to be deleted is the head node
    if (position == 1) {
        deleteHead(head);
        return;
    }

    // Traverse to the node at the specified position
    for (int i = 1; current != NULL && i < position; i++) {
        current = current->next;
    }

    // If the position is out of bounds
    if (current == NULL) {
        printf("Position %d exceeds list length.\n", position);
        return;
    }

    // If it's the last node
    if (current->next == NULL) {
        deleteTail(head);
        return;
    }

    // If it's a middle node, adjust adjacent pointers to skip 'current'
    current->prev->next = current->next;
    current->next->prev = current->prev;

    free(current); // Free the memory
}

// Main Function to execute the code
int main() {
    struct Node* head = NULL;

    // Create a list: 50 <-> 40 <-> 30 <-> 20 <-> 10
    insertFront(&head, 10);
    insertFront(&head, 20);
    insertFront(&head, 30);
    insertFront(&head, 40);
    insertFront(&head, 50);

    printf("Original Doubly Linked List:\n");
    printList(head);

    // 1. Test Head Deletion
    printf("\nDeleting the head node...\n");
    deleteHead(&head);
    printList(head);

    // 2. Test Tail Deletion
    printf("\nDeleting the tail node...\n");
    deleteTail(&head);
    printList(head);

    // 3. Test Middle Deletion (Delete node at position 2)
    printf("\nDeleting the node at position 2...\n");
    deleteAtPosition(&head, 2);
    printList(head);

    // Clean up remaining memory before exiting
    while (head != NULL) {
        deleteHead(&head);
    }

    return 0;
}
