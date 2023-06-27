#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[100];
    FILE *ptr1;
    FILE *ptr2;
    FILE *ptr3;
    FILE *ptr4;
    FILE *ptr5;

    ptr1 = fopen("bfile1.bin","rb");
    ptr2 = fopen("bfile2.bin","rb");
    ptr3 = fopen("bfile3.bin","rb");
    ptr4 = fopen("bfile4.bin","rb");
    ptr5 = fopen("bfile5.bin","rb");

    if(ptr1==NULL || ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5== NULL)
    {
        printf("file not exist");
    }
    
    fread(&n, 100, 1, ptr1);
    printf("the string in bfile1:%s\n",n);

    fread(&n, 100, 1, ptr2);
    printf("the string in bfile2:%s\n",n);

    fread(&n, 100, 1, ptr3);
    printf("the string in bfile3:%s\n",n);

    fread(&n, 100, 1, ptr4);
    printf("the string in bfile4:%s\n",n);

    fread(&n, 100, 1, ptr5);
    printf("the string in bfile5:%s\n",n);

    return 0;
}