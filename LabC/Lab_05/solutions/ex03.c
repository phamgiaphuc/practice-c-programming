#include <stdio.h>

// Declare functions
void sortColumns(int [][100], int, int);
void printArray(int [][100], int, int);

int main() {
    // Declare variables
    int m, n;
    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    int array[100][100];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    sortColumns(array, m, n);
    printArray(array, m, n);

    return 0;
}

void sortColumns(int array[][100], int m, int n) {
    for (int j = 0; j < n; j++) {
        // Odd
        if (j % 2 != 0) {
            for (int i = 0; i < m - 1; i++) {
                for (int k = i + 1; k < m; k++) {
                    if (array[i][j] > array[k][j]) {
                        int temp = array[i][j];
                        array[i][j] = array[k][j];
                        array[k][j] = temp;
                    }
                }
            }
        }
        // Even
        else {
            for (int i = 0; i < m - 1; i++) {
                for (int k = i + 1; k < m; k++) {
                    if (array[i][j] < array[k][j]) {
                        int temp = array[i][j];
                        array[i][j] = array[k][j];
                        array[k][j] = temp;
                    }
                }
            }
        }
    }
}

void printArray(int array[][100], int m, int n) {
    printf("Sorted Array:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}
