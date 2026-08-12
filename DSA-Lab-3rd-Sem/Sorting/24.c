#include <stdio.h>

int insertionSort(int arr[], int n) {
    int i, key, j;

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(ans, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
