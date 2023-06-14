#include <stdio.h>

int main() {
     // Declare variables
     char operation;
     int num1, num2;
     int result;
     printf("Input: ");
     scanf("%d%c%d", &num1, &operation, &num2);
     switch (operation) {
          case '+': // Add
            result = num1 + num2;
            printf("Result: %d\n", result);
            break;
        case '-': // Minus
            result = num1 - num2;
            printf("Result: %d\n", result);
            break;
        case '*': // Multiply
            result = num1 * num2;
            printf("Result: %d\n", result);
            break;
        case '/': // Divide
            if (num2 != 0) {
                result = num1 / num2;
                printf("Result: %d\n", result);
            } else {
                printf("Equation can not be calculated,\n");
            }
            break;
        default:
            printf("Error: Invalid operator.\n");
            break;

     }
     return 0;
}