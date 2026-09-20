#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int countNodes(struct Node* head) {
    int count = 0;
    struct Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    
    new_node->data = new_data;
    new_node->next = (*head_ref);
    
    *head_ref = new_node;
}

int main() {
    struct Node* head = NULL;

    push(&head, 10);
    push(&head, 20);
    push(&head, 30);

    int totalNodes = countNodes(head);
    printf("Total number of nodes in the singly linked list: %d\n", totalNodes);

    struct Node* current = head;
    struct Node* nextNode;
    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    return 0;
}
