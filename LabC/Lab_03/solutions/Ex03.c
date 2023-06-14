#include <stdio.h>
#include <math.h>

int main() {
     int num;
     int sum = 1;
     printf("Enter a number: ");
     scanf("%d", &num);
     for (int i = 3; i <= num; i += 2) {
          sum += pow(i, 2);
     }
     printf("The result is %d.\n", sum);
     return 0;
}