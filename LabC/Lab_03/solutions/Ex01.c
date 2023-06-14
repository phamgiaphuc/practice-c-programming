#include <stdio.h>
#define SIZE 100

// Declare functions
void calculateOperation(int, int[], int, int[]);
void printOutFactors(int[]);

int main() {
     // Declare variables
     int even_sum = 0, odd_sum = 0;
     int even_factors[SIZE], odd_factors[SIZE];
     printf("Calculate sum of even numbers and sum of odd numbers from 0 to 100.\n");
     printf("-------------------------------------------------------------------\n");
     calculateOperation(even_sum, even_factors, odd_sum, odd_factors);
     printf("-------------------------------------------------------------------\n");
     printf("The even factors: ");
     printOutFactors(even_factors);
     printf("The odd factors: ");
     printOutFactors(odd_factors);
     return 0;
}

// Calculating the sum of even numbers and odd numbers. Add even and odd numbers into 2 seperated arrays
void calculateOperation(int even_sum, int even_factors[], int odd_sum, int odd_factors[]) {
     // Declare variables
     int even_count = 0, odd_count = 0;
     for (int i = 0; i <= 100; i++) {
          if ((i % 2) == 0) { // Even number
               even_sum += i;
               even_factors[even_count] = i;
               even_count++;
          } else { // Odd number
               odd_sum += i;
               odd_factors[odd_count] = i;
               odd_count++;
          }
     }
     printf("The sum of even numbers: %d\n", even_sum);
     printf("The sum of odd numbers: %d\n", odd_sum);
}

// Printing values in the array
void printOutFactors(int array[]) {
     for (int i = 0; i < 50; i++) {
          if (i == (50 - 1)) {
               printf("%d\n", array[i]);
          } else {
               printf("%d, ", array[i]);
          }
     }
}