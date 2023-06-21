#include <stdio.h>

// Declare functions
void swapPointer(int**, int**);

int main() {
     // Declare variables
     int x, y, z, *p, *q, *r;
     // Assign values
     x = 1, y = 2, z = 3;
     p = &x, q = &y, r = &z;

     // Print (1)
     printf("\nPrint (1) - Before swapping\n");
     printf("The value of x, y, z respectively are: %d, %d, %d\n", x, y, z);
     printf("The value of p, q, r respectively are: %p, %p, %p\n", p, q, r);
     printf("The value of *p, *q, *r respectively are: %d, %d, %d\n", *p, *q, *r);

     // Print (2)
     printf("\nPrint (2) - Swapping\n");
     // r = p
     swapPointer(&r, &p); // r = 0x7ff7b8320338
     // p = q
     swapPointer(&p, &q); // p = 0x7ff7b8320334
     // q = r
     swapPointer(&q, &r); // q = 0x7ff7b8320338

     // Print (3)
     printf("\nPrint (3) - After swapping\n");
     printf("The value of x, y, z respectively are: %d, %d, %d\n", x, y, z);
     printf("The value of p, q, r respectively are: %p, %p, %p\n", p, q, r);
     printf("The value of *p, *q, *r respectively are: %d, %d, %d\n", *p, *q, *r);

     return 0;
}

void swapPointer (int **a, int **b) {
     *a = *b;
}