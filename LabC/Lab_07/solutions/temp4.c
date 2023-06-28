#include <stdio.h>
#include <stdlib.h>

int main() {
     // Declare variables
     long binary1, binary2;
     int i = 0, remainder = 0, sum[20];
     char *sum_string;

     // Input numbers
     printf("Enter the first binary number: ");
     scanf("%ld", &binary1);
     printf("Enter the second binary number: ");
     scanf("%ld", &binary2);

     // Calculation
     while (binary1 != 0 || binary2 != 0) {
          sum[i++] =(binary1 % 10 + binary2 % 10 + remainder) % 2;
          remainder =(binary1 % 10 + binary2 % 10 + remainder) / 2;
          binary1 = binary1 / 10;
          binary2 = binary2 / 10;
     }
     if (remainder != 0) {
          sum[i++] = remainder;
     }
     --i;
     printf("%d", i);

     // Convert the int array to char arrar (string)
     sum_string = (char*) sum;

     // Output
     printf("Sum of two binary numbers: ");
     while (i >= 0) {
          printf("%d", sum_string[i--]);
     }
     printf("\n");

     return 0;
}