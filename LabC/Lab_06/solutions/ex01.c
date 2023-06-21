#include <stdio.h>

int main() {
     // Declare variables
     int x, y, *ptrp, *ptrq;
     // Assign values
     x = 2;
     y = 8;
     ptrp = &x;
     ptrq = &y;

     // Print (1)
     printf("\nPrint (1)\n");
     printf("The address of x: %p\n", &x); // 0x7ff7bfa7e338
     printf("The values of x: %d\n", x); // 2

     // Print (2)
     printf("\nPrint (2)\n");
     printf("The value of p: %p\n", ptrp); // 0x7ff7bfa7e338
     printf("The value of *p: %d\n", *ptrp); // 2

     // Print (3)
     printf("\nPrint (3)\n");
     printf("The address of x: %p\n", &y); // 0x7ff7bfa7e334
     printf("The values of x: %d\n", y); // 8

     // Print (4)
     printf("\nPrint (4)\n");
     printf("The value of p: %p\n", ptrq); // 0x7ff7bfa7e334
     printf("The value of *p: %d\n", *ptrq); // 8

     // Print (5)
     printf("\nPrint (5)\n");
     printf("The addres of p: %p\n", &ptrp); // 0x7ff7bfa7e328

     // Print (6)
     printf("\nPrint (6)\n");
     printf("The addres of q: %p\n", &ptrq); // 0x7ff7bfa7e320
     return 0;
}