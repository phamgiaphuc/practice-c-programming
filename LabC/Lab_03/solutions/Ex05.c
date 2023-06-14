#include <stdio.h>

//Declare fucnctions
int calculateTotalMoney(float);

int main() {
     // Declare variables
     float distance;
     int total;
     while (1) {
          printf("Enter the number of distance: ");
          scanf("%f", &distance);
          if (distance <= 0) {
               printf("Enter again!\n");
          } else {
               total = calculateTotalMoney(distance);
               printf("The total money is %dVND.\n", total);
          }
     }
     return 0;
}

// Calculate the total money
int calculateTotalMoney(float distance) {
     int total = 0;
     while (distance != 0) {
          if (distance <= 2) { // Case 1: Distance <= 2km
               total += 15000; 
               break;
          } else {
               distance -= 2;
               if (distance <= 30) { // Case 2: Distance <= 30km && > 2km
                    total += 15000 + (distance * 2000) / 0.25;
               } else { // Case 3: Distance > 30km
                    float remaining_distance = distance - 30;
                    total += 15000 + (28 * 2000) / 0.25 + (remaining_distance / 1) * 5000 + (remaining_distance - (int)remaining_distance) * 2000;
               }
               break;
          }
     }
     return total;
}
