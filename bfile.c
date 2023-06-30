#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char n[50];
    FILE *ptr1;
    FILE *ptr2;
    FILE *ptr3;
    FILE *ptr4;
    FILE *ptr5;
    
    ptr1 = fopen("bfile1.bin","wb");
    ptr2 = fopen("bfile2.bin","wb");
    ptr3 = fopen("bfile3.bin","wb");
    ptr4 = fopen("bfile4.bin","wb");
    ptr5 = fopen("bfile5.bin","wb");
    
    if(ptr1 == NULL|| ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5==NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }
    
    printf("the string to be written in bfile1:");
    scanf("%s", n);
    int fsize = strlen(n);
    printf("The first character in the string: %c\n",n[0]);
    printf("The size of the string: %d\n", fsize);
    fwrite(&n[0], sizeof(char), 1, ptr1);
    fwrite(&fsize, sizeof(int), 1, ptr1);
    fwrite(n, sizeof(char), fsize, ptr1);
    fclose(ptr1);

    printf("the string to be written in bfile2:");
    scanf("%s", n);
    fsize = strlen(n);
    printf("The first character in the string: %c\n",n[0]);
    printf("The size of the string: %d\n", fsize);
    fwrite(&n[0], sizeof(char), 1, ptr2);
    fwrite(&fsize, sizeof(int), 1, ptr2);
    fwrite(n, sizeof(char), fsize, ptr2);
    fclose(ptr2);

    printf("the string to be written in bfile3:");
    scanf("%s", n);
    fsize = strlen(n);
    printf("The first character in the string: %c\n",n[0]);
    printf("The size of the string: %d\n", fsize);
    fwrite(&n[0], sizeof(char), 1, ptr3);
    fwrite(&fsize, sizeof(int), 1, ptr3);
    fwrite(n, sizeof(char), fsize, ptr3);
    fclose(ptr3);

    printf("the string to be written in bfile4:");
    scanf("%s", n);
    fsize = strlen(n);
    printf("The first character in the string: %c\n",n[0]);
    printf("The size of the string: %d\n", fsize);
    fwrite(&n[0], sizeof(char), 1, ptr4);
    fwrite(&fsize, sizeof(int), 1, ptr4);
    fwrite(n, sizeof(char), fsize, ptr4);
    fclose(ptr4);

    printf("the string to be written in bfile5:");
    scanf("%s", n);
    fsize = strlen(n);
    printf("The first character in the string: %c\n",n[0]);
    printf("The size of the string: %d\n", fsize);
    fwrite(&n[0], sizeof(char), 1, ptr5);
    fwrite(&fsize, sizeof(int), 1, ptr5);
    fwrite(n, sizeof(char), fsize, ptr5);
    fclose(ptr5);


    //merging the files
    FILE *fptr;

    fptr = fopen("bmerge.bin","w");
    ptr1 = fopen("bfile1.bin","r");
    ptr2 = fopen("bfile2.bin","r");
    ptr3 = fopen("bfile3.bin","r");
    ptr4 = fopen("bfile4.bin","r");
    ptr5 = fopen("bfile5.bin","r");

    char m;

    if(ptr1==NULL || ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5==NULL || fptr==NULL)
    {
        printf("could not open files.");
    }

    while ((m = fgetc(ptr1)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr2)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr3)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr4)) != EOF)
    {
        fputc(m, fptr);
    }

    while ((m = fgetc(ptr5)) != EOF)
    {
        fputc(m, fptr);
    }

    printf("All files have been merged.\n");
    fclose(fptr);

    return 0;
}
