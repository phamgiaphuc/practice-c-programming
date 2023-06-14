#include <stdio.h>

#define SIZE 1000

int isPerfectNumber (int, int[]);
void checkNumFactors(int, int, int[]);

int main() {
     // Declare variables
     int num;
     int factors[SIZE]; // Array storing the factors
     while (true) {
          printf("Enter an integer: "); // User input
          scanf("%d", &num);
          if (num <= 0) {
               printf("Your input value '%d' is wrong. Please input again!\n", num); // Check if the input value is correct
          } else {
               int numFactors = isPerfectNumber(num, factors);
               checkNumFactors(numFactors, num, factors);
          }
     }
     return 0;
}

void checkNumFactors(int numFactors, int num, int factors[]) {
     // Check numFactors
     if (numFactors != -1) {
          printf("%d is a perfect number since: ", num);
          // Print out all the factors
          for (int i = 0; i < numFactors; i++) {
               if (i == (numFactors - 1)) {
                    printf("%d = %d\n", factors[i], num);
               } else {
                    printf("%d + ", factors[i]);
               }
          }
     } else {
          printf("%d is not a perfect number\n", num);
     }
}

int isPerfectNumber (int num, int factors[]) {
     // Declare variables
     int sum = 0; // Sum up the divisors to check the number if it is a perfect number
     int factorIndex = 0;

     // Check the number by dividing by 1 to (number/2)
     for (int i = 1; i <= (num / 2); i++) {
          if ((num % i) == 0) {
               factors[factorIndex] = i;
               factorIndex++;
               sum += i;
          }
     }

     // Check if the sum is equal to the number
     if (sum == num) {
          return factorIndex; // Num is a perfect number
     } else {
          return -1; // Num is not a perfect number
     }
}