#include <stdio.h>

// Declare functions
void inputArray(int[], int);
void twoSum(int[], int, int);

int main() {
     // Declare variables
	int size, target;
     printf("Enter the size: ");
	scanf("%d", &size);
	int array[size];
	inputArray(array, size);
     printf("Enter the target number: ");
	scanf("%d", &target);
     twoSum(array, size, target);
	return 0;
}

void inputArray(int array[], int n) {
	printf ("Enter numbers: ");
	for (int i = 0; i < n; i++) {
	     scanf("%d", array + i);
	}
}

void twoSum(int array[], int n, int t) {
	int i, j, index1 = 0, index2 = 0;
	for ( i = 0; i < n; i++) {
		for ( j = i + 1; j < n; j++) {
			if ((array[i] + array[j])  == t) {
				index1 = i;
				index2 = j;
                    break;
			}
		}
	}
     if (index1 == 0 && index2 == 0) {
          print("No values!");
     } else {
          printf ("Return indices of the two numbers: %d, %d\n", index1, index2);
     }
}