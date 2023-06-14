#include <stdio.h>

// Declare functions
int calculation_1(int);

int main() {
     printf("Exercise 1\n");
     // Declare variables
     int result, number;
     printf("Input a number: ");     
     scanf("%d", &number);
     result = calculation_1(number);
     printf("The result: %d\n", result);
     return 0;
}

int calculation_1 (int number) {
     if (number > 0) {
          return (number*(number + 1)) + calculation_1(number - 1);
     } else {
          return 0;
     }
}