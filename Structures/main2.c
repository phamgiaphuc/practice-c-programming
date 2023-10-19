#include <stdio.h>
#include <string.h>

struct person {
     int age;
     float weight;
};

int main() {
     struct person *personPtr, person1;
     personPtr = &person1;   

     printf("Enter age: ");
     scanf("%d", &personPtr->age); // &[(*personPtr).age]

     printf("Enter weight: ");
     scanf("%f", &personPtr->weight);

     printf("Displaying:\n");
     printf("Age: %d\n", personPtr->age);
     printf("weight: %.1f", personPtr->weight);
     printf("\n");
     
     return 0;
}