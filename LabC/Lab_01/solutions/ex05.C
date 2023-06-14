#include <stdio.h>

int main()
{
     // Declare variables
     int num, week;
     float rate;
     int count = 1;
     
     printf("Enter the number of chickens: ");
     scanf("%d", &num);
     // Rate of breeding chicken is in percentage
     printf("Enter the rate after 1 week: ");
     scanf("%f", &rate);
     printf("Enter weeks: ");
     scanf("%d", &week);
     while (count <= week) {
          num += (num * (rate / 100));
          count++;
     }
     printf("The number of chickens after %d weeks is %d\n", week, num);
     return 0;
}
