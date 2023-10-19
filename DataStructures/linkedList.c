/**
 * Linked list example: Inserting and deleting nodes in a list
*/
#include <stdio.h>
#include <stdlib.h>

//Self-referential structure
struct listNode {
     int data; // Each listNode contains a character
     struct listNode *nextPointer; // A pointer to next node
};

typedef struct listNode ListNode; // Synonym for struct listNode
typedef ListNode *ListNodePointer; // Synonym for ListNode*

// Prototypes
void instruction();
void insert(ListNodePointer *, int);
void printList(ListNodePointer);
int isEmpty(ListNodePointer);

int main() {
     // Declared variables
     ListNodePointer startPointer = NULL; // Initialize there are no nodes
     int inputValue;
     int choice;

     // Loop while
     while (1) {
          instruction();
          printf("Input: ");
          scanf("%d", &choice);
          if (choice == 4) {
               printf("Program ends!\n");
               return 0;
          } else {
               printf("\n");
               switch (choice) {
               case 1:
                    printf("Choice 1: Insert an element into the list.\n");
                    printf("Enter a number: ");
                    scanf("%d", &inputValue);
                    insert(&startPointer, inputValue);
                    printList(startPointer);
                    break;
               case 2:
                    printf("Choice 2: Delete an element from the list.\n");
                    break;
               case 3:
                    printf("Choice 3: Print the list.\n");
                    printList(startPointer);
                    break;
               default:
                    printf("Invalid choice!\n");
                    break;
               }
          }
     }
     
     return 0;
}

void insert(ListNodePointer *nodePtr, int value) {
     ListNodePointer newPtr = malloc(sizeof(ListNode)); // Create node

     // Check if the newPtr has memory allocation
     if (newPtr != NULL) { // Is space avaliable

          newPtr -> data = value; // Assign value in the node
          newPtr -> nextPointer = NULL; // Node does not link to another node

          ListNodePointer previousPointer = NULL;
          ListNodePointer currentPointer = *nodePtr; 
          
          printf("--1--\n");
          printf("%p\n", previousPointer);
          printf("%p\n", currentPointer);
          printf("-----\n");

          while (currentPointer != NULL && value > currentPointer -> data) {
               previousPointer = currentPointer;
               currentPointer = currentPointer -> nextPointer;

               printf("--2--\n");
               printf("%p\n", previousPointer);
               printf("%p\n", currentPointer);
               printf("-----\n");
          }

          // Insert new node at beginning of the list
          if (previousPointer == NULL) {
               newPtr -> nextPointer = *nodePtr;
               *nodePtr = newPtr;
          } else { // Insert new node between previousPointer and currentPointer
               previousPointer -> nextPointer = newPtr;
               newPtr -> nextPointer = currentPointer;
          }
     } else {
          printf("%d can not be inserted. No memory allocation is available!\n", value);
     }
}

void printList(ListNodePointer currentPoiter) {
     // Check if list is empty
     if (isEmpty(currentPoiter)) {
          printf("List is empty!\n");
     } else {
          printf("The list is: ");

          while (currentPoiter != NULL) {
               printf("[ %d (%p) | %p ] --> ", currentPoiter -> data, &(currentPoiter -> data), currentPoiter -> nextPointer);
               // The list is: [ 3 (0x7f9ddb804090) | 0x7f9ddb804080 ] --> [ 4 (0x7f9ddb804080) | 0x7f9ddb904080 ] -->[ 5 (0x7f9ddb904080) | 0x0 ] --> [ NULL ]
               currentPoiter = currentPoiter -> nextPointer;
          }
          printf("[ NULL ]\n");
     }
}

// Return 1 if the list is empty, otherwise 0
int isEmpty(ListNodePointer pointer) {
     return pointer == NULL;
}

void instruction() {
     printf("\n");
     printf("--- Enter your choice ---\n");
     printf("1. Insert an element into the list.\n");
     printf("2. Delete an element from the list.\n");
     printf("3. Print the list.\n");
     printf("4. Exit the program.\n");
     printf("-------------------------\n");
}