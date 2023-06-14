#include <stdio.h>

// Declare functions
void inputArray(int[], int);
void min_max(int[], int);

int main() {
     // Declare variables
     int size;
     printf("Enter the size of the array: ");
     scanf("%d", &size);
     int array[size];
     inputArray(array, size);
     min_max(array, size);
     return 0;
}

void inputArray(int array[], int size) {
     for (int i = 0; i < size; i++) {
          printf("Enter the value of index %d in the array: ", i);
          scanf("%d", &array[i]);
     }
}

void min_max(int array[], int size) {
     int min_num = array[0], max_num = array[0], min_index, max_index;
     for (int i = 0; i < size; i++) {
          if (array[i] > max_num) {
               max_num = array[i];
          }
          if (array[i] < min_num) {
               min_num = array[i];
          }
     }

     for (int i = 0; i < size; i++) {
          if (array[i] == max_num) {
               max_index = i;
               break;
          }
     }

     for (int i = 0; i < size; i++) {
          if (array[i] == min_num) {
               min_index = i;
               break;
          }
     }

     printf("The min index: %d\n", min_index);
     printf("The max index: %d\n", max_index);

}