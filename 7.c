#include <stdio.h>
int main() {
    int r, c;
    printf("Enter rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);
    int m[r][c];
    int t[c][r];
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            t[j][i] = m[i][j];
        }
    }
    printf("Transposed Matrix:\n");
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            printf("%d\t",t[i][j]);
        }
        printf("\n");
    }
    return 0;
}
