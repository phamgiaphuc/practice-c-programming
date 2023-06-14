#include <stdio.h>

int isPerfectNumber(int);

int main() {
     printf("Exercise 3B\n");
     // Declare variables
     int temp_num = 1000;
     printf("The perfect number from 1 to %d: ", temp_num);
     for (int i = 1; i <= temp_num; i++) {
          int check = isPerfectNumber(i);
          if (check == i) {
               printf("%d ", i);
          }
     }
     printf("\n");
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