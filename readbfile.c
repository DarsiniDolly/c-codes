#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char n[50],m;
    int fsize,fsize1,fsize2,fsize3,fsize4;
    FILE *fptr;
    FILE *ptr1;
    FILE *ptr2;
    FILE *ptr3;
    FILE *ptr4;
    FILE *ptr5;

    fptr = fopen("bmerge.bin", "rb");
    ptr1 = fopen("bfile1.bin", "wb");
    ptr2 = fopen("bfile2.bin", "wb");
    ptr3 = fopen("bfile3.bin", "wb");
    ptr4 = fopen("bfile4.bin", "wb");
    ptr5 = fopen("bfile5.bin", "wb");


    if (fptr == NULL)
    {
        printf("Could not open the merged file.\n");
       
    }
    if (ptr1 == NULL || ptr2 == NULL || ptr3 == NULL || ptr4 == NULL || ptr5 == NULL)
    {
        printf("Could not open the output files.\n");
        
    }

    fread(&n[0], sizeof(char), 1,fptr);
    fread(&fsize, sizeof(int), 1, fptr);
    fread(n, sizeof(char), fsize,fptr);

    while ((m = fgetc(fptr)) == fsize )
    {
        fputc(m, ptr1);
    }
    fwrite(&n[0], sizeof(char), 1,ptr1);
    fwrite(&fsize, sizeof(int), 1, ptr1);
    fwrite(n, sizeof(char), fsize,ptr1);
    printf("index1:%c\n",n[0]);
    printf("size1:%d\n",fsize);
    printf("the string1:%s\n",n);
    fclose(ptr1);

    
    fread(&fsize1, sizeof(int), 1, fptr);
    fread(n, sizeof(char), fsize,fptr);

    while ((m = fgetc(fptr)) == fsize1)
    {
        fputc(m, ptr2);
    }
    fwrite(&n[0], sizeof(char), 1,ptr2);
    fwrite(&fsize, sizeof(int), 1, ptr2);
    fwrite(n, sizeof(char), fsize,ptr2);
    printf("index2:%c\n",n[0]);
    printf("size2:%d\n",fsize);
    printf("the string2:%s\n",n);
    fclose(ptr2);

    
    fread(&fsize2, sizeof(int), 1, fptr);
    fread(n, sizeof(char), fsize,fptr);
   
    while ((m = fgetc(fptr)) == fsize2)
    {
        fputc(m, ptr3);
    }
    fwrite(&n[0], sizeof(char), 1,ptr3);
    fwrite(&fsize, sizeof(int), 1, ptr3);
    fwrite(n, sizeof(char), fsize,ptr3);
    printf("index3:%c\n",n[0]);
    printf("size3:%d\n",fsize);
    printf("the string3:%s\n",n);
    fclose(ptr3);


    
    fread(&fsize3, sizeof(int), 1, fptr);
    fread(n, sizeof(char), fsize,fptr);

    while ((m = fgetc(fptr)) == fsize3)
    {
        fputc(m, ptr4);
    }
    fwrite(&n[0], sizeof(char), 1,ptr4);
    fwrite(&fsize, sizeof(int), 1, ptr4);
    fwrite(n, sizeof(char), fsize,ptr4);
    printf("index4:%c\n",n[0]);
    printf("size4:%d\n",fsize);
    printf("the string4:%s\n",n);
    fclose(ptr4);


    fread(&fsize4, sizeof(int), 1, fptr);
    fread(n, sizeof(char), fsize,fptr);

    while ((m = fgetc(fptr)) == fsize)
    {
        fputc(m, ptr5);
    }
    fclose(fptr);
    fwrite(&n[0], sizeof(char), 1,ptr5);
    fwrite(&fsize, sizeof(int), 1, ptr5);
    fwrite(n, sizeof(char), fsize,ptr5);
    printf("index5:%c\n",n[0]);
    printf("size5:%d\n",fsize);
    printf("the string5:%s\n",n);
    fclose(ptr5);
    
    

    return 0;

}
