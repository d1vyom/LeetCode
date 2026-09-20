#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node** headRef, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = newData;
    newNode->next = *headRef;
    *headRef = newNode;
}

int searchLinkedList(struct Node* head, int key) {
    struct Node* current = head;
    int position = 1;

    while (current != NULL) {
        if (current->data == key) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int searchKey, result;

    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);
    insertAtBeginning(&head, 30);
    insertAtBeginning(&head, 40);
    insertAtBeginning(&head, 50);

    printf("Linked List: ");
    printList(head);

    printf("Enter the element to search for: ");
    if (scanf("%d", &searchKey) != 1) {
        printf("Invalid input.\n");
        freeList(head);
        return 1;
    }

    result = searchLinkedList(head, searchKey);

    if (result != -1) {
        printf("Element %d found at position %d.\n", searchKey, result);
    } else {
        printf("Element %d not found in the linked list.\n", searchKey);
    }

    freeList(head);
    return 0;
}
