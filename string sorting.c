#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int stringcompare(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i])
            return -1;
        else if (str1[i] > str2[i])
            return 1;

        i++;
    }
    if (str1[i] == '\0' && str2[i] != '\0')
        return -1;
    else if (str1[i] != '\0' && str2[i] == '\0')
        return 1;

    return 0;
}

void bubbleSort(char** arr, int n) {
    int i, j;
    char* temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (stringcompare(arr[j], arr[j + 1]) > 0) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, i;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar();
    char** arr;

    printf("Enter the strings:\n");
    for (i = 0; i < n; i++) {
        arr[i] = malloc(100);
        fgets(arr[i], 100, stdin);
    }

    if(arr == NULL){
        printf("memory allocation failed.");
        return 1;
    }

    printf("\nThe array of strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s", arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nThe sorted array of strings:\n");
    for (i = 0; i < n; i++) {
        printf("%s", arr[i]);
    }

    return 0;
}



