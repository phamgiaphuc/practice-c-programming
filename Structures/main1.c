#include <stdio.h>
#include <string.h>

// Initialize a structure of person variables
struct Person {
     char fullName[25];
     int age; 
} person1; // Declared variables

// typedef struct { variables }

// Initialize a nested structure of more person variables
struct MoreInfo {
     struct Person person;
     char address[25];
     int favoriteNumber;
} modifiedPerson1; // Declared variables

typedef struct MoreInfo PersonTypeDef;

int main() {
     // Acess person1 variables
     // person1.fullName = "Acus"; // Common mistake when assign value to char variable
     strcpy(person1.fullName, "Acus");
     person1.age = 18;

     // int result = strcmp(person1.fullName, "");
     // printf("Compare = %d\n", result);

     // Print out the person1 variables
     printf("Person 1 information:\n");
     printf("Full name: %s\n", strcmp(person1.fullName, "") ? person1.fullName : "null");
     printf("Age: %d\n", person1.age);
     printf("\n");

     // Acess modifiedPerson1 variables 
     modifiedPerson1.person = person1;
     printf("Input the address: ");
     fgets(modifiedPerson1.address, sizeof(modifiedPerson1), stdin);
     printf("Input the favorite number: ");
     scanf("%d", &modifiedPerson1.favoriteNumber);

     // Print out the modifiedPerson1 variables
     printf("Modified person 1 information: \n");
     printf("Person 1: {fullName = %s, age = %d}\n", strcmp(modifiedPerson1.person.fullName, "") ? modifiedPerson1.person.fullName : "null", modifiedPerson1.person.age);
     printf("Address: %s", modifiedPerson1.address);
     printf("Favorite number = %d\n", modifiedPerson1.favoriteNumber);
     printf("\n");

     // Access person2 variables
     PersonTypeDef person2;
     strcpy(person2.person.fullName, "HelloWorld");
     person2.person.age = 20;
     strcpy(person2.address, "Korea");
     person2.favoriteNumber = 1;

     // Print out person2 variables
     printf("Person 2 information: \n");
     printf("Person 2: {fullName = %s, age = %d, address = %s, favoriteNumber = %d}\n", person2.person.fullName, person2.person.age, person2.address, person2.favoriteNumber);

     return 0;
}