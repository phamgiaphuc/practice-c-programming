#include <stdio.h>

int main() {
     
     // Declare variables
     int x, y;

     printf("Enter x: ");
     scanf("%d", &x);
     printf("Enter y: ");
     scanf("%d", &y);
     int result = x*(y-2)*((x-1)*(3*y-1)+y+10)-(y-3)*(4*y+2)+19*x; // 16 operations
     printf("Result: %d\n", result);
     return 0;
}