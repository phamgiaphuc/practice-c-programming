#include <stdio.h>

#define SIZE 100

// Declare functions
int largestIncreasingSubarray(int[], int[], int);
int largestDecreasingSubarray(int[], int[], int);
void printOutput(int[], int);

int main() {
    // Declare variables
    int n, a[SIZE], b[SIZE], size_a, size_b;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    size_a = largestIncreasingSubarray(array, a, n);
    size_b = largestDecreasingSubarray(array, b, n);
    if (size_a > size_b) {
        printOutput(a, size_a);
    } else {
        printOutput(b, size_b);
    }
    return 0;
}

void printOutput(int array[], int size) {
    printf("Largest sorted subarray: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int largestIncreasingSubarray(int array[], int a[], int n) {
    int max = 1, length = 1, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] > array[i - 1]) {
            length++;
        } else {
            if (max < length) {
                max = length;
                maxIndex = i - max;
            }
            length = 1;
        }
    }
    if (max < length) {
        max = length;
        maxIndex = n - max;
    }
    int start = 0;
    for (int i = maxIndex; i < max + maxIndex; i++) {
        a[start] = array[i];
        start++;
    }
    return max;
}

int largestDecreasingSubarray(int array[], int b[], int n) {
    int max = 1, length = 1, maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (array[i] < array[i - 1]) {
            length++;
        } else {
            if (max < length) {
                max = length;
                maxIndex = i - max;
            }
            length = 1;
        }
    }
    if (max < length) {
        max = length;
        maxIndex = n - max;
    }
    int start = 0;
    for (int i = maxIndex; i < max + maxIndex; i++) {
        b[start] = array[i];
        start++;
    }
    return max;
}
