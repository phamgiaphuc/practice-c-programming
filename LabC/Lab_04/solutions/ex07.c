#include <stdio.h>

// Declare functions
void inputArray(int[], int);
void moveElements(int[], int);

int main() {
     // Declare variables
     int size;
     printf("Enter the size of the array: ");
     scanf("%d", &size);
     int array[size];
     inputArray(array, size);
     printf("Result: ");
     moveElements(array, size);
     printf("\n");
     return 0;
}

void inputArray(int array[], int size) {
     for (int i = 0; i < size; i++) {
          printf("Enter the value of index %d in the array: ", i);
          scanf("%d", &array[i]);
     }
}

void moveElements(int array[], int size) {

     int j = 0;
     for (int i = 0; i < size; i++) {
          if (array[i] > 0) {
               if (i != j) {
                    int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
               }
               j++;
          }
     }

     for (int i = 0; i < size; i++) {
          printf("%d ", array[i]);
     }
}