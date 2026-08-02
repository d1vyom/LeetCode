#include <stdio.h>
int binarySearch(int arr[], int n, int t) {
    int low = 0;
    int high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == t) {
            return mid;
        }
        if (arr[mid] < t) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return -1;
}
int main() {
    int n, t, arr[100];
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to search: ");
    scanf("%d", &t);
    int result = binarySearch(arr, n, t);
    if (result != -1) {
        printf("%d found at index: %d\n", t, result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}
