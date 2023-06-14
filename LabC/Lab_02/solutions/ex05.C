#include <stdio.h>

/**
 * 2D array:
 *        1    2    3    4    5 (j)
 *     1  1    x    x    x    x    
 * 
 *     2  2    2    x    x    x    
 *
 *     3  3    3    3    x    x  
 * 
 *     4  4    4    4    4    x  
 * 
 *     5  5    5    5    5    5    
 *    (i)
*/

int main() {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}