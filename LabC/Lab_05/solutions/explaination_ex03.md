# Exercise 3

## Problem
Write a program to input an array of m x n. Sort the odd column in increasing order and the even column in decreasing order.
- Example:
```C
Input:           Output:
1 2              3 2
3 4              1 4
```

## Solution
- Click [here](ex03.c)
## Explaination
- In the "sortColumns" function, take the example as the input for the algorithm
```C
// Graph

     0    1              0  1    0  1
     ------         OR {[1, 2], [3, 4]}
0  | 1    2
1  | 3    4

// Operation
m = 2, n = 2 // The number of columns and length of each column
Start at j = 0
     Case 1: j = 0 -> j is an even number // Right case
          i = 0
          k = 1 // Right case
          array[0][0] = 1
          array[1][0] = 3
          Case 1.1: array[0][0] is smaller array[1][0] (1 < 3) // Right case
               temp = 1;
               array[0][0] = 3;
               array[1][0] = 1;
          k = 2 // Wrong case -> Out of the loop
          -----
          i = 1
          k = 2 // Wrong case -> Out of the loop

          -----
          i = 2 // Wrong case -> Out of the loop
     
     Case 2: j = 1 -> j is an odd number // Right case
          i = 0
          k = 1 // Right case
          array[0][1] = 2
          array[1][1] = 4
          Case 2.1: array[0][1] is larger array[1][1] (2 > 4) // Wrong case
          k = 2 // Wrong case -> Out of the loop
          -----
          i = 1
          k = 2 // Wrong case -> Out of the loop

          -----
          i = 2 // Wrong case -> Out of the loop
```