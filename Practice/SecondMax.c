#include <stdio.h>

void findSecondMax(int[], int);

int main() {
     int array[] = {2,3,14,9,5}; // Second max = 9; index = 1
     int size = sizeof(array) / sizeof(int);
     findSecondMax(array, size);
     return 0;
}

// void findSecondMax(int array[], int size) {
//      int step = 0;
//      int max = array[0];
//      for (int i = 0; i < size; i++) {
//           int check = array[i];
//           for (int j = 0; j < size; j++) {
//                if (check > array[j]) {
//                     step++;
//                }
//           }
//           if (step == (size - 2)) {
//                printf("The second max in the array is %d at index %d\n", check, i);
//           } else {
//                step = 0;
//           }
//      }
// }

void findSecondMax(int array[], int size) {
     int max1 = array[0], max2 = array[0];
     for (int i = 1; i < size; i++) {
          if(max1 < array[i]) {
               max2 = max1;
               max1 = array[i];
          }
     }
     printf("Second max: %d\n", max2);
}