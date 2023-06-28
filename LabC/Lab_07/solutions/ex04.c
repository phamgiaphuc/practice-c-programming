#include <stdio.h>
#include <string.h>

int isValidBinary(const char* str) {
     int len = strlen(str);
     for (int i = 0; i < len; i++) {
          if (str[i] != '0' && str[i] != '1') {
               return 0; 
          }
     }
     return 1; 
}

char* addBinary(const char* a, const char* b) {
     if (!isValidBinary(a) || !isValidBinary(b)) {
          return "Invalid input";  
     }

     int lenA = strlen(a);
     int lenB = strlen(b);
     int maxLen = (lenA > lenB) ? lenA : lenB;
     char result[maxLen + 2];  
     result[maxLen + 1] = '\0';  
     int carry = 0;
     int i = lenA - 1;
     int j = lenB - 1;
     int k = maxLen;

     while (i >= 0 || j >= 0) {
          int sum = carry;

          if (i >= 0) {
               sum += a[i] - '0';
               i--;
          }

          if (j >= 0) {
               sum += b[j] - '0';
               j--;
          }

          result[k] = (sum % 2) + '0';  
          carry = sum / 2;
          k--;
     }

     if (carry != 0) {
          result[k] = carry + '0';  
          return strdup(result); 
     }

     return strdup(result + 1);  
}

int main() {
     char a[100], b[100];

     printf("Enter the first binary number: ");
     scanf("%s", a);

     printf("Enter the second binary number: ");
     scanf("%s", b);

     char* result = addBinary(a, b);

     printf("Product: %s\n", result);

     return 0;
}
