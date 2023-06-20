#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
     int *array = (int*) malloc(10 * sizeof(int));
     printf("%d\n", *array);
     printf("%lu\n", sizeof(array));
     return 0;
}