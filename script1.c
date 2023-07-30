#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Defining a  structure named 'metadata' to hold file information.
typedef struct {
    char filename[10];
    int filesize;
    char index1;
    char index2;
    char string1[50];
    char string2[50];
    int size1;
    int size2;
    char keyvalue[836];
    int size3;
} metadata;

int main() {

    metadata data; // Create an instance of the 'metadata' struct.

    int signed_status, signed_status1, signed_status2, signed_status3, signed_status4, signed_status5;
    int f1size, f2size, f3size, f4size, f5size;

    // Open binary files in append mode for writing, along with binary signature files for reading.
    FILE* ptr1 = fopen("bfile1.bin", "ab");
    FILE* ptr2 = fopen("bfile2.bin", "ab");
    FILE* ptr3 = fopen("bfile3.bin", "ab");
    FILE* ptr4 = fopen("bfile4.bin", "ab");
    FILE* ptr5 = fopen("bfile5.bin", "ab");
    FILE* ptr6 = fopen("bfile1_bin.sign", "rb");
    FILE* ptr7 = fopen("bfile2_bin.sign", "rb");
    FILE* ptr8 = fopen("bfile3_bin.sign", "rb");
    FILE* ptr9 = fopen("bfile4_bin.sign", "rb");
    FILE* ptr10 = fopen("bfile5_bin.sign", "rb");
    FILE* ptr11 = fopen("public.pem", "rb"); // Open the public key file.
    FILE* fptr = fopen("bcombine.bin", "wb"); // Create a new file for writing, used to combine the contents.
    FILE* fptr1 = fopen("bcombine_bin.sign", "rb"); // File for reading binary signature.

    // Determine the size of the public key file and read its content into 'data.keyvalue'.
    fseek(ptr11, 0, SEEK_END);
    data.size3 = ftell(ptr11);
    rewind(ptr11);
    fread(data.keyvalue, data.size3, 1, ptr11);

    // Write the content of 'data.keyvalue' to the first five binary files.
    fwrite(data.keyvalue, data.size3, 1, ptr1);
    fwrite(data.keyvalue, data.size3, 1, ptr2);
    fwrite(data.keyvalue, data.size3, 1, ptr3);
    fwrite(data.keyvalue, data.size3, 1, ptr4);
    fwrite(data.keyvalue, data.size3, 1, ptr5);

    // Calculate the total filesize by summing 'data.size1', 'data.size2', and 'data.size3'.

    data.filesize = data.size1 + data.size2 + data.size3;

    // Determine the sizes of each binary file.
    fseek(ptr1, 0L, SEEK_END);
    f1size = ftell(ptr1);
    fseek(ptr2, 0L, SEEK_END);
    f2size = ftell(ptr2);
    fseek(ptr3, 0L, SEEK_END);
    f3size = ftell(ptr3);
    fseek(ptr4, 0L, SEEK_END);
    f4size = ftell(ptr4);
    fseek(ptr5, 0L, SEEK_END);
    f5size = ftell(ptr5);

    // Check if the binary signature file and each of the five binary files exist and set their status accordingly.
    if (fptr1 == NULL) {
        signed_status = 0;
    } else {
        signed_status = 1;
    }

    if (ptr6 == NULL) {
        signed_status1 = 0;
    } else {
        signed_status1 = 1;
    }

    if (ptr7 == NULL) {
        signed_status2 = 0;
    } else {
        signed_status2 = 1;
    }

    if (ptr8 == NULL) {
        signed_status3 = 0;
    } else {
        signed_status3 = 1;
    }

    if (ptr9 == NULL) {
        signed_status4 = 0;
    } else {
        signed_status4 = 1;
    }

    if (ptr10 == NULL) {
        signed_status5 = 0;
    } else {
        signed_status5 = 1;
    }

    // Print the signed status of the bcombine file and each individual file.
    printf("signed status of the bcombine file is: %d\n", signed_status);
    printf("signed status of the file1 is: %d\n", signed_status1);
    printf("signed status of the file2 is: %d\n", signed_status2);
    printf("signed status of the file3 is: %d\n", signed_status3);
    printf("signed status of the file4 is: %d\n", signed_status4);
    printf("signed status of the file5 is: %d\n", signed_status5);

    printf("Value in keyvalue1 in file1: %s\n", data.keyvalue);

    // Close all open files.
    fclose(fptr);
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    fclose(ptr4);
    fclose(ptr5);
    fclose(fptr1);
    fclose(ptr6);
    fclose(ptr7);
    fclose(ptr8);
    fclose(ptr9);
    fclose(ptr10);

    // Merge the five binary files into a single file.
    fptr = fopen("bcombine.bin", "wb");
    ptr1 = fopen("bfile1.bin", "rb");
    ptr2 = fopen("bfile2.bin", "rb");
    ptr3 = fopen("bfile3.bin", "rb");
    ptr4 = fopen("bfile4.bin", "rb");
    ptr5 = fopen("bfile5.bin", "rb");

    // Check if any of the files do not exist.
    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL || ptr4 == NULL || ptr5 == NULL || fptr == NULL) {
        printf("Files do not exist......");
    }

    char m;

    // Copy the contents of each binary file into the combined file one by one.
    while ((m = fgetc(ptr1)) != EOF) {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr2)) != EOF) {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr3)) != EOF) {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr4)) != EOF) {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr5)) != EOF) {
        fputc(m, fptr);
    }

    printf("All files have been merged.\n");
    fclose(fptr);
    fclose(ptr1);
    fclose(ptr2);
    fclose(ptr3);
    fclose(ptr4);
    fclose(ptr5);

    return 0;
}
