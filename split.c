#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char filename[10];
    int size;
    int offset;
} Filemetadata;

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

    Filemetadata metadata;

    if (input == NULL || output == NULL) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    // Set metadata fields
    strcpy(metadata.filename, inputfile);
    fseek(output, 0, SEEK_END);
    metadata.offset = ftell(output);
    fseek(input, 0, SEEK_END);
    metadata.size = ftell(input);

    // Write metadata to the merged file
    fwrite(&metadata, sizeof(Filemetadata), 1, output);

    // Copy the content of the input file to the merged file
    int ch;
    fseek(input, 0, SEEK_SET); // Rewind to the beginning of the input file
    while ((ch = fgetc(input)) != EOF) {
        fputc(ch, output);
    }

    fclose(input);
    fclose(output);
}

void ls(char *outputfile) {
    FILE *output = fopen(outputfile, "rb");
    if (output == NULL) {
        perror("Error opening merged file");
        exit(EXIT_FAILURE);
    }

    printf("Merged file names:\n");

    Filemetadata metadata;

    while (fread(&metadata, sizeof(Filemetadata), 1, output) != 0) {
        printf("%s\n", metadata.filename);
        fseek(output, metadata.size, SEEK_CUR);
    }

    fclose(output);
}

void split(char *inputfile) {
    FILE *input = fopen(inputfile, "rb");
    if (input == NULL) {
        perror("Error opening merged file");
        exit(EXIT_FAILURE);
    }

    Filemetadata metadata;
    

    while ( fread(&metadata, sizeof(Filemetadata), 1, input)!= 0) {
        // Create a new file using the filename from metadata
        printf("%s\n",metadata.filename);
        printf("%d\n",metadata.offset);
        printf("%d\n",metadata.size);

        FILE *output = fopen(metadata.filename, "wb");
        if (output == NULL) {
            perror("Error creating output file");
            exit(EXIT_FAILURE);
        }

        // Write the file content to the output file
        int ch;
        int bytesRead = 0;
        while ((ch = fgetc(input)) != EOF && bytesRead < metadata.size) {
            fputc(ch, output);
            bytesRead++;
        }

        // Close the output file
        fclose(output);
        
        // Rewind the file pointer to the beginning of the next metadata entry
        fseek(input, -1 , SEEK_CUR);
    }

    fclose(input);
    printf("Split %s into individual files.\n", inputfile);
}






void display(char *outputfile) {
    FILE *output = fopen(outputfile, "rb");
    if (output == NULL) {
        perror("Error opening merged file");
        exit(EXIT_FAILURE);
    }

    printf("File metadata in %s:\n", outputfile);

    Filemetadata metadata;

    while (fread(&metadata, sizeof(Filemetadata), 1, output) != 0) {
        printf("Filename: %s\n", metadata.filename);
        printf("Size: %d\n", metadata.size);
        printf("Offset: %d\n", metadata.offset);

        // Move the file pointer to the next metadata entry
        fseek(output, metadata.size, SEEK_CUR);
    }

    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s merged_file [ls/append/cat/split/display] [inputfiles...]\n", argv[0]);
        return 1;
    }
    

    char *outputfile = argv[1];
    char *operation = argv[2];

    if (strcmp(operation, "append") == 0) {
        if (argc < 4) {
            printf("Usage: %s merged_file append [inputfiles...]\n", argv[0]);
            return 1;
        }
        for (int i = 3; i < argc; i++) {
            append(argv[i], outputfile);
        }
    } else if (strcmp(operation, "ls") == 0) {
        ls(outputfile);
    } else if (strcmp(operation, "cat") == 0) {
        cat(outputfile);
    } else if (strcmp(operation, "split") == 0) {
        split(outputfile);
    } else if (strcmp(operation, "display") == 0) {
        display(outputfile);
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }

    return 0;
}
