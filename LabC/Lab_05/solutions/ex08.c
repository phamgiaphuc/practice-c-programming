#include <stdio.h>

void findLargestConsecutiveSubarray(int arr[], int n) {
    int start = -1;  // Start index of the largest consecutive subarray
    int end = -1;    // End index of the largest consecutive subarray
    int maxSum = 0;  // Sum of the largest consecutive subarray
    int currentStart = -1;  // Start index of the current consecutive subarray
    int currentSum = 0;     // Sum of the current consecutive subarray

    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) {
            if (currentStart == -1) {
                currentStart = i;
                currentSum = arr[i];
            } else {
                currentSum += arr[i];
            }

            if (currentSum > maxSum) {
                maxSum = currentSum;
                start = currentStart;
                end = i;
            }
        } else {
            currentStart = -1;
            currentSum = 0;
        }
    }

    if (start != -1 && end != -1) {
        printf("Largest consecutive subarray with the sum of %d: ", maxSum);
        for (int i = start; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("No consecutive positive subarray found.\n");
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findLargestConsecutiveSubarray(arr, n);

    return 0;
}
