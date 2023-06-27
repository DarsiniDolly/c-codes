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

    ptr1 = fopen("bfile1.bin","wb");
    ptr2 = fopen("bfile2.bin","wb");
    ptr3 = fopen("bfile3.bin","wb");
    ptr4 = fopen("bfile4.bin","wb");
    ptr5 = fopen("bfile5.bin","wb");

    if(ptr1==NULL || ptr2==NULL || ptr3==NULL || ptr4==NULL || ptr5==NULL )
    {
        printf("file not exist");
    }

    printf("the string to be written in bfile1: ");
    scanf("%s",n);
    fwrite(&n, 100, 1,ptr1);

    printf("the string to be written in bfile2: ");
    scanf("%s",n);
    fwrite(&n, 100, 1,ptr2);

    printf("the string to be written in bfile3: ");
    scanf("%s",n);
    fwrite(&n, 100, 1,ptr3);

    printf("the string to be written in bfile4: ");
    scanf("%s",n);
    fwrite(&n, 100, 1,ptr4);
    
    printf("the string to be written in bfile5: ");
    scanf("%s",n);
    fwrite(&n, 100, 1,ptr5);

    return 0;
}