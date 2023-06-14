#include <stdio.h>

int main() {
     
     // Declare variables
     int num, temp;

     printf("Enter a number: ");
     scanf("%d",&num);
     printf("Result: ");
     while(num != 0) {
          temp = num % 10;
          printf("%d ", temp);
          num /= 10;
     }
     printf("\n");
     return 0;
}