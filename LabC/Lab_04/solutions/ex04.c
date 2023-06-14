#include <stdio.h>

// Declare functions
void inputArray(int[], int);
void outputArray(int[], int);

int main() {
     // Declare variables
     int size;
     printf("Enter the size of the array: ");
     scanf("%d", &size);
     int array[size];
     inputArray(array, size);
     outputArray(array, size);
     return 0;
}

void inputArray(int array[], int size) {
     for (int i = 0; i < size; i++) {
          printf("Enter the value of index %d in the array: ", i);
          scanf("%d", &array[i]);
     }
}

void outputArray(int array[], int size) {
     printf("The array elements: ");
     for (int i = 0; i < size; i++) {
          printf("%d ", array[i]);
     }
     printf("\n");
}