#include <stdio.h>

// Declare functions
int checkYear(int);
int checkMonth(int, int);

int main() {
     // Declare variables
     int date, month, year;
     int previousDate, nextDate, previousMonth, nextMonth;
     printf("Input dd mm yy: ");
     scanf("%d %d %d", &date, &month, &year);
     int checkY = checkYear(year); // Check whether it is a leap year or not
     int checkM = checkMonth(checkY, month); // Check month
     
     if (checkM == 28) { // Feburary in normal year
          if (date == 1) {
               previousDate = 31;
               previousMonth = 1;
               nextDate = 2;
               nextMonth = 2;
          } else if (date == 28) {
               previousDate = 27;
               previousMonth = 2;
               nextDate = 1;
               nextMonth = 3;
          } else {
               previousDate = date - 1;
               nextDate = date + 1;
               previousMonth = nextMonth = 2;
          }
     } else if (checkM == 29) { // Feburary in leap year
          if (date == 1) {
               previousDate = 31;
               previousMonth = 1;
               nextDate = 2;
               nextMonth = 2;
          } else if (date == 29) {
               previousDate = 28;
               previousMonth = 2;
               nextDate = 1;
               nextMonth = 3;
          } else {
               previousDate = date - 1;
               nextDate = date + 1;
               previousMonth = nextMonth = 2;
          }
     } else if (checkM == 31) { // Month: 1, 3, 5, 7, 8, 10, 12
          if (date == 1) {
               previousDate = 31;
               if (month == 1) {
                    previousMonth = 12;
                    year = year - 1;
               } else {
                    previousMonth = month + 1;
               }
               nextDate = 2;
               nextMonth = month;
          } else if (date == 31) {
               previousDate = 30;
               previousMonth = month;               
               nextDate = 1;
               if (month == 12) {
                    nextMonth = 1;
                    year++;
               } else {
                    nextMonth = month + 1;
               }
          } else {
               previousDate = date - 1;
               nextDate = date + 1;
               previousMonth = nextMonth = month;
          }
     } else { // Month: 4, 6, 9, 11
          if (date == 1) {
               previousDate = 31;
               previousMonth = month - 1;
               nextDate = 2;
               nextMonth = month;
          } else if (date == 31) {
               previousDate = 30;
               previousMonth = month;
               nextDate = 1;
               nextMonth = month + 1;
          } else {
               previousDate = date - 1;
               nextDate = date + 1;
               previousMonth = nextMonth = month;
          }
     }

     printf("The number of days in month %d is %d days.\n", month, checkM);
     printf("The previous date is %d/%d/%d\n", previousDate, previousMonth, year);
     printf("The next date is %d/%d/%d\n", nextDate, nextMonth, year);
     return 0;
}

int checkYear(int year) {
     if ((year % 4) == 0) {
          return 1;
     }
     return 0;
}

int checkMonth(int checkY, int month) {
     if (month == 2) { // Feburary
          if (checkY == 1) {
               return 29; // Leap year -> Return 29 days
          } else {
               return 28; // Not leap year -> Return 28 days
          }
     } else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
          return 31; // Month: 1, 3, 5, 7, 8, 10, 12
     } else {
          return 30; // Month: 4, 6, 9, 11
     }
}