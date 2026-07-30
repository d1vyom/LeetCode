#include <stdio.h>

void clearBuffer() {
    while (getchar() != '\n');
}

void traversal(int arr[], int n) {
    int i;
    if (n == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("Array Elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertion(int arr[], int *n) {
    int pos, value, i;

    if (*n == 100) {
        printf("Array is full! Insertion not possible.\n");
        return;
    }

    printf("Enter position (1 to %d): ", *n + 1);
    scanf("%d", &pos);
    clearBuffer();

    if (pos < 1 || pos > *n + 1) {
        printf("Invalid Position!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    clearBuffer();

    for (i = *n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = value;
    (*n)++;

    printf("Element inserted successfully.\n");
}

void deletion(int arr[], int *n) {
    int pos, i;

    if (*n == 0) {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position to delete (1 to %d): ", *n);
    scanf("%d", &pos);
    clearBuffer();

    if (pos < 1 || pos > *n) {
        printf("Invalid Position!\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
        arr[i] = arr[i + 1];

    (*n)--;

    printf("Element deleted successfully.\n");
}

int main() {
    int arr[100];
    int n, i, choice;

    printf("Enter initial length of array: ");
    scanf("%d", &n);
    clearBuffer();

    if (n > 100 || n < 0) {
        printf("Invalid array size.\n");
        return 0;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        clearBuffer();
    }

    do {
        printf("\n===== MENU =====\n");
        printf("1. Traversal\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                traversal(arr, n);
                break;

            case 2:
                insertion(arr, &n);
                traversal(arr, n);
                break;

            case 3:
                deletion(arr, &n);
                traversal(arr, n);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while (choice != 4);

    return 0;
}
