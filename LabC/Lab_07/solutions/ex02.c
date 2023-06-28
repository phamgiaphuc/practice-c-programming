#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare functions
void fillArray(int *, int);
int removeDuplicatedElement(int *, int);

int main() {
     // Declare variables
     int size, *ptr, result;

     // Input the size of the ptr
     printf("Enter the size of the pointer: ");
     scanf("%d", &size);

     // Allocate the memory for the ptr
     ptr = (int *)malloc(size * sizeof(int));
     if (ptr == NULL) {
          printf("Memory allocation failed. Exiting...\n");
          return 1;
     }

     // Input elements to the array
     printf("Input the elements: ");
     fillArray(ptr, size);

     // Remove duplicated element in the array
     result = removeDuplicatedElement(ptr, size);
     printf("The new length of the array is %d\n", result);

     return 0;
}

void fillArray(int *ptr, int size) {
     int i;
     for (i = 0; i < size; i++) {
          scanf("%d", ptr + i);
     }
}

int removeDuplicatedElement(int *ptr, int size) {
     int i, j, temp;
     for (i = 0; i < size; i++) {
          for (j = i + 1; j < size; j++) {
               if (*(ptr + i) == *(ptr + j)) {
                    temp = *(ptr + j);
                    *(ptr + j) = *(ptr + size - 1);
                    *(ptr + size - 1) = temp;
                    size--;
               }
          }
     }
     printf("Array after removing duplicated element: ");
     for (i = 0; i < size; i++) {
          printf("%d ", *(ptr + i));
     }
     printf("\n");
     return size;
}