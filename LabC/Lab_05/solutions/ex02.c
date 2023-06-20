#include <stdio.h>
#include <stdlib.h>

// Declare functions
void insertElememtsToArray(int[], int, int);
void combineArraysToPointer(int[], int[], int, int);
void medianOfArray(int*, int);

int main() {
     printf("\n");
     // Declare variables
     int length_1, length_2;

     // Enter the length for the arrays
     printf("Enter the length for the array 1: ");
     scanf("%d", &length_1);
     printf("Enter the length for the array 2: ");
     scanf("%d", &length_2);

     // Declare variables
     int array1[length_1], array2[length_2], *ptr;

     // Insert elements to arrays
     insertElememtsToArray(array1, 1, length_1);
     insertElememtsToArray(array2, 2, length_2);

     // Combine arrays
     combineArraysToPointer(array1, array2, length_1, length_2);

     return 0;
}

// Insert elements to the arrays
void insertElememtsToArray(int temp[], int num, int length) {
     printf("Enter the elements for array %d: ", num);
     for (int i = 0; i < length; i++) {
          scanf("%d", &temp[i]);
     }
}

// Combine arrays to pointer
void combineArraysToPointer(int array1[], int array2[], int length_1, int length_2) {
     // Declare variables
     int *ptr;
     int total_length = length_1 + length_2;

     // Allocate the memory for the pointer a and pointer b
     ptr = (int*) malloc(total_length * sizeof(int));

     // If memory cannot be allocated
     if(ptr == NULL) {
          printf("Error! memory not allocated.\n");
          exit(0);
     }

     // Combine arrays to pointer
     for (int i = 0; i < length_1; i++) {
          *(ptr + i) = array1[i];
     }
     for (int i = 0; i < length_2; i++) {
          *(ptr + i + length_1) = array2[i];
     }

     // Sort the array/pointer
     for (int i = 0; i < total_length; i++) {
          for (int j = i + 1; j < total_length; j++) {
               if (*(ptr + i) > *(ptr + j)) {
                    int temp = *(ptr + i);
                    *(ptr + i) = *(ptr + j);
                    *(ptr + j) = temp;
               }
          }
     }

     // Array after sorted
     printf("New array after sorted: ");
     for (int i = 0; i < total_length; i++) {
          printf("%d ", *(ptr + i));
     }
     printf("\n");

     // The median of sorted array
     medianOfArray(ptr, total_length);
}

// The median of sorted array
void medianOfArray(int *ptr, int total_length) {
     // Declare variables
     int position = total_length / 2;
     float median;
     
     if ((total_length % 2) == 0) {
          median = (*(ptr + (position - 1)) + *(ptr + position)) / 2.0;
          printf("The median of the sorted array is %.1f\n", median);
     } else {
          median = *(ptr + position);
          printf("The median of the sorted array is %.f\n", median);
     }
}