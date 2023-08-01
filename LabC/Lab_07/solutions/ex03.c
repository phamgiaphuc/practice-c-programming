#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *multiplyComplexNumbers(const char*,const char*);

int main() {
     // Declare variables
     char *ptr1 = (char *)malloc(100 * sizeof(char));
          char *ptr2 = (char *)malloc(100 * sizeof(char));

     // Input the complex numbers
     printf("Input 1st complex number: ");
     scanf("%s", ptr1);
     printf("Input 2nd complex number: ");
     scanf("%s", ptr2);

     // Calculation
     char *result = multiplyComplexNumbers(ptr1, ptr2);
     printf("Product: %s\n", result);

     // Free allocated memmory
     free(ptr1);
     free(ptr2);
     free(result);

     return 0;
}

char *multiplyComplexNumbers(const char* num1, const char* num2) {
     int a1, b1, a2, b2;
     sscanf(num1, "%d+%di", &a1, &b1);
     sscanf(num2, "%d+%di", &a2, &b2);

     int realPart = (a1 * a2) - (b1 * b2);
     int imaginaryPart = (a1 * b2) + (b1 * a2);

     char* result = (char*)malloc(100 * sizeof(char));
     sprintf(result, "%d+%di", realPart, imaginaryPart);

     return result;
}