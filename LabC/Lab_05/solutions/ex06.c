#include <stdio.h>

// Declare functions
int isPrime(int);
void sortPrimes(int[], int);

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

    sortPrimes(array, n);

    printf("Sorted prime numbers in increasing order:\n");
    for (int i = 0; i < n; i++) {
        if (isPrime(array[i])) {
            printf("%d ", array[i]);
        }
    }
    printf("\n");

    return 0;
}

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    
    return 1;
}

void sortPrimes(int array[], int n) {
    for (int i = 0; i < n; i++) {
        if (isPrime(array[i])) {
            for (int j = i + 1; j < n; j++) {
                if (isPrime(array[j]) && array[j] < array[i]) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
    }
}