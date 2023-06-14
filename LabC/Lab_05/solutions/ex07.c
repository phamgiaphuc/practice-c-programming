#include <stdio.h>

// Declare functions
void findLargestSortedSubarray(int[], int);

int main() {
    // Declare variables
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int array[n];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    findLargestSortedSubarray(array, n);
    return 0;
}

void findLargestSortedSubarray(int array[], int n) {
    int maxLength = 1;
    int maxStart = 0;
    int currLength = 1;
    int currStart = 0;
    int isIncreasing = array[1] > array[0]; // Assume increasing order if the second element is larger than the first

    for (int i = 1; i < n; i++) {
        if ((array[i] > array[i - 1] && isIncreasing) || (array[i] < array[i - 1] && !isIncreasing)) {
            currLength++;
        }
        else {
            if (currLength > maxLength) {
                maxLength = currLength;
                maxStart = currStart;
            }

            currStart = i;
            currLength = 1;
            isIncreasing = array[i] > array[i - 1];
        }
    }

    if (currLength > maxLength) {
        maxLength = currLength;
        maxStart = currStart;
    }

    printf("Largest sorted subarray: ");
    for (int i = maxStart; i < maxStart + maxLength; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
