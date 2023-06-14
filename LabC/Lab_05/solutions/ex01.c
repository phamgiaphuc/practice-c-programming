#include <stdio.h>
#include <stdlib.h>

// Declare functions
void insertElementsToPointer(int*, int);
void twoSum(int*, int, int[], int);

int main() {
     // Declare variables
     int length, target, *ptr, result[2];

     // Enter the number of elements in the array
     printf("Enter the number of elements in the array: ");
     scanf("%d", &length);

     // Enter the target number
     printf("Enter the target number: ");
     scanf("%d", &target);

     // Allocate the memory for the pointer
     ptr = (int*) malloc(length * sizeof(int));

     // If memory cannot be allocated
     if(ptr == NULL) {
          printf("Error! memory not allocated.\n");
          exit(0);
     }
     insertElementsToPointer(ptr, length);
     twoSum(ptr, length, result, target);

     // Deallocating the memory
     free(ptr);
}

// Insert elements to the pointer
void insertElementsToPointer(int *ptr, int length) {
     printf("Enter elements: ");
     for(int i = 0; i < length; i++) {
          scanf("%d", ptr + i);
     }
}

// Two sum problem
void twoSum(int *ptr, int length, int result[], int target) {
     for (int i = 0; i < length; i++) {
          for (int j = i + 1; j < length; j++) {
               if ((*(ptr + i)) + *(ptr + j) == target) {
                    result[0] = i;
                    result[1] = j;
               }
          }
     }

     printf("The result is: ");

     for (int i = 0; i < 2; i++) {
          printf("%d ", result[i]);
     }
     
     printf("\n");
}