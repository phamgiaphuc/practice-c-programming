#include <stdio.h>
#include <math.h>

int main() {
     printf("%s\t%s\t%s\n", "Number", "Square", "Cube");
     for (int i = 0; i <= 10; i++) {
          int a = pow(i, 2);
          int b = pow(i, 3);
          printf("%d\t%d\t%d\t\n", i, a, b);
     }
     return 0;
}
