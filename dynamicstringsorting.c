#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int myCompare(const void* a, const void* b)
{
    return strcmp(*(const char**)a, *(const char**)b);
}

void sort(const char* arr[], int n)
{
    qsort(arr, n, sizeof(const char*), myCompare);
}

int main()
{
    int n;
    printf("Enter the number of strings: ");
    scanf("%d", &n);
    getchar(); // consume the newline character

    const char** arr = malloc(n * sizeof(const char*));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the strings:\n");
    for (int i = 0; i < n; i++) {
        char buffer[100];
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; // remove the trailing newline character
        arr[i] = strdup(buffer);
    }

    printf("\nGiven array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %s\n", i, arr[i]);

    sort(arr, n);

    printf("\nSorted array is:\n");
    for (int i = 0; i < n; i++)
        printf("%d: %s\n", i, arr[i]);

    // Free the dynamically allocated memory
    for (int i = 0; i < n; i++)
        free((void*)arr[i]);
    free(arr);

    return 0;
}
