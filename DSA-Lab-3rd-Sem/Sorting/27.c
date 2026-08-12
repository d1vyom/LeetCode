#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void countSort(int arr[], int n, int exp) {
    int output[n]; 
    int i;
    int count[10] = {0};

    for (i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[arr[i] / exp % 10];
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int radixSort(int arr[], int n) {
    int m = getMax(arr, n);
    int exp;

    for (exp = 1; m / exp > 0; exp *= 10) {
        countSort(arr, n, exp);
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
    radixSort(ans, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
