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

     for (int i = 0; i < total_length; i++) {
          if (i < length_1) {
               *(ptr + i) = array1[i];
          } else {
               *(ptr + i) = array2[i - length_2];
          }
     }

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
          printf("The median of the sorted array is %f\n", median);
     } else {
          median = *(ptr + position);
          printf("The median of the sorted array is %.f\n", median);
     }
}