#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to print the circular linked list
void printList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Function to insert a node at the end to help build the list
void insertEnd(struct Node** head_ref, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
        return;
    }

    struct Node* temp = *head_ref;
    while (temp->next != *head_ref) {
        temp = temp->next;
    }
    
    temp->next = new_node;
    new_node->next = *head_ref;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head_ref, int key) {
    // Case 1: List is empty
    if (*head_ref == NULL) {
        printf("List is empty. Cannot delete %d.\n", key);
        return;
    }

    struct Node *curr = *head_ref, *prev = NULL;

    // Case 2: The list contains only one node
    if (curr->data == key && curr->next == *head_ref) {
        free(curr);
        *head_ref = NULL;
        return;
    }

    // Case 3: The node to be deleted is the head node
    if (curr->data == key) {
        // Find the last node to update its next pointer
        while (curr->next != *head_ref) {
            curr = curr->next;
        }
        
        struct Node* temp = *head_ref;
        curr->next = temp->next;   // Last node points to second node
        *head_ref = temp->next;    // Update head to second node
        free(temp);
        return;
    }

    // Case 4: The node to be deleted is in the middle or at the end
    curr = *head_ref;
    while (curr->next != *head_ref && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    // If the node was found
    if (curr->data == key) {
        prev->next = curr->next;
        free(curr);
    } else {
        printf("Key %d not found in the list.\n", key);
    }
}

// Main function to run and test the program
int main() {
    struct Node* head = NULL;

    // 1. Create a circular linked list
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("Original Circular Linked List:\n");
    printList(head);

    // 2. Delete a node from the middle
    printf("\nDeleting 30 (Middle Node):\n");
    deleteNode(&head, 30);
    printList(head);

    // 3. Delete the head node
    printf("\nDeleting 10 (Head Node):\n");
    deleteNode(&head, 10);
    printList(head);

    // 4. Delete the last node
    printf("\nDeleting 40 (Last Node):\n");
    deleteNode(&head, 40);
    printList(head);

    // 5. Delete the remaining single node
    printf("\nDeleting 20 (Only Remaining Node):\n");
    deleteNode(&head, 20);
    printList(head);

    return 0;
}
