#include <stdio.h>
#include <stdlib.h>

// Define node
struct Node {
    int data;
    struct Node* next;
};

// Functions
void insertAtBeginning(struct Node** head_ref, int new_data);
void insertAtEnd(struct Node** head_ref, int new_data);
void insertAtPosition(struct Node** head_ref, int new_data, int position);
void deleteNode(struct Node** head_ref, int key);
void deleteAtPosition(struct Node** head_ref, int position);
void displayList(struct Node* node);

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n*** SINGLY LINKED LIST MENU ***\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete a Value\n");
        printf("5. Delete at Specific Position\n");
        printf("6. Display List\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter position (1-based index): ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;
            case 5:
                printf("Enter position to delete (1-based index): ");
                scanf("%d", &position);
                deleteAtPosition(&head, position);
                break;
            case 6:
                displayList(head);
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Insert at beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) { printf("Memory allocation failed!\n"); return; }
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
    printf("Inserted %d at the beginning.\n", new_data);
}

// 2. Insert at end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) { printf("Memory allocation failed!\n"); return; }
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("Inserted %d as the first element.\n", new_data);
        return;
    }

    struct Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    printf("Inserted %d at the end.\n", new_data);
}

// 3. Insert at position
void insertAtPosition(struct Node** head_ref, int new_data, int position) {
    if (position < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    // If inserting at position 1, reuse beginning logic
    if (position == 1) {
        insertAtBeginning(head_ref, new_data);
        return;
    }

    struct Node* temp = *head_ref;
    // Traverse to the node just before the insertion index
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position > the size of the list + 1
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if (!new_node) { printf("Memory allocation failed!\n"); return; }
    new_node->data = new_data;
    
    new_node->next = temp->next;
    temp->next = new_node;
    printf("Inserted %d at position %d.\n", new_data, position);
}

// 4. Delete by value
void deleteNode(struct Node** head_ref, int key) {
    struct Node *temp = *head_ref, *prev = NULL;

    if (temp == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        printf("Deleted %d from the list.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", key);
}

// 5. Delete at position
void deleteAtPosition(struct Node** head_ref, int position) {
    if (*head_ref == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    if (position < 1) {
        printf("Invalid position! Position must be >= 1.\n");
        return;
    }

    struct Node* temp = *head_ref;

    // Case 1: Deleting the head node
    if (position == 1) {
        *head_ref = temp->next;
        free(temp);
        printf("Deleted node at position 1.\n");
        return;
    }

    struct Node* prev = NULL;
    // Traverse to the targeted position
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }

    // If position > the number of nodes
    if (temp == NULL) {
        printf("Position out of bounds!\n");
        return;
    }

    // Unlink and free memory
    prev->next = temp->next;
    free(temp);
    printf("Deleted node at position %d.\n", position);
}

// 6. Display
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("Linked List is empty!\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}
