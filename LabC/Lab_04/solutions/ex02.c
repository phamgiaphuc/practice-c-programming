#include <stdio.h>
#include <math.h>

// Declare functions
float calculation_2(float);

int main() {
     printf("Exercise 2\n");
     printf("N\t\tPi\n");
     printf("------------------------------\n");
     // Declare variables
     float result, temp;
     for (float i = 10; i <= 20; i++) {
          temp = calculation_2(i);
          result = sqrt(6*temp);
          printf("%.3f\t\t%f\n", i, result);
     }
     return 0;
}

float calculation_2(float number) {
     if (number > 0) {
          float pow_number = pow(number, 2);
          return (1/pow_number) + calculation_2(number - 1);
     } else {
          return 0;
     }
}