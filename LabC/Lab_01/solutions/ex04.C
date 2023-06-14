#include <stdio.h>

int main() {

     // Declare variables
     int t;
     int x = 1;
     int y = 2;
     
     if (x > y) {
          t = 0;
          x = 5;
     } else {
          t = 1;
          x = 10;
     }
     printf("x = %d; t = %d\n", x, t);
     return 0;
}