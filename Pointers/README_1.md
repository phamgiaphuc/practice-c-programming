# Pointers Overview

## Address in C:
```C
#include <stdio.h>
int main() {
     // Declare variables
     int var = 5;
     printf("var: %d\n", var); // print the integer value of 'var' - 5

     // Notice the use of & before var
     printf("Address 1 of var: %p", &var);  // print the address of the 'var' in hexadecimal form - 0x7ff7b908e388
     printf("Address 2 of var: %x", &var); // print the address of the 'var' in hexadecimal integer - b908e388
     return 0;
}
```

## Pointers in C:
- Pointers (pointer variables) are special variables that are used to store addresses rather than values.
- Pointer syntax:
```C
// Declaration methods
int* p; // Declare a pointer p of int type (or any data types)
int * p;
int *p;
```
### Assigning address to pointers
```C
#include<stdio.h>
int main() {
     // Declare variables 
     int* p, n;
     n = 10; // Assign a value to n
     p = &n; // Assign the address's value of n to p
     printf("Address of n: %p\n", &n); // 0x7ff7b13d637c
     printf("Address of p: %p\n", &p); // 0x7ff7b13d6380 holds the address of n 0x7ff7b13d637c
     printf("Value of p: %p\n", p); // 0x7ff7b13d637c
     return 0;
}
```

### Getting value from the assgined address of the pointers
```C
printf("The value of assigned pointer: %d\n", *p); // 10
```

### Showing the complements of & and *
```C
printf("Showing that * and & are complements of each other\n&*p = %p\n*&p = %p\n", &*p, *&p); // 0x7ff7bee3e37c = 0x7ff7bee3e37c
```

### Changing value pointed by pointers
```C
// Example 1
int* pc, c;
c = 5;
pc = &c;
c = 1; // Change c value
printf("%d", c);    // Output: 1
printf("%d", *pc);  // Ouptut: 1

// Example 2
int* pc, c;
c = 5;
pc = &c;
*pc = 1; // Change *pc value
printf("%d", *pc);  // Ouptut: 1
printf("%d", c);    // Output: 1

// Example 3
int* pc, c, d;
c = 5;
d = -15;

pc = &c; // Assign c address to pc
printf("%d", *pc); // Output: 5
pc = &d; // Assign d address to pc
printf("%d", *pc); // Ouptut: -15
```

### Common mistakes
```C
int c, *pc;

// pc is address but c is not
pc = c;  // Error

// &c is address but *pc is not
*pc = &c;  // Error

// both &c and pc are addresses
pc = &c;  // Not an error

// both c and *pc are values 
*pc = c;  // Not an error
```

## Pointers with arrays
### Relationships betwwen pointers and arrays
- An array is a block of sequential data. Let's write a program to print addresses of array elements.
```C
#include <stdio.h>
int main() {
     int x[4];
     int i;

     for(i = 0; i < 4; ++i) {
          printf("&x[%d] = %p\n", i, &x[i]);
     }

     printf("Address of array x: %p", x);

     return 0;
}

/*
Output:
&x[0] = 0x7ff7be30c370 // Each int has a size of 4
&x[1] = 0x7ff7be30c374 // 0 + 4 = 4
&x[2] = 0x7ff7be30c378 // 4 + 4 = 8
&x[3] = 0x7ff7be30c37c // 8 + 4 = 12, in hexadecimal 12 is represented by c
Address of array x: 0x7ff7be30c370 // Notice that, the address of &x[0] and x is the same. It's because the variable name x points to the first element of the array.
*/
```
- Logic between pointers and arrays:
```C
&x[0] = &x // Address of the first element in the array is the address of the array
// Therefore
x[0] = *x // The value of the first element in the array
// Similarly
&x[1] is equivalent to x+1 and x[1] is equivalent to *(x+1).
&x[2] is equivalent to x+2 and x[2] is equivalent to *(x+2).
...
Basically, &x[i] is equivalent to x+i and x[i] is equivalent to *(x+i).
```
- Examples
```C
// Example 1
#include <stdio.h>
int main() {

     int i, x[6], sum = 0;
     printf("Enter 6 numbers: ");
     for(i = 0; i < 6; ++i) {
     // Equivalent to scanf("%d", &x[i]);
          scanf("%d", x+i);
     // Equivalent to sum += x[i]
          sum += *(x+i);
     }
     printf("Sum = %d", sum);
     return 0;
}

/*
Output:
Enter 6 numbers: 2
3
4
4
12
4
Sum = 29 
 */

// Example 2
#include <stdio.h>
int main() {
     int x[5] = {1, 2, 3, 4, 5};
     int* ptr;
     // ptr is assigned the address of the third element
     ptr = &x[2]; 
     printf("*ptr = %d \n", *ptr);   // 3
     printf("*(ptr+1) = %d \n", *(ptr+1)); // 4
     printf("*(ptr-1) = %d", *(ptr-1));  // 2
     return 0;
}
```

