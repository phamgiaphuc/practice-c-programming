#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char* strs[], int n) {
    if (n == 0) {
        return "prefix not found";
    }

    char* prefix = strs[0];
    int i, j;

    for (i = 1; i < n; i++) {
        j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
    }

    return prefix;
}

int main() {
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);

    char* strs[n];
    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);
        strs[i] = strdup(temp);  
    }

    char* prefix = longestCommonPrefix(strs, n);

    printf("Longest common prefix: %s\n", prefix);

    return 0;
}
