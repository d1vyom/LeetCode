#include <stdio.h>
#include <stdlib.h>

// 1. Structure definition for a node
struct Node {
    int data;
    struct Node* next;
};

// 2. Traversal function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;

    if (temp == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 3. Main entry point (Spelled exactly as 'main' in lowercase)
int main() {
    // Creating nodes
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    // Assigning data and linking nodes
    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    // Displaying the list
    displayList(head);

    // Freeing memory
    free(head);
    free(second);
    free(third);

    return 0;
}