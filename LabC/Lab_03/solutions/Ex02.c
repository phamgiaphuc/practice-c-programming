#include <stdio.h>
#include <limits.h>

// Declare functions
int checkNumber(int);

int main() {
     // Declare variables
     int num;
     long long int factorial = 1;
     printf("Enter a number: ");
     scanf("%d", &num);
     int check = checkNumber(num);
     if (check == 1) { // Even number
          for (int i = 2; i <= num; i+= 2) {
               factorial *= i;
          }
     } else { // Odd number
          for(int i = 1; i<= num; i+= 2) {
               factorial *= i;
          }
     }
     if (factorial > LLONG_MAX) {
          printf("The factorial is too large to be represented.\n");
     } else {
          printf("The factorial with the given integer %d is %lld\n", num, factorial);
     }
     return 0;
}

// Check if the number is even or odd number
int checkNumber(int num) {
     if ((num % 2) == 0) { 
          return 1; // Even number
     }
     return 0; // Odd number
}

