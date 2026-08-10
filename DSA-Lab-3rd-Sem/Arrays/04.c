#include <stdio.h>
int main() {
    int r, c, i, j;
    int arr1[100][100], arr2[100][100], sum[100][100];
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &r, &c);
    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    printf("Sum:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
