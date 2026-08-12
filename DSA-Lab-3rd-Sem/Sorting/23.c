#include <stdio.h>

int selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_index = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
    return 0;
}

int main() {
    int n, i;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int ans[n];
    printf("Enter elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ans[i]);
    }
    selectionSort(ans, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
