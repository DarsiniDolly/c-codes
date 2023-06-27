#include <stdio.h>
#include <stdlib.h>

int main()
{
    char n[100];
    int i;
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
    fprintf(ptr1,"%s",n);
   
    printf("the string to be written in file2:");
    scanf("%s",n);
    fprintf(ptr2,"%s",n);
   
    printf("the string to be written in file3:");
    scanf("%s",n);
    fprintf(ptr3,"%s",n);
   
    printf("the string to be written in file4:");
    scanf("%s",n);
    fprintf(ptr4,"%s",n);
   
    printf("the string to be written in file5:");
    scanf("%s",n);
    fprintf(ptr5,"%s",n);
    
    return 0;
}
