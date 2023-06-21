#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declare functions
void fillArray(int*, int);
void sortArray(int*, int);

int main() {
     // Declare variables
     int size1, size2, i, *ptr;
     printf("Enter the size of the array: ");
     scanf("%d", &size1);

     // Allocate memory for the dynamic array
     ptr = (int*)malloc(size1 * sizeof(int));
     if (ptr == NULL) {
          printf("Memory allocation failed. Exiting...\n");
          return 1;
     }    

     // (1) Fill array with random values between 1 and 99
     fillArray(ptr, size1);
     // (2) Sort array in increasing order
     sortArray(ptr, size1);
     // Array after sorted
     printf("The array after sorted: ");
     for (i = 0; i < size1; i++) {
          printf("%d ", *(ptr + i));
     }
     printf("\n");

     // (3) Double the size of the array, fill the new elements and sort it in increasing order
     printf("Enter the new size of the array: ");
     scanf("%d", &size2);
     ptr = realloc(ptr, size2 * sizeof(int));
     fillArray(ptr, size2);
     sortArray(ptr, size2);
     printf("The new array after sorted: ");
     for (i = 0; i < size2; i++) {
          printf("%d ", *(ptr + i));
     }
     printf("\n");

     // Free the allocated memory
     free(ptr);
     return 0;
}

void fillArray(int *ptr, int size) {
     srand(time(0));
     int i;
     for (i = 0; i < size; i++) {
          ptr[i] = 1 + (rand() % 99);
     }
}

void sortArray(int *ptr, int size) {
     for (int i = 0; i < size; i++) {
          for (int j = i + 1; j < size; j++) {
               if (*(ptr + i) > *(ptr + j)) {
                    int temp = *(ptr + i);
                    *(ptr + i) = *(ptr + j);
                    *(ptr + j) = temp;
               }
          }
     }
}