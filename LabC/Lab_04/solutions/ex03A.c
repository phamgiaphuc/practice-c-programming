#include <stdio.h>

// Declare functions
int isPerfectNumber(int);

int main() {
     printf("Exercise 3A\n");
     // Declare variables
     int number;
     printf("Input a number: ");
     scanf("%d", &number);
     int check = isPerfectNumber(number);
     if (check == number) {
          printf("%d is a perfect number.\n", number);
     } else {
          printf("%d is not a perfect number.\n", number);
     }
     return 0;
}

int isPerfectNumber(int number) {
     int sum = 0;
     for (int i = 1; i <= (number / 2); i++) {
          if ((number % i) == 0) {
               sum += i;
          }
     }
     return sum;
}