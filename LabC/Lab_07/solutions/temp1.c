#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* commonPrefixUtil(char* str1, char* str2)
{
	char* result = (char*)malloc(100 * sizeof(char));
	int len = strlen(str1) < strlen(str2) ? strlen(str1)
										: strlen(str2);

	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i])
			break;
		result[i] = str1[i];
	}

	result[len] = '\0';
	return result;
}

char* commonPrefix(char* arr[], int n)
{
	char* prefix = arr[0];

	for (int i = 1; i < n; i++) {
		prefix = commonPrefixUtil(prefix, arr[i]);
	}

	return prefix;
}

int main()
{
	char* arr[] = { "abc", "abd", "abf"};
	int n = sizeof(arr) / sizeof(arr[0]);

	char* ans = commonPrefix(arr, n);

	if (strlen(ans))
		printf("The longest common prefix is %s\n", ans);
	else
		printf("Common prefix is not found.\n");

	free(ans);

	return 0;
}
