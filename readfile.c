#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char n[100];
    int fsize;
    FILE *ptr1;
    FILE *ptr2;
    FILE *ptr3;
    FILE *ptr4;
    FILE *ptr5;

    ptr1 = fopen("file1.txt","r");
    ptr2 = fopen("file2.txt","r");
    ptr3 = fopen("file3.txt","r");
    ptr4 = fopen("file4.txt","r");
    ptr5 = fopen("file5.txt","r");

    if(ptr1==NULL || ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5 == NULL)
    {
        printf("file not exist");
    }
     
    fscanf(ptr1, "%s", n);
    fscanf(ptr1, "%d", &fsize);
    printf("the first char in the given string:%c\n",n[0]);
    printf("the size of the given string:%d\n",fsize);
    fscanf(ptr1, "%s", n);
    printf("the string in file1:%s\n",n);

    fscanf(ptr2, "%s", n);
    fscanf(ptr2, "%d", &fsize);
    printf("the first char in the given string:%c\n",n[0]);
    printf("the size of the given string:%d\n",fsize);
    fscanf(ptr2, "%s", n);
    printf("the string in file2:%s\n",n);

    fscanf(ptr3, "%s", n);
    fscanf(ptr3, "%d", &fsize);
    printf("the first char in the given string:%c\n",n[0]);
    printf("the size of the given string:%d\n",fsize);
    fscanf(ptr3, "%s", n);
    printf("the string in file3:%s\n",n);

    fscanf(ptr4, "%s", n);
    fscanf(ptr4, "%d", &fsize);
    printf("the first char in the given string:%c\n",n[0]);
    printf("the size of the given string:%d\n",fsize);
    fscanf(ptr4, "%s", n);
    printf("the string in file4:%s\n",n);

    fscanf(ptr5, "%s", n);
    fscanf(ptr5, "%d", &fsize);
    printf("the first char in the given string:%c\n",n[0]);
    printf("the size of the given string:%d\n",fsize);
    fscanf(ptr5, "%s", n);
    printf("the string in file5:%s\n",n);
    
    return 0;
}
