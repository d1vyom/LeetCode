#include <stdio.h>
int main() {
    int m, n, p, q, i, j, k;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &m, &n);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &p, &q);
    if (n != p) {
        printf("Error! Column of first matrix must equal row of second matrix\n");
        return 0;
    }
    int arr1[10][10], arr2[10][10], r[10][10];
    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            for (k = 0; k < n; k++) {
                r[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
    printf("Product:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            printf("%d ", r[i][j]);
        }
        printf("\n");
    }
    return 0;
}
