#include <stdio.h>
#include <string.h>
// this program is to find whether the given word is in the string or not
int main() {
    char arr[50], word[50];
    int i = 0, j = 0;

    printf("Enter the string: ");
    fgets(arr, 50, stdin);
    while (arr[i] != '\n' && i < 50) {  //this loop is to check the newline character or to check whether it reached the maximum limit 
        i++;
    }
    arr[i] = '\0';// new line character is replaced by null character for proper termination

    printf("Enter the word to be searched in the string: ");
    fgets(word, 50, stdin);
    while (word[j] != '\n' && j < 50) {
        j++;
    }
    word[j] = '\0';

    int found = 0;
    for (i = 0; arr[i] != '\0'; i++) {
        if (arr[i] == word[0]) { // comparing the first word
            found = 1;
            for (j = 1; word[j] != '\0'; j++) {
                if (arr[i + j] != word[j]) { // comparision starts from the second word
                    found = 0;
                    break;
                }
            }
        }
    }

    if (found=1) {
        printf("The word '%s' is present in the string.\n", word);
    } else {
        printf("The word '%s' is not present in the string.\n", word);
    }

    return 0;
}

