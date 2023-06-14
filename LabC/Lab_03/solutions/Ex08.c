#include <stdio.h>

int main() {
     // Declare variables
     int rows;
     int temp = 1;
     printf("Enter the number of rows: ");
     scanf("%d", &rows);
     for (int i = 0; i < rows; i++) {
          for (int j = 1; j <= (rows - i); j++) {
               printf("  ");
          }
          for (int k = 0; k <= i; k++) {
               if (k == 0 || i == 0) {
                    temp = 1;
               } else {
                    temp = temp * (i - k + 1) / k;
               }
               printf("%4d", temp);
          }
          printf("\n");
     }
     return 0;
}