## Passing Addresses and Pointers to Functions
- Example 1: Passing Addresses to Functions
```C
#include <stdio.h>
void swap(int *n1, int *n2);

int main()
{
     int num1 = 5, num2 = 10;

     // address of num1 and num2 is passed
     swap( &num1, &num2);

     printf("num1 = %d\n", num1); // num1 = 10
     printf("num2 = %d", num2); // num2 = 5
     return 0;
     }

     void swap(int* n1, int* n2)
     {
     int temp;
     temp = *n1;
     *n1 = *n2;
     *n2 = temp;
}
```

- Example 2: Passing Pointers to Functions
```C
#include <stdio.h>

void addOne(int* ptr) {
     (*ptr)++; // adding 1 to *ptr
}

int main() {
     int* p, i = 10;
     p = &i;
     addOne(p);

     printf("%d", *p); // 11
     return 0;
}
```

## Dynamic Memory Allocation
- To allocate memory dynamically, library functions are malloc(), calloc(), realloc() and free() are used. These functions are defined in the <stdlib.h> header file.
### sizeof()
- When you use the sizeof operator on a pointer variable like array, it returns the size of the pointer itself, not the size of the allocated memory.
```C
int *ptr = (int*) malloc(10 * sizeof(int));
     printf("%lu\n", sizeof(ptr)); // 8
```
- In this case, the size of ptr is 8 because you are running the code on a system where the size of a pointer is 8 bytes. Pointer sizes can vary depending on the platform and compiler being used. It is common for 64-bit systems to have 8-byte pointers.
- To get the size of the allocated memory, you need to keep track of it separately. In your example, you allocated memory for an array of 10 integers, so the total size of the allocated memory would be 10 * sizeof(int).
- If you want to print the size of the allocated memory, you should calculate it separately and then use printf to display it:
```C
printf("%lu\n", 10 * sizeof(int));
```

### malloc() = mememory allocation: size
- The malloc() function allocates memory and leaves the memory uninitialized
- Syntax:
```C
ptr = (castType*) malloc(size);
```
- Example: 
```C
ptr = (float*) malloc(100 * sizeof(float)); // the size is 400 bytes
```
### calloc() = contiguous allocation: size + number of elements
- The calloc() function allocates memory and initializes all bits to zero.
- Syntax:
```C
ptr = (castType*)calloc(n, size);
```
- Example:
```C
ptr = (float*) calloc(25, sizeof(float)); // the size is 100 bytes and the number of element is 25
```
### free(): erasing unused memory
- Dynamically allocated memory created with either calloc() or malloc() doesn't get freed on their own. You must explicitly use free() to release the space.
- Syntax:
```C
free(ptr); // This statement frees the space allocated in the memory pointed by ptr.
```
### realloc():
- Syntax:
```C
ptr = realloc(ptr, x);
```
### Examples
- Example 1: malloc() and free()
```C
// Program to calculate the sum of n numbers entered by the user

#include <stdio.h>
#include <stdlib.h>

int main() {
     int n, i, *ptr, sum = 0;

     printf("Enter number of elements: ");
     scanf("%d", &n);

     ptr = (int*) malloc(n * sizeof(int));
     
     // if memory cannot be allocated
     if(ptr == NULL) {
     printf("Error! memory not allocated.");
     exit(0);
     }

     printf("Enter elements: ");
     for(i = 0; i < n; ++i) {
     scanf("%d", ptr + i);
     sum += *(ptr + i);
     }

     printf("Sum = %d\n", sum);
     
     // deallocating the memory
     free(ptr);

     return 0;
}
```
- Example 2: calloc() and free()
```C
// Program to calculate the sum of n numbers entered by the user

#include <stdio.h>
#include <stdlib.h>

int main() {
     int n, i, *ptr, sum = 0;
     printf("Enter number of elements: ");
     scanf("%d", &n);

     ptr = (int*) calloc(n, sizeof(int));
     if(ptr == NULL) {
     printf("Error! memory not allocated.");
     exit(0);
     }

     printf("Enter elements: ");
     for(i = 0; i < n; ++i) {
     scanf("%d", ptr + i);
     sum += *(ptr + i);
     }

     printf("Sum = %d", sum);
     free(ptr);
     return 0;
}
```
- Example 3: realloc()
```C
#include <stdio.h>
#include <stdlib.h>

int main() {
     int *ptr, i , n1, n2;
     printf("Enter size: ");
     scanf("%d", &n1);

     ptr = (int*) malloc(n1 * sizeof(int));

     printf("Addresses of previously allocated memory:\n");
     for(i = 0; i < n1; ++i)
     printf("%pc\n",ptr + i);

     printf("\nEnter the new size: ");
     scanf("%d", &n2);

     // rellocating the memory
     ptr = realloc(ptr, n2 * sizeof(int));

     printf("Addresses of newly allocated memory:\n");
     for(i = 0; i < n2; ++i)
     printf("%pc\n", ptr + i);
     
     free(ptr);

     return 0;
}
/*
Output: 
Enter size: 2
Addresses of previously allocated memory:
0x7f85c8705b20c
0x7f85c8705b24c

Enter the new size: 5
Addresses of newly allocated memory:
0x7f85c8705b20c
0x7f85c8705b24c 
0x7f85c8705b28c
0x7f85c8705b2cc
0x7f85c8705b30c
 * /
```
