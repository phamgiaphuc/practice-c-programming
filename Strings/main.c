#include <stdio.h>
#include <string.h>

int main() {
     // Declare variables
     char string1[20] = "Hello";
     char string2[] = "World";

     /**
      * String handling library has functions to 
      * - Manipulate string data
      * - Search strings
      * - Tokenize strings
      * - Determine string length
     */

     /**
      * 1. String Manipulation Functions
     */
     // strcpy(string1, string2); // Copy string2 to string1. Value string1 is returned. --> string1 = "World"
     // strncpy(string1, string2, 3); // Copy number characters of string2 to string1. Value string1 is returned. --> string1 = "Worlo"
     // strcat(string1, string2); // Append string2 to string1. Value string1 is returned. --> string1 = "HelloWorld"
     // strncat(string1, string2, 2); // Append number characters of string2 to string1. Value string1 is returned. --> string1 = "HelloWo"

     // printf("%s\n", string1);

     /**
      * 2. String Comparison Functions
     */
     // int result;
     // result = strcmp(string1, string2); // Compare 2 strings. Returns negative number if s1 < s2; zero if s1 = s2; positive number if s1 > s2.
     // result = strncmp(string1, string2, 1); // Compare up to n characters of string s1 to s2. Returns as values above.
     
     // printf("Result = %d\n", result);

     /**
      * 3. String Search Functions
     */
     // char *result;
     // int value;
     // result = strchr(string1, 'e'); // Locates the FIRST occurrence of character c in string s. 
                                       // If c is found, a pointer to c in s is returned. Otherwise, a NULL pointer is returned. --> result = "ello"
     // value = strcspn(string1, "lo"); // Determines and returns the length of the initial segment of string s1 consisting of characters not contained in string s2. --> value = 1
     // value = strspn(string1, "Hel"); // The length of the initial portion of str1 containing only characters that appear in str2.
                                         // Therefore, if all of the characters in str1 are in str2, the function returns the length of the entire str1 string, 
                                         // and if the first character in str1 is not in str2, the function returns zero. --> value = 0
     // result = strpbrk(string1, string2); // Locates the first occurrence in string s1 of any character in string s2. 
                                            // If a character from string s2 is found, a pointer to the character in string s1 is returned. Other- wise, a NULL pointer is returned. --> result = "llo"
     // result = strrchr(string1, 'l'); // Locates the last occurrence of c in string s. 
                                        // If c is found, a pointer to c in string s is returned. Otherwise, a NULL pointer is returned. --> result = "lo"
     // result = strstr(string1, "He"); // Locates the first occurrence in string s1 of string s2. 
                                          // If the string is found, a pointer to the string in s1 is returned. Otherwise, a NULL pointer is returned. --> result = "ello"
     // result = strtok(string1, string2); // A sequence of calls to this function split str into tokens, which are sequences of contiguous characters separated by any of the characters that are part of delimiters.
                                           // string1 = "He\0" --> result = "He"
     // printf("%s\n", string1);
     // printf("Result = %s\n", result);
     // printf("Value = %d\n", value);

     /**
      * 3. String Memory Functions 
     */
     // char *result;
     // int value;
     // result = memcpy(string1, string2, 2); // Copies n characters from the object pointed to by s2 into the object pointed to by s1. A pointer to the resulting object is returned. --> result = "Wollo"
     // result = memmove(string1, string2, 2); // Copies n characters from the object pointed to by s2 into the object pointed to by s1. 
                                               // The copy is performed as if the characters are first copied from the object pointed to by s2 into a temporary array, 
                                               // and then copied from the temporary array into the object pointed to by s1. A pointer to the resulting object is returned. --> result = "Wollo"
     // value = memcmp(string1, string2, 2); // Compares the first n characters of the objects pointed to by s1 and s2. 
                                             // The function returns 0, less than 0, or greater than 0 if s1 is equal to, less than or greater than s2, respectively.
     // result = memchr(string1, 'l', 2); // Locates the first occurrence of c (converted to unsigned char) in the first n characters of the object pointed to by s. 
                                          // If c is found, a pointer to c in the object is returned. Otherwise, null is returned. --> result = null
     // result = memset(string1, 'x', 6); // Copies c (converted to unsigned char) into the first n characters of the object pointed to by s. A pointer to the result is returned. --> result = "xxxlo"

     // printf("Result = %s\n", result);
     // printf("Value = %d\n", value);

     /**
      * 4. Other Functions
     */
     // char *result;
     // int value;
     // result = strerror(2); // Creates a system-dependent error message based on errornum. Returns a pointer to the string
     // value = strlen(string1); // Return the size of string

     // printf("Error = %s\n", result);
     // printf("Value = %d\n", value);
     
     return 0;
}