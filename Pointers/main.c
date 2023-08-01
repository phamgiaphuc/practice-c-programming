// Your code goes here...
#include <stdio.h>

int main()
{
     int *ptrA;
     int *ptrB;
     
     ptrA = (int *)1;
     ptrB = (int *)2;
     
     if(ptrB > ptrA)
          printf("PtrB is greater than ptrA\n");
     
     printf("%p\n", ptrA);
     printf("%p\n", ptrB);

    return(0);
}