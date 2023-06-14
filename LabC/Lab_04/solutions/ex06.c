#include <stdio.h>

// Declare functions
void inputArray(int[], int);
int isSymetric(int[], int);

int main() {
     // Declare variables
     int size;
     printf("Enter the size of the array: ");
     scanf("%d", &size);
     int array[size];
     inputArray(array, size);
     int result = isSymetric(array, size);
     printf("Output: %d\n", result);
     return 0;
}

void inputArray(int array[], int size) {
     for (int i = 0; i < size; i++) {
          printf("Enter the value of index %d in the array: ", i);
          scanf("%d", &array[i]);
     }
}

int isSymetric(int array[], int size) {
     int check = 0;
     int i = 0, j = (size - 1);
     while (i <= j) {
          if (array[i] != array[j]) {
               check = -1;
               break;
          }
          i++;
          j--;
     }
     if (check == 0) {
          return 1; // Symetric
     } else {
          return 0; // Not symetric
     }
     
}