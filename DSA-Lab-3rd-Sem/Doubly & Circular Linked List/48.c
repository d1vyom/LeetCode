#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print/traverse the circular linked list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(Head: %d)\n", head->data);
}

// 1. Insertion at the Beginning
struct Node* insertAtBeginning(struct Node* head, int value) {
    // Allocate memory for new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    // If list is empty, point the node to itself and make it head
    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    // If list is not empty, find the last node
    struct Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }

    // Link new node to head and update last node's next pointer
    newNode->next = head;
    temp->next = newNode;

    // Make new node the new head
    return newNode;
}

// 2. Insertion at the End
struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* temp = head;
    // Traverse to the last node
    while (temp->next != head) {
        temp = temp->next;
    }

    // Update pointers: last node points to new node, new node points to head
    temp->next = newNode;
    newNode->next = head;

    return head;
}

// 3. Insertion at a Specific Position (1-indexed)
struct Node* insertAtPosition(struct Node* head, int value, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }

    // If position is 1, it's a beginning insertion
    if (position == 1) {
        return insertAtBeginning(head, value);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    struct Node* temp = head;
    // Traverse to the node right before the desired position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
        // If we loop back to head before reaching position, it's out of bounds
        if (temp == head) {
            printf("Position out of bounds!\n");
            free(newNode);
            return head;
        }
    }

    // Insert the new node into the list
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

// Main Function to demonstrate operations
int main() {
    struct Node* head = NULL;

    printf("--- Demonstrating Circular Linked List Insertion ---\n\n");

    // Insert into an empty list / insert at end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    printf("After inserting 10, 20, 30 at the end:\n");
    display(head);

    // Insert at the beginning
    head = insertAtBeginning(head, 5);
    printf("\nAfter inserting 5 at the beginning:\n");
    display(head);

    // Insert at a specific position (e.g., position 3)
    head = insertAtPosition(head, 15, 3);
    printf("\nAfter inserting 15 at position 3:\n");
    display(head);

    // Insert at another position (e.g., position 5)
    head = insertAtPosition(head, 25, 5);
    printf("\nAfter inserting 25 at position 5:\n");
    display(head);

    // Clean up memory before exiting
    if (head != NULL) {
        struct Node* current = head;
        struct Node* nextNode;
        do {
            nextNode = current->next;
            free(current);
            current = nextNode;
        } while (current != head);
    }

    return 0;
}
