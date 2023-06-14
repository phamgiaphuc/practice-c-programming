#include <stdio.h>

int main() {
     // Declare variables
     int totalOfPossiblity = 0;
     printf("Possiblities:\n");
     for (int a = 0; a <= 30; a++) {
          for (int b = 0; b <= 15; b++) {
               for (int c = 0; c <= 6; c++) {
                    for (int d = 0; d <= 3; d++) {
                         if (a*1000 + b*2000 + c*5000 + d*10000 == 30000) {
                              totalOfPossiblity++;
                              printf("Case %d: ", totalOfPossiblity);
                              if (a > 0) {
                                   printf("%d notes of 1,000VND ", a);
                              }
                              if (b > 0) {
                                   if (a > 0) {
                                        printf("+ ");
                                   }
                                   printf("%d notes of 2,000VND ", b);
                              }
                              if (c > 0) {
                                   if (a > 0 || b > 0) {
                                        printf("+ ");
                                   }
                                   printf("%d notes of 5,000VND ", c);
                              }
                              if (d > 0) {
                                   if (a > 0 || b > 0 || c > 0) {
                                        printf("+ ");
                                   }
                                   printf("%d notes of 10,000VND ", d);
                              }
                              printf("\n");
                         }
                    }
               }
          }
     }
     printf("The number of possiblity is %d\n", totalOfPossiblity);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
     return 0;
}