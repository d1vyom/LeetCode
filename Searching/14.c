#include <stdio.h>
int linearSearch(int arr[], int n, int t) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == t) {
            return i;
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
    int result = linearSearch(arr, n, t);
    if (result != -1) {
        printf("%d found at index: %d\n", t, result);
    } else {
        printf("Element not found in the array.\n");
    }
    return 0;
}
