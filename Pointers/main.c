#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 5

void bubbleSort(int *, int);
void swapElements(int *, int *);

int main() {
     int a[SIZE] = {3, 2, 4, 5, 1};
     int i;
     bubbleSort(a, SIZE);
     for (; i < SIZE; i++) {
          printf("%d ", *(a + i));
     }
     printf("\n");
     return 0;
}

void bubbleSort(int *array, int size) {
     for (int i = 0; i < size; i++) {
          for (int j = 0; j < size - 1; j++) {
               if (array[j] > array[j + 1]) {
                    swapElements(&array[j], &array[j + 1]);
               }
          }
     }
}

void swapElements(int *aptr, int *bptr) {
     int temp = *aptr;
     *aptr = *bptr;
     *bptr = temp;
}