#include <stdio.h>
int linearSearch(int arr[], int n, int key) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}
int main() {
    int arr[100], n, i, key, index;
    printf("Enter the length of the array: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    
    index = linearSearch(arr, n, key);
    if (index != -1)
        printf("Element found at index %d (Position %d)\n", index, index + 1);
    else
        printf("Element not found\n");
    return 0;
}
