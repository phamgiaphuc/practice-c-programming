#include <stdio.h>
#include <stdlib.h>

// Self-referential structure
struct node {
     int data;
     struct node *nextPointer;
};

typedef struct node listNode;
typedef listNode *listNodePtr;

// Declared function
void printLinkedlist(struct node *p) {  // Print the linked list value
     while (p != NULL) {
          printf("%d ", p-> data);
          p = p -> nextPointer;
     }
     printf("\n");
}

int main() {
     // Declared variables: Initialized the nodes
     listNodePtr head = NULL;
     listNodePtr one = NULL;
     listNodePtr two = NULL;
     listNodePtr three = NULL;

     // Allocate the memory for each node
     one = malloc(sizeof(listNode));
     two = malloc(sizeof(listNode));
     three = malloc(sizeof(listNode));

     // Assign the data value for each node
     one -> data = 1;
     two -> data = 2;
     three -> data = 3;

     // Assign the address for each node (connect nodes)
     one -> nextPointer = two;
     two -> nextPointer = three;
     three -> nextPointer = NULL;

     // Save the address of first node in head
     head -> nextPointer = one;

     // Print the linked list
     printLinkedlist(head);

     // Free allocated memory
     free(one);
     free(two);
     free(three);

     return 0;
}