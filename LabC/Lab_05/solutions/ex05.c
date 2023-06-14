#include <stdio.h>

void inputMatrix(int matrix[][100], int m, int n) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void findMinRow(int matrix[][100], int minRow[], int m, int n) {
    for (int i = 0; i < m; i++) {
        int min = matrix[i][0];
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        minRow[i] = min;
    }
}

int findMaxMin(int minRow[], int m) {
    int maxMin = minRow[0];
    for (int i = 1; i < m; i++) {
        if (minRow[i] > maxMin) {
            maxMin = minRow[i];
        }
    }
    return maxMin;
}

int main() {
    // Declare variables
    int m, n;
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    int matrix[100][100];
    inputMatrix(matrix, m, n);

    int minRow[100];
    findMinRow(matrix, minRow, m, n);

    int maxMin = findMaxMin(minRow, m);

    printf("The maximum number from the minimum elements of each row is: %d\n", maxMin);

    return 0;
}
