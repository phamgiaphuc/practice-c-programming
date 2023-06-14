#include <stdio.h>
#include <math.h>

int main() {
     printf("       Quadratic Equation       \n");
     printf("--------------------------------\n");
     
     // Declare variables
     float a, b, c;
     printf("Input a: ");
     scanf("%f", &a);
     printf("Inupt b: ");
     scanf("%f", &b);
     printf("Input c: ");
     scanf("%f", &c);
     printf("Result: ");

     // Case a = 0: x = -b/c
     if (a == 0) {
          printf("%.3f\n", (-b / c));
     } else {
          float denta = pow(b, 2) - (4 * a * c);
          if (denta == 0) { // Case denta = 0: x = -b / (2 * a);
               printf("%.2f\n", (-b / (2 * a)));
          } else if (denta > 0) {
               float x1 = (-b + sqrt(denta)) / (2 * a);
               float x2 = (-b - sqrt(denta)) / (2 * a);
               printf("%.3f, %.3f\n", x1, x2);
          } else {
               printf("No Solution!\n");
          }
     }
}