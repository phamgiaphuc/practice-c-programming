#include <stdio.h>

// Declare functions
void swapValue(int*, int*);

int main() {
     // Declare variables
     int x, y, z, *p, *q, *r;
     // Assign values
     x = 1, y = 2, z = 3;
     p = &x, q = &y, r = &z;

     // Print (1)
     printf("\nPrint (1) - Before\n");
     printf("The value of x, y, z respectively are: %d, %d, %d\n", x, y, z);
     printf("The value of *p, *q, *r respectively are: %d, %d, %d\n", *p, *q, *r);

     // Print (2)
     printf("\nPrint (2) - Swapping\n");
     // z = x
     swapValue(r, p); // z = 1
     // x = y
     swapValue(p, q); // x = 2
     // y = z
     swapValue(q, r); // y = 1

     // Print (3)
     printf("\nPrint (3) - After swapping\n");
     printf("The value of x, y, z respectively are: %d, %d, %d\n", x, y, z);
     printf("The value of *p, *q, *r respectively are: %d, %d, %d\n", *p, *q, *r);

     return 0;
}

void swapValue (int *a, int *b) {
     *a = *b;
}