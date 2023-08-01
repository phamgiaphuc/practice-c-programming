#include <stdio.h>
#include <stdlib.h>

void sortDistance(int[], int[][2], int, int);

int main() {
     int array[] = {9, 8, 1, 2, 3};
     int x = 6;
     int size = sizeof(array) / sizeof(int);
     int result[size][2];
     sortDistance(array, result, size, x);
     return 0;
}

void sortDistance(int array[], int result[][2], int size, int x) {
     for (int i = 0; i < size; i++) {
          result[i][0] = abs(x - array[i]);
          result[i][1] = &array[i];
     }
     for (int j = 0; j < size; j++) {
          if (result[j][0] > result[j + 1][0]) {
               int temp = result[j][0];
               result[j][0] = result[j + 1][0];
               result[j + 1][0] = temp;
          }
     }
     for (int t = 0; t < size; t++) {
          printf("%d ", result[t][0]);
     }
     printf("\n");
}
