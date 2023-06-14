#include <stdio.h>

int main() {
     // Declare variables
     int currenTotalAccount, numberOfYear, count = 1;
     float yearlyInterestRate;
     printf("Enter the current balance of the bank saving account: ");
     scanf("%d", &currenTotalAccount);
     printf("Enter the yearly interest rate: ");
     scanf("%f", &yearlyInterestRate);
     printf("Enter the number of year: ");
     scanf("%d", &numberOfYear);
     // Calculate the final total account
     while (count <= numberOfYear) {
          int temp = currenTotalAccount;
          currenTotalAccount += (temp * (yearlyInterestRate / 100));
          count++;
     }
     // Print final total
     printf("Final total after %d years: %d\n", numberOfYear, currenTotalAccount);
}