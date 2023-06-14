#include <stdio.h>

int main() {

     // Declare variables
     int n, max, min;
     printf("%d %d", max, min);
     
     while(1) {
          printf("Enter a number: ");
          scanf("%d", &n);
          if (n == 0) {
               break;
          } else {
               if (max < n) {
                    max = n;
               }
               if (min > n) {
                    min = n;
               }
          }
     }
     printf("The maximum number: %d\n", max);
     printf("The minimum number %d\n", min);
}