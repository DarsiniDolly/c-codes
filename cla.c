#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char filename[50];
    int size;
    char string[4096];
    
}filemetadata;

void ls(char *mergedfile) {
    FILE *merged = fopen(mergedfile, "rb");
    if (merged == NULL) {
        perror("Error opening merged file");
        exit(EXIT_FAILURE);
    }
    char filename[4096];  // Variable to store the filename
    printf("Merged file names:\n");

    while (fscanf(merged, "%s", filename) != EOF) {
        printf("%s\n", filename);
    }

    fclose(merged);
}


void cat(char *outputfile) {
    FILE *output = fopen(outputfile, "rb");
    if (output == NULL) {
        perror("Error opening merged file");
        exit(EXIT_FAILURE);
    }
    int ch;
    printf("Merged file content:\n");
    while ((ch = fgetc(output)) != EOF) {
        putchar(ch);
    }

    fclose(output);
}


void append(char *inputfile, char *outputfile) {
    FILE *input = fopen(inputfile, "rb");
    FILE *output = fopen(outputfile, "ab");

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch, output);
    }

    printf("File %s appended \n", inputfile);

    fclose(input);
    fclose(output);

    FILE *merged = fopen(outputfile, "ab");
    if (merged == NULL) {
        perror("Error opening merged file");
        exit(EXIT_FAILURE);
    }
    // Append the filename to the merged file
    fprintf(merged, "%s\n", inputfile);
    fclose(merged);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s merged_file [ls/append/cat] inputfiles...\n", argv[0]);
        return 1;
    }
    
    char *outputfile = argv[1];
    char *operation = argv[2];

    if (strcmp(operation, "append") == 0) {
        for (int i = 3; i < argc; i++) {
            append(argv[i], outputfile);
        }
    } else if (strcmp(operation, "ls") == 0) {
        ls(outputfile);
    } else if (strcmp(operation, "cat") == 0) {
        cat(outputfile);
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}
