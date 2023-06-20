#include <stdio.h>

void inputMatrix(int matrix[][100], int n) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void sortDiagonals(int matrix[][100], int n) {
    // Sort the first diagonal (increasing order)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[i][i] > matrix[j][j]) {
                int temp = matrix[i][i];
                matrix[i][i] = matrix[j][j];
                matrix[j][j] = temp;
            }
        }
    }

    // Sort the second diagonal (decreasing order)
    for (int i = n - 1, j = 0; j < n; i--, j++) {
        for (int k = i - 1, z = j + 1; z < n; k--, z++) {
            if (matrix[i][j] < matrix[k][z]) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[k][z];
                matrix[k][z] = temp;
            }
        }
    }
}

void printMatrix(int matrix[][100], int n) {
    printf("Matrix after sorting diagonals:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the value of n (even):\n");
    scanf("%d", &n);

    int matrix[n][100];
    inputMatrix(matrix, n);

    sortDiagonals(matrix, n);

    printMatrix(matrix, n);

    return 0;
}
