#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct metadata{
    char filename[50];
    int filesize;
    char index1;
    char index2;
    char string1[50];
    char string2[50];
    int size1;
    int size2;
};

int main()
{
   struct metadata data; 
    
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
    
    printf("the name of the file1:");
    scanf("%s", data.filename);
    printf("the string1 in file1:");
    scanf("%s",data.string1);
    data.size1= strlen(data.string1);
    printf("The size of the string1 in file1: %d\n",data.size1);
    printf("the string2 in file1:");
    scanf("%s",data.string2);
    data.size2= strlen(data.string2);
    printf("The size of the string2 in file1: %d\n",data.size2);
    data.filesize = data.size1 + data.size2;
    printf("the size of the file:%d\n",data.filesize);
    data.index1 =data.string1[0];
    data.index2 = data.string2[0];
    printf("The first character in the string1:%c\n",data.index1);
    printf("the first character in the string2:%c\n",data.index2);
    
    fwrite(&data, sizeof(struct metadata),1,ptr1);
    fclose(ptr1);

    printf("the name of the file2:");
    scanf("%s", data.filename);
    printf("the string1 in file2:");
    scanf("%s",data.string1);
    data.size1= strlen(data.string1);
    printf("The size of the string1 in file2: %d\n",data.size1);
    printf("the string2 in file2:");
    scanf("%s",data.string2);
    data.size2= strlen(data.string2);
    printf("The size of the string2 in file2: %d\n",data.size2);
    data.filesize = data.size1 + data.size2;
    printf("the size of the file:%d\n",data.filesize);
    data.index1 =data.string1[0];
    data.index2 = data.string2[0];
    printf("The first character in the string1:%c\n",data.index1);
    printf("the first character in the string2:%c\n",data.index2);
    
    fwrite(&data, sizeof(struct metadata),1,ptr2);
    fclose(ptr2);

    printf("the name of the file3:");
    scanf("%s", data.filename);
    printf("the string1 in file3:");
    scanf("%s",data.string1);
    data.size1= strlen(data.string1);
    printf("The size of the string1 in file3: %d\n",data.size1);
    printf("the string2 in file3:");
    scanf("%s",data.string2);
    data.size2= strlen(data.string2);
    printf("The size of the string2 in file3: %d\n",data.size2);
    data.filesize = data.size1 + data.size2;
    printf("the size of the file:%d\n",data.filesize);
    data.index1 =data.string1[0];
    data.index2 = data.string2[0];
    printf("The first character in the string1:%c\n",data.index1);
    printf("the first character in the string2:%c\n",data.index2);
    
    fwrite(&data, sizeof(struct metadata),1,ptr3);
    fclose(ptr3);

    printf("the name of the file4:");
    scanf("%s", data.filename);
    printf("the string1 in file4:");
    scanf("%s",data.string1);
    data.size1= strlen(data.string1);
    printf("The size of the string1 in file4: %d\n",data.size1);
    printf("the string2 in file4:");
    scanf("%s",data.string2);
    data.size2= strlen(data.string2);
    printf("The size of the string2 in file4: %d\n",data.size2);
    data.filesize = data.size1 + data.size2;
    printf("the size of the file:%d\n",data.filesize);
    data.index1 =data.string1[0];
    data.index2 = data.string2[0];
    printf("The first character in the string1:%c\n",data.index1);
    printf("the first character in the string2:%c\n",data.index2);
    
    fwrite(&data, sizeof(struct metadata),1,ptr4);
    fclose(ptr4);

    printf("the name of the file5:");
    scanf("%s", data.filename);
    printf("the string1 in file5:");
    scanf("%s",data.string1);
    data.size1= strlen(data.string1);
    printf("The size of the string1 in file5: %d\n",data.size1);
    printf("the string2 in file5:");
    scanf("%s",data.string2);
    data.size2= strlen(data.string2);
    printf("The size of the string2 in file5: %d\n",data.size2);
    data.filesize = data.size1 + data.size2;
    printf("the size of the file:%d\n",data.filesize);
    data.index1 =data.string1[0];
    data.index2 = data.string2[0];
    printf("The first character in the string1:%c\n",data.index1);
    printf("the first character in the string2:%c\n",data.index2);
    
    fwrite(&data, sizeof(struct metadata),1,ptr5);
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
