#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char keypad[10][5] = {
     "",     // 0
     "",     // 1
     "abc",  // 2
     "def",  // 3
     "ghi",  // 4
     "jkl",  // 5
     "mno",  // 6
     "pqrs", // 7
     "tuv",  // 8
     "wxyz"  // 9
};

void generateCombinations(int* input, int size, char* output, int index) {
     if (index == size) {
          printf("%s\n", output);
          return;
     }

     int digit = input[index];
     int length = strlen(keypad[digit]);

     for (int i = 0; i < length; i++) {
          output[index] = keypad[digit][i];
          generateCombinations(input, size, output, index + 1);
     }
}

int main() {
     int input[100];
     int size, i;
     char output[100];

     printf("Enter the size of the input: ");
     scanf("%d", &size);

     printf("Enter the keypad inputs: ");
     for (i = 0; i < size; i++) {
          scanf("%d", &input[i]);
     }

     printf("Possible combinations of letters:\n");
     generateCombinations(input, size, output, 0);

     return 0;
}
