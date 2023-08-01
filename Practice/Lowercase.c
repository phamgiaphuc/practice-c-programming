#include <stdio.h>
#include <string.h>
#include <ctype.h>

void lowercaseChar(char[]);

int main() {
     char text[100] = "  i aM a sTuDent";
     lowercaseChar(text);
     return 0;
}

void lowercaseChar(char text[]) {
     int length = strlen(text);
     int start = 0;
     for (int i = 0; i < length; i++) {
          if (text[i] != 32) {
               start = i;
               break;
          }
     }
     text[start] = toupper(text[start]);
     for (int i = start + 1; i < length; i++) {
          if (text[i] != 32 && text[i - 1] == 32) {
               text[i] = toupper(text[i]);
          } else {
               text[i] = tolower(text[i]);
          }
     }
     for (int i = 0; i < length; i++) {
          printf("%c", text[i]);
     }
     printf("\n");
}