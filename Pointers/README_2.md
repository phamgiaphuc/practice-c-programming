# Pointer declaration with "const"

## Question: 
```C
what is the difference between int *const myPtr = &x, const int *myPtr = &x and const int *const Ptr = &x ?
```
## Explaination:
The three declarations you provided involve different combinations of const and pointer qualifiers. Let's break down each one:

1. int *const myPtr = &x
- myPtr is a constant pointer to an integer. It means that myPtr will always point to the same memory location throughout its lifetime.
- The integer value stored in the memory location pointed by myPtr can be modified.
```C
int x = 5;
int y = 10;

int *const myPtr = &x;

*myPtr = 7; // Modifying the value at the memory location

myPtr = &y; // Error: Cannot reassign the constant pointer
```

2. const int *myPtr = &x
- myPtr is a non-constant pointer to a constant integer. It means that myPtr can be reassigned to point to different memory locations, but the value stored in the memory location it points to cannot be modified through this pointer.
- The pointer itself can be modified (i.e., you can reassign myPtr to point to a different memory location).
```C
int x = 5;
int y = 10;

const int *myPtr = &x;

myPtr = &y; // Reassigning the pointer to a different memory location

*myPtr = 7; // Error: Cannot modify the value through the const pointer
```

3. const int *const Ptr = &x
- In this case, Ptr is a constant pointer to a constant integer. Both the pointer itself and the value it points to are constant and cannot be modified.
```C
int x = 5;
int y = 10;

const int *const Ptr = &x;

*Ptr = 7; // Error: Cannot modify the value through the const pointer

Ptr = &y; // Error: Cannot reassign the constant pointer
```

Please note that in the examples, the error comments indicate operations that would result in a compilation error due to violating the constness of the pointer or the value it points to, depending on the case.

## Summary:
To summarize:
- In the first case, the pointer is constant, but the value it points to is - not constant.
- In the second case, the pointer is non-constant, but the value it points to is constant.
- In the third case, both the pointer and the value it points to are constant.
