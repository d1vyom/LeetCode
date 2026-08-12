#include <stdio.h>

int bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
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
    bubbleSort(ans, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
