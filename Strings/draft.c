// Your code goes here...
#include<stdio.h>
#include <string.h>
 
int main() {    
  char str1[20] = "ab" , str2[20] = "db";    
  if (strcmp(str1, str2) == 0) {
   printf("2 chuoi bang nhau.");
  } else if (strcmp(str1, str2) > 0) {
   printf("Chuoi 1 lon hon chuoi 2");
  } else {
   printf("Chuoi 1 nho hon chuoi 2");
  }
  printf("\n");
  return 0;
}