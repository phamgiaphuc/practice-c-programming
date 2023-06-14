#include<stdio.h>

int main() {

     // Declare variables
     int n;
     
     printf("Enter a number: ");
     scanf("%d", &n);
     printf("Result: ");
     if(n < 2) {
          printf("No result!");
     } else {
          for (int i = 2; i <= n; i++) {
               int result = 0; 
               for (int j = 2; j < i; j++) {
                    if (i % j == 0) {
                         result = -1;
                         break;
                    }
               }
               if (result == 0) {
                    printf("%d ", i);
               }
          }
     }
     printf("\n");
     return 0;
}