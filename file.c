#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char n[50];
    int fsize;
    FILE  *ptr1;
    FILE  *ptr2;
    FILE  *ptr3;
    FILE  *ptr4;
    FILE  *ptr5;
    
    ptr1 = fopen("file1.txt","w");
    ptr2 = fopen("file2.txt","w");
    ptr3 = fopen("file3.txt","w");
    ptr4 = fopen("file4.txt","w");
    ptr5 = fopen("file5.txt","w");

    if( ptr1==NULL || ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5==NULL)
    {
        printf("FILE NOT EXIST\n");
    }
    
    printf("the string to be written in file1:");
    scanf("%s",n);
    fprintf(ptr1,"%c\n",n[0]);
    fsize = strlen(n);
    fprintf(ptr1,"%d\n",fsize);
    fprintf(ptr1,"%s\n",n);
    printf("%c\n",n[0]);
    printf("%d\n",fsize);
    fclose(ptr1);

    printf("the string to be written in file2:");
    scanf("%s",n);
    fprintf(ptr2,"%c\n",n[0]);
    fsize = strlen(n);
    fprintf(ptr2,"%d\n",fsize);
    fprintf(ptr2,"%s\n",n);
    printf("%c\n",n[0]);
    printf("%d\n",fsize);
    fclose(ptr2);

    printf("the string to be written in file3:");
    scanf("%s",n);
    fprintf(ptr3,"%c\n",n[0]);
    fsize = strlen(n);
    fprintf(ptr3,"%d\n",fsize);
    fprintf(ptr3,"%s\n",n);
    printf("%c\n",n[0]);
    printf("%d\n",fsize);
    fclose(ptr3);

    printf("the string to be written in file4:");
    scanf("%s",n);
    fprintf(ptr4,"%c\n",n[0]);
    fsize = strlen(n);
    fprintf(ptr4,"%d\n",fsize);
    fprintf(ptr4,"%s\n",n);
    printf("%c\n",n[0]);
    printf("%d\n",fsize);
    fclose(ptr4);

    printf("the string to be written in file5:");
    scanf("%s",n);
    fprintf(ptr5,"%c\n",n[0]);
    fsize = strlen(n);
    fprintf(ptr5,"%d\n",fsize);
    fprintf(ptr5,"%s\n",n);
    printf("%c\n",n[0]);
    printf("%d\n",fsize);
    fclose(ptr5);

   
    

    //merging the files
    FILE *fptr;

    fptr = fopen("merge.txt","w");
    ptr1 = fopen("file1.txt","r");
    ptr2 = fopen("file2.txt","r");
    ptr3 = fopen("file3.txt","r");
    ptr4 = fopen("file4.txt","r");
    ptr5 = fopen("file5.txt","r");

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

